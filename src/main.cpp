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
    for (int i = 0; i < 100000; i++) {
        getline(file, password);
        tree.insert(password);
        map.addPass(password);
    }
    file.close();
    bool continueLoop = true;
    while (continueLoop) {
        // any more menu options
        cout << "Menu" << endl;
        cout << "-----" << endl;
        cout << "1. Find Password Using Prefix Tree." << endl;
        cout << "2. Find Password Using Hash Table." << endl;
        cout << "3. Find out if it is an exact match or just similar." << endl;
        cout << "4. Exit" << endl;
        // cout << "Please input a number to pick a menu option." << endl;
        cout << "Please enter a menu option: ";
        string input;
        getline(cin, input);
        int inputNum = stoi(input);
        if (inputNum == 4) {
            cout << "Exited program successfully." << endl;
            continueLoop = false;
            break;
        }
        if (inputNum != 4) {
            cout << "Please input a password to check." << endl;
            string passInput;
            getline(cin, passInput);
            if (inputNum == 1) {
                bool prefixCheck = tree.searchString(passInput);
                if (prefixCheck) {
                    cout << "Password was found." << endl;

                }
                if (!prefixCheck) {
                    cout << "Password was not found." << endl;
                }
            }
            if (inputNum == 2) {
                //NOTE: add similar functionality for hash
                bool hashCheck = map.checkPass(passInput);
                if (hashCheck == true) {
                    cout << "Password was found." << endl;
                }
                if (hashCheck == false) {
                    cout << "Password was not found." << endl;
                }
            }
            if (inputNum == 3) {
                cout << "Checking Prefix Tree:" << endl;
                bool prefixCheck = tree.searchString(passInput);
                if (prefixCheck) {
                    cout << "Password was found in prefix tree." << endl;

                }
                if (!prefixCheck) {
                    cout << "Password was not found in prefix tree." << endl;
                }
                cout << "Checking Hash Map:" << endl;
                bool hashCheck = map.checkPass(passInput);
                if (hashCheck) {
                    cout << "Password was found in hash map." << endl;
                }
                if (!hashCheck) {
                    cout << "Password was not found in hash map." << endl;
                }
                if (prefixCheck and hashCheck) {
                    cout << "Therefore, password is an exact match found in both structures." << endl;
                }
                if (!prefixCheck and hashCheck) {
                    cout << "Therefore, password is an exact match found in only hash map." << endl;
                }
                if (prefixCheck and !hashCheck) {
                    cout << "Therefore, password must be similar as it was only found in prefix tree." << endl;
                }
                if (!prefixCheck and !hashCheck) {
                    cout << "Therefore, password is not found in either structure." << endl;
                }
            }
        }
    }
}
