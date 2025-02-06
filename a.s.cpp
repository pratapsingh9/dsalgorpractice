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

class Solution{
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
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
          /* code */
          total += nums[i];
        }

        long long lsum = 0 ;
        int count = 0;

        for (size_t i = 0; i < nums.size()-1; i++)
        {
          /* code */
          lsum+= nums[i];
          total -= nums[i];
          if(lsum>=total){
            count++;
          } 
        }
        return count;
        
    }
};

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int t = 0;
        for(int i = 0; i<nums.size(); i++) t+= nums[i];


        int lsum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
          /* code */
          t-= nums[i];

          if(lsum=t) return i;

          lsum+= nums[i];
        }

        return -1;
        
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i<nums.size(); i++) total+= nums[i];

        int lsum = 0;
        for(int i = 0; i<nums.size(); i++){
          if(lsum == total - lsum - nums[i]) return i;
          lsum+= nums[i];
        }
        return  -1;
    }
};

class Solution {
public:
    typedef long long ll;
    int minimumAverageDifference(vector<int>& nums) {
        ll total  = 0;
        for(int n:nums) total+= n;

        ll lsum = 0;
        int n = nums.size();
        int res = 0;
        ll minDiff = LLONG_MAX;

        for (size_t i = 0; i < nums.size(); i++)
        {
          lsum += nums[i];
          ll rsum = total - lsum;
          ll lavg = lsum / (i+1);
          ll ravg =  (i==n-1) ? 0 : rsum / (n-i-1);
          ll diff = abs(lavg - ravg);

          if (diff<minDiff)
          {
            minDiff= diff;
            res=i;
          }
        }
          return res;
        
    }
};