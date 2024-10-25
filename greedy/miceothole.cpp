#include <bits/stdc++.h>
using namespace std;

int nMeetingInOneRoom(vector<int> vec )


int minRotation(vector<int> start, vector<int> end) {
  if (start.size() != end.size()) return -1;
  int n = 10;
  int ans = 0;
  for (int i = 0; i < start.size(); i++) {
    int clockWise = (end[i] - start[i] + n) % n;
    int antiClockWise = (start[i] - end[i] + n) % n;
    ans += min(clockWise, antiClockWise);
  }
  return ans;
}

int assignMicetohole(vector<int> mouse, vector<int> hole) {
  if (mouse.size() != hole.size()) return -1;

  sort(mouse.begin(), mouse.end());
  sort(hole.begin(), hole.end());
  int ans = INT_MIN;
  for (int i = 0; i < hole.size(); i++) {
    ans = max(ans, abs(mouse[i] - hole[i]));
  }
  return ans;
}

int main() { return 0; }