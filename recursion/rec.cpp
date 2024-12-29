#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> arr, int l, int r, int mid) {
  int n1 = mid - l + 1;
  int n2 = r - mid;
  vector<int> L(n1);
  vector<int> R(n2);

  for (int i = 0; i < n1; ++i) {
    L[i] = arr[i + l];
  }
  for (int i = 0; i < n2; ++i) {
    R[i] = arr[mid + 1 + i];
  }
  int i = 0, j = 0, k = l;

  while (i < n1 and j < n2) {
    if (L[i] < R[j]) {
      arr[k++] = L[i];
      j++;
    } else {
      arr[k++] = R[j];
    }
  }
  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void mergeSort(vector<int> nums, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid - 1);
    mergeSort(nums, mid + 1, right);

    merge(arr, left, right, mid);
  }
}

void printSubsequnece(string str, string current, int index,
                      vector<string>& str) {
  if (index == str.size()) {
    str.push_back(current);
    return;
  }
  printSubsequnece(str, current, index + 1, str);
  printSubsequnece(str, current + str[index], index + 1, str);
}

void printPermutation(string str, int index, vector<string>& result) {
  if (index == str.size()) {
    result.push_back(str);
    return;
  }
  for (int i = index; i < str.size(); i++) {
    swap(str[index], str[i]);
    printPermutation(str, index + 1, result);
    swap(str[index], str[i]);
  }
}

void findSubsequences(string str, string current, int index,
                      vector<string>& result) {
  if (index == str.size()) {
    result.push_back(current);
    return;
  }
  findSubsequences(str, current, index + 1, result);
  findSubsequences(str, current + str[index], index + 1, result);
}

void stringReverse(string s, int low, int high) {
  if (low < high) {
    return;
  }
  swap(s[low], s[high]);

  return stringReverse(s, low + 1, high - 1);
}

void findSubsequences(string str, string current, int index,
                      vector<string>& result) {
  if (index == str.size()) {
    result.push_back(current);
    return;
  }
  findSubsequences(str, current, index + 1, result);
  cout << current << endl;
  findSubsequences(str, current + str[index], index + 1, result);
  cout << current << endl;
}

int main() {
  string str = "abc";
  vector<string> subsequences;

  findSubsequences(str, "", 0, subsequences);

  for (const string& subsequence : subsequences) {
    cout << "\"" << subsequence << "\"" << endl;
  }

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(const vector<int>& arr, int target) {
  int n = arr.size();
  vector<vector<bool>> dp(n + 1, vector<int>(target + 1, false));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int t = 1; t <= target; t++) {
      if (arr[i - 1] > target) {
        dp[i][t] = dp[i - 1][t];
      } else {
        dp[i][t] =
            dp[i - 1][t] || dp[i - 1][t - arr[i - 1]];
      }
    }
  }
  return dp[n][target];
}

bool subsetSumRecursive(const vector<int>& arr, int n, int target,
                        vector<vector<int>> memo) {
  if (target == 0) return true;  // Subset found
  if (n == 0) return false;      // No elements left
  if (memo[n][target] != -1) return memo[n][target];
  if (arr[n - 1] <= target) {
    // Choose the current element or skip it
    memo[n][target] = subsetSumRecursive(arr, n - 1, target - arr[n - 1]) ||
                      subsetSumRecursive(arr, n - 1, target);
  } else {
    memo[n][target] = subsetSumRecursive(arr, n - 1, target);
  }
  return memo[n][target];
}

int main() {
  vector<int> arr = {2, 3, 7, 8, 10};
  int target = 11;
  cout << (subsetSumRecursive(arr, arr.size(), target) ? "Yes" : "No") << endl;
  return 0;
}
