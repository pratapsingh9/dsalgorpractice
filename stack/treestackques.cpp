#include <bits/stdc++.h>

#include <stack>
using namespace std;

// Define a binary tree node
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr) return nullptr;

  if (root == p || root == = q) return root;

  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);

  if (left && right) return root;

  return (left != nullptr) ? left : right;
}

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
  printPathNodesToAllLevel(root->left) && printPathNodesToAllLevel(root->right);
}

bool checkSameTree(TreeNode* root, TreeNode* node) {
  if (root == nullptr && node == nullptr) return true;
  if (!root || !node) return false;
  if (root->val != node->val) return false;

  return checkSameTree(root->left, node->left) &&
         checkSameTree(root->right, node->right);
}

bool checkBalancedBst(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  int ltor = maxDepty(root->left);
  int rtol = maxDepty(root->right);

  if (abs(ltor - rtol) > 1) {
    return false;
  }

  return checkBalancedBst(root->right) && checkBalancedBst(root->left);
}

int maxDepty(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + max(maxDepty(root->left), maxDepty(root->right));
}

void postOrder(TreeNode* root) {
  if (root == NULL) return;
  stack<TreeNode*> st;
  st.push(root);
  while (!st.empty() || root != nullptr) {
    TreeNode* curr = st.top();
    st.pop();

    if (curr->left) }
}
void postOrder(TreeNode* root) {
  if (root == nullptr) return;
  stack<TreeNode*> st;
  TreeNode* curr = root;
  st.push(root);
  while (curr != nullptr || !st.empty()) {
    TreeNode* value = st.top();
    st.pop();
    cout << value->val << " ";
    if (value->left) {
      st.push(value->left);
    }
    if (value->right) {
      st.push(value->right);
    }
  }
}

void inorderTraversaliterative(TreeNode* root) {
  if (root == nullptr) return;
  stack<TreeNode*> st;
  TreeNode* curr = root;

  while (curr != nullptr || !st.empty()) {
    while (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    }
    TreeNode* value = st.top();
    st.pop();
    cout << value->val << endl;
    curr = curr->right;
  }
}

void preorder(TreeNode* root) {
  if (root == nullptr) return;
  stack<TreeNode*> st;
  TreeNode* curr = root;
  st.push(root);
  while (curr != nullptr || !st.empty()) {
    TreeNode* curr = st.top();
    st.pop();
    cout << curr->val << " ";
    if (curr->right) {
      st.push(curr->right);
    }
    if (curr->left) {
      st.push(curr->left);
    }
  }
}

void rightView(TreeNode* root) {
  if (root == nullptr) return;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();

    for (int i = 1; i <= n; i++) {
      /* code */
      TreeNode* curr = q.front();
      q.pop();
      if (i == n) cout << curr->val << endl;
      if (curr->left) q.push(curr->left);
      if (curr->right) q.push(curr->right);
    }
  }
}

void leftView(TreeNode* root) {
  if (root == nullptr) return;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      TreeNode* curr = q.front();
      q.pop();

      if (i == 0) {
        cout << curr->val << endl;
      }
      if (curr->right) q.push(curr->right);
      if (curr->left) q.push(curr->left);
    }
  }
}

void inorderTraversal(TreeNode* root) {
  stack<TreeNode*> s;
  TreeNode* curr = root;
  while (curr != nullptr || !s.empty()) {
    while (curr != nullptr) {
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();
    cout << curr->val << endl;
    curr = curr->right;
  }
}

int maxAns = 0;

int findMaxDiameter(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  int l = findMaxDiameter(root->left);
  int r = findMaxDiameter(root->right);

  maxAns = max(maxAns, l + r);

  return 1 + max(l, r);
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  // Inorder traversal of the tree
  printPathNodesToAllLevel(root);

  return 0;
}
