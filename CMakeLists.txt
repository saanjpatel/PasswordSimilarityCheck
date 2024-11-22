cmake_minimum_required(VERSION 3.27)
project(PasswordSimilarityCheck)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PasswordSimilarityCheck
        Hash.cpp
        Hash.h
        main.cpp
        PrefixTree.cpp
        PrefixTree.h)
