#include <bits/stdc++.h>
using namespace std;

int frog(int i, const vector<int> &arr, vector<int> &dp) {
  if (i == 0) return 0;
  if (dp[i] != -1) return dp[i];
  int jumpone = frog(i - 1, arr) + abs(arr[i] - arr[i - 1]);
  int jumpTwo = frog(i - 2, arr) + abs(arr[i] - arr[i - 2]);

  dp[i] = min(jumpTwo, jumpone);
  return dp[i];
}

int frogJumpTabu(int i, const vector<int> &arr) {
  int n = arr.size();
  vector<int> dp(n, 0);
  dp[0] = 0;
  // dp[1] = min(dp[0],dp[1]);
  for (int i = 1; i < n; i++) {
    dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]),
                dp[i - 2] + abs(arr[i] - arr[i - 2]));
  }
  return dp[n - 1];
}
class Solution {
 public:
  int solve(int sr, int sc, int er, int ec, vector<vector<int>> &dp) {
    if (sr == er && sc == ec) return 1;
    if (sr > er || sc > ec) return 0;
    if (dp[sr][sc] != -1) return dp[sr][sc];
    int right = solve(sr, sc + 1, er, ec, dp);
    int left = solve(sr + 1, sc, er, ec, dp);
    return dp[sr][sc] = left + right;
  }
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m - 1, n - 1, dp);
  }
};

class Solution {
 public:
  int solve(int sr, int sc, int er, int ec, vector<vector<int>> &grid,
            vector<vector<int>> &dp) {
    if (sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[0].size() ||
        grid[sr][sc] == 1) {
      return 0;
    }
    if (sr == er && sc == ec) return 1;

    if (dp[sr][sc] != -1) return dp[sr][sc];

    int down = solve(sr + 1, sc, er, ec, grid, dp);
    int right = solve(sr, sc + 1, er, ec, grid, dp);

    dp[sr][sc] = down + right;
    return dp[sr][sc];
  }

  int uniquePathsWithObstacles(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty() || grid[0][0] == 1) return 0;

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve(0, 0, n - 1, m - 1, grid, dp);
  }
};
class Solution {
 public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    return minHelper(grid, m, n, 0, 0, dp);
  }

  int minHelper(vector<vector<int>> &grid, int m, int n, int i, int j,
                vector<vector<int>> &dp) {
    if (i >= m || j >= n) {
      return INT_MAX;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (i == m - 1 && j == n - 1) {
      return grid[i][j];
    }
    int down = minHelper(grid, m, n, i + 1, j);
    int right = minHelper(grid, m, n, i, j + 1);
    dp[i][j] = grid[i][j] + min(down, right);
    return dp[i][j];
  }
};

class Solution {
 public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];

    for (int j = 1; j < n; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    return dp[m - 1][n - 1];
  }
};

class Solution {
 public:
  int maxPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return maxHelper(grid, m, n, 0, 0, dp);  // Start from the top-left corner
  }

  int maxHelper(vector<vector<int>> &grid, int m, int n, int i, int j,
                vector<vector<int>> &dp) {
    if (i < 0 || j < 0 || i >= m || j >= n) {
      return INT_MIN;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (i == m - 1 && j == n - 1) {
      return grid[i][j];
    }
    int right = maxHelper(grid, m, n, i, j + 1);
    int down = maxHelper(grid, m, n, i + 1, j);
    int diagonal = maxHelper(grid, m, n, i + 1, j + 1);
    dp[i][j] = grid[i][j] + max({right, down, diagonal});
    return dp[i][j];
  }
};
class Solution {
 public:
  int helper(vector<vector<int>> &triangle, int row, int col,
             vector<vector<int>> &dp) {
    if (row == triangle.size() - 1) {
      return triangle[row][col];
    }
    if (dp[row][col] != -1) return dp[row][col];
    int left = helper(triangle, row + 1, col, dp);
    int right = helper(triangle, row + 1, col + 1, dp);
    dp[row][col] = triangle[row][col] + min(left, right);
    return dp[row][col];
  }

  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++) {
      dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int row = 0; row <) }
};
