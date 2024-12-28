#include "Block.h"
#include <vector>
#include "./cryptoUtils/rsa.h"
#include <filesystem>

#include "primitives/Blockchain.h"
# include "./cryptoUtils/sha256.h"
#include "cryptoUtils/aes.h"
#include "cryptoUtils/aes.h"

namespace fs = filesystem;
using namespace std;



int main() {
    // Create messages
    Message msg1 = {"AlicePublicKey", "BobPublicKey", "EncryptedHelloBob", "bobsHash", "message1ID", "cloud", "bobsSignature"};
    Message msg2 = {"BobPublicKey", "AlicePublicKey", "EncryptedHelloAlice", "alicesHash", "message2ID", "cloud", "alicesSignature"};

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
        string message = "Hello, OpenSSL N";
        cout << "Original Message: " << message << "\n";

        // encrypt message with aes cipher block chaining (cbc) using random generated symmetric key
        // Key (32 bytes for AES-256)

        vector<unsigned char> key = {
            't', 'h', 'i', 's', 'i', 's', '3', '2', 'b', 'y', 't', 'e', 's', 'k', 'e', 'y',
            'f', 'o', 'r', 'a', 'e', 's', '-', '2', '5', '6', '!', '@', '#', '$', '%', '^'
        };

        // IV (16 bytes for AES CBC)
        vector<unsigned char> iv = {
            '1', '2', '3', '4', 'i', 'n', 'i', 't', 'v', 'e', 'c', 't', 'o', 'r', '!', '!'
        };

        /* iv is an initialization vector, it is used to ensure that the same key and text will not produce the same ciphertext
         * ensures randomness and improves security of application and message.
         * kind of similar to how you initialize randomness to ai models; same level of randomness produces the same results;
         * same initialization vector, message, and key produces same ciphertext.
         */

        // Create AES object with AES-256
        AES aes(AESKeyLength::AES_256);

        // Pad the message
        vector<unsigned char> paddedMessage = AES::PadMessage(message);

        // Encrypt the message; this results in the aes symmetric key
        vector<unsigned char> ciphertext = aes.EncryptCBC(paddedMessage, key, iv);

        // encrypt aes symmetric key with recipients public RSA key
        cout << "public key file: " << publicKeyFile << "\n";
        string ciphertext_to_string = AES::CiphertextToHex(ciphertext);
        string encryptedSymmetricKey = RSAUtil::encrypt(ciphertext_to_string, publicKeyFile);
        cout << encryptedSymmetricKey << endl;

        // send rsa encrypted aes key along with aes encrypted message to recipient


        // recipient decrypts:
        /* aes key using private RSA key of recipient
         * decrypt message using aes key
         */

        // Create a block with these messages
        vector<Message> messages = {msg1, msg2};
        Block newBlock(1, messages);

        Blockchain knightChain;
        knightChain.AddBlock(newBlock);
        cout << "block added." << endl;


    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}