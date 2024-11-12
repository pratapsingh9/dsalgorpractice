#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
 public:
  int findMinDifference(int idx, int currSum, int totalSum,
                        std::vector<int>& nums,
                        std::vector<std::vector<int>>& memo) {
    if (idx == nums.size()) {
      int otherSubsetSum = totalSum - currSum;
      return std::abs(currSum - otherSubsetSum);
    }
    if (memo[idx][currSum] != -1) return memo[idx][currSum];

    int include =
        findMinDifference(idx + 1, currSum + nums[idx], totalSum, nums, memo);
    int exclude = findMinDifference(idx + 1, currSum, totalSum, nums, memo);

    memo[idx][currSum] = std::min(include, exclude);
    return memo[idx][currSum];
  }

  int minimumDifference(std::vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) {
      totalSum += num;
    }
    int halfSum = totalSum / 2;
    std::vector<std::vector<int>> memo(nums.size(),
                                       std::vector<int>(halfSum + 1, -1));
    return findMinDifference(0, 0, totalSum, nums, memo);
  }
};
class Solution {
 public:
  bool canAchieveTarget(int idx, int target, std::vector<int>& nums,
                        vector<vector<int>>& memo) {
    if (target == 0) {
      return true;
    }
    if (idx >= nums.size() || target < 0) {
      return false;
    }
    if (memo[idx][target] != -1) return memo[idx][target];
    bool include = canAchieveTarget(idx + 1, target - nums[idx], nums, memo);
    bool exclude = canAchieveTarget(idx + 1, target, nums, memo);
    memo[idx][target] = include || exclude;
    return memo[idx][target];
  }

  bool subsetSumToTarget(std::vector<int>& nums, int target) {
    vector<vector<bool>> memo(nums.size(), vector<int>(target, -1));
    return canAchieveTarget(0, target, nums, memo);
  }
};

#include <vector>

class Solution {
 public:
  bool subsetSumToTarget(vector<int>& nums, int target) {
    std::vector<std::vector<bool>> dp(n + 1,
                                      std::vector<bool>(target + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (j >= nums[i - 1]) {
          dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[nums.size()][target];
  }
};

int countSubsetRecu(vector<int>& nums, int n, int sum,
                    vector<vector<int>>& dp) {
  if (sum == 0) return 1;
  if (n == 0) return 0;
  if (dp[n][sum] != -1) return dp[n][sum];
  if (nums[n - 1] > sum) {
    dp[n][sum] = countSubsetRecu(nums, n - 1, sum);
  } else {
    dp[n][sum] = countSubsetRecu(nums, n - 1, sum - nums[n - 1]) +
                 countSubsetRecu(nums, n - 1, sum);
    return dp[n][sum];
  }
}

int countSubsets(vector<int>& nums, int n, int sum) {
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      dp[i][j] = dp[i - 1][j];

      if (nums[i - 1] <= sum) {
        dp[i][j] += dp[i - 1][j - nums[i - 1]];
      }
    }
  }
  return dp[n][sum];
}

class Solution {
 public:
  int lcs(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
    if (i == 0 || j == 0) {
      return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (text1[i - 1] == text2[j - 1]) {
      dp[i][j] = 1 + lcs(text1, text2, i - 1, j - 1, dp);
    } else {
      dp[i][j] =
          max(lcs(text1, text2, i - 1, j, dp), lcs(text1, text2, i, j - 1, dp));
    }
    return dp[i][j];
  }
};
