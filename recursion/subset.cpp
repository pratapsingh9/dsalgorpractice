#include <bits/stdc++.h>
using namespace std;

void backtrackingSubsetSum(vector<int> &nums, vector<vector<int>> &res, vector<int> &current, int index) {
  res.push_back(current);
  for (int i = index; i < nums.size(); i++) {
    current.push_back(nums[i]);
    backtrackingSubsetSum(nums, res, current, i + 1);
    current.pop_back();
  }
}

vector<vector<int>> subsetSum(vector<int> &nums) {
  vector<vector<int>> res;
  vector<int> current;
  backtrackingSubsetSum(nums, res, current, 0);
  return res;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  vector<vector<int>> result = subsetSum(nums);
  for (const auto &subset : result) {
    cout << "{ ";
    for (int num : subset) {
      cout << num << " ";
    }
    cout << "}" << endl;
  }

  return 0;
}
