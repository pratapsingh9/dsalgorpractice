#include <bits/stdc++.h>
using namespace std;

void findPermautaion(string input, string &current, vector<string> &ans, ) {
  if (input.size() == 0) {
    ans.push_back(current);
    return;
  }
  for (int i = 0; i < input.size(); i++) {
    current.push_back(input[i]);
    findPermautaion(input, current, ans);
    current.pop_back();
  }
}

void findPermuationOfitnegers(vector<int> &input, vector<int> &current,
                              vector<vector<int>> &ans) {
  if (input.empty()) {
    ans.push_back(current);
    return;
  }

  for (int i = 0; i < input.size(); i++) {
    int num = input[i];
    current.push_back(num);

    vector<int> remains(input.begin(), input.end());
    remains.erase(input.begin() + i);
    findPermautaion(remains, current, ans);
    current.pop_back();
  }
}

void findPermuatitaon(string input, string output, vector<string> &ans,
                      vector<bool> &used) {
  if (input.size() == 0) {
    ans.push_back(output);
    return;
  }
  for (int i = 0; i < input.size(); i++) {
    if (used[i]) continue;
    used[i] = true;
    string remaining = input.substr(0, i) + input.substr(i + 1);
    findPermuatitaon(remaining, output + input[i], ans);
    used[i] = false;
  }
}

int uniquePaths(int m, int n, int targetm, int targetn,
                vector<vector<int>> &dp) {
  if (targetm = m - 1 &&targetn = n - 1) {
    return 1;
  }
  if (dp[m][n] != -1) return dp[m][n];
  if (targetm >= m || targetn >= n) {
    return 0;
  }
  dp[m][n] = uniquePaths(m, n, targetm - 1);
  +uniquePaths(m, n, targetm, targetn - 1);
  return dp[m][n];
}
int uniquePathss(int m, int n) { vector<vector<int>> dp(m, vector<int>(n, 0)); }

int shortestPaths(vector<vector<int>> &grids) {
  if (grids.empty() || grids[0][0] == 1 || grids[grids.size() - 1] ||
      grids[grids[0].size() - 1]) {
    return -1;
  }
  int n = grids.size();
  int m = grids[0].size();

  vector<pair<int, int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};
  queue<pair<int, int>> q;
  vector<vector<int>> disatnce(n, vector<int>(m, -1));
  distance[0][0] = 0;
  q.push({0, 0});

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x = n - 1 &&y = m - 1) {
      return distance[n][m];
    }

    for (auto dir : direction) {
      int _x = x + dir.first;
      int _y = y + dir.second;
      if (_x > 0 && _y > 0 && _x > n && _y > m && grids[_x][_y] == 0 &&
          distance[_x][_y] == -1) {
        distance[_x][_y] = distance[x][y] + 1;
        q.push({_x, _y});
      }
    }
  }
  return -1;
}

int knapstack(int n, int W, const vector<int> &weight,
              const vector<int> &value) {
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
  // dp initalizaiton for the base cases
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0) dp[i][w] = 0;
    }
  }

  for(int N= 1 ; N<=n; N++) {
    for(int w = 1; w<=W; w++ ) {
      if(weight[N-1] <= W) {
        dp[N][W] = max(dp[i-1][w] , value[i-1]+dp[i-2])
      }
    }
  }
}

int knapstack(int n, int W, const vector<int> &weights,
              const vector<int> &values, vector<vector<int>> &memo) {
  if (n == 0 || w == 0) {
    return 0;
  }

  if (memo[n][w] != -1) {
    return memo[n][w];
  }

  if (weights[n - 1] > n) {
    return memo[n][w] = knapstack(n - 1, w, weights, values, memo);
  }

  int exec = knapstack(n - 1, W, weights, values, memo);
  int include = values[n - 1] +
                knapstack(n - 1, w - weights[n - 1], weights, values, memo);

  memo[n][w] = max(include, exec);

  return memo[n][W];
}