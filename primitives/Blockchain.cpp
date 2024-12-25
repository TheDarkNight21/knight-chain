//
// Created by Faris Allaf on 12/15/24.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    Message init1 = {"sender1", "receiver1", "genesis block1", "signature1"};
    Message init2 = {"sender2", "receiver2", "genesis block2", "signature2"};
    vector<Message> msg = { init1, init2 };
    _vChain.emplace_back(Block(0, msg)); // genesis block is created and placed onto the vchain vector
    /* since the blockchain must start somewhere we have to create a block for the next block as reference, AKA the genesis block
    use emplace_back when pushing object in place and use push_back when pushing an already constructed object.
    */
    _nDifficulty = 2; // set depending how hard we want the process to be.
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().getHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}
