#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
  if (ransomNote.size() != magazine.size()) return false;
  unordered_map<char, int> mp;
  for (auto ch : ransomNote) {
    mp[ch]++;
  }
  for (auto ch : magazine) {
    if (mp.find(ch) != mp.end()) {
      mp[ch]--;
      if (mp[ch] == 0) {
        mp.erase(ch);
      }
    }
  }
  return mp.empty();
}
unordered_map<int, int> mp;
TreeNode* solve(vector<int> inorder, vector<int> postorder, int instart,
                int inEnd, int index) {
  if (instart > inEnd) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(postorder[index--]);
  int pos = mp[postorder[index]];

  root->left = solve(inorder, postorder)
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  int index = n - 1;
  int n = postorder.size();

  for (int i = 0; i < inorder.size(); i++) {
    mp[inorder[i]] = i;
  }
  return solve(inorder, postorder, 0, postorder.size() - 1, index);
}
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
 public:
  unordered_set<int> elements;
  void dobfs(TreeNode* root, int val) {
    if (!root) return;
    queue<int> q;
    q.push(root);
    root->val = 0;
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      elements.insert(node->val);
      if (node->val) {
        node->left->val = node->val * 2 + 1;
        q.push(node->left);
      }
      if (node->right) {
        node->right->val = 2 * node->val + 2;
        q.push(node->right);
      }
    }
  }
  FindElements(TreeNode* root) { dobfs(root, root->val); }

  bool find(int target) { return elements.find(target) != elements.end(); }
};

class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
      num[i] += nums[i - 1];
    }
    int ans = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      ans = min(ans, nums[i]);
    }
    if (ans >= 0) return 1;
    return -ans + 1;
  }
};

bool hasSubarrayWithSumk(vector<int> v, int k) {
  unordered_map<int, int> mp;
  mp[0] = 1;
  int sum = 0;
  for (int num : v) {
    sum += num;

    if (mp.find(sum - k) != mp.end()) {
      return true;
    }
    mp[sum]++;
  }
}

int longestSubarrayWithSumk(vector<int>& v, int k) {
  unordered_map<int, int> mp;
  int sum = 0, length = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];

    if (sum == k) {
      length = i + 1;
    }

    if (mp.find(sum - k) != mp.end()) {
      length = max(length, i - mp[sum]);
    }
    if (mp.find(sum) == mp.end()) {
      mp[sum]++;
    }
    return length;
  }
}

int countSubarraysWithSum(vector<int>& a, int k) {
  unordered_map<int, int> mp;
  mp[0] = 1;
  int sum = 0, count = 0;
  mp[0] = 1;
  for (int n : a) {
    sum += n;
    if (mp.find(sum - k) != mp.end()) {
      count += mp[sum - k];
    }
    mp[sum]++;
  }
}

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int count = 0, longest = 0;

    for (int num : s) {
      if (!s.count(num + 1)) {
        int start = num;
        int longe = 1;
        while (s.count(start + 1)) {
          longe += 1;
          start++;
        }
        longest = max(longest, longe);
      }
    }
    return longest;
  }
};

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int value = abs(nums[i]) - 1;
      if (nums[value] < 0)
        res.push_back(abs(nums[i]));
      else {
        nums[value] *= -1;
      }
    }
    return res;
  }
};

class Solution {
 public:
  bool isPalindrome(string s) {
    int start = 0, end = s.size() - 1;
    while (start <= end) {
      if (!isalnum(s[start])) start++;
      if (!alnum(s[end])) end--;
      if (tolower(s[start]) != tolower(s[end]))
        return false;
      else {
        start++;
        end--;
      }
    }
    return true;
  }
};

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int sum = 0, maxlen = INT_MIN;
    unordered_map<int, int> prefixMap({0, -1});

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (prefixMap.count(sum)) {
        maxlen = max(maxlen, i - prefixMap[sum]);
      }
      prefixMap[sum] = i;
    }
    return maxlen;
  }
};

void solving() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n - 1; i++;) cin >> a[i];
  long long curr = accumulate(begin(a), end(a), 0);
  long long total = (long long)(n * (n + 1) / 2);
  cout << total - curr << endl;
}

class Solution {
 public:
  typedef pair<int, int> PI;
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++) {
      mp[nums[i]]++;
    }
    vector<int> answer;
    auto solver = [&](unordered_map<int, int>& mp) {
      priority_queue<PI> pq;
      for (auto it : mp) {
        pq.push({it.second, it.first});
      }
      int sum = 0, count = 0;
      while (!pq.empty() && count < x) {
        PI it = pq.top();
        pq.pop();
        sum += it.second * it.first;
        count++;
      }
      return sum;
    };
    answer.push_back(solver(mp));
    for (int i = 1; i <= n - k; i += 1) {
      int removingElement = nums[i - 1];
      int addingElement = nums[i + k - 1];

      if (--mp[removingElement] == 0) {
        mp.erase(removingElement);
      }

      mp[addingElement]++;

      answer.push_back(solver(mp));
    }
    return answer;
  }
};

class Solution {
 public:
  void solveKrde(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp,
                 vector<bool>& used) {
    if (temp.size() == nums.size()) {
      res.push_back(temp);
      return;
    }
    for (int i = 0; i < nums.size(); i += 1) {
      if (used[i]) continue;
      if (nums[i] == nums[i - 1] && !used[i - 1] && i > 0) {
        continue;
      }
      used[i] = true;
      temp.push_back(nums[i]);
      solveKrde(nums, res, temp, used);
      used[i] = false;
      temp.pop_back();
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    vector<bool> used(nums.size(), false);
    sort(begin(nums), end(nums));
    solveKrde(nums, res, temp, used);
    return res;
  }
};

class Solution {
 public:
  void solveKrdeBhai(vector<vector<int>>& res, vector<int>& temp,
                     unordered_map<int, int>& freq, int& n, int idx) {
    if (idx == n) {
      res.push_back(temp);
    }
    for (auto it : mp) {
      temp.push_back(it.first);
      mp[it.first]--;
      solveKrdeBhai(res, temp, freq, n, idx + 1);
      temp.pop_back();
      mp[it.first]++;
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    int n = nums.size();
    unordered_map<int, int> freq;
    for (int c : nums) {
      freq[c]++;
    }
    solveKrdeBhai(res, temp, freq, n, 0);
    return res;
  }
};


