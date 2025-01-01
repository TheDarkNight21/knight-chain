//
// Created by Faris Allaf on 12/15/24.
//

#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct Message {
    string messageID;
    string conversationID;
    string encryptedContent;
    string senderID;
    string recipientID;
    string timestamp;
    bool isGroupMessage;
    string groupID;
    string signature;

    // Convert a message to a string for hashing
    string toString() const {
        // Concatenate all fields, including the boolean as a string
        return messageID +
               conversationID +
               encryptedContent +
                signature +
               senderID +
               recipientID +
               timestamp +
               (isGroupMessage ? "true" : "false") +
               groupID;
    }
};

class Block {
public:

    // Block(const Block&) = default; // Default copy constructor
    // Block(Block&&) = default;      // Default move constructor
    // Block& operator=(const Block&) = default; // Default copy assignment
    // Block& operator=(Block&&) = default;      // Default move assignment

    uint32_t _nIndex; // position of block on chain
    int64_t _nNonce; // number used to solve the mining puzzle (part of hashing)
    string _sHash; // hash of this block (unique identifier based on its content)
    time_t _tTime; //timestamp for when block was created
    vector<Message> _messages;  // Messages stored in this block


    string sPrevHash; // hash of previous box - stored for linking

    Block(uint32_t nIndexIn, const vector<Message> &messagesIn); // constructor to init a new block with an index and some data

    string getHash() const; // returns hash of this block

    void MineBlock(uint32_t nDifficulty); // simulates the mining process by solving cryptographic puzzle.

    string _CalculateHash() const; // private method to compute a blocks hash based on its data and other properties

    bool ValidateMessages(const string& publicKeyFile) const;

    string toString() const;


private:
};


#endif //BLOCK_H