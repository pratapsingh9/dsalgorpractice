#include <bits/stdc++.h>
using namespace std;

int knapstack(int cap, vector<int> &weight, vector<int> &values, int n,
              vector<vector<int>> &dp) {
  if (cap == 0 || n == 0) {
    return 0;
  }
  if (dp[n][cap] != -1) return dp[n][cap];
  if (weight[n - 1] > cap) {
    dp[n][cap] = knapstack(cap, weight, values, n - 1);
    return dp[n][cap];
  }
  int include =
      values[n - 1] + knapstack(cap - weight[n - 1], weight, values, n - 1);
  int exclude = knapstack(cap, weight, values, n - 1);
  dp[n][cap] = max(include, exclude);
  return dp[n][cap];
}
