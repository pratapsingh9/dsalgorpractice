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

int main() {
  vector<int> nums = {4, 5, 2, 10, 8};
  vector<int> res = nextGreaterElement(nums);
  for (auto ele : res) {
    cout << ele << " ";
  }
  cout << endl;
  vector<int> res1 = nxtSmallerElement(nums);
  for (auto ele : res1) {
    cout << ele << " ";
  }
  return 0;
}