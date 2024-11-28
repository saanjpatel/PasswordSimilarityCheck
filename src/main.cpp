#include <iostream>
using namespace std;
#include <fstream>
#include "PrefixTree.h"
#include "Hash.h"
//
// Created by Saanj Patel on 11/22/2024.
//
int main() {
    // referenced https://cplusplus.com/reference/fstream/ifstream/?kw=ifstream
    ifstream file("rockyou.txt");
    string password;
    PrefixTree tree;
    HashMap map(20, 0.75);
    for (int i = 0; i < 1000; i++) {
        getline(file, password);
        tree.insert(password);
        map.addPass(password);
    }
    file.close();
    bool continueLoop = true;
    while (continueLoop) {
        cout << "Menu" << endl;
        cout << "------" << endl;
        cout << "1. Check Password Using Prefix Tree." << endl;
        cout << "2. Check Password Using Hash Table." << endl;
        cout << "3. Exit" << endl;
        // cout << "Please input a number to pick a menu option." << endl;
        cout << "Please enter a menu option: " << endl;
        string input;
        getline(cin, input);
        int inputNum = stoi(input);
        if (inputNum == 3) {
            cout << "Exited program successfully." << endl;
            continueLoop = false;
            break;
        }
        if (inputNum == 1 or inputNum == 2) {
            cout << "Please input a password to check." << endl;
            string passInput;
            getline(cin, passInput);
            if (inputNum == 1) {
                bool prefixCheck = tree.searchString(passInput);
                if (prefixCheck) {
                    cout << "Password is commonly used." << endl;
                }
                if (!prefixCheck) {
                    cout << "Password is not commonly used." << endl;
                }
            }
            if (inputNum == 2) {
                //NOTE: add similar functionality for hash
                bool hashCheck = map.checkPass(passInput);
                if (hashCheck == true) {
                    cout << "Password is commonly used." << endl;
                }
                if (hashCheck == false) {
                    cout << "Password is not commonly used." << endl;
                }
            }
        }
    }
}
