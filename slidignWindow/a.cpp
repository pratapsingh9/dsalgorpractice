#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_set<int> mySet;
  mySet.size return 0;
}

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        dp[i] = 0;
      } else {
        dp[i] = dp[i + 1];
        if (i + 1 < n) {
          int twodigits = (s[i] - '0') * 10 + (s[i + 1] - '0');
          if (twodigits >= 10 && twodigits <= 26) {
            dp[i] += dp[i + 2];
          }
        }
      }
    }
    return dp[0];
  }
};

class Solution {
 public:
  int numDecodings(string s) {
    vector<int> memo(s.size() + 1, -1);
    return solver(s, 0, memo);
  }
  int solver(string &s, int index, vector<int> &memo) {
    if (index == s.size()) {
      return 1;
    }
    if (s[index] == '0') return 0;
    if (memo[index] != -1) return memo[index];
    int include = solver(s, index + 1, memo);

    int exclude = 0;
    if (index + 1 < s.size()) {
      int twoDigit = (s[index] - '0') * 10 + (s[index + 1] - '0');
      if (twoDigit >= 10 && twoDigit < 26) {
        exclude = solver(s, index + 2, memo);
      }
    }
    memo[index] = include + exclude;
    return memo[index];
  }
};
class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();
    int prev1 = 1, prev2 = 0;  // dp[i+1] and dp[i+2]

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