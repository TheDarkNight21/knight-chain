//
// Created by Faris Allaf on 12/15/24.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block")); // genesis block is created and placed onto the vchain vector
    /* since the blockchain must start somewhere we have to create a block for the next block as reference, AKA the genesis block
    use emplace_back when pushing object in place and use push_back when pushing an already constructed object.
    */
    _nDifficulty = 6; // set depending how hard we want the process to be.
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().getHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}
