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

int help(vector<int> &cost , int i , vector<int> &dp) {
  if(i>=cost.size()) return 0;
  if(dp[i] != -1) return dp[i];
  dp[i] = cost[i] + min(help(cost , i+1 , dp) , help(cost,i+2, dp));
  return dp[i];
  
}

int minCost(vector<int> &cost ) {
  vector<int> dp(cost.size()+1,-1);
  return min(help(cost , 0 , dp),help(cost , 1 , dp));
}


int minCostDp(vector<int> &cost) {
  int n = cost.size();
  vector<int> dp(n ,-1);

  dp[0]=0;
  dp[1]=cost[0];


  for(int i = 2; i<n; i++) {
    dp[i] = cost[i-1] + min(dp[i-1]  , dp[i-2]);
  }
  return min(dp[n] , dp[n-1]);
}