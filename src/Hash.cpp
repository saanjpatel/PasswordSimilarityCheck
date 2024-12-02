//
// Created by Saanj Patel on 11/22/2024.
//
// C++ reference : https://en.cppreference.com/w/
// reference: Professor Aman's lecture slides on sets, maps, and hash tables
#include "Hash.h"

// used ASCII value and power of 27 to multiple each character in the string
int HashMap::hashFunc(string& password) {
    int base = 27;
    unsigned long long hashVal = 0;
    unsigned long long power = 1;
    // starts from the last character in the string
    for (int i = password.length()-1; i>=0; i--) {
        int ascii = static_cast<int>(password[i]);
        hashVal = (hashVal +  ascii * power);
        power = (power * base);
    }

    return hashVal % capacity;

}

// constructor to initialize the hash map
HashMap::HashMap(int startCapacity, double limit) {
    capacity = startCapacity;
    numElements = 0;
    loadFactor = limit;
    vecNodes.resize(capacity);
    for (int i=0; i<capacity; i++) {
        vecNodes[i].notVacant = false;
    }
}

// adds a password into the hash map and resize if it is greater than or equal to the load factor
void HashMap::addPass(string &password) {

    if ((double)numElements / (double)capacity >= loadFactor) {
        resizeVec();
    }
    int hashCode = hashFunc(password);
    while (vecNodes[hashCode].notVacant == true) {   // spot is full
        hashCode = (hashCode + 1) % capacity;       // used linear probing to resolve collisions
    }
    vecNodes[hashCode].password = password;
    vecNodes[hashCode].notVacant = true;
    numElements++;

}

// checks if the password entered by the user matches with any password from the dataset
bool HashMap::checkPass(string &password) {
    int hashCode = hashFunc(password);
    while (vecNodes[hashCode].notVacant) {
        if (vecNodes[hashCode].password == password) {
            return true;
        }
        // moves to the next open slot
        hashCode = (hashCode + 1) % capacity;
    }
    return false;
}

// resizes the hash map if it becomes clustered
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

