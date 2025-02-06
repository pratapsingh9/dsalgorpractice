#include <bits/stdc++.h>
using namespace std;

int main() { return 0; }
class Solution {
 public:
  unordered_map<TreeNode *, TreeNode *> mp;

  void inOrder(TreeNode *root) {
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

  void solve(TreeNode *target, int k, vector<int> &result) {
    queue<TreeNode *> q;
    q.push(target);

    unordered_set<TreeNode *> visited;
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
        TreeNode *curr = q.front();
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

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    vector<int> res;
    inOrder(root);
    solve(target, k, res);
    return res;
  }
};

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> rectangles(n);
  int total_row_points = 0, total_col_points = 0;

  for (int i = 0; i < n; i++) {
    cin >> rectangles[i].first >> rectangles[i].second;
    total_row_points += rectangles[i].second;
    total_col_points += rectangles[i].first;
  }

  if (total_row_points < k && total_col_points < k) {
    cout << -1 << "\n";
    return;
  }
  if (total_row_points >= k) {
    int operations = 0;
    for (auto &[width, height] : rectangles) {
      operations += width * height;
      if (operations / height >= k) {
        cout << operations << "\n";
        return;
      }
    }
  }
  if (total_col_points >= k) {
    int operations = 0;
    for (auto &[width, height] : rectangles) {
      operations += width * height;
      if (operations / width >= k) {
        cout << operations << "\n";
        return;
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
 public:
  int findBottomLeftValue(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode *> q;
    q.push(root);
    vector<int> lastlevel;
    while (!q.empty()) {
      int size = q.size();
      lastlevel.clear();
      for (size_t i = 0; i < size; i++) {
        /* code */
        TreeNode *current = q.front();
        q.pop();
        lastlevel.push_back(current->val);
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }
    }
    return lastlevel[0];
  }
};
class Solution {
 public:
  int findBottomLeftValue(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode *> q;
    q.push(root);
    int answerValue = 0;
    while (!q.empty()) {
      int size = q.size();
      answerValue = q.front()->val;
      for (size_t i = 0; i < size; i++) {
        TreeNode *current = q.front();
        q.pop();
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }
    }
    return answerValue;
  }
};

#include <climits>  // For INT_MIN and INT_MAX
#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isEvenOddTree(TreeNode *root) {
    if (!root) return true;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
      int size = q.size();
      int prev = (level % 2 == 0) ? INT_MIN ? INT_MAX;
      for (int i = 0; i < size; i++) {
        TreeNode *current = q.front();
        q.pop();
        if (level @2 == 0) {
          if (current->val % 2 == 0 || current.val <= prev) {
            return false;
          }
        } else {
          if (current->val % 2 != 0 || current->val >= prev) {
            return false;
          }
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }

      level++;
    }

    return true;
  }
};

