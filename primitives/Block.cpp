//
// Created by Faris Allaf on 12/15/24.
//

#include "Block.h"
#include "../cryptoUtils/sha256.h"
#include "../cryptoUtils/rsa.h"
#include <sstream>
#include <openssl/types.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

Block::Block(uint32_t nIndexIn, const vector<Message> &messagesIn) : _nIndex(nIndexIn), _messages(messagesIn) { // copy contents of parameters into variables _nIndex and _sData
    _nNonce = -1; // set to -1 for now
    _tTime = time(nullptr); // current time
}

string Block::getHash() const {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime;

    for (const auto &message : _messages) {
        ss << message.toString();
    }

    ss << _nNonce << sPrevHash;

    return sha256(ss.str());
}

bool Block::ValidateMessages(const string& publicKeyFile) const {
    for (const auto& message : _messages) {
        if (!RSAUtil::validateMessage(message.encryptedContent, message.signature, publicKeyFile)) {
            return false; // Invalid message signature
        }
    }
    return true;
}

string Block::toString() const {
    string blockContent = "";
    for (const auto &message : _messages) {
        blockContent += message.toString();
    }
    blockContent += to_string(_nIndex);
    return blockContent + "\n";
}


