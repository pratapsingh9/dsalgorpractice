#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printPathNodesToAllLevel(TreeNode* root, vector<string>& vec, string ans) {
  if (root == nullptr) {
    return;
  }
  if (ans.empty()) {
    ans += (to_string(root->val));
  } else {
    ans += "->" + to_string(root->val);
  }
  if (!root->left && !root->right) {
    vec.push_back(ans);
    return;
  }
  printPathNodesToAllLevel(root->left, vec, ans);
  printPathNodesToAllLevel(root->right, vec, ans);
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->left->right = new TreeNode(5);
  vector<string> vs;
  printPathNodesToAllLevel(root, vs, "");

  for (const string& path : vs) {
    cout << path << endl;
  }

  return 0;
}
