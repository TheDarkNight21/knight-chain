#include "Block.h"
#include <vector>

#include "Blockchain.h"
using namespace std;

int main() {
    // Create messages
    Message msg1 = {"AlicePublicKey", "BobPublicKey", "EncryptedHelloBob"};
    Message msg2 = {"BobPublicKey", "AlicePublicKey", "EncryptedHelloAlice"};

    // Create a block with these messages
    vector<Message> messages = {msg1, msg2};
    Block newBlock(1, messages);

    // Mine the block
    newBlock.MineBlock(4);

    // Print the block hash
    cout << "block Hash: " << newBlock.getHash() << endl;

    Blockchain knightChain;
    knightChain.AddBlock(newBlock);
    cout << "block added." << endl;

    return 0;
}