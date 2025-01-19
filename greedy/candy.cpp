#include <bits/stdc++.h>
using namespace std;

pair<int, int> candyIssue(vector<int> candy, int k) {
  int n = candy.size();
  vector<int> sorted = candy;
  sort(sorted.begin(), sorted.end());
  int minCost = 0, candiyremaing = 0;
  for (int i = 0; i < n - candiyremaing; i++) {
    minCost += sorted[i];
    candiyremaing += k;
  }
  int maxCost = 0;
  candiyremaing = 0;
}

pair<int, int> kitnaDega(vector<int> candy, int k) {
  int n = candy.size();
  vector<int> sorted = candy;
  sort(sorted.begin(), sorted.end());
  int minCost = 0, maxCost = 0, candiesRemaing = 0;
  for (int i = 0; i < n - candiesRemaing; i++) {
    minCost += sorted[i];
    candiesRemaing += k;
  };

  candiesRemaing = 0;

  for (int i = n - 1; i >= candiesRemaing; i--) {
    maxCost += sorted[i];
    candiesRemaing += k;
  }

  return {minCost, maxCost};
}

struct Activity {
  int start, end;
};
bool compare(Activity a, Activity b) { return a.end < b.end; }

int maxActiviyt(vector<Activity> &activity) {
  sort(activity.begin(), activity.end(), compare);

  cout << " Selected " << endl;

  int lastSelected = activity[0].end;
  int ans = 1;
  for (int i = 1; i < activity.size(); i++) {
    if (activity[i].start >= lastSelected) {
      ans++;
      lastSelected = activity[i].end;
    }
  }
  return ans;
}

int maxJumpsRecursive(vector<int> &start, int index) {
  if (index >= start.size() - 1) return 0;

  if (start[index] == 0) return 0;
  int minJUmps = INT_MAX;
  for (int i = 0; i < start.size(); i++) {
    int nextIndex = i + start[i];
    int result = minJUmps(start, nextIndex);
    if (result != INT_MAX) {
      minJUmps = min(minJUmps, 1 + result);
    }
  }
  return minJUmps;
}

struct Job {
  int id;        // Job ID
  int profit;    // Profit if completed
  int deadline;  // Deadline by which the job needs to be done
};

bool compare(Job &a, Job &b) { return a.profit > b.profit; }

int jobSequnce(vector<Job> &jobs, int n) {
  sort(jobs.begin(), jobs.end(), compare);

  vector<int> slot(n, -1);

  int totalProfit = 0;
  vector<int> JobOrder;

  for (int i = 0; i < jobs.size(); i++) {
  }
}

vector<vector<int>> mergeOverlappintIntervals(vector<vector<int>> &arr) {
  int ans = 0;
  sort(arr.begin(), arr.end());
  int start = 0;
  int end = 0;
  start = arr[0][0];
  end = ele[0][1];
  vector<vector<int>> answer;
  for (vector<int> ele : arr) {
    if (ele[0] <= end) {
      end = max(ele[1], end);
    } else {
      answer.push_back({start, end});
      start = ele[0];
      end = ele[1];
    }
  }
}