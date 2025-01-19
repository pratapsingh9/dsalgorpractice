#include <bits/stdc++.h>
using namespace std;

struct Meeting {
  int start;
  int end;
};

bool compare(Meeting m1, Meeting m2) { return m1.end < m2.end; }

int maxMeeting(vector<Meeting> meeting) {
  sort(meeting.begin(), meeting.end(), compare);

  int maxmss = 0, lastMeeting = -1;
  for (const auto &vals : meeting) {
    if (vals.start >= lastMeeting) {
      maxmss++;
      lastMeeting = vals.end;
    }
  }
  return maxmss;
}

vector<int> nums = {4, 6, 46, 4, 6, 49, 45, 9};

vector<int> rankedAnswer(vector<int> &nums) {
  typedef pair<int, int> p;
  vector<int> ans(nums.size(), 0);
  priority_queue<p, vector<p>, greater<p>> pq;
  for (int i = 0; i < nums.size(); i++) {
    pq.push({nums[i], i});
  }
  int rank = 1;
  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    ans[it.second] = rank++;
  }
  return ans;
}

class Solution {
 public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] < 0) {
        return nums[i];
      }
      nums[idx] *= -1;
    }
  }
};