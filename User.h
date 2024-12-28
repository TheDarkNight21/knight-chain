//
// Created by Faris Allaf on 12/23/24.
//

#ifndef USER_H
#define USER_H

class User {
public:
    string userID;       // Public key or unique user identifier
    string publicKey;    // User's public key
    string privateKey;   // User's private key
    bool useCloud;       // Preference: true for cloud, false for local-only

    User(string id, string pubKey, string privKey, bool cloudPreference);
};
#endif //USER_H
