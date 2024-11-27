//
// Created by Saanj Patel on 11/22/2024.
//
// referenced https://www.interviewcake.com/concept/java/trie to understand prefix tree
#include "PrefixTree.h"
// referenced https://cplusplus.com/reference/string/string/?kw=string for string functions
Node* PrefixTree::insertCharHelper(Node *node, string password, int count) {
    if (count < password.length()) {
        if (node == nullptr) {
            node = new Node(password.at(count));
        }
        bool insert = false;
        if (node->children.at(0) == nullptr) {
            node->children.at(0) = new Node(password.at(count));
            node->children.at(0) = insertCharHelper(node->children.at(0), password, count+1);
            insert = true;
        }
        if (!insert) {
            for (int i = 0; i < node->children.size(); i++) {
                if (node->children.at(i)->let == password.at(count)) {
                    node->children.at(i) = insertCharHelper(node->children.at(i), password, count+1);
                    insert = true;
                }
            }
        }

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
            if (node->children.at(i)->let == password.at(count)) {
                checkchar = true;
                node = node->children.at(i);
                count += 1;
                break;
            }
        }
        if (!checkchar) {
            return false;
        }

    }
    return true;

}
bool PrefixTree::searchString(string password) {
    bool stringInTree = searchStringHelper(this->root, password, 0);
    return stringInTree;
}
void PrefixTree::deletepostOrderTraversal(Node *node) {
    for (int i = 0; i < node->children.size(); i++) {
        deletepostOrderTraversal(node->children.at(i));
    }
    delete node;
}
PrefixTree::~PrefixTree() {
    deletepostOrderTraversal(this->root);
}