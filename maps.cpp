#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (start <= end) {
      return {start, end};
    }
    return {-1, -1};
  }
};

int main() {
  unordered_map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};
  cout << brackets.count('(') << endl;
  return 0;
}

