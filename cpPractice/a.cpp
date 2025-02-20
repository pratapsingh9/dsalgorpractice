#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void solve(int n, int k, string& current, int& count, string& answer) {
    if (current.size() == n) {
      count++;
      if (count == k) {
        answer = current;
      }
      return;
    }
    for (char c = "a"; c <= 'c'; c++) {
      if (!current.empty() && current.back() != c) {
        current.push_back(c);
        solve(n, k, current, count, answer);
        current.pop_back();
        if (!answer.empty()) return;
      }
    }
  }
  string getHappyString(int n, int k) {
    int count = 0;
    string current = "";
    string answer = "";
    solve(n, k, current, count, answer);
    return answer;
  }
};

class Solution {
 public:
  void solve(int index, string& current, string& result,
             unordered_set<string>& st, int n) {
    if (index == n) {
      if (st.find(current) == st.end()) {
        result = current;
      }
      return;
    }
    if (!result.empty()) return;
    current.push_back('0');
    solve(index + 1, current, result, st, n);
    current.pop_back();

    if (!result.empty()) return;

    current.push_back('1');
    solve(index + 1, current, result, st, n);
    current.pop_back();
  }
  string findDifferentBinaryString(vector<string>& nums) {
    string current = "";
    string result = "";
    unordered_set<string> st(nums.begin(), nums.end());
    int n = nums.size();
    solve(0, current, result, st, n);
    return result;
  }
};