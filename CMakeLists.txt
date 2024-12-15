cmake_minimum_required(VERSION 3.30)
project(firstBlockchain)

set(CMAKE_CXX_STANDARD 20)

add_executable(firstBlockchain main.cpp
        Block.h
        Blockchain.h
        sha256.h
        sha256.cpp
        Block.cpp
        Blockchain.cpp)
