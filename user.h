#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "FirebaseHandler.h" // Include your Firebase utility header

using namespace std;

class user {
public:
    // Fields
    string userID;               // Public key or unique user identifier
    string publicKey;            // User's public key
    string privateKey;           // User's private key
    bool useCloud;               // Preference: true for cloud, false for local-only
    string displayName;          // User's display name
    string profilePicture;       // URL to profile picture
    vector<string> conversationIDs; // List of conversations the user is part of
    string lastActive;           // Last active timestamp in UTC

    // Constructor
    user(string id, string pubKey, string privKey, bool cloudPreference,
         string name = "", string picture = "");

    // Backend Interaction Methods
    void createOrFetchUser();    // Create or fetch user data from Firestore
    void updateUserData();       // Update user data in Firestore
    void addConversation(const string& conversationID); // Add a conversation
    void removeConversation(const string& conversationID); // Remove a conversation

    // Utility Methods
    void updateLastActive();     // Update the last active timestamp
    string toString() const;     // Convert user data to a string for debugging or logging

private:
    FirebaseHandler firebase;    // Firebase interaction utility
};

#endif // USER_H