#include <bits/stdc++.h>
using namespace std;

int power(int n, int pow) {
  if (pow == 0) {
    return 1;
  }

  return n * power(n, pow - 1);
}

int cutRod(int prices[], int n) {
  if (n <= 0) return 0;
  int maxProfit = INT_MIN;
  for (int i = 0; i < n; i++) {
    maxProfit = std::max(maxProfit, prices[i] + cutRod(prices, n - i - 1));
  }
  return maxProfit;
}

int coinChange(vector<int> coins, int index, int amount) {
  if (amount == 0) return 1;
  if (amount < 0 || index < 0) return 0;

  return coinChange(coins, index, amount - coins[index]) +
         coinChange(coins, index - 1, amount);
}

vector<int> ans = {1,2,3,4,5}

int sumOfarrayElements(vector<int> &num , int index) {
  if (index == num.size()) {
    return 0;
  }

  int ans = num[index] + sumOfarrayElements(num, index + 1);
  return ans;
}

bool checkPalindrome(string s, int l, int r) {
  if (l > r) {
    return true;
  }

  return s[l] == s[r] && checkPalindrome(s, l + 1, r - 1);
}

void printArrayinRevers(vector<int> n, int i) {
  if (i == n.size()) {
    return;
  }
  int ele = n[i];
  printArrayinRevers(n, i + 1);
  cout << ele << endl;
}

int knapStack(vector<int> w, vector<int> values, int capactiy, int n) {
  if (n == 0 || capactiy == 0) return 0;
  if (w[n - 1] > capactiy) {
    return max
  }
}

void allSubsequnceOfstring(string &s, int ind, string curr) {
  if (ind == s.size()) {
    cout << curr << endl;
    return;
  }

  allSubsequnceOfstring(s, ind + 1, curr + s[ind]);
  allSubsequnceOfstring(s, index + 1, curr);
}

void generateParenthisHelper(vector<string> &ans, int n, string current,
                             int open, int close) {
  if (current.length() == 2 * n) {
    ans.push_back(current);
    return;
  }

  if (open < n) {
    generateParenthisHelper(ans, n, current + '(', open + 1, close);
  }
  if (close < n) {
    // closing
    generateParenthisHelper(ans, n, current + ')', open, close + 1);
  }
}

int wayToClimb(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  int left = wayToClimb(n - 1);
  int right = wayToClimb(n - 2);
  return left + right;
}

void permutateResults(vector<string> &result, string str, int start) {
  if (start == str.size()) {
    result.push_back(str);
    return;
  }
  for (int i = start; i < str.size(); i++) {
  }
}

vector<string> generateParenthis(int n) {
  vector<string> ans;
  generateParenthisHelper(ans, n, "", 0, 0);
}

int main() {
  cout << power(2, 4) << endl;
  return 0;
}