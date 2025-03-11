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

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vecto
  }
};

class Solution {
 public:
  int splitNum(int num) {
    string res = to_string(num);
    sort(begin(res), end(res));
    string num1 = "", num2 = "";
    for (size_t i = 0; i < res.size(); i++) {
      /* code */
      if (i % 2 == 0) {
        num1 += res[i];
      } else {
        num2 += res[i];
      }
    }
    return stoi(num1) + stoi(num2);
  }
};

class Solution {
 public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                  vector<vector<int>>& nums2) {
    map<int, int> mp;
    for (auto& it : nums1) {
      mp[it[0]] = it[1];
    }
    for (auto it : nums2) {
      mp[it[0]] += it[1];
    }
    vector<vector<int>> res;
    for (auto it : mp) {
      res.push_back({it.first, it.second});
    }
    return res;
  }
};

class Solution {
 public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                  vector<vector<int>>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int i = 0;
    int j = 0;
    vector<vector<int>> res;
    while (i < m && j < n) {
      if (nums1[i][0] > nums2[j][0]) {
        res.push_back(nums2[j]);
        j++;
      } else if (nums1[i][0] < nums2[j][0]) {
        res.push_back(nums1[i]);
        i++;
      } else {
        res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
        i++;
        j++;
      }
    }
    while (i < m) {
      res.push_back(nums1[i]);
      i++;
    }
    while (j < n) {
      res.push_back(nums2[j]);
      j++;
    }
    return res;
  }
};

class Solution {
 public:
  int largestInteger(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, set<int>> mp;
    for (int i = 0; i < n - k; i++) {
      for (int j = i; j < i + k; j++) {
        mp[nums[j]].insert(i);
      }
    }
    int maxi = INT_MIN;
    for (auto it : mp) {
      int ele = it.first;
      int elements = it.second;
      if (elements == 1) {
        maxi = max(maxi, ele);
      }
    }
    return maxi;
  }
};

class Solution {
 public:
  int solve(int prev, int curr, vector<int>& nums, vector<vector<int>>& dp) {
    int n = nums.size();
    if (curr == n) return nums[prev];
    if (curr == n - 1) return max(nums[prev], nums[curr]);
    if (dp[prev][curr] != -1) return dp[prev][curr];
    int first =
        max(nums[curr], nums[curr + 1]) + solve(prev, curr + 2, nums, dp);
    int second =
        max(nums[prev], nums[curr + 1]) + solve(curr, curr + 2, nums, dp);
    int third =
        max(nums[prev], nums[curr]) + solve(curr + 1, curr + 2, nums, dp);
    return dp[prev][curr] = min({first, second, third});
  }

  int minCost(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(0, 1, nums, dp);
  }
};

class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    sort(ages.begin(), ages.end());
    int ans = 0;

    for (int i = 0; i < ages.size(); i++) {
      int age = ages[i];
      if (age <= 14) continue;

      int left =
          upper_bound(ages.begin(), ages.end(), 0.5 * age + 7) - ages.begin();
      int right = upper_bound(ages.begin(), ages.end(), age) - ages.begin();

      ans += right - left - 1;
    }

    return ans;
  }
};

class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    unordered_map<char, vector<string>> mp;
    for (string word : words) {
      mp[word[0]].push_back(word);
    }
  }
};

class Solution {
 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (m == 0 || n == 0) return false;

    vector<vector<pair<int, int>>> moves = {{},
                                            {{0, -1}, {0, 1}},
                                            {{-1, 0}, {1, 0}},
                                            {{0, -1}, {1, 0}},
                                            {{0, 1}, {1, 0}},
                                            {{-1, 0}, {0, -1}},
                                            {{-1, 0}, {0, 1}}};

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      if (r == m - 1 && c == n - 1) return true;

      for (auto& move : moves[grid[r][c]]) {
        int nr = r + move.first, nc = c + move.second;

        if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
          for (auto& back : moves[grid[nr][nc]]) {
            if (nr + back.first == r && nc + back.second == c) {
              visited[nr][nc] = true;
              q.push({nr, nc});
              break;
            }
          }
        }
      }
    }
    return false;
  }
};

