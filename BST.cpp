#include "BST.h"
#include <iostream>

using namespace std;

BSTNode* insertBST(BSTNode* p, int k) {
    if (!p) return new BSTNode(k);

    if (k < p->key) {
        p->left = insertBST(p->left, k);
    } else if (k > p->key) {
        p->right = insertBST(p->right, k);
    }
    return p;
}

bool searchBST(BSTNode* p, int k) {
    if (!p) return false;
    if (p->key == k) return true;
    if (k < p->key) return searchBST(p->left, k);
    return searchBST(p->right, k);
}

void printBSTInOrder(BSTNode* root) {
    if (root == nullptr) return;
    printBSTInOrder(root->left);
    cout << root->key << " ";
    printBSTInOrder(root->right);
}

void freeBST(BSTNode* root) {
    if (!root) return;
    freeBST(root->left);
    freeBST(root->right);
    delete root;
}