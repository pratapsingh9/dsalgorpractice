class Solution {
 public:
  unordered_map<TreeNode*, TreeNode*> mp;

  void inOrder(TreeNode* root) {
    if (root == NULL) return;
    if (root->left) {
      mp[root->left] = root;
    }
    inOrder(root->left);
    if (root->right) {
      mp[root->right] = root;
    }
    inOrder(root->right);
  }

  void solve(TreeNode* target, int k, vector<int>& result) {
    queue<TreeNode*> q;
    q.push(target);

    unordered_set<TreeNode*> visited;
    visited.insert(target);


    while (!q.empty()) {
      int n = q.size();
      if (k == 0) {
        while (!q.empty()) {
          result.push_back(q.front()->val);
          q.pop();
        }
        return;
      }

      while (n--) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr->left && !visited.count(curr->left)) {
          q.push(curr->left);
          visited.insert(curr->left);
        }

        if (curr->right && !visited.count(curr->right)) {
          q.push(curr->right);
          visited.insert(curr->right);
        }

        if (mp.count(curr) && !visited.count(mp[curr])) {
          q.push(mp[curr]);
          visited.insert(mp[curr]);
        }
      }

      k--;
    }
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> res;
    inOrder(root);
    solve(target, k, res);
    return res;
  }
};
