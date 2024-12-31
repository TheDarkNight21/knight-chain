cmake_minimum_required(VERSION 3.30)
project(firstBlockchain)

set(CMAKE_CXX_STANDARD 20)

# Specify the OpenSSL root directory
set(OPENSSL_ROOT_DIR /opt/homebrew/Cellar/openssl@3/3.4.0)
set(OPENSSL_INCLUDE_DIR /opt/homebrew/Cellar/openssl@3/3.4.0/include)
set(OPENSSL_LIBRARIES /opt/homebrew/Cellar/openssl@3/3.4.0/lib)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Add the executable target and include all source files
add_executable(firstBlockchain
        main.cpp
        primitives/Block.h
        primitives/Blockchain.h
        cryptoUtils/sha256.h
        cryptoUtils/sha256.cpp
        primitives/Block.cpp
        primitives/Blockchain.cpp
        User.h
        cryptoUtils/rsa.h
        cryptoUtils/rsa.cpp
        cryptoUtils/aes.h
        cryptoUtils/aes.cpp
        user.cpp
)

# Link OpenSSL libraries to the target
target_include_directories(firstBlockchain PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(firstBlockchain OpenSSL::SSL OpenSSL::Crypto)