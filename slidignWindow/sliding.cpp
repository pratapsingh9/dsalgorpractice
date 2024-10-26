#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> nums) {
  stack<int> st;
  int n = nums.size();
  vector<int> res(n, -1);

  for (int i = n - 1; i = > 0; i--) {
    while (!st.empty() && st.top() < nums[i]) {
      st.pop();
    }
    if (!st.empty()) {
      res[i] = st.top();
    }
    st.push(i);
  }
  return res;
}
vector<int> nxtSmallerElement(vector<int> nums) {
  stack<int> st;
  int n = nums.size();
  vector<int> res(n, -1);

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && st.top() >= nums[i]) {
      st.pop();
    }
    if (!st.empty()) {
      res[i] = st.top();
    }
    st.push(i);
  }
  return res;
}
