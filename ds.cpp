#include <bits/stdc++.h>
using namespace std;

long long sumOfDistinctCounts(const vector<int>& categories) {
  unordered_map<int, int>
      lastSeen;          // To store the last seen index of each element
  int start = 0;         // Start of the sliding window
  long long result = 0;  // Final result to store the sum of distinct counts

  for (int end = 0; end < categories.size(); ++end) {
    int current = categories[end];

    // If the current element was seen before, move the start of the window
    if (lastSeen.count(current) && lastSeen[current] >= start) {
      start = lastSeen[current] +
              1;  // Move start to exclude the previous occurrence
    }

    // Update the last seen index of the current element
    lastSeen[current] = end;

    // Calculate the number of subarrays ending at the current index
    // and add it to the result
    result += (end - start + 1);
  }

  return result;
}

int main() {
  vector<int> categories = {1, 2, 1};
  cout << "Output: " << sumOfDistinctCounts(categories) << endl;
  return 0;
}

vector<int> subarrayWithSUm(vector<int> nums, int target) {
  //  will store the total sum till the index
  unordered_map<int, int> mp;

  int cumSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    /* code */
    cumSum += nums[i];
    if (cumSum == target) return {0, i};
    if (mp.find(target - cumSum) != mp.end()) {
      return {mp[target - cumSum], i};
    }
    mp[cumSum] = i;
  }
  return vector<int>{};
}

bool isIsomorphic(string a, string b) {
  if (a.size() != b.size()) return false;

  unordered_map<char, char> atob, btoa;

  for (int i = 0; i < a.size(); i++) {
    char a = s[i], b = t[i];

    if (atob.count(a) !=) }
}

class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxbeatury = 1;
    int left = 0;
    for (int i = 0; i < n; i++) {
      /* code */
      while (nums[i] - nums[left] > 2 * k) {
        left++;
      }
      maxbeatury = max(maxbeatury, i - left + 1);
    }
    return maxbeatury;
  }
};
class Solution {
 public:
  int fillCups(vector<int>& amount) {
    sort(amount.begin(), amount.end());
    if (amount[2] > amount[0] + amount[1]) return amount[2];

    return (amount[0] + amount[1] + amount[2] + 1) / 2;
  }
};
class Solution {
 public:
  int fillCups(vector<int>& amount) {
    priority_queue<int> pq;
    for (int x : amount) {
      if (x > 0) pq.push(x);
    }

    int time = 0;
    while (!pq.empty()) {
      int first = pq.top();
      pq.pop();
      if (!pq.empty()) {
        int second = pq.top();
        pq.pop();

        if (--first > 0) pq.push(first);
        if (--second > 0) pq.push(second);
      } else {
        if (--first > 0) pq.push(first);
      }
      time++;
    }
    return time;
  }
};

class Solution {
 public:
  bool compareOperator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  }
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (int x : arr) {
      mp[x]++;
    }
    vector<pair<int, int>> vec;

    for (auto& entry : mp) {
      vec.push_back({entry.second, entry.first});
    }

    sort(vec.begin(), vec.end(), compareOperator);

    int target = arr.size() / 2;
    int answer = 0;
    int removed = 0;
    for (auto& p : vec) {
      removed += p.first;
      answer++;
      if (removed >= target) break;
    }
    return answer;
  }
};


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
    }
};1