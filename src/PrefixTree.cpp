//
// Created by Saanj Patel on 11/22/2024.
//
// referenced https://www.interviewcake.com/concept/java/trie to understand prefix tree
// referenced Prof. Kapoor's tree and balanced tree lecture slides
#include "PrefixTree.h"
// referenced https://cplusplus.com/reference/string/string/?kw=string for string functions
Node* PrefixTree::insertCharHelper(Node *node, string password, int count) {
    if (count < password.length()) {
        // if null make new node
        if (node == nullptr) {
            node = new Node(password.at(count));
        }
        // bool var to check if character was already inserted in following conditions
        bool insert = false;
        // if first child is nullptr add there
        if (node->children.at(0) == nullptr) {
            node->children.at(0) = new Node(password.at(count));
            node->children.at(0) = insertCharHelper(node->children.at(0), password, count+1);
            insert = true;
        }
        if (!insert) {
            // if already exists, go to the next one
            for (int i = 0; i < node->children.size(); i++) {
                if (node->children.at(i)->let == password.at(count)) {
                    node->children.at(i) = insertCharHelper(node->children.at(i), password, count+1);
                    insert = true;
                }
            }
        }
        // last condition insert next into vector
        if (!insert) {
            node->children.push_back(new Node(password.at(count)));
            node->children.at(node->children.size()-1) = insertCharHelper(node->children.at(node->children.size()-1), password, count+1);
        }
    }
    return node;
}
void PrefixTree::insert(string password) {
    this->root = insertCharHelper(this->root, password,0);
}
bool PrefixTree::searchStringHelper(Node *node, string password, int count) {
    while (count < password.length()) {
        bool checkchar = false;
        for (int i = 0; i < node->children.size(); i++) {
            // if found continue
            if (node->children.at(i)->let == password.at(count)) {
                checkchar = true;
                node = node->children.at(i);
                count += 1;
                break;
            }
        }
        // otherwise not found return false
        if (!checkchar) {
            return false;
        }

    }
    // if all characters found return true
    return true;

}
bool PrefixTree::searchString(string password) {
    bool stringInTree = searchStringHelper(this->root, password, 0);
    return stringInTree;
}
void PrefixTree::deletepostOrderTraversal(Node *node) {
    // make sure to not delete null pointer if condition
    if (node != nullptr) {
        for (int i = 0; i < node->children.size(); i++) {
            if (node->children.at(i) != nullptr) {
                deletepostOrderTraversal(node->children.at(i));
            }
        }
    }
    delete node;
}

int PrefixTree::countVariationsHelper(Node *node, string password, int count) {
    int numVar = 0;
    while (count < password.length()) {
        bool checkchar = false;
        for (int i = 0; i < node->children.size(); i++) {
            // if found continue
            if (node->children.at(i)->let == password.at(count)) {
                checkchar = true;
                node = node->children.at(i);
                count += 1;
                break;
            }
        }
        // otherwise not found return -1
        if (!checkchar) {
            return -1;
        }

    }
    // if all characters found return variations
    if (count == password.length()) {
        numVar = countFromLastCharHelper(node, 0);
    }
    return numVar;

}
int PrefixTree::countFromLastCharHelper(Node *node, int numVar) {
    // count number of children
    for (int i = 0; i < node->children.size(); i++) {
        if (node->children.at(i) != nullptr) {
            numVar += 1;
        }
        // if first child is nullptr means no variations
        if (node->children.at(i) == nullptr) {
            return 0;
        }
    }
    return numVar;
}
int PrefixTree::countVariations(string password) {
    int variations = countVariationsHelper(this->root, password, 0);
    return variations;
}
PrefixTree::~PrefixTree() {
    deletepostOrderTraversal(this->root);
}