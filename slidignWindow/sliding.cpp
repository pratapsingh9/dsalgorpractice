#include <bits/stdc++.h>
using namespace std;

vector<int> findDigits(int n) {
  vector<int> ans = {};

  return ans;
}

vector<int> firstNegativeResult(vector<int> &vec, int k) {
  vector<int> ans(vec.size());
  queue<int> q;
  for (int i = 0; i < k; i++) {
    if (vec[i] < 0) q.push(vec[i]);
  }
  if (!q.empty()) {
    /* code */
    ans.push_back(vec[q.front()]);
  } else {
    ans.push_back()
  }

  for (int right = k; right < vec.size(); right++) {
    int
  }
  return ans;
}

int main() {
  vector<int> val = {12, -1, -7, 8, -15, 30, 16, 28};
  int k = 3;
  vector<int> ans = firstNegativeResult(val, k);
  for (int ele : ans) {
    cout << ele << ' ';
  }
  return 0;
}