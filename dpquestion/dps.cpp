#include <bits/stdc++.h>
using namespace std;

bool canPartitionHelper(vector<int>& nums, int index, int target,
                        vector<vector<int>>& dp) {
  if (target == 0) return true;
  if (target < 0) return false;
  if (dp[index][target] != -1) return dp[index][target];

  dp[index][target] =
      canPartitionHelper(nums, index - 1, target) ||
      canPartitionHelper(nums, index - 1, target - nums[index - 1]);
  return dp[index][target];
}

bool canPartitionHelper(vector<int>& nums, int index, int target) {
  vector<vector<bool>> dp(index + 1, vector<bool>(target + 1, false));
  for (int i = 0; i < nums.size(); i++) {
    dp[i][0] = true;
  }

  for (int idx = 1; idx <= index; idx++) {
    for (int t = 1; t <= target; t++) {
      if (nums[idx - 1] <= t) {
        dp[idx][t] = dp[idx - 1][t] || dp[idx - 1][t - nums[idx - 1]];
      } else {
        dp[idx][t] = dp[idx - 1][t];
      }
    }
  }

  return dp[index][target];
}

class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    return numsHelper(nums, target, 0, nums.size() - 1);
  }

  int numsHelper(vector<int>& nums, int target, int start, int end) {
    if (start > end) return 0;
  }
};

#include <vector>
using namespace std;

class Solution {
 public:
  int countSubsetsWithSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(target, -1));
    return countSubsets(nums, target, n - 1, memo);
  }

 private:
  int countSubsets(vector<int>& nums, int target, int index,
                   vector<vector<int>>& memo) {
    if (target == 0) return 1;
    if (index < 0) return 0;
    if (memo[index][target] != -1) return memo[index][target];
    int include = 0;
    if (nums[index] <= target) {
      include = countSubsets(nums, target - nums[index], index - 1);
    }
    int exclude = countSubsets(nums, target, index - 1);
    memo[index][target] = include + exclude;
    return memo[index][target];
  }
};

#include <vector>
using namespace std;

class Solution {
 public:
  int countSubsetsWithSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= target; j++) {
        if (nums[i - 1] > target) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        }
      }
    }
    return dp[n][target];
  }
};
