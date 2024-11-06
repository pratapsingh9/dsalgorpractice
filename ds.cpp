#include <bits/stdc++.h>
using namespace std;
class LRUCache {
 public:
  vector<pair<int, int>> cache;
  int n;
  LRUCache(int capacity) { this->n = capacity; }

  int get(int key) {
    for (int i = 0; i < cache.size(); i++) {
      if (cache[i].first == key) {
        int val = cache[i].second;
        pair<int, int> tmp = cache[i];
        cache.erase(cache.begin() + i);
        cache.push_back(tmp);
        return val;
      }
    }
    return -1;
  }

  void put(int key, int value) {
    for (int i = 0; i < cache.size(); i++) {
      if (cache[i].first == key) {
        cache.erase(cache.begin() + i);
        cache.push_back({key, value});
        return;
      }
    }
    if (n == cache.size()) {
      cache.erase(cache.begin());
      cache.push_back({key, value});
    } else {
      cache.push_back({key, value});
    }
  }
};

class LRUCache {
 public:
  vector<pair<int, int>> capacity;
  int n;
  LRUCache(int capacity) { this->n = capacity; }

  int get(int key) {
    for (int i = 0; i < capacity.size(); i++) {
      if (capacity[i].first == key) {
        int val = capacity[i].second;
        pair<int, int> temp = capacity[i];
        capacity.erase(capacity.begin() + i);
        capacity.push_back(temp);
        return val;
      }
    }
    return -1;
  }

  void put(int key, int value) {
    for (int i = 0; i < capacity.size(); i++) {
      if (capacity[i].first == key) {
        capacity.erase(capacity.begin() + i);
        capacity.push_back({key, value});
        return;
      }
    }
    if (capacity.size() == n) {
      capacity.erase(capacity.begin());
      capacity.push_back({key, value});
    } else {
      capacity.push_back({key, value});
    }
  }
};