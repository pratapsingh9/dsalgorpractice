#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
  if (ransomNote.size() != magazine.size()) return false;
  unordered_map<char, int> mp;
  for (auto ch : ransomNote) {
    mp[ch]++;
  }
  for (auto ch : magazine) {
    if (mp.find(ch) != mp.end()) {
      mp[ch]--;
      if (mp[ch] == 0) {
        mp.erase(ch);
      }
    }
  }
  return mp.empty();
}

unordered_map<int, int> mp;

TreeNode* solve(vector<int> inorder, vector<int> postorder, int instart,
                int inEnd, int index) {
  if (instart > inEnd) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(postorder[index--]);
  int pos = mp[postorder[index]];

  root->left = solve(inorder, postorder)
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  int index = n - 1;
  int n = postorder.size();

  for (int i = 0; i < inorder.size(); i++) {
    mp[inorder[i]] = i;
  }
  return solve(inorder, postorder, 0, postorder.size() - 1, index);
}