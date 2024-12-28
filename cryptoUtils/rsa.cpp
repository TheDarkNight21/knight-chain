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
    EVP_PKEY_CTX* ctx = nullptr;
    EVP_PKEY* pkey = nullptr;

    // Create a context for key generation
    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);
    if (!ctx) {
        throw runtime_error("Failed to create EVP_PKEY_CTX.");
    }

    // Initialize the context for key generation
    if (EVP_PKEY_keygen_init(ctx) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        throw runtime_error("Failed to initialize key generation context.");
    }

    // Set the RSA key size
    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, keySize) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        throw runtime_error("Failed to set RSA key size.");
    }

    // Generate the key pair
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        throw runtime_error("Failed to generate RSA key pair.");
    }

    EVP_PKEY_CTX_free(ctx); // Free the context as it is no longer needed

    // Save private key
    FILE* privateFile = fopen(privateKeyFile.c_str(), "wb");
    if (!privateFile || !PEM_write_PrivateKey(privateFile, pkey, nullptr, nullptr, 0, nullptr, nullptr)) {
        if (privateFile) fclose(privateFile);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to save private key.");
    }
    fclose(privateFile);

    // Save public key
    FILE* publicFile = fopen(publicKeyFile.c_str(), "wb");
    if (!publicFile || !PEM_write_PUBKEY(publicFile, pkey)) {
        if (publicFile) fclose(publicFile);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to save public key.");
    }
    fclose(publicFile);

    // Cleanup
    EVP_PKEY_free(pkey);
}

string RSAUtil::encrypt(const string& plaintext, const string& publicKeyFile) {
    FILE* publicFile = fopen(publicKeyFile.c_str(), "rb");
    if (!publicFile) {
        throw runtime_error("Failed to open public key file.");
    }

    // Read the public key
    EVP_PKEY* pkey = PEM_read_PUBKEY(publicFile, nullptr, nullptr, nullptr);
    fclose(publicFile);
    if (!pkey) {
        throw runtime_error("Failed to read public key.");
    }

    // Create a context for encryption
    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) {
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to create encryption context.");
    }

    if (EVP_PKEY_encrypt_init(ctx) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to initialize encryption.");
    }

    // Specify padding (OAEP recommended for modern usage)
    if (EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to set RSA padding.");
    }

    // Determine the buffer size required for encryption
    size_t outLen = 0;
    if (EVP_PKEY_encrypt(ctx, nullptr, &outLen,
                         reinterpret_cast<const unsigned char*>(plaintext.c_str()),
                         plaintext.size()) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to determine encrypted data size.");
    }

    // Encrypt the plaintext
    vector<unsigned char> encrypted(outLen);
    if (EVP_PKEY_encrypt(ctx, encrypted.data(), &outLen,
                         reinterpret_cast<const unsigned char*>(plaintext.c_str()),
                         plaintext.size()) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Encryption failed: " + string(ERR_error_string(ERR_get_error(), nullptr)));
    }

    // Cleanup
    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    // Return the encrypted data as a string
    return string(encrypted.begin(), encrypted.end());
}

string RSAUtil::decrypt(const string& ciphertext, const string& privateKeyFile) {
    FILE* privateFile = fopen(privateKeyFile.c_str(), "rb");
    if (!privateFile) {
        throw runtime_error("Failed to open private key file.");
    }

    // Read the private key
    EVP_PKEY* pkey = PEM_read_PrivateKey(privateFile, nullptr, nullptr, nullptr);
    fclose(privateFile);
    if (!pkey) {
        throw runtime_error("Failed to read private key.");
    }

    // Create a context for decryption
    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) {
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to create decryption context.");
    }

    if (EVP_PKEY_decrypt_init(ctx) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to initialize decryption.");
    }

    // Specify padding (OAEP recommended for modern usage)
    if (EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to set RSA padding.");
    }

    // Determine the buffer size required for decryption
    size_t outLen = 0;
    if (EVP_PKEY_decrypt(ctx, nullptr, &outLen,
                         reinterpret_cast<const unsigned char*>(ciphertext.c_str()),
                         ciphertext.size()) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to determine decrypted data size.");
    }

    // Decrypt the ciphertext
    vector<unsigned char> decrypted(outLen);
    if (EVP_PKEY_decrypt(ctx, decrypted.data(), &outLen,
                         reinterpret_cast<const unsigned char*>(ciphertext.c_str()),
                         ciphertext.size()) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Decryption failed: " + string(ERR_error_string(ERR_get_error(), nullptr)));
    }

    // Cleanup
    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    // Return the decrypted data as a string
    return string(decrypted.begin(), decrypted.begin() + outLen);
}

string RSAUtil::sign(const string& message, const string& privateKeyFile) {
    // Open the private key file
    FILE* privateFile = fopen(privateKeyFile.c_str(), "rb");
    if (!privateFile) {
        throw runtime_error("Failed to open private key file.");
    }

    // Read the private key
    EVP_PKEY* pkey = PEM_read_PrivateKey(privateFile, nullptr, nullptr, nullptr);
    fclose(privateFile);
    if (!pkey) {
        throw runtime_error("Failed to read private key.");
    }

    // Create a signing context
    EVP_MD_CTX* mdCtx = EVP_MD_CTX_new();
    if (!mdCtx) {
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to create message digest context.");
    }

    // Initialize the signing operation
    if (EVP_DigestSignInit(mdCtx, nullptr, EVP_sha256(), nullptr, pkey) <= 0) {
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to initialize signing operation.");
    }

    // Add the message to the context
    if (EVP_DigestSignUpdate(mdCtx, message.c_str(), message.size()) <= 0) {
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to add message to signing context.");
    }

    // Determine the size of the signature
    size_t sigLen = 0;
    if (EVP_DigestSignFinal(mdCtx, nullptr, &sigLen) <= 0) {
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to determine signature size.");
    }

    // Generate the signature
    vector<unsigned char> signature(sigLen);
    if (EVP_DigestSignFinal(mdCtx, signature.data(), &sigLen) <= 0) {
        EVP_MD_CTX_free(mdCtx);
        EVP_PKEY_free(pkey);
        throw runtime_error("Failed to generate signature.");
    }

    // Cleanup
    EVP_MD_CTX_free(mdCtx);
    EVP_PKEY_free(pkey);

    // Return the signature as a string
    return string(signature.begin(), signature.end());
}
