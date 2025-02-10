#include <bits/stdc++.h>
using namespace std;

void dfss(vector<vector<char>> &grid, int i, int j, char replacement) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
    return;
  }
  if (grid[i][j] != '0') {
    return grid[i][j];
  }
  grid[i][j] = replacement;
  dfss(grid, i + 1, j, replacement);
  dfss(grid, i - 1, j, replacement);
  dfss(grid, i, j + 1, replacement);
  dfss(grid, i, j - 1, replacement);
}

void replaceowithZero(vector<vector<char>> &grid, char replacement) {
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == '0') {
        dfss(grid, i, j, replacement);
      }
    }
  }
} 

void printGrid(const vector<vector<char>> &grid) {
  for (const auto &row : grid) {
    for (char value : row) {
      cout << value << " ";
    }
    cout << endl;
  }
}

void print(vector<vector<char>> &grids) {
  for (const auto &row : grids) {
    for (char value : grids[row]) {
      cout << value << "->";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<char>> grid = {{'1', '0', '0', '1'},
                               {'0', '0', '1', '0'},
                               {'1', '0', '0', '1'},
                               {'0', '1', '1', '0'}};

  char replacement = 'x';

  replaceowithZero(grid, replacement);
  printGrid(grid);

  return 0;
}
class Solution {
 public:
  int solve(vector<int> &arr, int index, int k, vector<int> &memo) {
    if (index == arr.size()) {
      return 0;
    }
    if (memo[index] != -1) return memo[index];
    int maxSum = 0;
    int maxValueInpartition = arr[index];
    for (int i = 0; i <= k && index + i <= arr.size(); i++) {
      maxValueInpartition = max(maxValueInpartition, arr[j + index - 1]);
      maxSum = max(maxSum, maxValueInpartition * j + solve(index))
    }

    return memo[index] = maxSum;
  }
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    vector<int> memo(arr.size(), -1);
    return solve(arr, 0, k, memo);
  }
};

class Solution {
 public:
  bool palindorem(string s, int start, int end) {
    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }

  void solve(string s, int index, ) {}

  void vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> answer;
    solve(s, 0, result, answer);
    return result;
  }
};

class Solution {
 public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    unordered_set<int> st(banned.begin(), banned.end());
    int ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      if (st.count(i)) {
        continue;
      }

      if (sum + i > maxSum) {
        break;
      }

      sum += i;
      ans++;
    }
    return ans;
  }
};

class Solution {
 public:
  bool isPalindrome(string s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j]) return false;
      i++;
      j--;
    }
    return true;
  }
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";
    if (n == 1) return s;
    int maxLen = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (isPalindrome(s, i, j) && (j - i + 1) > maxLen) {
          maxLen = j - 1 + 1;
          start = i;
        }
      }
    }
    return s.substr(start, maxLen);
  }
};

class Solution {
 public:
  long long maxSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++) {
      int currSum = 0;
      for (int end = start; end < n; end++) {
        if ((end - start)) }
    }
  }
};

class Solution {
 public:
  int solver(vector<int> &nums, int index, vector<int> &memo) {
    int n = nums.size();
    if (memo[index] == -1) return nums[memo];

    if (index >= n - 1) return 0;
    if (nums[index] == 0) return INT_MAX;
    int minJumps = INT_MIN;

    for (int i = 1; i < nums[index]; ++i) {
      int jumps = solver(nums, index + i);
      if (jumps != INT_MAX) {
        minJumps = min(minJumps, 1 + jumps);
      }
    }
    memo[index] = minJumps;
    return memo[index];
  }
  int jump(vector<int> &nums) {
    vector<int> memo(nums.size(), -1);
    return solver(nums, 0, memo);
  }
};

class Solution {
 public:
  int jump(vector<int> &nums) {
    int maxy = 0, current = 0;
    int jumps = 0;
    for (int i = 0; i < nums.size(); i++) {
      /* code */
      maxy = max(maxy, i + nums[i]);
      if (i >= current) {
        jumps++;
        current = maxy;
      }
      if (current >= nums.size() - 1) break;
    }
    return jumps;
  }
};

class Solution {
 public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<bool> prefixMatch(n - 1, 0);

    for (int i = 0; i < n - 1; i++) {
      /* code */
      prefixMatch[i] = (nums[i] % 2 == nums[i + 1] % 2) ? true : false;
    }

    vector<int> prefixMatchnahi(n, 0);

    for (int i = 1; i < n; i++) {
      /* code */
      prefixMatchnahi[i] = mismatch[i - 1] + prefixMatch[i - 1];
    }

    vector<bool> result;

    for (const auto &q : queries) {
      int from = q[0];
      int to = q[1];

      if (prefixMatchnahi[to] - prefixMatchnahi[from] == 1) {
        answer.push_back(true);
      } else {
        answer.push_back(false);
      }
    }

    return answer;
  }
};
class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) return false;
  }
};

class Solution {
 public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());

    int left = 0, rigth = people.size() - 1;
    int answer = 0;
    while (left <= rigth) {
      if (people[left] + people[rigth] <= limit) {
        left += 1;
      }
      rigth++;
      answer++;
    }
    return answer;
  }
};

class Solution {
 public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    if (!root) return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      double qlen = q.size(), row = 0;
      for (int i = 0; i < qlen; i++) {
        TreeNode *curr = q.front();
        q.pop();
        row += curr->val;

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }

      ans.push_back(row / qlen);
    }

    return ans;
  }
};
