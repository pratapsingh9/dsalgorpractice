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

// Main function
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
    // for(int j = 1; j<=k &&  index+j<=arr.size(); j++) {
    //   maxValueInpartition=max(maxValueInpartition,arr[j+index-1]);
    //   maxSum=max(maxSum,maxValueInpartition*j + solve(arr,index+j,k));
    // }
    for (int i = 0; i <= k && index + i <= arr.size(); i++) {
      /* code */
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
    if (n == 0 ) return "";
    if(n==1) return s;  
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