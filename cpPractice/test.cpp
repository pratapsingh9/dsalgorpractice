#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> arr(n);  // Array to store the input
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Prefix sum array
  vector<int> prefixsum(n, 0);
  prefixsum[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefixsum[i] = arr[i] + prefixsum[i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int result = prefixsum[r] - prefixsum[l - 1];
    cout << result << endl;
  }
}

void computerPrefixSum(const vector<vector<int>>& matrix,
                       vector<vector<int>>& prefixSum) {
  int rows = matrix.size();
  int cols = matrix[0].size();

  prefixSum = vector<vector<int>>(rows, vector<int>(cols, 0));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colsl j++) {
      prefixSum = matrix[i][j];
      if (i > 0) prefixSum[i][j] += matrix[i - 1][j];
      if (j > 0) prefixSum[i][j] += matrix[i][j - 1];
      if (i > 0 && j > 0) prefixSum[i][j] -= matrix[i - 1][j - 1];
    }
  }
}

void computePrefixSum2D(const vector<vector<int>>& matrix,
                        vector<vector<int>>& prefixSum) {
  int rows = matrix.size();
  int cols = matrix[0].size();

  // Initialize the prefix sum array
  prefixSum = vector<vector<int>>(rows, vector<int>(cols, 0));

  // Calculate prefix sum values
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      prefixSum[i][j] = matrix[i][j];

      if (i > 0) prefixSum[i][j] += prefixSum[i - 1][j];
      if (j > 0) prefixSum[i][j] += prefixSum[i][j - 1];
      if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i - 1][j - 1];
    }
  }
}

int querySum(const vector<vector<int>>& prefixSum, int r1, int c1, int r2,
             int c2) {
  int sum = prefixSum[r2][c2];
  if (r1 > 0) sum -= prefixSum[r1 - 1][c2];
  if (c1 > 0) sum -= prefixSum[r2][c1 - 1];
  if (r1 > 0 && c1 > 0) sum += prefixSum[r1 - 1][c1 - 1];
  return sum;
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  vector<vector<int>> prefixSum;
  computePrefixSum2D(matrix, prefixSum);

  // Query the sum of submatrix from (1, 1) to (2, 2)
  int r1 = 1, c1 = 1, r2 = 2, c2 = 2;
  cout << "Sum of submatrix from (1, 1) to (2, 2): "
       << querySum(prefixSum, r1, c1, r2, c2) << endl;

  return 0;
}
class Solution {
 public:
  int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    int n = nums.size();
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
      int skip = dp[i - 1];
      int robHouse = nums[i] + dp[i - 2];
      dp[i] = max(skip, robHouse);
    }
    return dp[n - 1];
  }
};
class Solution {
 public:
  int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    for (int i = 2; i < n(); i++) {
      int skip = dp[i - 1];
      int robHouse = nums[i] + dp[i - 2];
      dp[i] = min(skip, robHouse);
    }
    return dp[nums.size() - 1];
  }
  int solve(vector<int>& nums, int n, vector<int>& memo) {
    if (n < 0) return 0;
    if (memo[n] != -1) return memo[n];
    int robHouse = nums[n] + solve(nums, n - 2, memo);
    int skip = solve(nums, n - 1, memo);
    memo[n] = max(robHouse, skip);
    return memo[n];
  }
};
class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) { return solve() }
};

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int minInsertionsRecursion(string& s, int start, int end,
                           vector<vector<int>>& dp) {
  if (start >= end) {
    return 0;
  }
  if (dp[start][end] != -1) return dp[start][end];
  if (s[start] == s[end]) {
    return dp[start][end] = minInsertionsRecursion(s, start + 1, end - 1);
  }
  dp[start][end] = 1 + min(minInsertionsRecursion(s, start + 1, end),
                           minInsertionsRecursion(s, start, end - 1));
  return dp[start][end];
}

int main() {
  string s = "abca";
  vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
  cout << "Minimum insertions to make the string a palindrome: "
       << minInsertionsRecursion(s, 0, s.size() - 1, dp) << endl;
  return 0;
}
int minInsertionsRecursion(string& s, int start, int end) {
  vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = 0;
    }
  }
}