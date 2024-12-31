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

bool Blockchain::ValidateChain() const {
        for (size_t i = 1; i < _vChain.size(); ++i) {
            const Block& current = _vChain[i];
            const Block& previous = _vChain[i - 1];

            // Check if the current block's hash is valid
            if (current.getHash() != current._CalculateHash()) {
                return false; // Tampered block
            }

            // Check if the previous hash matches
            if (current.sPrevHash != previous.getHash()) {
                return false; // Broken chain
            }
        }
        return true;
    }

void Blockchain::SaveToDisk(const string &filename) {

}


Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}
