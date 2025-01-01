//
// Created by Faris Allaf on 12/15/24.
//

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain(); // constructor to initialize new blockchain

    void AddBlock(Block bNew); // adds a new block to the blockchain by linking it to the last block in the chain

    void SaveToDisk(const string& filename);

    void LoadFromDisk(const string& filename);

private:
    uint32_t _nDifficulty; // determines how hard it is to mine a new block
    vector<Block> _vChain; // a vector (list) that stores all the blocks in the chain
    bool ValidateChain() const;

    Block _GetLastBlock() const; // helper method to access the last block in the chain

    void empty();

};
#endif //BLOCKCHAIN_H
