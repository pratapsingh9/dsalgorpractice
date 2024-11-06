#include <bits/stdc++.h>
using namespace std;

bool containsDupliaton(vector<int> &nums) {
  if (nums.size() < 2) return false;
  sort(nums.begin(), nums.end());
  int left = 0, right = 1;

  while (right < nums.size()) {
    if (nums[left] == nums[right]) {
      return true;
    }
    left++;
    right++;
  }

  return false;
}

// search in roated sorted array 

int searchInOrataedSortedAray(vector<int> &nums , int target) {
    int l = 0 , r = nums.size()-1;
    while(l<r) {
        int mid = l + (r-l)/2;

        if(nums[mid] == target) {
            return mid;
        }

        if(nums[mid] > target) {
            if(nums[l] < target && target < nums[mid] ){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }else{
            if(nums[mid] < target && target < nums[r]) {
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
    }
    return -1;
}


int findMIninreoates(vector<int> nums) {
  int l = 0, r = nums.size() - 1;

  while (l < r) {
    int mid = l + (r - l) / 2;
    if (nums[mid] > nums[r]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return nums[l];
}

int maxProduct(vector<int> &num) {
  int maxy = num[0];
  int res = num[0];
  int miny = num[0];
  for (int i = 0; i < num.size(); i++) {
    if (num[i] < 0) {
      swap(maxy, miny);
    }
    maxy = max(num[i], num[i] * maxy);
    miny = min(num[i], num[i] * miny) res = max(res, maxy);
  }

  return res;
}

int maxProudct(vector<int> &nums) {
  int maxy = nums[0];
  int miny = nums[0];
  int res = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < 0) {
      swap(miny, maxy);
    }

    maxy = max(nums[i], maxy * nums[i]);
    miny = min(nums[i], min * nums[i]);
  }
}

void setMatrixZeros(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  vector<bool> row(n, false);
  vector<bool> cols(m, false);

  for (int i = 0; i < n; i++) {
    /* code */
    for (int i = 0; i < m; i++) {
      /* code */
      if (matrix[i][j] == 0) {
        row[i] = true;
        cols[j] = true;
      }
    }
  }

  // set rows to zero based index

  for (int i = 0; i < n; i++) {
    if (row[i]) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = 0;
      }
    }
  }

  // set columns to zero based

  for (int j = 0; j < m; j++) {
    if (cols[j]) {
      for (int i = 0; i < n; i++) {
        matrix[i][j] = 0;
      }
    }
  }
}

vector<int> spiralMatrix(vector<vector<int>> matrix) {
  if (matrix.empty()) return matrix;
  int left = 0;
  int right = matrix[0].size();
  int bottom = matrix.size();
  int top = 0;
  vector<int> ans;
  while (top <= bottom && left <= right) {
    for (int i = left; i < right; i++) {
      ans.push_back(matrix[top][i]);
    }
    top += 1;
    for (int i = top; i < bottom; i++) {
      ans.push_back(matrix[i][right]);
    }
    --right;
    if (top <= bottom) {
      for (int i = right; i >= right; i++) {
        ans.push_back(matrix[bottom][i]);
      }
      --bottom;
    }
    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
  }
  return ans;
}

vector<vector<int>> rotateImage(vector<vector<int>> matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  if (matrix.empty()) {
    return matrix;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }

  return matrix;
}

int main() { return 0; }