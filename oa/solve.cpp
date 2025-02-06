#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  int idxI = 0;
  int maxprice = 0;
  for (int i = 0; i < n; i++) {
    /* code */
    int total = 0;
    for (int j = 1; j <= i; j++) {
      /* code */
      total += (x - (j - 1));
    }

    for (int j = i + 1; j <= n; j += 1) {
      total += y;
    }

    if () }
}

int main() {
  int N, x, y;
  cin >> N >> x >> y;

  int maxI = 0;
  long long maxPrice = 0;

  for (int i = 0; i <= N; i++) {
    long long total = 0;
    for (int j = 1; j <= i; j++) {
      total += (x - (j - 1));
    }
    for (int j = i + 1; j <= N; j++) {
      total += y;
    }

    if (total > maxPrice) {
      maxPrice = total;
      maxI = i;
    }
  }

  cout << maxI << " " << maxPrice << endl;
  return 0;
}

class Solution {
 public:
  int dp[304][304];

  int solve(vector<int>& nums, int left, int right) {
    if (left > right) return 0;
    if (dp[left][right] != -1) return dp[left][right];

    int maxCoins = 0;
    for (int i = left; i <= right; i++) {
      int coins = nums[left - 1] * nums[i] * nums[right + 1] +
                  solve(nums, left, i - 1) + solve(nums, i + 1, right);
      maxCoins = max(maxCoins, coins);
    }

    return dp[left][right] = maxCoins;
  }

  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    memset(dp, -1, sizeof(dp));
    return solve(nums, 1, nums.size() - 2);
  }
};

class Solution {
public:
    int computeCost(vector<int>& piles, int left, int right, int k, vector<int>& sumPrefix, vector<vector<int>>& memo) {
        if (left >= right) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        
        int minCost = INT_MAX;
        for (int mid = left; mid < right; mid += (k - 1)) {
            int cost = computeCost(piles, left, mid, k, sumPrefix, memo) + computeCost(piles, mid + 1, right, k, sumPrefix, memo);
            minCost = min(minCost, cost);
        }

        if ((right - left) % (k - 1) == 0) {
            minCost += sumPrefix[right + 1] - sumPrefix[left];
        }

        return memo[left][right] = minCost;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;

        vector<int> sumPrefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sumPrefix[i] = sumPrefix[i - 1] + stones[i - 1];
        }

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return computeCost(stones, 0, n - 1, k, sumPrefix, memo);
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty() || words.empty()) {
          return result;
        }

        int wordLen = words[0].size();
        int count = words.size();
        
        int totalNeeded = wordLen*count;
        unordered_map<string,int> wordMap;

        for(string &word: words) {
          wordMap[word]++;
        }

    }
};

class Solution {
public:
    bool palindrome(string &s , int i , int j ) {
      while(i<j) {
        if(s[i]!=s[j]) return false;
        i++; j--;
      }
      return true;
    }
    void solved(string &s , vector<vector<string>> &res , vector<string> current, int index) {
      if(index==s.size()) {
        res.push_back(current);
        return ;
      }

      for(int i = index; i<s.size(); i++) {
        if(palindrome(s,index,i)) {
          current.push_back(s.substr(index,i-index+1));
          solved(s,res,current,index+1);-
          current.pop_back();
        }
      }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        solved(s,res,current,0);
        return res;
    }
};

int findFirstAndLast(vector<int> &array , int searchElement , bool first) {
  int start = 0 , end = array.size()-1;
  int ans = -1;
  while(start<end) {
    int mid = start + (end-start)/2;
    if(searchElement > array[mid])  {
      start=mid+1;
    }else if(searchElement < array[mid]) {
      end=mid-1;
    }else{
      ans=mid;
      if(first) {
        end=mid-1;
      }else{
        start=mid+1;
      }
    }
  }
  return ans;
}



