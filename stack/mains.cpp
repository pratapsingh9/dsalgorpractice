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

string reverseWords(string s) {
  stack<char> st;
  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ' || s[i] == '\0') {
      while (!st.empty()) {
        ans += st.top();
        st.pop();
      }
      if (s[i] == ' ') {
        ans += ' ';
      }
    } else {
      st.push(s[i]);
    }
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  if (!ans.empty() && ans.back() == ' ') {
    ans.pop_back();
  }
  return ans;
}

void reverseStack(stack<int> &s) {
  queue<int> q;
  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  }
  while (!q.empty()) {
    s.push(q.front());
    q.pop();
  }
}

vector<int> nxtSmallerUnit(vector<int> nums) {
  int n = nums.size();
  stack<int> s;
  vector<int> res(n, -1);
  for (int i = n - 1; i = > 0; i--) {
                while(s.empty() && s.top() >= nums[i]]) {
                  s.pop();
                }
                if (!s.empty()) {
                  res[i] = s.top();
                }

                st.push(i);
  }
  return res;
}

void insertStack(int ele , stack<int> &s) {
  if(s.empty() || s.top() < val) {
    s.push(val);
    return ;
  } 

  int top = s.top();
  s.pop();
  insertStack(ele , s);
  s.push(top);
}

void revesestack(stack<int> &s) {
  if(s.empty()) return ;
  int top = s.top();
  s.pop();
  revesestack(s);
  insertStack(top , s);
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

vector<int> next(vector<int> nums) {
  int n = nums.size();
  stack<int> s;
  vector<int> res(n, -1);
  for (int i = 0; i < n * 2 - 1; i++) {
    while (!s.empty() && nums[s.top()] <= nums[i % n]) {
      st.pop();
    }
    while (!s.empty()) {
      res[i % n] = nums[s.top()];
    }
    s.push(i % n);
  }
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