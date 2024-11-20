#include <bits/stdc++.h>
using namespace std;

int countError(vector<int> &processOrder, vector<int> &executionOrder) {
  stack<int> s;
  for (int i = processOrder.size() - 1; i >= 0; i--) {
    s.push(processOrder[i]);
  }
  int ans = 0;
  for (auto val : executionOrder) {
    if (!s.empty() && s.top() == val) {
      s.pop();
    } else {
      ans++;
    }
  }
  return ans;
}

vector<int> nextgreateTOleft(vector<int> &nums) {
  int n = nums.size();
  vector<int> ans(n);
  stack<int> s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && s.top() <= nums[i]) {
      s.pop();
    }
    if (s.empty()) {
      ans.push_back(-1);
    } else {
      ans.push_back(s.top());
    }
    s.push(i);
  }
}

vector<int> calculateSpan(vector<int> prize) {
  int n = prize.size();
  vector<int> ans(n, -1);
  stack<int> s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && prize[s.top()] <= prize[i]) {
      s.pop();
    }
    if (!s.empty()) {
      ans[i] = i - s.top();
    } else {
      ans[i] = i + 1;
    }
    s.push(i);
  }
}

class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> hash(26, 0);
    for (char c : s) {
      hash[c - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (hash[s[i] - 'a'] == 1) return i;
    }
    return -1;
  }
};

int solve(vector<int> nums, int k) {
  unordered_map<int, int> prefixMap;
  int ans = 0, left = 0;
  int currSum = 0;
  prefixMap[0] = 1;
  for (int num : nums) {
    currSum += num;
    if (prefixMap.find(currSum - k) != prefixMap.end()) {
      ans += prefixMap[currSum - k];
    }
    prefixMap[currSum]++;
  }
  return ans;
}

class TrieNode {
  TrieNode *children[26];
  int count;

  TrieNode() {
    count = 0;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }

}

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";
    TrieNode *root = new TrieNode();

    for (const string &str : strs) {
      TrieNode *currNode = str;

      for (char c : str) {
        int indx = c - 'a';
        if (currNode->children[indx] == nullptr) {
          currNode->children[indx] = new TrieNode();
        }
      }
    }
  }
};

class Solution {
 public:
  void dfs(int r, int c, vector<vector<int>> &grid) {}
  int numEnclaves(vector<vector<int>> &grid) {
    int row = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < row; i++) {
      grid[0][i] = dfs(i, 0, grid);
      if (grid[i][cols - 1] == 1) dfs(i, cols - 1, grid);
    }
    for (int j = 0; j < cols; j++) {
      if (grid[j][0] == 1) dfs(0, j, grid);
      if (grid[row - 1][j] == 1) dfs(row - 1, j, grid);
    }
    int enclaveCount = 0;
    for (int i = 0; i <) }
};

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(0);
    visited[0] = true;
    while (!st.empty()) {
      int node = st.top();
      st.pop();
      // visited[node]=true;
      for (auto edge : rooms[node]) {
        if (!visited[edge]) {
          visited[edge] = true;
          st.push(edge);
        }
      }
    }
    for (bool it : visited) {
      if (!it) return false;
    }
    return true;
  }
};
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int dfs(int i, int j, vector<vector<int>> &grid) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] == 0) {
      return 0;
    }

    grid[i][j] = 0;
    int area = 1;
    area += dfs(i + 1, j, grid) + dfs(i - 1, j, grid) + dfs(i, j + 1, grid) +
            dfs(i, j - 1, grid);
    return area;
  }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
      /* code */
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          ans = max(ans, dfs(i, j, grid));
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int dfs(int i, int j, vector<vector<int>> &grid) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] == 0) {
      return 0;
    }

    grid[i][j] = 0;
    int area = 1;
    area += dfs(i + 1, j, grid);
    area += dfs(i - 1, j, grid);
    area += dfs(i, j + 1, grid);
    area += dfs(i, j - 1, grid);

    return area;
  }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxy = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          maxy = max(dfs(i, j, grid), maxy);
        }
      }
    }
    return maxy;
  }
};

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int row = mat.size();
    int cols = mat[0].size();

    vector<vector<int>> ans(row, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < cols; j++) {
        if (mat[i][j] == 0) {
          q.push({i, j});
          ans[i][j] = 0;
        }
      }
    }
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;

      for (auto &dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;

        if (newX > 0 || newY > 0 || newX < row || newY < cols) {
          if (ans[x][y] + 1 < ans[newX][newY]) {
            ans[newX][newY] = ans[x][y] + 1;
            q.push({newX, newY});
          }
        }
      }
    }
    return ans;
  }
};

