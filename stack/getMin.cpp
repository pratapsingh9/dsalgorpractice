#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElemtn(vector<int>arr)

class MinStack {
  stack<int> st;
  stack<int> minst;

 public:
  void push(int x) {
    st.push(x);
    if (minst.empty() || x <= minst.top()) {
      minst.push(x);
    }
  }
  void pop() {
    if (st.top() == minst.top()) {
    }
  }
}

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}