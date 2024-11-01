#include <bits/stdc++.h>
using namespace std;

int countError(vector<int> &processOrder, vector<int> &executionOrder) {
  stack<int> s;
  for (int i = processOrder.size() - 1; i >= 0; i--) {
    s.push(processOrder[i]);
  }
  int ans = 0;
  for (auto val : executionOrder) {
    if (!s.empty() && s.top() == val) {
      s.pop();
    } else {
      ans++;
    }
  }
  return ans;
}

vector<int> nextgreateTOleft(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i = 0;i<n;i++) {
        while(!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        if(s.empty()) {
            ans.push_back(-1);
        }else{
            ans.push_back(s.top());
        }
        s.push(i);
    }

    }

vector<int> calculateSpan(vector<int> prize) {
    int n = prize.size();
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i = 0; i<n; i++) {
        while(!s.empty() && prize[s.top()] <= prize[i]) {
            s.pop();
        }
        if(!s.empty()) {
            ans[i] = i-s.top() ;
        } else{
            ans[i] = i + 1;
        }
        s.push(i);
    }
}