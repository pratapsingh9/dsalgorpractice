#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

stack

TreeNode* inorder(TreeNode*root , int x) {
    TreeNode* curr = root;
}


int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Morris Inorder Traversal: ";
    morrisInorderTraversal(root);  // Perform Morris Inorder Traversal
    cout << std::endl;

    // delet memeory and free up the space
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}