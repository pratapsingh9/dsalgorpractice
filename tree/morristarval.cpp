#include <iostream>

#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    unordered_map<int , int> mp;

    TreeNode*buildBstHelper(vector<int> preorder  , int prestart , int preEnd , vector<int> inorder , int inStart , int inEnd) {
        if(inStart > inEnd || prestart > preEnd) {
            return nullptr;
        }
        TreeNode*root = new TreeNode(preorder[prestart]);
        int findIndex = mp[preorder[prestart]];
        int leftsubtreeSize = inStart - findIndex;

        root->left = buildBstHelper(preorder ,prestart+1 ,  )
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return buildBstHelper(preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1);    
    }
};
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