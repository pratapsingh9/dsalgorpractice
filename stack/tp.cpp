#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* findLcaofBinaryTree(TreeNode* root, int n, int m) {
  if (root == nullptr) return nullptr;

  TreeNode* l = findLcaofBinaryTree(root->left, n, m);
  TreeNode* r = findLcaofBinaryTree(root->right, n, m);

  if (l && r) return root;

  return l != nullptr ? l : r;
}

TreeNode* findLca(TreeNode* root, int n, int m) {
  if (root == nullptr) return nullptr;
  if (root->val == n || root->val == m) return root;
  if (n > root->val && m > root->val) return findLca(root->right, n, m);
  if (n < root->val && m < root->val) return findLca(root->left, n, m);

  return root;
}

void inorderTarget(TreeNode* root, vector<int>& vec) {
  if (root == nullptr) {
    return;
  }

  inorderTarget(root->left, vec);
  vec.push_back(root->val);
  inorderTarget(root->right, vec);
}

bool findTarget(TreeNode* root, int target) {
  vector<int> vec;
  inorderTarget(root, vec);

  int f = 0, l = vec.size() - 1;
  while (f < l) {
    int ans = vec[f] + vec[l];

    if (ans == target) return true;
    if (ans > target)
      l--;
    else {
      f++;
    }
  }

  return false;
}

TreeNode* minValueInorderSuccessor(TreeNode* root) {
  if (!root) return nullptr;
  TreeNode* curr = root;
  while (curr && curr->left) {
    curr = curr->left;
  }
  return root;
}

TreeNode* deleteNode(TreeNode* root, int val) {
  if (root == nullptr) return nullptr;

  if (val > root->val) {
    root->right = deleteNode(root->right, val);
  }
  if (val < root->val) {
    root->left = deleteNode(root->left, val);
  }

  else {
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      return nullptr;
    }
    if (root->right == nullptr && root->left) {
      TreeNode* node = root->left;
      delete root;
      return node;
    }

    if (root->left == nullptr && root->right) {
      TreeNode* node = root->right;
      delete root;
      return node;
    }

    else {
      TreeNode* successor = minValueInorderSuccessor(root->right);
      root->val = successor->val;
      root->right = deleteNode(root->right, successor->val);
    }
  }
}
class Solution {
 public:
  TreeNode* minValueNode(TreeNode* root) {
    TreeNode* curr = root;
    while (curr && curr->left != nullptr) {
      curr = curr->left;
    }
    return curr;
  }

  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    }

    else {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr
      } else if (root->left == nullptr) {
        TreeNode* node = root->right;
        delete root;
        return node;
      } else if (root->right == nullptr) {
        TreeNode* node = root->left;
        delete root;
        return node;
      }
      TreeNode* inorderSuccesors = minValueNode(root->right);
      root->val = inorderSuccesors->val;
      root->right = deleteNode(root->right, inorderSuccesors->val);
    }
    return root;
  }
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

TreeNode* deletebset(TreeNode* root, int key) {}

TreeNode* insertBst(TreeNode* root, int value) {
  if (root == nullptr) return new TreeNode(value);
  if (root->val > value) {
    if (root->left == nullptr) {
      root->left = new TreeNode(value);
    } else {
      insertBst(root->left, value);
    }
  } else {
    if (root->right == nullptr) {
      root->right = new TreeNode(value);
    } else {
      insertBst(root->right, value);
    }
  }
  return root;
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
