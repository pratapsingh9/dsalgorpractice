#include <bits/stdc++.h>
using namespace std;

void add2num() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << n + m << endl;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  while (n--) {
    cin >> n;
    if (n % 3 == 0) {
      ans += 1;
    }
  }
  return ans;
}

class Solution {
 public:
  vector<int> intersection(vector<vector<int>>& nums) {
    unordered_map<int, int> mp;
    for (auto it : nums) {
      for (auto i : it) {
        mp[i]++;
      }
    }
    int n = nums.size();
    vector<int> ans;
    for (auto it : mp) {
      if (it.second == n) {
        ans.push_back(it.first);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};