pair<int, int> secondSmallestlargest(vector<int>& nums) {
  int smallest = INT_MAX, secondsmall = INT_MAX;
  int largest = INT_MIN, secondlarget = INT_MIN;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < smallest) {
      secondsmall = smallest;
      smallest = nums[i];
    } else if (nums[i] < secondsmall && nums[i] != smallest) {
      secondsmall = nums[i];
    }

    if (nums[i] > largest) {
      secondlarget = largest;
      largest = nums[i];
    } else if (nums[i] > secondlarget && nums[i] < largest) {
      secondlarget = nums[i];
    }
  }
  return {secondsmall, secondlarget};
}

class Solution {
 public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_set<int> st;
    int a = -1, b = -1;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int var = grid[i][j];
        if (st.count(var)) {
          a = var;
        } else {
          st.insert(var);
        }
      }
    }
    for (int i = 1; i <= n * n; i += 1) {
      if (st.find(i) == st.end()) {
        b = i;
        break;
      }
    }
    return {a, b};
  }
};

class Solution {
 public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    int size = n * n;
    vector<int> count(size + 1, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        count[grid[i][j]]++;
      }
    }
    int a = -1, b = -1;
    for (int i = 1; i <= size; i++) {
      if (count[i] == 2) {
        a = num;
      } else if (count[i] == 0) {
        b = num
      }
    }
    return {a, b};
  }
};

class Solution {
 public:
  void solveKr(string& s, vector<string>& result, int idx) {
    if (idx == s.size()) {
      result.push_back(s);
      return;
    }
    if (isalpha(s[idx])) {
      s[idx] = toupper(s[idx]);
      solve(s, result, idx + 1);
      s[idx] = tolower(s[idx]);
      solve(s, result, idx + 1);
    } else {
      solveKr(s, result, idx + 1);
    }
  }
  vector<string> letterCasePermutation(string s) {
    vector<string> res;
    solveKr(s, res, 0);
    return res;
  }
};

class Solution {
 public:
  void solve(string& s, int idx, vector<string>& result, string current) {
    if (idx == s.size()) {
      result.push_back(current);
      return;
    }

    if (isalpha(s[idx])) {
      solve(s, idx + 1, result, current + (char)tolower(s[idx]));
      solve(s, idx + 1, result, current + (char)toupper(s[idx]));
    } else {
      solve(s, idx + 1, result, current + s[idx]);
    }
  }
  vector<string> letterCasePermutation(string s) {
    vector<string> res;
    solve(s, 0, res, "");
    return res;
  }
};

class Solution {
 public:
  int minimumRecolors(string blocks, int k) {
    if (k > blocks.size()) return 0;
    int res = 0, countWhite = 0;
    for (int i = 0; i < k; i++) {
      if (blocks[i] == 'W') countWhite++;
    }
    res = countWhite;
    for (int i = k; i < blocks.size(); i++) {
      if (blocks[i] == 'W') countWhite++;
      if (blocks[i - k] == 'W') countWhite--;

      res = min(res, countWhite);
    }
    return res;
  }
};

string simpleCipher(string input, int k) {
  string ans = "";
  int adjustedShift = k % 26;
  for (char c : input) {
    char an = (char)('A' + (ch - 'A' - adjustedShift + 26) % 26);
    ans += an;
  }
  return ans;
}

class Solution {
 public:
  int solve(int l, int r, vector<vector<int>>& dp) {
    if (l >= r) return 0;
    if (dp[l][r] != 0) return dp[l][r];
    int minCost = INT_MAX;
    for (int k = l; k <= r; k++) {
      int cost = k + max(solve(l, k - 1), solve(k + 1, r));
      minCost = min(minCost, cost);
    }
    dp[l][r] = minCost;
    return dp[l][r];
  }

  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    return solve(1, n), dp;
  }
};

class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    priority_queue<string> pq;
    for (string& v : votes) pq.push(v);
    return pq.top();
  }
};

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int left = 0;
    int a = 0, b = 0, c = 0;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a')
        a++;
      else if (s[i] == 'b')
        b++;
      else
        c++;

      while (a > 0 && b > 0 && c > 0) {
        res += s.size()-i;
        if (s[left] == 'a') a--;
        if (s[left] == 'b')
          b--;
        else
          c--;
        left++;
      }
    }
    return res;
  }
};