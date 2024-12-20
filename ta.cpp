#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> result = prices;
    stack<int> st;

    for (int i = 0; i < prices.size(); i++) {
      while (!st.empty() && prices[st.top()] >= prices[i]) {
        int j = st.top();
        st.pop();
        result[j] -= prices[i];
      }
      st.push(i);
    }
    return result;
  }
};

class Solution {
 public:
  vector<vector<string>> mostPopularCreator(vector<string>& creators,
                                            vector<string>& ids,
                                            vector<int>& views) {
    vector<vector<string>> result;
    unordered_map<string, int> creatorViews;
    for (int i = 0; i < creators.size(); i++) {
      creatorViews[creators[ids]] += views[i];
    }
    for (const auto& creator : creatorViews) {
      result
    }
    return result;
  }
};

class Solution {
 public:
  static bool compare(const string& a, const string& b) {
    if (a.size() != b.size()) {
      return a > b;
    }
    return a > b;
  }

  string kthLargestNumber(vector<string>& nums, int k) {
    priority_queue<string, vector<string>, decltype(compare)> pq(compare);

    for (const string& s : nums) {
      pq.push(s);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    return pq.top();
  }
};