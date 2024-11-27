//
// Created by Saanj Patel on 11/22/2024.
//
#include <iostream>
#include <unordered_map>
using namespace std;
#ifndef PASSWORDSIMILARITYCHECK_HASH_H
#define PASSWORDSIMILARITYCHECK_HASH_H

class HashMap {
private:
    unordered_map<string, int> passMap;
public:
    void addPass(string& password);
    bool checkPass(string& password);

};






#endif //PASSWORDSIMILARITYCHECK_HASH_H
