#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findMinDistance(vector<string>& words, string word1, string word2) {
  int index1 = -1, index2 = -1;
  int minDistance = INT_MAX;
  for (int i = 0; i < words.size(); i++) {
    if (words[i] == word1) {
      index1 = i;
    }
    if (words[i] == word2) {
      index2 = i;
    }
    if (index1 != -1 && index2 != -1) {
      minDistance = min(minDistance, abs(index1 - index2));
    }
  }
  return minDistance;
}

class Solution {
 public:
  vector<string> removeAnagrams(vector<string>& words) {
    vector<string> answer;
    unordered_map<string, bool> mp;
    for (string w : words) {
      string reversedword = w;
      sort(reversedword.begin(), reversedword.end());
      if (mp.find(reversedword) == mp.end()) {
        answer.push_back(w);
        mp[reversedword] = true;
      }
    }
    return answer;
  }
};

class Solution {
 public:
  int solve(vector<string>& digits, int n, vector<int>& memo, long current) {
    if (current > n) return 0;
    if (memo[current] != -1) return memo[current];
    int count = 0;
    if (current > 0) count++;
    for (const string& str : digits) {
      int digit = str[0] - '0';
      count += solve(digits, n, memo, current * 10 + digit);
    }
    memo[current] = count;
    return memo[current];
  }
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    vector<int> memo(n + 1, -1);
    return solve(digits, n, memo, 0);
  }
};

class Solution {
 public:
  string reverseStr(string& s, int k) {
    int n = s.size();
    int j = 0;
    while (j < n) {
      int a = j;
      int b = min(j + k - 1, n - 1);
      while (a < b) {
        swap(s[a], s[b]);
        a++;
        b--;
      }
      j += 2 * k;
    }
    return s;
  }
};

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
      if(k==0) {
        return nums1 == nums2  ? 0 : -1;
      }
      
    }
};
