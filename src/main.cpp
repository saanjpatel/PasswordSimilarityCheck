#include <iostream>
using namespace std;
#include <fstream>
#include "PrefixTree.h"
#include "Hash.h"
#include <chrono>
//
// Created by Saanj Patel on 11/22/2024.
//
int main() {
    // referenced https://cplusplus.com/reference/fstream/ifstream/?kw=ifstream
    ifstream file("rockyou.txt");
    string password;
    // create instances of prefix tree and hashmap
    PrefixTree tree;
    HashMap map(20, 0.75);
    //start insertion timer for prefix tree
    auto startP = chrono::high_resolution_clock::now();
    // insert both for first 100,000
    for (int i = 0; i < 100000; i++) {
        getline(file, password);
        tree.insert(password);
    }
    //end insertion timer for prefix tree
    auto endP = chrono::high_resolution_clock::now();
    auto PrefixTime = chrono::duration_cast<chrono::nanoseconds>(endP - startP).count();

    //clear flags and go back to the beginning of the file for reading
    file.clear();
    file.seekg(0, ios::beg);

    //start insertion timer for hash table
    auto startH = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++) {
        getline(file, password);
        map.addPass(password);
    }
    //end insertion timer for hash table
    auto endH = chrono::high_resolution_clock::now();
    auto HashTime = chrono::duration_cast<chrono::nanoseconds>(endH - startH).count();
    file.close();
    bool continueLoop = true;
    // menu options loop
    while (continueLoop) {
        // any more menu options
        cout << "Menu" << endl;
        cout << "-----" << endl;
        cout << "1. Find Password Using Prefix Tree." << endl;
        cout << "2. Find Password Using Hash Table." << endl;
        cout << "3. Find out if it is an exact match or just similar." << endl;
        cout << "4. Find Minimum Number of Variations Starting with Given Password using Prefix Tree." << endl;
        cout << "5. Find the Amount of Time for Inserting data into the Prefix Tree and Hash Table" << endl;
        cout << "6. Exit" << endl;
        cout << "Please enter a menu option:" << endl;
        // getting menu option chosen
        string input;
        getline(cin, input);
        int inputNum = stoi(input);
        // if exit
        if (inputNum == 6) {
            cout << "Exited program successfully." << endl;
            continueLoop = false;
            break;
        }
        //if finding insertion time
        if (inputNum == 5){
            cout << "Time taken to insert into prefix tree: " << PrefixTime <<"ns"<< endl;
            cout << "Time taken to insert into hash table: " << HashTime <<"ns"<< endl;
        }
        // if checking password
        if (inputNum != 6 && inputNum != 5) {
            cout << "Please input a password to check." << endl;
            string passInput;
            getline(cin, passInput);
            // use prefix tree
            if (inputNum == 1) {
                bool prefixCheck = tree.searchString(passInput);
                if (prefixCheck) {
                    cout << "Password was found." << endl;
                }
                if (!prefixCheck) {
                    cout << "Password was not found." << endl;
                }
            }
            // use hashmap
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
            // checking both
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
            // check for variations
            if (inputNum == 4) {
                bool prefixCheck = tree.searchString(passInput);
                if (prefixCheck) {
                    cout << tree.countVariations(passInput) << " variations" << endl;

                }
                if (!prefixCheck) {
                    cout << "No variations." << endl;
                }
            }

        }
    }
}
