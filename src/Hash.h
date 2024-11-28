//
// Created by Saanj Patel on 11/22/2024.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#ifndef PASSWORDSIMILARITYCHECK_HASH_H
#define PASSWORDSIMILARITYCHECK_HASH_H

class HashMap {
private:
    struct Nodes {
        string password;
        bool notVacant;
    };
    vector<Nodes> vecNodes;
    int capacity;
    int numElements;
    double loadFactor;
    // hash function
    int hashFunc(string& password);

public:
    HashMap(int startCapacity, double limit);
    int getSize();
    void resizeVec();
    void addPass(string& password);
    bool checkPass(string& password);

};








#endif //PASSWORDSIMILARITYCHECK_HASH_H
