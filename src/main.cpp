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
    for (int i = 0; i < 100000; i++) {
        getline(file, password);
        tree.insert(password);
    }
    file.close();
    cout << "Input password to check: ";
    string input;
    getline(cin, input);
    bool check = tree.searchString(input);
    if (check) {
        cout << "true" << endl;
    }
    if (!check) {
        cout << "false" << endl;
    }
}
