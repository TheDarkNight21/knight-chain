//
// Created by Faris Allaf on 12/15/24.
//

#include "Blockchain.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#include <fstream>



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
    ofstream file(filename, ios::binary);
    if (!file.is_open()) throw runtime_error("Could not open file");

    json jBlocks = json::array(); // Array of blocks
    for (const auto& block : _vChain) {
        json blockData;
        blockData["index"] = block._nIndex;
        blockData["nonce"] = block._nNonce;
        blockData["hash"] = block._sHash;
        blockData["prevHash"] = block.sPrevHash;
        blockData["timestamp"] = block._tTime;


        // Serialize messages within the block
        json messagesJson = json::array();
        for (const auto& message : block._messages) {
            messagesJson.push_back({
                {"messageID", message.messageID},
                {"conversationID", message.conversationID},
                {"encryptedContent", message.encryptedContent},
                {"senderID", message.senderID},
                {"recipientID", message.recipientID},
                {"timestamp", message.timestamp},
                {"isGroupMessage", message.isGroupMessage},
                {"groupID", message.groupID},
                {"signature", message.signature}
            });
        }
        blockData["messages"] = messagesJson;
        jBlocks.push_back(blockData);
    }

    file << jBlocks.dump(4); // Pretty print with 4 spaces
    file.close();
    _vChain.clear();
}

void Blockchain::LoadFromDisk(const string &filename) {
    _vChain.clear();
    ifstream file(filename, ios::binary);
    if (!file.is_open()) throw runtime_error("Could not open file");

    json jBlocks;
    file >> jBlocks;
    file.close();

    for (const auto& blockData : jBlocks) {
        uint32_t index = blockData["index"];
        cout << "index: " << index << endl;
        int64_t nonce = blockData["nonce"];
        string hash = blockData["hash"];
        cout << "hash" << hash << endl;
        string prevHash = blockData["prevHash"];
        time_t timestamp = blockData["timestamp"];

        // Deserialize messages for the block
        vector<Message> messages;
        for (const auto& msgData : blockData["messages"]) {
            Message message;
            message.messageID = msgData["messageID"];
            message.conversationID = msgData["conversationID"];
            message.encryptedContent = msgData["encryptedContent"];
            message.senderID = msgData["senderID"];
            message.recipientID = msgData["recipientID"];
            message.timestamp = msgData["timestamp"];
            message.isGroupMessage = msgData["isGroupMessage"];
            message.groupID = msgData["groupID"];
            message.signature = msgData["signature"];
            messages.push_back(message);
        }

        // Reconstruct the block
        auto block = Block(index, messages);
        block._sHash = hash;
        block.sPrevHash = prevHash;  // Manually set private values
        block._nNonce = nonce;      // Requires friend access or public setter
        block._tTime = timestamp;   // Requires friend access or public setter

        // Push the block into the chain
        _vChain.push_back(block);
        cout << block.toString() << endl;
    }
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}

void Blockchain::empty() {
    _vChain.clear();
}
