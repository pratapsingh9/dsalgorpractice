#include <bits/stdc++.h>
using namespace std;

int trappingRainwater(vector<int> rain) {
  int ans = 0;
  stack<int> s;
  for (int i = 0; i < rain.size() - 1; i++) {
    while (!s.empty() && rain[s.top()] <) }
}

int trappingRainWater(vector<int> rain) {
  int ans = 0;
  stack<int> s;
  for (int i = 0; i < rain.size() - 1; i++) {
    while (!s.empty() && rain[i] > rain[s.top()]) {
      int top = s.top();
      s.pop();

      if (s.empty()) break;

      int distance = i - s.top() - 1;
      int bounded_H = min(rain[i], rain[s.top()] - rain[top]);
      ans += distance * bounded_H;
    }
    s.push(i);
  }
  return ans;
}

int trap(vector<int> rains) {
  int l = 0, r = rains.size() - 1;
  int lmax = 0, rmax = 0;
  int ans = 0;

  while (l < r) {
    if (rains[l] < rains[r]) {
      if (rains[l] > lmax) {
        lmax = rains[l];
      } else {
        ans += lmax - rains[l];
      }
      l++;
    } else {
      if (rains[r] > rmax) {
        rmax = rains[r];
      } else {
        ans += rmax - rains[r];
      }
      r--;
    }
  }
  return ans;
}

int findfirstmsisignPositive(vector<int> &nums) {
  sort(nums.begin(),nums.end());
  int missing = 1;
  for(int num:nums) {
    if(num==missing) {
      missing++;
    }
    else if(num>missing) {
      
    }
  }
  return 
}