#include <bits/stdc++.h>
using namespace std;


// top largest k element
int largest(vector<int> arr  , int k ) {
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


// tpp k frequen elemnts

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

// minise the cost of adding the ropes
int costofRopes(vector<int> ans){
  if(ans.empty()) return 0;
  priority_queue<int , vector<int> , greater<int>> pq;
  int cost = 0;
  for(int n:ans){
    pq.push(n);
  }
  while(pq.size() > 1) {
    int f = pq.top();
    pq.pop();
    int s = pq.top();
    pq.pop();
    cost += f+s;
    pq.push(f+s);
  }
  return cost;
 }

// k th closest point to origin
vector<pair<int,int>> kthClosespointOrigin(vector<pair<int,int>> point , int k ) {
    typedef pair<int , pair<int,int>> pi;
  priority_queue<pi>pq;
  for(auto &points:point) {
    int dist = points.first*points.first + points.second*points.second;
    pq.push({dist , points});
    if(pq.size() > k) pq.pop();
  }
  vector<pair<int,int>> ans;
  while(!pq.empty()) {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
}


// sum of element between kth small and kth largest
int costofkandklarge(vector<int> sum , int f , int l) {
  if(sum.empty()) return 0;
  if(sum.size() < f || sum.size() < l ) return -1;
  priority_queue<int , vector<int> , greater<int>> pq;
  for(int n:sum) {
    pq.push(n);
    if(pq.size() > l) {
      pq.pop();
    } 
  }
  int ans = 0;
  int c = 0;
  while(!pq.empty()) {
    if(c>f || c==f) ans+= pq.top();
    pq.pop();
    c++;
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