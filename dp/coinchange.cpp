#include <bits/stdc++.h>
using namespace std;


// top largest k element
int largestk(vector<int> arr  , int k ) {
    priority_queue<int , vector<int> , greater<int>> pq;
    for(int n:arr) {
        pq.push(n);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}


// frequency sort code
vector<int> frequencySort(vector<int> num  , int k) {
  vector<int> ans;
  unordered_map<int,int>mp;
  for(int n:num) {
    mp[n]++;
  }
  priority_queue<pair<int , int> > pq;
  for(auto ele:mp) {
    pq.push({ele.second , ele.first});
  }
  while(!pq.empty()) {
    int num = pq.top().second;
    int freq = pq.top().first;
    for(int i = 0;i<freq;i++) {
      ans.push_back(num);
    }
    pq.pop();
  }
  return ans;
}


// k closest points to origin

vector<int> topKfrequentELement(vector<int>num , int k ) {
  typedef pair<int , int> pi;
  unordered_map<int , int > mp;
  vector<int> ans;
  for(int n:num) {
    mp[n]++;
  }
  priority_queue<pi , vector<pi> , greater<pi>> pq;
  for(auto val:mp) {
    pq.push({val.second , val.first});
    if(pq.size() > k) pq.pop();
  }
  while(!pq.empty()) {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
}

// K closest elemtns in arr
vector<int> kthClosestELement(vector<int> num , int k , int target) {
  vector<int> ans;
  priority_queue<pair<int,int>> pq;
  for(int n:num) {
    pq.push({abs(target-n), n});
    if(pq.size() > k) {
      pq.pop();
    }
  }
  while(!pq.empty()) {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
}


// k array sorted h isse kaise solve kru
vector<int> kSortedarray(vector<int> num  , int k ){
  if(k==0) return num;
  priority_queue<int ,vector<int> , greater<int>> pq;
  vector<int> ans;
  for(int n :num) {
    pq.push(n);
    if(pq.size() > k) {
      ans.push_back(pq.top());
      pq.pop();
    }
  }
  while(!pq.empty()) {
    ans.push_back(pq.top());
    pq.pop();
  }
  return ans;
}


// k th smallest element
int smallestK(vector<int> arr  , int k ) {
    priority_queue<int> pq;
    for(int n :arr) {
        pq.push(n);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}

int main() {
    return 0;
}