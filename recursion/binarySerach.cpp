#include <bits/stdc++.h>
using namespace std;

int binary(vector<int> &nums , int target , int left  , int right) {
    
}

int binarySearch(vector<int> &nums, int target, int low, int high) {
  if (low > high) {
    return -1;
  }
  int mid = low + (high - low) / 2;
  if (nums[mid] == target) {
    return target;
  } else if (nums[mid] > target) {
    return binarySearch(nums, target, low, mid - 1);
  } else {
    return binarySearch(nums, target, mid + 1, high);
  }
}

int main() { return 0; }