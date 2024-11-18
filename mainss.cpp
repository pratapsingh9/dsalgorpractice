#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool validPath(int n, vector<vector<int>>& edges, int source,
                 int destination) {
    if (source == destination) return true;
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    unordered_set<int> visited;
    queue<int> que;

    que.push(source);
    visited.insert(source);

    while (!que.empty()) {
      int top = que.front();
      que.pop();
      for (int it : graph[top]) {
        if (it == destination) {
          return true;
        }
        if (visited.find(it) == visited.end()) {
          que.push(it);
        }
      }
    }
    return false;
  }
};

int main() { return 0; }

class Solution {
 public:
  void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
    visited[node] = true;
    int n = isConnected.size();
    for (int j = 0; j < n; j++) {
      if (isConnected[node][j] == 1 && !visited[j]) {
        dfs(isConnected, visited, j);
      }
    }
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int provCount == 0;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        provCount++;
        dfs(isConnected, visited, i);
      }
    }
    return provCount;
  }
};

class Solution {
 public:
  void dfs(vector<vector<int>>& edges, vector<bool>& visited, int node,
           vector<int>& components) {
    visited[node] = true;
    components.push_back(node);
    for (auto it : edges[node]) {
      if (!visited[it]) {
        dfs(edges, visited, it);
      }
    }
  }

  bool isComplete(vector<vector<int>>& edges, vector<int>& components) {
    int size = components.size();
    for (int node : components) {
      if (edges[node] != size - 1) return false;
    }
    return true;
  }

  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        vector<int> comp;
        dfs(graph, visited, i, comp);
        if (isComplete(graph, comp)) {
          ans++;
        }
      }
    }
    return ans;
  }
};
class Solution {
 public:
  bool dfs(int x, int y, int parentX, int parentY, vector<vector<char>>& grid,
           vector<vector<bool>>& visited) {
    visited[x][y] = true;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (auto& it : directions) {
      int newX = x + it.first;
      int newY = y + it.second;

      if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size()) {
        continue;
      }

      if (newX == parentX && newY == parentY) {
        continue;
      }

      if (grid[newX][newY] == grid[x][y]) {
        if (visited[newX][newY]) {
          return true;
        }
        if (!visited[newX][newY] && dfs(newX, newY, x, y, grid, visited)) {
          return true;
        }
      }
    }
    return false;
  }

  bool containsCycle(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (!visited[i][j]) {
          if (dfs(i, j, -1, -1, grid, visited)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