#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0][0] == 1 ||
        grid[grid.size() - 1][grid[0].size()] == 1) {
      return -1;
    }
    int m = grid.size();
    int n = grid[0].size();
    vector<pair<int, int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                        {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    vector<vector<int>> distance(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    distance[0][0] = 1;
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;

      q.pop();

      if (x == m - 1 && y == n - 1) return distance[x][y];
      for (auto dir : direction) {
        int newX = dir.first + x;
        int newY = dir.second + y;

        if (newX > 0 && newY > 0 && newX < m && newY < n &&
            grid[newX][newY] == -1) {
          distance[newX][newY] = distance[x][y] + 1;
          q.push({newX, newY});
        }
      }
    }
    return -1;
  }
};

class Solution {
 public:
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> colors(n, -1);  // -1 means uncolored
    queue<int> q;

    for (int i = 0; i < n; i++) {
      if (colors[i] == -1) {  // If the node is uncolored, start BFS
        q.push(i);
        colors[i] = 0;  // Color the node with color 0

        while (!q.empty()) {
          int node = q.front();
          q.pop();

          for (int neighbor : graph[node]) {  // Check neighbors
            if (colors[neighbor] == -1) {     // If the neighbor is uncolored
              colors[neighbor] =
                  1 - colors[node];  // Color it with opposite color
              q.push(neighbor);
            } else if (colors[neighbor] ==
                       colors[node]) {  // Conflict in coloring
              return false;             // Not bipartite
            }
          }
        }
      }
    }

    return true;  // Return true if no conflicts were found
  }
};

class Solution {
 public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    vector<vector<int>> adj(n);
    adj[it[0] - 1].push_back(it[1] - 1);
    adj[it[1] - 1].push_back(it[0] - 1);

    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
      if (color[i] == -1) {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
          int node = q.front();
          q.pop();

          for (auto neighbour : adj[node]) {
            if (color[neighbour] == -1) {
              color[neighbour] = 1 - color[node];
              q.push(neighbour);
            } else if (color[neighbour] == color[node]) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};
class Solution {
 public:
  bool dfs(int node, int color, vector<vector<int>> &adj,
           vector<int> &visited) {
    visited[node] = color;
    for (auto neighbour : adj[node]) {
      if (color[neighbour] == -1) {
        color[neighbour] = 1 - color[node];
        if (!dfs(neighbour, 1 - color, adj, visited)) {
          return false;
        }
      } else if (color[neighbour] == color[node]) {
        return false;
      }
    }
    return true;
  }
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    vector<vector<int>> adj(n);
    for (auto it : dislikes) {
      adj[it[0] - 1].push_back(it[1] - 1);
      adj[it[1] - 1].push_back(it[0] - 1);
    }
    vector<int> visited(n, -1);
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        if (!dfs(i, 0, adj, visited)) {
          return false;
        }
      }
    }
    return true;
  }
};

class Solution {
 public:
  int helper(int i, vector<int> &nums, int &n, vector<int> &dp) {
    int l = 1;
    if (dp[i] != -1) return dp[i];
    for (int j = i + 1; j < n; j++) {
      if (nums[j] > nums[i]) {
        l = max(l, 1 + helper(j, nums, n, dp));
      }
    }
    dp[i] = l;
    return dp[i];
  }
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    int maxy = 0;
    if (n == 0) return 0;
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < n; i++) {
      maxy = max(maxy, helper(i, nums, n, dp));
    }

    return maxy;
  }
};

class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
