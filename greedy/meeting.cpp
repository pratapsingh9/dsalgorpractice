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

int main() { return 0; }
