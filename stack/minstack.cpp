#include <bits/stdc++.h>
using namespace std;

class MinStack {
  stack<int> st;
  stack<int> ms;

  private:
    int value;
 public:
  MinStack() {}
  void push(int val) {
    if (ms.empty() || val <= ms.top()) {
      ms.push(val);
    }
    st.push(val);
  }
  void pop() {
    if (st.top() == ms.top()) {
      ms.pop();
    }
    st.pop();
  }
  int top() {
    if (st.empty()) return -1;
    return st.top();
  }
  int getMin() {
    if (!ms.empty()) return ms.top();
    return -1;
  }
};
