#include "Block.h"
#include <vector>
#include "./cryptoUtils/rsa.h"
#include <filesystem>

#include "primitives/Blockchain.h"
# include "./cryptoUtils/sha256.h"

namespace fs = filesystem;
using namespace std;

int main() {
    // Create messages
    Message msg1 = {"AlicePublicKey", "BobPublicKey", "EncryptedHelloBob", "bobsSignature"};
    Message msg2 = {"BobPublicKey", "AlicePublicKey", "EncryptedHelloAlice", "alicesSignature"};

    // Create a block with these messages
    vector<Message> messages = {msg1, msg2};
    Block newBlock(1, messages);

    Blockchain knightChain;
    knightChain.AddBlock(newBlock);
    cout << "block added." << endl;


    fs::path projectRoot = fs::current_path();
    if (projectRoot.has_parent_path()) {
        projectRoot = projectRoot.parent_path();
    }
    fs::path newDirectory = projectRoot / "keys";

    if (exists(newDirectory)) {
        cout << "directory already exists." << endl;
    } else {
        fs::create_directory(newDirectory);
    }


    const string publicKeyFile = newDirectory /  "public.pem";
    const string privateKeyFile = newDirectory  / "private.pem";
    cout << privateKeyFile << endl;
    const int keySize = 2048;

    try {
        // Generate RSA keys
        RSAUtil::generateKeys(publicKeyFile, privateKeyFile, keySize);
        cout << "Keys generated successfully.\n";

        // Message to encrypt
        string message = "Hello, OpenSSL RSA!";
        cout << "Original Message: " << message << "\n";

        // encrypt message with aes using random generated symmetric key

        // encrypt aes symmetric key with recipients public RSA key


        // send rsa encrypted aes key along with aes encrypted message to recipient


        // recipient decrypts:
        /* aes key using private RSA key of recipient
         * decrypt message using aes key
         */

    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}