//
// Created by Faris Allaf on 12/24/24.
//

#include "rsa.h"
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <sstream>
#include "../cryptoUtils/sha256.h"

using namespace std;

void RSAUtil::generateKeys(const string& publicKeyFile, const string& privateKeyFile, int keySize) {
    RSA* rsa = RSA_new();
    BIGNUM* bn = BN_new();

    if (!BN_set_word(bn, RSA_F4)) { // RSA_F4 is 65537
        throw runtime_error("Failed to initialize BIGNUM.");
    }

    if (!RSA_generate_key_ex(rsa, keySize, bn, nullptr)) {
        BN_free(bn);
        RSA_free(rsa);
        throw runtime_error("Failed to generate RSA key.");
    }

    // Save private key
    FILE* privateFile = fopen(privateKeyFile.c_str(), "wb");
    if (!privateFile || !PEM_write_RSAPrivateKey(privateFile, rsa, nullptr, nullptr, 0, nullptr, nullptr)) {
        fclose(privateFile);
        BN_free(bn);
        RSA_free(rsa);
        throw runtime_error("Failed to save private key.");
    }
    fclose(privateFile);

    // Save public key
    FILE* publicFile = fopen(publicKeyFile.c_str(), "wb");
    if (!publicFile || !PEM_write_RSAPublicKey(publicFile, rsa)) {
        fclose(publicFile);
        BN_free(bn);
        RSA_free(rsa);
        throw runtime_error("Failed to save public key.");
    }
    fclose(publicFile);

    BN_free(bn);
    RSA_free(rsa);
}

string RSAUtil::encrypt(const string& plaintext, const string& publicKeyFile) {
    cout << publicKeyFile << endl;
    FILE* publicFile = fopen(publicKeyFile.c_str(), "rb");
    if (!publicFile) {
        throw runtime_error("Failed to open public key file.");
    }
    cout << publicFile << endl;

    RSA* rsa = PEM_read_RSAPublicKey(publicFile, nullptr, nullptr, nullptr);
    fclose(publicFile);
    if (!rsa) {
        throw runtime_error("Failed to read public key.");
    }

    vector<unsigned char> encrypted(RSA_size(rsa));
    int result = RSA_public_encrypt(plaintext.size(),
                                    reinterpret_cast<const unsigned char*>(plaintext.c_str()),
                                    encrypted.data(), rsa, RSA_PKCS1_OAEP_PADDING);
    RSA_free(rsa);

    if (result == -1) {
        throw runtime_error("Encryption failed: " + string(ERR_error_string(ERR_get_error(), nullptr)));
    }

    return string(encrypted.begin(), encrypted.begin() + result);
}

string RSAUtil::decrypt(const string& ciphertext, const string& privateKeyFile) {
    FILE* privateFile = fopen(privateKeyFile.c_str(), "rb");
    if (!privateFile) {
        throw runtime_error("Failed to open private key file.");
    }

    RSA* rsa = PEM_read_RSAPrivateKey(privateFile, nullptr, nullptr, nullptr);
    fclose(privateFile);
    if (!rsa) {
        throw runtime_error("Failed to read private key.");
    }

    vector<unsigned char> decrypted(RSA_size(rsa));
    int result = RSA_private_decrypt(ciphertext.size(),
                                     reinterpret_cast<const unsigned char*>(ciphertext.c_str()),
                                     decrypted.data(), rsa, RSA_PKCS1_OAEP_PADDING);
    RSA_free(rsa);

    if (result == -1) {
        throw runtime_error("Decryption failed: " + string(ERR_error_string(ERR_get_error(), nullptr)));
    }

    return string(decrypted.begin(), decrypted.begin() + result);
}

string RSAUtil::sign(const string &message, const string &privateKeyFile) {
    // open private key file
    FILE* privateFile = fopen(privateKeyFile.c_str(), "rb");
    if (!privateFile) {
        throw runtime_error("Failed to open private key file.");
    }
    // read private key from file
    RSA* rsa = PEM_read_RSAPrivateKey(privateFile, nullptr, nullptr, nullptr);
    cout << rsa << endl;
    fclose(privateFile);
    if (!rsa) {
        throw runtime_error("Failed to read private key.");
    }

    // hash message
    string hashedMsg = sha256(message);

    // sign the hashed message
    string signedMsg = encrypt(hashedMsg, privateKeyFile);

    return signedMsg;

}
