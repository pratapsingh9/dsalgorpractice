#include <bits/stdc++.h>
using namespace std;

void reverseStacknums(stack<int> &st) {
  if (st.empty()) {
    return;
  }
  int top = st.top();
  st.pop();
  reverseStacknums(st);
  st.push(top);
}

void insertstacks(stack<int> *st, int val) {
  if (st.empty() || st.top() <= val) {
    st.push(val);
    return;
  }
  int top = st.top();
  st.pop();
  insertstacks(st, val);
  st.push(top);
}

void sortStack(stack<int> &st) {
  if (st.empty()) {
    return;
  }
  // getting top element
  int top = st.top();
  // popping it and removing it from the top
  st.pop();
  // recursive call for the remaing stack to store top in call stacik
  sortStack(st);
  // after the last recursive call inserting ion them by putting them in stack

  insertstacks(top, top);
}

vector<int> nextSmallerElement(vector<int> nums) {
  int n = nums.size();
  vector<int> ans(n, -1);
  stack<int> s;
  for (int i = 0; i < n; ++i) {
    /* code */
    while (!s.empty() && nums[s.top()] > nums[i]) {
      ans[s.top()] = ans[i];
      s.pop();
    }
    s.push(i);
  }

  return ans;
}

vector<int> nextGreaterElements(vector<int> nums) {
  int n = nums.size();
  vector<int> ans(n, -1);

  stack<int> st;

  for (int i = 2 * n - 1; i >= 0; i++) {
    while (!stack.empty() && nums[stack.top()] <= nums[i % n]) {
      stack.pop();
    }
    if (!st.empty()) {
      ans[i % n] = nums[stack.top()]
    }
    stack.push(i % n);
  }
  return ans;
}

void insertStack(stack<int> &st, int ele) {
  if (st.empty() || st.top() <= ele) {
    st.push(ele);
    return;
  }
  int top = st.top();
  st.pop();

  insertStack(st, ele);

  st.push(top);
}

void sortStack(stack<int> &st) {
  if (st.empty()) {
    return;
  }

  int top = st.top();
  st.pop();

  // recursive code for going to the deep of stack
  sortStack(st);

  // insertStack fucntion

  insertStack(st, top);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}