//
// Created by Saanj Patel on 11/22/2024.
//
// C++ reference : https://en.cppreference.com/w/
// reference: Professor Aman's lecture slides on sets, maps, and hash tables
#include "Hash.h"

int HashMap::hashFunc(string& password) {
        int base = 129;
        int hashVal = 0;
        int power = 1;
        for (int i = password.length()-1; i>=0; i--) {
            int ascii = (int)password[i];
            hashVal = (hashVal +  ascii * power) % capacity;
            power = (power * base) % capacity;
        }

        return hashVal;

}

HashMap::HashMap(int startCapacity, double limit) {
    capacity = startCapacity;
    numElements = 0;
    loadFactor = limit;
    vecNodes.resize(capacity);
    for (int i=0; i<capacity; i++) {
        vecNodes[i].notVacant = false;
    }
}

void HashMap::addPass(string &password) {
    if ((double)numElements / (double)capacity >= loadFactor) {
        resizeVec();
    }
    int hashCode = hashFunc(password);
    while (vecNodes[hashCode].notVacant == true) {   // spot is full
        hashCode = (hashCode + 1) % capacity;       // used linear probing to resolve collisions
        // break;
    }
    vecNodes[hashCode].password = password;
    vecNodes[hashCode].notVacant = true;
    numElements++;
}

bool HashMap::checkPass(string &password) {
    int hashCode = hashFunc(password);
    while (vecNodes[hashCode].notVacant) {
        if (vecNodes[hashCode].password == password) {
            return true;
        }
        hashCode = (hashCode + 1) % capacity;
    }
    return false;
}

void HashMap::resizeVec() {
    capacity *= 2; // double the capacity
    vector<Nodes> newVec(capacity);
    for (int i=0; i<vecNodes.size(); i++) {
        if (vecNodes[i].notVacant) {
            int hashCode = hashFunc(vecNodes[i].password);
            while (newVec[hashCode].notVacant == true) {
                hashCode = (hashCode + 1) % capacity;
            }
            newVec[hashCode] = vecNodes[i];
        }
    }
    vecNodes = newVec;
}

