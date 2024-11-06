#include <bits/stdc++.h>
using namespace std;

pair<int,int> candyIssue(vector<int> candy , int k){
  int n = candy.size();
  vector<int> sorted = candy;
  sort(sorted.begin() , sorted.end());
  int minCost = 0 , candiyremaing =0;
  for(int i = 0; i<n-candiyremaing; i++) {
    minCost+=sorted[i];
    candiyremaing+=k;
  }
  int maxCost = 0;
  candiyremaing = 0;
  for(int i = n-1; i>=candiyremaing; i--) {
    
  } 
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

int main() { return 0; }