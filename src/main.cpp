#include <iostream>
using namespace std;
#include <fstream>
#include "PrefixTree.h"
//
// Created by Saanj Patel on 11/22/2024.
//
int main() {
    // referenced https://cplusplus.com/reference/fstream/ifstream/?kw=ifstream
    ifstream file("rockyou.txt");
    string password;
    PrefixTree tree;
    for (int i = 0; i < 5; i++) {
        getline(file, password);
        tree.insert(password);
    }
}
