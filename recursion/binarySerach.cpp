#include <bits/stdc++.h>
using namespace std;

int binary(vector<int> &nums, int target, int left, int right) {}

int binarySearch(vector<int> &nums, int target, int low, int high) {
  if (low > high) {
    return -1;
  }
  int mid = low + (high - low) / 2;
  if (nums[mid] == target) {
    return target;
  } else if (nums[mid] > target) {
    return binarySearch(nums, target, low, mid - 1);
  } else {
    return binarySearch(nums, target, mid + 1, high);
  }
}

class Solution {
 public:
  vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  typedef pair<int, pair<int, int>> P;
  int minEfforst(vector<vector<int>> &h) {
    int m = h.size();
    int n = h[0].size();
    vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
    priority_queue<P, vector<P>, greater<P>> pq;
    distance[0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
      int dist = pq.top().first;
      auto cords = pq.top().second;
      pq.pop();
      int x = cords.first;
      int y = cords.second;
      for (auto dir : dirs) {
        int newX = dir.first + x;
        int newY = dir.second + y;
        if (x >= 0 && y >= 0 && x < m && y < n) {
          int absDiff = h[x][y] - h[newX][newY];
          int maxdiff = max(absDiff, dist);
          if (distance[newX][newY] > maxdiff) {
            distance[newX][newY] = maxdiff;
            pq.push({maxdiff, {newX, newY}});
          }
        }
      }
    }
    return distance[m - 1][n - 1];
  }
};

class Solution {
 public:
  vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  typedef pair<int, pair<int, int>> P;
  int minEfforst(vector<vector<int>> &h) {
    int m = h.size();
    int n = h[0].size();
    vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    priority_queue<P, vector<P>, greater<P>> pq;
    result[0][0] = 0;
    pq.push({0, {0, 0}});
    while (!pq.empty()) {
      int diff = pq.top().first;
      int[x, y] = pq.top().second;
      pq.pop();
      for (auto &dir : dirs) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (x >= 0 && y >= 0 && x < m && y < n) {
          int absDiff = h[x][y] - h[newX][newY];
          int maxDiff = max(absDiff, diff);
          if (result[newX][newY] > maxDiff) {
            result[newX][newY] = maxDiff;
            pq.push({maxDiff, {newX, newY}});
          }
        }
      }
    }
    return result[m - 1][n - 1];
  }
} class Solution {
 public:
  void dfs(vector<vector<int>> &graph, int i, vector<bool> &visited) {
    visited[i] = true;
    int n = graph.size();
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == 1 && !visited[j]) {
        dfs(graph, j, visited);
      }
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int provinceCount = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        provinceCount++;
        dfs(isConnected, i, visited);
      }
    }
  }
};

class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                               vector<int> &people) {
    int maxTime = 0;
    for (auto it : flowers) {
      maxTime = max(maxTime, flowers[1]);
    }
    vector<int> bloomChanges(maxTime + 2, 0);
    for (auto flower : flowers) {
      bloomChanges[flower[0]] += 1;
      bloomChanges[flower[1] + 1] -= 1;
    }

    vector<int> bloomCount(maxTime + 2, 0);
    for (int i = 1; i < maxTime; ++i) {
      bloomCount[i] = bloomCount[i - 1] + bloomChanges[i];
    }

    vector<int> result;
    for (int &person : people) {
      if (person > maxTime) {
        result.push_back(0);
      } else {
        result.push_back(bloomCount[person]);
      }
    }
    return result;
  }
};

class Solution {
 public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int low = 0, high = mountainArr.length() - 1;
    while (high - low > 1) {
      int mid = low + (high - low) / 2;
      if (mountainArr.get(mid) > target &&
          mountainArr.get(mid) > mountainArr.get(mid + 1)) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};
