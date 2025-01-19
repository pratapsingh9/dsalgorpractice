#include <bits/stdc++.h>
#include <strings.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j) {
  if (i < 0 || j < 0 || i > grid.size() || j > grid[0].size()) {
    return;
  }
  grid[i][j] = '0';
  dfs(grid, i + 1, j);
  dfs(grid, i - 1, j);
  dfs(grid, i, j + 1);
  dfs(grid, i, j - 1);
}

int numberofIslands(vector<vector<int>> &grids) {
  int num_island = 0;
  for (int i = 0; i < grids.size(); i += 1) {
    for (int j = 0; j < grids[0].size(); j += 1) {
      if (grids[i][j] == '1') {
        num_island += 1;
        dfs(grids, i, j);
      }
    }
  }
}

int numberOfIslands(vector<vector<char>> &grid) {
  int num_ofIsland = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == '1') {
        num_ofIsland++;
        dfs(grid, i, j);
      }
    }
  }
  return num_ofIsland;
}

void dfss(vector<vector<char>> &grid, int i, int j, char replacement) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
    return;
  }

  if (grid[i][j] != '0') {
    return;
  }

  grid[i][j] = replacement;

  dfs(grid, i + 1, j, replacement);  // down
  dfs(grid, i - 1, j, replacement);  // up
  dfs(grid, i, j + 1, replacement);  // right
  dfs(grid, i, j - 1, replacement);  // left
}

void replaceowithZero(vector<vector<char>> &grid, char replacement) {
  for (auto ele : grid) {
    for (auto n : grid[ele]) {
      if (grid[ele][n] == '0') {
        dfss(grid, ele, n, replacement)
      }
    }
  }
}

int main() {
  vector<vector<char>> grid = {{'1', '0', '0', '1'},
                               {'0', '0', '1', '0'},
                               {'1', '0', '0', '1'},
                               {'0', '1', '1', '0'}};
  char replacement = "x";

  replaceowithZero(grid, replacement);
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();

      TreeNode *node = p.first;
      int col = p.second.first;
      int row = p.second.second;

      nodes[col][row].insert(node->val);

      if (node->left) {
        q.push({node->left, {col - 1, row + 1}});
      }
      if (node->right) {
        q.push({node->right, {col + 1, row + 1}});
      }
    }

    vector<vector<int>> result;
    for (auto &p : nodes) {
      vector<int> col_nodes;
      for (auto &q : p.second) {
        col_nodes.insert(col_nodes.end(), q.second.begin(), q.second.end());
      }
      result.push_back(col_nodes);
    }

    return result;
  }
};

class Solution {
 public:
  Node *connect(Node *root) {
    if (!root) return nullptr;
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      Node *prev = nullptr;
      for (int i = 1; i < size; i++) {
        Node *curr = q.front();
        q.pop();

        if (prev) {
          prev->next = curr;
        }

        prev = curr;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
      prev->next = nullptr;
    }
    return root;
  }
};

#define max 200
typedef struct {
  int items[max];
  int top;
} Stack;

void init(Stack *s) { s->top = -1; }

void push(Stack *s, int item) {
  if (s->top == max - 1) {
    return;
  }

  s->items[++(s->top)] = item;
}

class Solution {
 public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    vector<int> wcount(26, 0);

    for (const string word : words2) {
      vector<int> charcount(26, 0);
      for (char c : word) {
        charcount[c - 'a']++;
      }

      for (int i = 0; i < 26; i++) {
        wcount[i] = max(wcount[i], charcount[i]);
      }
    }

    vector<string> ans;

    for (const string &word : words1) {
      vector<int> chars(26, 0);

      for (char c : word) {
        chars[c - 'a']++;
      }

      bool flag = true;
      for (size_t i = 0; i < 26; i++) {
        /* code */
        if (chars[i] < wcount[i]) {
          flag = false;
          break;
        }
      }
      if (flag) ans.push_back(word);
    }

    return ans;
  }
};

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); // Combined max frequency for words2
        
        // Merge frequency requirements from words2
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        
        vector<string> result;
        
        // Check each word in words1
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
