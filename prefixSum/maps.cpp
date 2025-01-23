#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int pivotInteger(int n) {
    int sum = (n * (n + 1)) / 2;
    int cumSum = 0;
    for (size_t i = 1; i <= n; i++) {
      /* code */
      cumSum += i;
      if (cumSum == sum - cumSum + i) return i;
    }
    return -1;
  }
};

int countSubarraysWithSum(vector<int>& arr, int target) {
  unordered_map<int, int> mp;
  mp[0] = 1;
  int prefixsum = 0, count = 0;

  for (int num : arr) {
    prefixsum += num;
    if (mp.find(prefixsum - target) != mp.end()) {
      count += mp[prefixsum - target];
    }
    mp[prefixsum]++;
  }
  return count;
}

int countNiceSubarrays(vector<int>& arr, int K) {
  unordered_map<int, int> mp;
  mp[0] = 1;
  int prefixsum = 0, count = 0;
  for (int num : arr) {
    prefixsum += num;
    if (mp.find(prefixsum - k) != mp.end()) {
      count += mp[prefixsum - k];
    }
    mp[prefixsum]++;
  }
  return count;
}

class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (isWater[r][c] == 1) {
          height[r][c] = 0;
          q.push({r, c});
        }
      }
    }
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      for (const auto& dir : direction) {
        int nr = r + dir[0], nc = c + dir[1];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && height[nr][nc] == -1) {
          height[nr][nc] = height[r][c] + 1;
          q.push({nr, nc});
        }
      }
    }
    return height;
  }
};

void solvePrefixquery() {
  int n;
  cin >> n;
  vector<int> array(n);
  for (int i = 0; i < n; i++) cin >> array[i];
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int yp
  }
}

#include <iostream>
#include <vector>

using namespace std;

int ass() {
  int n, q;
  cin >> n >> q;

  vector<long long> arr(n + 1, 0);
  vector<long long> diff(n + 1, 0);

  // Input the array
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  // Process the queries
  while (q--) {
    int type, l, r;
    cin >> type >> l >> r;

    if (type == 1) {
      long long x;
      cin >> x;
      diff[l] += x;
      if (r + 1 <= n) diff[r + 1] -= x;
    } else {
      long long sum = 0;
      for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        arr[i] += diff[i];
        diff[i] = 0;
      }
      for (int i = l; i <= r; i++) {
        sum += arr[i];
      }
      cout << sum << endl;
    }
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int rwmpas() {
  int n, q;
  cin >> n >> q;

  vector<int> arr(n + 1, 0);
  vector<long long> prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    long long sum = 0;
    for (int i = l; i <= r; i++) {
      if (arr[i] > x) {
        sum += arr[i];
      }
    }
    cout << sum << endl;
  }

  return 0;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<long long> arr(n + 1, 0);
  vector<long long> diff(n + 1, 0);

  for (int i = 1; i < n; i++) cin >> arr[i];

  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;

    diff[l] += x;
    diff[r + 1] -= x;
  }

  long long totalSum = 0;
  long long running_sum = 0;
  for (int i = 1; i <= n; i++) {
    running_sum += diff[i];
    arr[i] += running_sum;
    totalSum += arr[i];
  }

  cout << totalSum << endl;
}

class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<int> rcount(rows, 0), Ccount(cols, 0);
    for (size_t i = 0; i < rows; i++) {
      /* code */
      for (size_t j = 0; j < cols; j++) {
        /* code */

        if (grid[i][j] == 1) {
          /* code */
          rcount[i]++;
          Ccount[j] + pratap96 + ;
        }
      }
    }
    int servers = 0;
    for (size_t i = 0; i < rows; i++) {
      /* code */
      for (size_t j = 0; j < cols; j++) {
        /* code */
        if (grid[i][j] == 1 && (rcount[i] > 1 || Ccount[j] > 1)) {
          servers++;
        }
      }
    }
    return servers;
  }
};

class Solution {
 public:
  bool inRange(int x1, int y1, int r, int x2, int y2) {
    long long dx = x2 - x1;
    long long dy = y2 - y1;
    return dx * dx + dy * dy <= (long long)r * r;
  }
  void dfs(int bomb, const vector<vector<int>>& graph,
           unordered_set<int>& visited) {
    visited.insert(bomb);
    for (int neighbor : graph[bomb]) {
      if (visited.find(neighbor) == visited.end()) {
        dfs(neighbor, graph, visited);
      }
    }
  }
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> graph(n);
  }
};

class Solution {
 public:
  int dfs(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    visited[start] = true;
    int count = 1;
    for (int neighbour : graph[start]) {
      if (!visited[neighbour]) {
        count += dfs(neighbour, visited);
      }
    }
    return count;
  }
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        long long dx = bombs[j][0] - bombs[i][0];
        long long dy = bombs[j][1] - bombs[i][1];
        long long distance = dx * dx + dy * dy;
        long long radiusSquare = bombs[i][2] * bombs[i][2];
        if (distance <= radiusSquare) {
          graph[i].push_back(j);
        }
      }
    }

    int count = INT_MIN;
    for (int i = 0; i < n; i++) {
      vector<bool> visited(n, false);
      count = max(count, dfs(graph, i, visited));
    }
    return count;
  }
};