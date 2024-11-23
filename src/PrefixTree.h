//
// Created by Saanj Patel on 11/22/2024.
//
#include <iostream>
using namespace std;
#include <vector>
#ifndef PASSWORDSIMILARITYCHECK_PREFIXTREE_H
#define PASSWORDSIMILARITYCHECK_PREFIXTREE_H
struct Node {
    char let;
    vector<Node*> children;
    Node(char let) {
        this->let = let;
        this->children = {nullptr};
    }
    Node() {
        this->let = '\0';
        this->children = {nullptr};
    }
};
class PrefixTree {
private:
    Node* root = new Node();
    Node* insertCharHelper(Node* node, string password, int count);
public:
    void insert(string password);
};
#endif //PASSWORDSIMILARITYCHECK_PREFIXTREE_H
