//
// Created by Faris Allaf on 12/15/24.
//

#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <iostream>
using namespace std;

struct Message {
    string sender;    // Public key of the sender
    string receiver;  // Public key of the receiver
    string content;   // Encrypted message content

    // Convert a message to a string for hashing
    string toString() const {
        return sender + receiver + content;
    }
};

class Block {
public:
    string sPrevHash; // hash of previous box - stored for linking

    Block(uint32_t nIndexIn, const vector<Message> &messagesIn); // constructor to init a new block with an index and some data

    string getHash(); // returns hash of this block

    void MineBlock(uint32_t nDifficulty); // simulates the mining process by solving cryptographic puzzle.

private:
    uint32_t _nIndex; // position of block on chain
    int64_t _nNonce; // number used to solve the mining puzzle (part of hashing)
    string _sHash; // hash of this block (unique identifier based on its content)
    time_t _tTime; //timestamp for when block was created
    vector<Message> _messages;  // Messages stored in this block

    string _CalculateHash() const; // private method to compute a blocks hash based on its data and other properties
};


#endif //BLOCK_H