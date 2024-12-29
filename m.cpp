#include <bits/stdc++.h>
using namespace std;

int maximiseMemeory(vector<int> memory) {
  sort(memory.rbegin(), memory.rend());
  int total = 0;
  for (int i = 0; i < memory.size(); i++) {
    total += (i + 1) * (int)memory[i];
  }
  return total;
}

int main() {
  vector<int> meoory = {3, 4, 5};
  cout << maximiseMemeory(meoory) << endl;
  return 0;
}

int smallestPostiiveNumber(vector<int> nums) { sort(nums.begin(), nums.end()); }

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      /* code */
      int mid = l + (r - l) / 2;

      bool evenCheck = (mid % 2) == 0;
      if (evenCheck) {
        /* code */
        if (nums[mid] == nums[mid + 1]) {
          /* code */
          l = mid + 2;
        } else {
          r = mid;
        }
      } else {
        if (nums[mid] == nums[mid + 1]) {
          /* code */
          r = mid;
        } else {
          l = mid + 1;
        }
      }
    }
    return nums[l];
  }
};

class Solution {
 public:
  int solve(vector<int>& nums, int target, int index,
            vector<unordered_map<int, int>>& memoDp) {
    if (memoDp[index].count(target)) {
      return memoDp[index][target];
    }
    if (index == 0) {
      return (target == nums[0]) + (target == -nums[0]);
    }
    int add = solve(nums, target - nums[index], index - 1, memoDp);
    int subtract = solve(nums, target + nums[index], index - 1, memoDp);
    memoDp[index][target] = add + subtract;

    return memoDp[index][target];
  }

  int findTargetSumWays(vector<int>& nums, int target) {
    vector<unordered_map<int, int>> memoDp(nums.size());
    return solve(nums, target, nums.size() - 1, memoDp);
  }
};

class Solution {
 public:
  int solve(int amount, vector<int>& coins, int index,
            vector<vector<int>>& memoDp) {
    if (index >= coins.size() || amount < 0) {
      return 0;
    }
    if (memoDp[amount][index] != -1) return memoDp[amount][index];
    if (amount == 0) return 1;
    int include = solve(amount - coins[index], coins, index, memoDp);
    int exclude = solve(amount, coins, index + 1, memoDp);
    memoDp[amount][index] = include + exclude;
    return memoDp[amount][index];
  }
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> memoDp(amount + 1, vector<int>(coins.size(), -1));
    return solve(amount, coins, 0, memoDp);
  }
};

class Solution {
 public:
  int solve(vector<vector<int>>& triangle, int row, int col) {
    if (row == triangle.size() - 1) {
      return triangle[row][col];
    }

    int left = solve(triangle, row + 1, col);
    int right = solve(triangle, row + 1, col + 1);
    return triangle[row][col] + min(left, right);
  }
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    return solve(triangle, 0, 0);
  }
};

class Solution {
 public:
  const int MOD = 1e9 + 7;

  int checkRecord(int n) { return solve(n, 0, 0); }
  int solve(int remainingDays, int absentCount, int lateCount) {
    if (remainingDays == 0) return 1;
    int total = 0;
    total += solve(remainingDays - 1, absentCount, 0);
    if (absentCount < 1) {
      total += solve(remainingDays - 1, absentCount + 1, 0);
    }
    if (lateCount < 2) {
      total += solve(remainingDays - 1, absentCount, lateCount + 1);
    }

    return total % MOD;
  }
};

class Solution {
 public:
  int helper(string s, int k, int index, vector<int>& dp) {
    if (index == s.size()) return 1;
    if (s[index] == '0') return 0;
    if (dp[index] != -1) return dp[index];
    int ans = 0;
    long num = 0;

    for (int j = index; j < s.size(); j++) {
      num = num * 10 + s[index] - '0';
      if (num > k) break;
      ans = (ans + helper(s, k, j + 1, dp)) % 1000000007;
    }
    dp[index] = ans;
    return dp[index];
  }
  int numberOfArrays(string s, int k) {
    vector<int> dp(s.size(), -1);
    return helper(s, k, 0, dp);
  }
};
class Solution {
 public:
  int MOD = 1000000007;
  int numberOfArrays(string s, int k) {
    int n = s.size();
    vector<int> dp(n, -1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        dp[i] = 0;
        break;
      }
      long num = 0;
      for (int j = i; j < n; j++) {
        num = (num * 10) + (s[j] - '0');
        if (num > k) break;
        dp[i] = dp[i] + (dp[j + 1]) % MOD;
      }
    }
    return dp[0];
  }
};

class Solution {
 public:
  int MOD = 1e9 + 7;
  int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int solve(vector<vector<int>>& grid, int currentRow, int currentColumn,
            int row, int column, vector<vector<int>>& memoDp) {
    if (memoDp[currentRow][currentColumn] != -1)
      return memoDp[currentRow][currentColumn];
    int count = 1;
    for (auto dirs : directions) {
      int newRow = dirs[0] + currentRow;
      int newCol = dir[1] + currentColumn;

      if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < column &&
          grid[newRow][newCol] > grid[currentRow][currentColumn]) {
        count = (count + solve(grid, newRow, newCol, row, column,memoDp)) % MOD;
      }
    }
    memoDp[currentRow][currentColumn] = count;
    return memoDp[currentRow][currentColumn];
  }
  int countPaths(vector<vector<int>>& grid) {
    int row = grid.size();
    int column = grid[0].size();
    int count = 0;
    vector<vector<int>> memoDp(row + 1, vector<int>(column + 1, -1));
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        count = (count + solve(grid, i, j, row, column, memoDp)) % MOD;
      }
    }
    return count;
  }
};

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxValues = 0;
        int maxPrevvalues = values[0] + 0;
        for(int i = 1; i<values.size(); i++) {
          maxValues=max(maxValues,maxPrevvalues+values[i] - i );
          maxPrevvalues=max(maxPrevvalues,values[i] + i);
        }
        return maxValues;
    }
};

class Solution {
  public:
      int solve(int day , vector<int> &prices , bool shouldBuy) {
        if(day>= prices.size()) return 0;
        if(shouldBuy) {
          int buy = -prices[day] + solve(day+1,prices,false);
          int skip =  solve(day+1,prices,true);
          return max(buy,skip);
        }else{
          int buy = prices[day] + 
        }
      }
      int maxProfit(vector<int>& prices) {
        return solve(0,prices,true);  
      }
};