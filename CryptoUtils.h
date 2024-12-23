//
// Created by Faris Allaf on 12/23/24.
//

#ifndef CRYPTOUTILS_H
#define CRYPTOUTILS_H
#include <string>

#include "Block.h"
using namespace std;

class CryptoUtils {
public:
    pair<string, string> GenerateKeyPair(); // creates RSA key pair for user
    string encryptMessage(Message msg, string publicKey); // encrypts message based on public key
    string decryptMessage(Message msg, string privateKey); // decrypts message based on public key
    string signMessage(Message msg, string privateKey); // signs message with users private key
    string verfiySignature(Message msg, string signature, string publicKey); // verifies signature


private:

};

#endif //CRYPTOUTILS_H
