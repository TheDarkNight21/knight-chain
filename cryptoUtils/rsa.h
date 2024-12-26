#ifndef RSA_H
#define RSA_H

#include <string>
using namespace std;

class RSAUtil {
public:
    // Generates an RSA key pair and saves them to files
    static void generateKeys(const string& publicKeyFile, const string& privateKeyFile, int keySize);

    // Encrypts a plaintext message using the public key
    static string encrypt(const string& plaintext, const string& publicKeyFile);

    // Decrypts a ciphertext message using the private key
    static string decrypt(const string& ciphertext, const string& privateKeyFile);

    // signs message using senders private key
    static string sign(const string& message, const string& privateKeyFile);
};

#endif // RSA_H