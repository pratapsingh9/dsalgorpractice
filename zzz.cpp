#include <bits/stdc++.h>
#include <strings.h>
using namespace std;

class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    set<string> st;
    for (int i = 0; i < emails.size(); i++) {
      string email = emails[i];
      string cleanstring = " ";
      for (int j = 0; j < email.size(); j++) {
        if (email[j] == '.')
          continue;
        else if (email[j] == '@' || email[j] == '+') {
          break;
        }
        cleanstring += string[j];
      }
      cleanstring += email.substr(email.find(@), email.size());
      st.insert(cleanstring);
    }
    return st.size();
  }
};

class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    int n = nums.size() / 2;
    vector<int> vec(10001, 0);
    for (int i = 0; i < nums.size(); i++) {
      vec[nums[i]]++;
      if (vec[i] == n) {
        return i;
      }
    }
    return -1;
  }
};

class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    vector<int> hashing(26, 0);
    for (int i = 0; i < text.size(); i++) {
      hashing[text[i] - 'a']++;
    }

    int countB = hashing['b' - 'a'];
    int countA = hashing['a' - 'a'];
    int countL = hashing['l' - 'a'] / 2;
    int countO = hashing['o' - 'a'] / 2;
    int countN = hashing['n' - 'a'];

    return min({countB, countA, countL, countN, countO});
  }
};


class Solution {
 public:
  int findLucky(vector<int>& arr) {
    vector<int> hashing(501, 0);
    for (int x : arr) {
      hashing[x]++;
    }
    int largest = -1;
    for (int i = 1; i < 501; i++) {
      if (hashing[i] == i) {
        largest = max(largest, i);
      }
    }
    return largest;
  }
};

class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2) return true;
    vector<int> diffIndices;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i]) {
        diffIndices.push_back(i);
        if (diffIndices.size() > 2) return false;
      }
    }
    return diffIndices.size() == 2 &&
           s1[diffIndices[0]] == s2[diffIndices[1]] &&
           s1[diffIndices[1]] == s2[diffIndices[0]];
  }
};
class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> st(nums.begin(), nums.end());
    while (st.find(original) != st.end()) {
      original *= 2;
    }

    return original;
  }
};

class Solution {
 public:
  int solve(vector<int>& nums, int index, int depth, int sum, int target) {
    if (depth == 3) {
      for (int i = index; i < nums.size(); ++i) {
        if (nums[i] == target) return 1;
      }
      return 0;
    }
    if (index >= nums.size()) return 0;
    int include = solve(nums, index + 1, depth + 1, sum + nums[index], target);
    int exclude = solve(nums, index + 1, depth, sum, target);
    return include + exclude;
  }

  int countQuadruplets(vector<int>& nums) { return solve(nums, 0, 0, 0, 0); }
};

class Solution {
 public:
  int countKDifference(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      int diff = nums[i] - k;
      if (mp.find(diff) != mp.end()) {
        ans += mp[diff];
      }
      if (mp.find(nums[i] + k) != mp.end()) {
        ans += mp[nums[i] + k];
      }
      mp[nums[i]]++;
    }
    return ans;
  }
};
class Solution {
 public:
  int numDifferentIntegers(string word) {
    unordered_set<string> mywords;
    int n = word.length();
    int i = 0;
    while (i < n) {
      if (!isdigit(word[i])) {
        i++;
        continue;
      }

      string num;
      while (i < n && isdigit(word[i])) {
        num += word[i];
        i++;
      }

      while (num.size() > 1 && num[0] == '0') {
        num.erase(num.begin());
      }
      mywords.insert(num);
    }
    return mywords.size();
  }
};

void storeIndex(int index, vector<int>& index) { if (index == indcex1) }

class Solution {
 public:
  void inorder(TreeNode* root, int prev, int ans) {
    if (!root) return;
    inorder(root->left, prev, ans);
    if (prev != -1) {
      ans = min(ans, root->val - prev);
    }
    prev = root->val;
    inorder(root->right, prev, ans);
  }
  int minDiffInBST(TreeNode* root) {
    int prev = -1;
    int ans = INT_MAX;
    inorder(root, prev, ans);
    return ans;
  }
};

