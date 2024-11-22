cmake_minimum_required(VERSION 3.27)
project(PasswordSimilarityCheck)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PasswordSimilarityCheck
        src/Hash.cpp
        src/Hash.h
        src/main.cpp
        src/PrefixTree.cpp
        src/PrefixTree.h)
