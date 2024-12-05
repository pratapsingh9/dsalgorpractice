#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &cost, int i, vector<int> &dp) {
  if (i >= cost.size()) return 0;
  if (dp[i] != -1) return dp[i];
  dp[i] = cost[i] + min(helper(cost, i + 1, dp), helper(cost, i + 2, dp));
  return dp[i];
}

int minCost(vector<int> &cost) {
  vector<int> dp(cost.size() + 1, -1);
  return min(helper(cost, 0, dp), helper(cost, 1, dp));
}

int help(vector<int> &cost, int i, vector<int> &dp) {
  if (i >= cost.size()) return 0;
  if (dp[i] != -1) return dp[i];
  dp[i] = cost[i] + min(help(cost, i + 1, dp), help(cost, i + 2, dp));
  return dp[i];
}

int minCost(vector<int> &cost) {
  vector<int> dp(cost.size() + 1, -1);
  return min(help(cost, 0, dp), help(cost, 1, dp));
}

int minCostDp(vector<int> &cost) {
  int n = cost.size();
  vector<int> dp(n, -1);

  dp[0] = 0;
  dp[1] = cost[0];

  for (int i = 2; i < n; i++) {
    dp[i] = cost[i - 1] + min(dp[i - 1], dp[i - 2]);
  }
  return min(dp[n], dp[n - 1]);
}

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();
    int prev1 = 1, prev2 = 0;
    for (int i = n - 1; i >= 0; i--) {
      int current = 0;
      if (s[i] != '0') {
        current = prev1;
        if (i + 1 < n) {
          int twoDigits = (s[i] - '0') * 10 + (s[i + 1] - '0');
          if (twoDigits >= 10 && twoDigits <= 26) {
            current += prev2;
          }
        }
      }
      prev2 = prev1;
      prev1 = current;
    }

    return prev1;
  }
};

class Solution {
public:
    int numTrees(int n) {
      vector<int> dp(n+1,0);
      dp[0]=1;
      dp[1]=1;

      for(int nodes = 2; nodes<=n;nodes++) {
        for(int root = 1; root<=nodes; root++) {
          dp[nodes]+= dp[root-1] * dp[nodes-root];
        }
      }
      return dp[n];
    }
};
class Solution {
 public:
  int solver(int start, int end,vector<vector<int>> &memo) {
    if (start > end) {
      return 1;
    }
    if(memo[start][end] != -1) return memo[start][end];
    int totalTrees = 0;
    for (int root = start; root < end; root++) {
      int leftTrees = solver(start, root - 1,memo);
      int rightTrees = solver(root + 1, end,memo);

      totalTrees += leftTrees * rightTrees;
    }
    memo[start][end] = totalTrees;
    return totalTrees;
  }
  int numTrees(int n) { 
    vector<vector<int>> memo(n+1,vector<int> (n+1,-1));
    return solver(1, n , memo);
   }
};