class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    if (root == NULL) {
      return false;
    }

    queue<pair<TreeNode*, TreeNode*>> q;
    q.push({root, NULL});

    while (!q.empty()) {
      int size = q.size();
      TreeNode* parentX = NULL;
      TreeNode* parentY = NULL;
      for (int i = 0; i < size; i++) {
        auto [node, parent] = q.front();
        q.pop();
        if (node->val == x) {
          parentX = parent;
        }
        if (node->val == y) {
          parentY = parent;
        }
        if (node->left) {
          q.push({node->left, node});
        }
        if (node->right) {
          q.push({node->right, node});
        }
      }

      if (parentX && parentY) {
        return parentX != parentY;
      }

      if (parentX || parentY) {
        return false;
      }
    }
    return false;
  }
};

class Solution {
 public:
  bool TryWorking(vector<int>& root) {
    if (!root) return false;
    if (!root || root->right) return false;
    if (root->right || root->left) {
      root->left = TryWorking(root->left);
    }
  }
}

class Solution {
 public:
  bool evaluateTree(TreeNode* root) {
    if (!root) return false;
    if (!root->left && !root->right) {
      return root->val;
    }
    if (root->val == 2) {
      return evaluateTree(root->left) || evaluateTree(root->right);
    }
    if (root->val == 3) {
      return evaluateTree(root->right) && evaluateTree(root->right);
    }
    return false;
  }
};

class Solution {
 public:
  const int MOD = 1e9 + 7;
  int solve(int length, int low, int high, int zero, int one,
            vector<int>& memoDp) {
    if (length > high) return 0;
    if (memoDp[length] != -1) return memoDp[length];
    long long ans = (length >= low) ? 1 : 0;
    if (length + zero <= high)
      ans = (ans + solve(length + zero, low, high, zero, one, memoDp)) % MOD;
    if (length + one <= high)
      ans = (ans + solve(length + one, low, high, zero, one, memoDp)) % MOD;
    memoDp[length] = ans;
    return ans;
  }
  int countGoodStrings(int low, int high, int zero, int one) {
    if (low > high || zero <= 0 || one <= 0) return 0;
    vector<int> memoDp(high + 1, -1);
    return solve(0, low, high, zero, one, memoDp);
  }
};

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    int totalCount = 0;
    int uniqueCount = 1;
    int avalibleCount = 9;

    for (int i = 1; i <= 9; i++) {
      uniqueCount *= avalibleCount;
      if (i > 1) {
        avalibleCount--;
      }
      totalCount += uniqueCount;
    }

    return totalCount;
  }
};

class Solution {
 public:
  void solve(vector<int>& nums, int& ans, int index, int sum) {
    if (index >= nums.size()) {
      if (sum % 3 == 0) {
        ans = max(ans, sum);
      }
      return;
    }
    solve(nums, ans, index + 1, sum + nums[index]);
    solve(nums, ans, index + 1, sum);
  }
  int maxSumDivThree(vector<int>& nums) {
    int ans = 0;
    vector<vector<int>> memoDp(nums.size(), vector<int>());
    solve(nums, ans, 0, 0);
    return ans;
  }
};
class Solution {
 public:
  int solve(vector<int>& nums, int index, int remainder,
            vector<vector<int>>& memo) {
    if (index >= nums.size()) {
      return remainder == 0 ? 0 : INT_MIN;
    }
    if (memo[index][remainder] != INT_MIN) {
      return memo[index][remainder];
    }
    int include = solve(nums, index + 1, (remainder + nums[index]) % 3, memo);
    if (include != INT_MIN) {
      include += nums[index];
    }
    int exclude = solve(nums, index + 1, remainder, memo);
    memo[index][remainder] = max(include, exclude);
    return memo[index][remainder];
  }

  int maxSumDivThree(vector<int>& nums) {
    vector<vector<int>> memo(nums.size(), vector<int>(3, INT_MIN));
    return solve(nums, 0, 0, memo);
  }
};

class Solution {
 public:
  int numSquares(int n) { return solve(n); }
  int solve(int n) {
    if (n == 0) return 0;
    if (n <= 0) return INT_MAX;
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++) {
      int include = solve(n - i * i);
      int exclude =
    }
  }
};










class zzz
{
private:
  /* data */
public:
  zzz(/* args */);
  ~zzz();
};

zzz::zzz(/* args */)
{
}

zzz::~zzz()
{
}
