#include <bits/stdc++.h>
using namespace std;

long long sumOfDistinctCounts(const vector<int>& categories) {
  unordered_map<int, int> lastSeen;
  int start = 0;
  long long result = 0;

  for (int end = 0; end < categories.size(); ++end) {
    int current = categories[end];
    if (lastSeen.count(current) && lastSeen[current] >= start) {
      start = lastSeen[current] + 1;
    }
    lastSeen[current] = end;
    result += (end - start + 1);
  }
  return result;
}

int main() {
  vector<int> categories = {1, 2, 1};
  cout << "Output: " << sumOfDistinctCounts(categories) << endl;
  return 0;
}

vector<int> subarrayWithSUm(vector<int> nums, int target) {
  unordered_map<int, int> mp;
  int cumSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    cumSum += nums[i];
    if (cumSum == target) return {0, i};
    if (mp.find(target - cumSum) != mp.end()) {
      return {mp[target - cumSum], i};
    }
    mp[cumSum] = i;
  }
  return vector<int>{};
}

bool isIsomorphic(string a, string b) {
  if (a.size() != b.size()) return false;

  unordered_map<char, char> atob, btoa;

  for (int i = 0; i < a.size(); i++) {
  }
}

class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxbeatury = 1;
    int left = 0;
    for (int i = 0; i < n; i++) {
      /* code */
      while (nums[i] - nums[left] > 2 * k) {
        left++;
      }
      maxbeatury = max(maxbeatury, i - left + 1);
    }
    return maxbeatury;
  }
};
class Solution {
 public:
  int fillCups(vector<int>& amount) {
    sort(amount.begin(), amount.end());
    if (amount[2] > amount[0] + amount[1]) return amount[2];

    return (amount[0] + amount[1] + amount[2] + 1) / 2;
  }
};

class Solution {
 public:
  int fillCups(vector<int>& amount) {
    priority_queue<int> pq;
    for (int x : amount) {
      if (x > 0) pq.push(x);
    }
    int time = 0, ;
    while (!pq.empty()) {
      int first = pq.top();
      pq.pop();
      if (!pq.empty()) {
        int second = pq.top();
        pq.pop();
        if (--first > 0) pq.push(first);
        if (--second > 0) pq.push(second);
      } else {
        if (--first > 0) pq.push(first);
      }
      time++;
    }
    return time;
  }
};

class Solution {
 public:
  bool compareOperator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  }
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (int x : arr) {
      mp[x]++;
    }
    vector<pair<int, int>> vec;

    for (auto& entry : mp) {
      vec.push_back({entry.second, entry.first});
    }

    sort(vec.begin(), vec.end(), compareOperator);

    int target = arr.size() / 2;
    int answer = 0;
    int removed = 0;
    for (auto& p : vec) {
      removed += p.first;
      answer++;
      if (removed >= target) break;
    }
    return answer;
  }
};

class Solution {
 public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> freq;
    for (int x : barcodes) {
      freq[x]++;
    }

    vector<pair<int, int>> freqvec;
    for (auto& it : freq) {
      freqvec.push_back({it.second, it.first});
    }

    sort(freqvec.begin(), freqvec.end());

    vector<int> result(barcodes.size(), 0);
    int index = 0;

    for (auto& [count, barcode] : freqvec) {
      for (int i = 0; i < count; i++) {
        /* code */
        result[index] = barcode;
        index += 2;
        if (index >= barcodes.size()) {
          index = 1;
        }
      }
    }
    return result;
  }
};

class Solution {
 public:
  typedef pair<int, string> P;
  vector<string> topKFrequent(vector<string>& words, int k) {
    if (words.empty()) return {};
    unordered_map<string, int> mp;
    for (string it : words) {
      mp[it]++;
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<string> result;
    for (auto it : mp) {
      pq.push({it.second, it.first});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    while (!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

class Solution {
 public:
  int maxProfitHelper(int day, bool canBuy, const vector<int>& prices,
                      vector<unordered_map<bool, int>>& memoDp) {
    if (day >= prices.size()) return 0;
    if (memoDp[day].count(canBuy)) return memoDp[day][canBuy];

    if (canBuy) {
      int buy = -prices[day] + maxProfitHelper(day + 1, false, prices, memoDp);
      int skip = maxProfitHelper(day + 1, true, prices, memoDp);
      memoDp[day][canBuy] = max(buy, skip);
    } else {
      int sell = prices[day] + maxProfitHelper(day + 2, true, prices, memoDp);
      int skip = maxProfitHelper(day + 1, false, prices, memoDp);
      memoDp[day][canBuy] = max(sell, skip);
    }

    return memoDp[day][canBuy];
  }

  int maxProfit(vector<int>& prices) {
    vector<unordered_map<bool, int>> memoDp(prices.size());
    return maxProfitHelper(0, true, prices, memoDp);
  }
};
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int day = n - 1; day >= 0; day--) {
      dp[day][1] = max(-prices[day] + dp[day + 1][0], dp[day + 1][1]);
      dp[day][0] = max(prices[day] + day[day + 2][1], dp[day + 1][1]);
    }
    return dp[0][1];
  }
};

class Solution {
 public:
  int maximumPopulation(vector<vector<int>>& logs) {
    vector<int> popChanged(2051, 0);
    for (const auto& log : logs) {
      popChanged[log[0]]++;
      popChanged[log[1]]--;
    }
    int currentPopulation = 0, maxPopulation = 0, maxyear = 0;

    for (int year = 1950; year < 2051; year++) {
      currentPopulation += popChanged[year];
      if (currentPopulation > maxPopulation) {
        maxPopulation = currentPopulation;
        maxyear = year;
      }
    }
    return maxyear;
  }
};

class Solution {
 public:
  int numberOfPoints(vector<vector<int>>& nums) {
    vector<bool> isCovered(101, false);
    for (const auto& num : nums) {
      int start = num[0];
      int end = num[1];
      for (int i = start; i < end; i++) {
        isCovered[i] = true;
      }
    }
    int c = 0;
    for (int n : isCovered) {
      if (n) c++;
    }
    return c;
  }
};

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> passengerPrefix(1001, 0);
    for (const auto& query : trips) {
      int passenger = query[0];
      int start = query[1];
      int end = query[2];
      passengerPrefix[start] += passenger;
      passengerPrefix[end] -= passenger;
    }
    int currentPassenger = 0;
    for (int i = 0; i < 1001; i++) {
      currentPassenger += passengerPrefix[i];
      if (currentPassenger > capacity) return false;
    }
    return true;
  }
};

class MyCalendarTwo {
 public:
  vector<int> events;
  MyCalendarTwo() { events.resize(1000001); }

  bool book(int startTime, int endTime) {
    events[startTime] += 1;
    events[endTime] -= 1;

    int activeEvents = 0;
    for (int time = 0; time < 1000001; time++) {
      activeEvents += events[time];
      if (activeEvents > 2) {
        events[startTime] -= 1;
        events[endTime] += 1;
      }
    }
    return true;
  }
};

class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.size();
    vector<int> prefix(n + 1, 0);
    for (const auto& shift : shifts) {
      int start = shift[0];
      int end = shift[1];
      int direction = shift[2];
      prefix[start] += (direction == 1) ? 1 : -1;
      prefix[end + 1] += (direction == 1) ? -1 : 1;
    }

    int netShift = 0;
    for (int i = 0; i < n; i++) {
      netShift += prefix[i];
      prefix[i] = netShift;
    }
    for (int i = 0; i < n; i++) {
      int shift = prefix[i] % 26;
      s[i] = ((s[i] - 'a' + shift + 26) % 26) + 'a';
    }
    return s;
  }
};

class Solution {
 public:
  string shiftingLetters(string s, vector<int>& shifts) {
    int n = s.size();
    for (int i = n - 2; i >= 0; --i) {
      shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
    }

    for (int i = 0; i < n; i++) {
      int shitng = shifts[i] % 26;
      s[i] = ((s[i] - 'a' + 26 + shitng) % 26) + 'a';
    }
    return s;
  }
};

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int n = s.size();
    int ones = 0, zeros = 0;
    int left = 0;
    int count = 0;

    for (int right = 0; right < n; right++) {
      if (s[right] == '0')
        zeros++;
      else
        ones++;

      while (ones < zeros * zeros) {
        if (s[left] == '0')
          ones--;
        else
          zeros--;
        left++;
      }

      count += (right - left + 1);
    }
    return count;
  }
};

class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    long long pair = 0, result = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); right += 1) {
      pair += mp[nums[right]]++;
      while (pair >= k) {
        result += nums.size()
      }
    }
  }
};

class Solution {
 public:
  int partitionString(string s) {
    int ans = 1;
    unordered_set<char> st;
    for (char c : s) {
      if (st.count(c)) {
        ans++;
        st.clear();
      }
      st.insert(c);
    }
    return ans;
  }
};

class Solution {
 public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int l = 0, int r = tokens.size() - 1;
    int score = 0, maxscore = 0;
    while (l <= r) {
      if (power >= tokens[i]) {
        power -= tokens[i];
        score++;
        l++;
        maxscore = max(maxscore, score);
      } else if (score > 0) {
      }
    }
  }
};

class Solution {
 public:
  int minimumOperations(vector<vector<int>>& grid) {
    int rows = grid.size();
    int column = grid[0].size();
    int ans = 0;
    for (int col = 0; col < column; col++) {
      for (int row = 0; row < rows; row++) {
        if (grid[row][col] >= grid[row + 1][col]) {
          int diff = grid[row][col] - grid[row + 1][col] + 1;
          grid[row + 1][col] += diff;
          ans += diff;
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> freq1, freq2;
    for (const string word : words1) {
      freq1[word]++;
    }
    for (const string word : words2) {
      freq2[word]++;
    }
    int count = 0;
    for (const auto [word, count] : freq1) {
      if (count == 1 && freq2[word] == 1) {
        count++;
      }
    }
    return count;
  }
};

class Solution {
 public:
  int solve(int index, vector<int>& days, vector<int>& costs,
            vector<int>& memoDp) {
    if (index >= days.size()) {
      return 0;
    }

    if (memoDp[index] != -1) return memoDp[index];

    int oneDayPass = costs[0] + solve(index + 1, days, costs, memoDp);

    int i = index;
    while (i < days.size() && days[i] < days[index] + 7) {
      i++;
    }
    int sevenDayPass = costs[1] + solve(i, days, costs, memoDp);

    i = index;
    while (i < days.size() && days[i] < days[index] + 30) {
      i++;
    }
    int thirtyDayPass = costs[2] + solve(i, days, costs, memoDp);

    memoDp[index] = min({oneDayPass, sevenDayPass, thirtyDayPass});

    return memoDp[index];
  }
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> memoDp(days.size() + 1, -1);
    return solve(0, days, costs, memoDp);
  }
};

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n + 1, 0);
    for (int index = n - 1; index >= 0; index--) {
      int ondedaypass = costs[0] + dp[index + 1];

      int i = index;
      while (i < n && days[i] < days[index] + 7) {
        i++;
      }

      int weeklyPass = costs[1] + dp[i];

      i = index;
      while (i < n && days[i] < days[index] + 30) {
        i++;
      }

      int thirtyDayPass = costs[2] + dp[i];

      dp[index] = min({ondedaypass, weeklyPass, thirtyDayPass});
    }
    return dp[0];
  }
};

class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    unordered_map<char, int> mp;
    string row1 = "qwertyuiop";
    string row2 = "asdfghjkl";
    string row3 = "zxcvbnm";
    for (char c : row1) mp[c] = 0;
    for (char c : row2) mp[c] = 1;
    for (char c : row3) mp[c] = 2;
    vector<string> result;
    for (const string& word : words) {
      int row = mp[tolower(word[0])];
      bool isValid = true;
      for (char c : word) {
        if (mp[tolower(c)] != row) {
          isValid = false;
          break;
        }
      }
      if (isValid) result.push_back(word);
    }
    return result;
  }
};

class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> frrq;
    for (const int& num : nums) frrq[num]++;
    int maxl = 0;
    for (const auto& [key, value] : frrq) {
      if (frrq.count(key + 1)) {
        maxl = max(maxl, value + frrq[key + 1]);
      }
    }
    return maxl;
  }
};

class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> visitedWord(banned.begin(), banned.end());
    unordered_map<string, int> frq;

    string word = "";
    for (const char& c : paragraph) {
      if (isalpha(c)) {
        word += tolower(c);
      } else if (!word.empty()) {
        frq[word]++;
        word = "";
      }
    }

    if (!word.empty()) frq[word]++;

    string answer = "";
    int maxCount = 0;

    for (const auto& [key, value] : frq) {
      if (visitedWord.find(key) == visitedWord.end() && value > maxCount) {
        answer = key;
        maxCount = value;
      }
    }
    return answer;
  }
};

class Solution {
 public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> wordCount;
    string word = "";
    string s = s1 + ' ' + s2 + ' ';
    for (char c : s) {
      if (isalpha(c)) {
        word += tolower(c);
      } else if (!word.empty()) {
        wordCount[word]++;
        word = "";
      }
    }
    vector<string> answer;
    for (const auto& [key, value] : wordCount) {
      if (value == 1) {
        answer.push_back(key);
      }
    }
    return answer;
  }
};

class Solution {
 public:
  int maxScore(string s) {
    int oneCount = count(s.begin(), s.end(), '1');
    int zero = 0;
    int ans = 0;
    for (int i = 0; i < s.size() - 1; i += 1) {
      if (s[i] == '1') {
        oneCount--;
      } else {
        zero++;
      }
      ans = max(oneCount + zero, ans);
    }
    return ans;
  }
};

class Solution {
 public:
  int solve(int n, int startNum, vector<int>& dp) {
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    int maxProduct = 0;
    for (int i = 1; i <= n / 2; i++) {
      int product = i * max(n - i, solve(n - i, 1, dp));
      maxProduct = max(maxProduct, product);
    }

    return dp[n] = maxProduct;
  }

  int integerBreak(int n) {
    if (n <= 3) return n - 1;
    vector<int> dp(n + 1, -1);
    return solve(n, 1, dp);
  }
};

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    string answer = "";

    for (int len = 1; len <= n; len++) {
      for (int left = 0; left <= n - len; left++) {
        int right = left + len - 1;
        if (s[left] == s[right]) {
          if (len == 1 || len == 2 || dp[left + 1][right - 1]) {
            dp[left][right] = true;
            if (len > answer.size()) {
              answer = s.substr(left, len);
            }
          }
        }
      }
    }
    return answer;
  }
};

class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size() / 2;
    int totalCosts = 0;

    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
      return (a[0] - a[1]) < (b[0] - b[1]);
    });

    for (int i = 0; i < n; i++) {
      totalCosts += costs[i][0];
    }
    for (int i = n; i < n * 2; i++) {
      totalCosts += costs[i][1];
    }

    return totalCosts;
  }
};

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(),
         [&](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    int neededArrows = 1;
    int endingIndex = points[0][1];
    for (int i = 1; i < points.size(); i++) {
      if (points[i][0] > endingIndex) {
        neededArrows++;
        endingIndex = points[i][1];
      }
    }
    return neededArrows;
  }
};

class Solution {
 public:
  // time complexity O(n)
  // space complexity O(1)
  vector<int> partitionLabels(string s) {
    vector<int> last(26, 0);
    for (int i = 0; i < s.size(); i += 1) {
      last[s[i] - 'a'] = i;
    }

    vector<int> ans;
    int maxEnd = 0, start = 0;
    for (size_t i = 0; i < s.size(); i++) {
      /* code */

      maxEnd = max(maxEnd, last[s[i] - 'a']);
      if (i == maxEnd) {
        ans.push_back(i - start + 1);
        // storing start kyuki jab ek partiion ban jaayega toh dusre ka size k
        // liye 2 pointer use kar rhe h
        start = i;
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> empmap;
    for (Employee* emps : empmap) {
      empmap[emps->id] = emp;
    }
    int answer = 0;
    queue<int> q;
    q.push(id);
    while (!q.empty()) {
      int currenId = q.front();
      q.pop();

      Employee* current = empmap[currenId];
      answer += current->importance;
      for (int sub_id : current->subordinates) {
        q.push(sub_id);
      }
    }
    return answer;
  }
};

class Solution {
 public:
  int solve(vector<vector<int>>& adj, long long& fuelCost, int node, int parent,
            int& seats) {
    int rep = 1;

    for (int neighbour : adj[node]) {
      if (neighbour == parent) return;
      rep += solve(adj, fuelCost, neighbour, node);
    }
    if (node != 0) {
      fuelCost += (rep + seats - 1) / seats;
    }
    return rep;
  }
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n = roads.size();
    vector<vector<int>> adj(n);
    for (const auto& edge : roads) {
      int a = edge[0], b = edge[1];
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    long long fuelCost = 0;
    solve(adj, fuelCost, 0, -1, seats);

    return fuelCost;
  }
};

class Solution {
 public:
  vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int dfs(vector<vector<int>>& grid, int i, int j, int islandId) {
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return 0;
    grid[i][j] = islandId;
    int size = 1;
    for (auto& dir : directions) {
      int newX = dir[0] + i;
      int newY = dir[1] + j;
      size += dfs(grid, newX, newY, islandId);
    }
    return size;
  }

  int n;
  int largestIsland(vector<vector<int>>& grid) {
    n = grid.size();
    unordered_map<int, int> islandsize;
    int islandId = 2;
    int maxsize = 0;

    for (size_t i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int size = dfs(grid, i, j, islandId);
        islandsize[islandId] = size;
        maxsize = max(maxsize, size);
        islandId++;
      }
    }

    for (size_t i = 0; i < n; i++) {
      /* code */
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          unordered_set<int> visitedIslands;
          int current = 1;

          for (auto& dir : directions) {
            int newX = dir[0] + i;
            int newY = dir[1] + j;
            if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
                grid[newX][newY] >= 2) {
              visitedIslands.insert(grid[newX][newY]);
            }
          }
          for (int id : visitedIslands) {
            current += islandsize[id];
          }

          maxsize = max(maxsize, current);
        }
      }
    }
    return maxsize;
  }
};

class Solution {
 public:
  int getHeight(TreeNode* node) {
    if (!node) return 0;
    return 1 + max(getHeight(node->left), getHeight(node->right));
  }
  void solveTree(TreeNode* node, vector<vector<string>>& res, int row, int left,
                 int right) {
    if (!node) return;
    int col = (left + right) / 2;
    res[row][col] = to_string(node->val);
    solveTree(node->left, res, row + 1, left, col - 1);
    solveTree(node->right, res, row + 1, col + 1, right);
  }
  vector<vector<string>> printTree(TreeNode* root) {
    int height = getHeight(root);
    int width = pow(2, height) - 1;

    vector<vector<string>> res(height, vector<string>(width, ""));

    solveTree(root, res, 0, 0, width - 1);
    return res;
  }
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
      TreeNode* newnode = new TreeNode(val);
      newnode->left = root;
      return newnode;
    }

    queue<TreeNode*> q;
    q.push(root);
    int currentDepth = 1;
    while (!q.empty()) {
      int size = q.size();
      if (currentDepth == depth - 1) {
        while (size--) {
          /* code */
          TreeNode* node = q.front();
          q.pop();
          TreeNode* realLeft = node->left;
          TreeNode* realRight = node->right;

          node->left = new TreeNode(val);
          node->right = new TreeNode(val);
          node->left->left = realLeft;
          node->right->right = realRight;
        }
        return root;
      }
      while (size--) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      currentDepth++;
    }
    return root;
  }
};
class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
      TreeNode* newnode = new TreeNode(val);
      newnode->left = root;
      return newnode;
    }
    solve(root, val, depth, 1);
    return root;
  }
  void solve(TreeNode* node, int val, int depth, int currentDepth) {
    if (!node) return;
    if (currentDepth == depth - 1) {
      TreeNode* realLeft = node->left;
      TreeNode* realRight = node->right;

      node->left = new TreeNode(val);
      node->right = new TreeNode(val);
      node->left->left = realLeft;
      node->right->right = realRight;

      return;
    }

    solve(node->left, val, depth, currentDepth + 1);
    solve(node->right, val, depth, currentDepth + 1);
  }
};

class Solution {
 public:
  bool dfs(ListNode* head, TreeNode* root) {
    if (!head) return true;
    if (!root) return false;

    if (root->val == head->val) {
      return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
    return false;
  }
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (!root) return false;
    if (dfs(root, head)) {
      return true;
    }
    return isSubPath(head, root->right) || isSubPath(head, root->left);
  }
};

#include <iostream>
#include <string>
using namespace std;

int findMaxLength(string& s, int i, int j, vector<vector<int>>& dp) {
  if (dp[i][j] != -1) return dp[i][j];
  if ((j - i + 1) % 2 != 0) return 0;
  int mid = (i + j) / 2;
  int leftSum = 0, rightSum = 0;
  for (int k = i; k <= mid; k++) leftSum += s[k] - '0';
  for (int k = mid + 1; k <= j; k++) rightSum += s[k] - '0';
  if (leftSum == rightSum) return dp[i][j] = j - i + 1;

  dp[i][j] = max(findMaxLength(s, i, j - 1), findMaxLength(s, i + 1, j));
  return dp[i][j];
}

int longestEvenSubstring(string s) {
  int n = s.size();
  int maxLength = 0;
  int n = s.length();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      maxLength = max(maxLength, findMaxLength(s, i, j, dp));
    }
  }

  return maxLength;
}

class Solution {
 public:
  int minAddToMakeValid(string s) {
    string stack = "";
    for (char c : s) {
      if (stack.size() && stack.back() == '(' && c == ')') {
        stack.pop_back();
      } else {
        stack.push_back(c);
      }
    }
    return stack.size();
  }
};

class Solution {
 public:
  bool isArraySpecial(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i += 2) {
      if (nums[i] % 2 == nums[i - 1] % 2) {
        return false;
      }
    }
    return true;
  }
};
class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> mp;
    queue<Node*> q;
    Node* cloned = new Node(node->val);
    mp[node] = cloned;
    q.push(node);
    while (!q.empty()) {
      Node* node = q.front();
      q.pop();

      for (Node* neighbour : node->neighbors) {
        if (mp.find(neighbour) == mp.end()) {
          Node* cloneNeighbour = new Node(neighbour->val);
          mp[neighbour] = cloneNeighbour;
          q.push(neighbour);
        }
        mp[node]->neighbors.push_back(mp[neighbour]);
      }
    }
    return cloned;
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> st(nums.begin(), nums.end());
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* curr = head;

    while (curr) {
      if (st.find(curr->val) != st.end()) {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }

    return dummy.next;
  }
};

class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    ListNode* temp = head->next;
    int sum = 0;

    while (temp != nullptr) {
      if (temp->val == 0) {
        curr->next = new ListNode(sum);
        curr = curr->next;
        sum = 0;
      } else {
        sum += temp->val;
      }
      temp = temp->next;
    }

    return dummy->next;
  }
};
class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    ListNode* temp = head->next;
    int sum = 0;

    while (temp != nullptr) {
      if (temp->val == 0) {
        curr->next = new ListNode(sum);
        curr = curr->next;
        sum = 0;
      } else {
        sum += temp->val;
      }
      temp = temp->next;
    }

    return dummy->next;
  }
};
class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    ListNode* temp = head->next;
    int sum = 0;
    while (temp != nullptr) {
      if (temp->val == 0) {
        current->next = new ListNode(sum);
        current = current->next;
        sum = 0;
      } else {
        sum += temp->val;
      }
      temp = temp->next;
    }
    return dummy->next;
  }
};

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    int m = n + 1;
    vector<int> g(m);

    g[0] = startTime[0] - 0;
    for (int i = 1; i < n; i++) {
      g[i] = startTime[i] - endTime[i - 1];
    }
    g[m - 1] = eventTime - endTime[n - 1];

    int om = 0;
    for (int gap : g) {
      om = max(om, gap);
    }

    vector<int> p(m);
    vector<int> s(m);

    p[0] = g[0];
    for (int i = 1; i < m; i++) {
      p[i] = max(p[i - 1], g[i]);
    }

    s[m - 1] = g[m - 1];
    for (int i = m - 2; i >= 0; i--) {
      s[i] = max(s[i + 1], g[i]);
    }

    int res = om;

    for (int i = 0; i < n; i++) {
      int d = endTime[i] - startTime[i];
      int cG = 0;

      if (i == 0) {
        cG = g[0] + d + (n >= 2 ? g[1] : 0);
      } else if (i == n - 1) {
        cG = g[n - 1] + d + g[n];
      } else {
        cG = g[i] + d + g[i + 1];
      }

      int mO = 0;
      if (i == 0) {
        if (m > 2) mO = s[2];
      } else if (i == n - 1) {
        if (m > 2) mO = p[m - 3];
      } else {
        int lm = i - 1 >= 0 ? p[i - 1] : 0;
        int rm = i + 2 < m ? s[i + 2] : 0;
        mO = max(lm, rm);
      }

      int cP = mO >= d ? cG : cG - d;
      res = max(res, cP);
    }

    return res;
  }
};
class Solution {
 public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> result(k, nullptr);
    ListNode* temp = head;
    while (temp) {
      n++;
      temp = temp->next;
    }

    // Step 2: Determine size of each part
    int baseSize = n / k;    // Minimum nodes in each part
    int extraNodes = n % k;  // Extra nodes to distribute among first few parts

    // Step 3: Split the list
    ListNode* current = head;
    for (int i = 0; i < k && current; i++) {
      result[i] = current;  // Store head of the current partbva
      int partSize =
          baseSize + (extraNodes > 0
                          ? 1
                          : 0);  // Increase size for first 'extraNodes' parts
      extraNodes--;

      // Move to the last node of the current part
      for (int j = 1; j < partSize; j++) {
        if (current) current = current->next;
      }

      // Cut the link to separate parts
      if (current) {
        ListNode* nextPart = current->next;
        current->next = nullptr;
        current = nextPart;
      }
    }

    return result;
  }
};

class Solution {
 public:
  int maxDifference(string s) {
    int maxEven = 0;
    int maxOdd = 0;
    vector<int> freq(26, 0);
    for (char c : s) {
      freq[c - 'a']++;
      if (freq[c - 'a'] % 2 == 0) {
        maxEven = max(maxEven, freq[c - 'a']);
      } else if (freq[c - 'a'] % 2 != 0) {
        maxOdd = max(maxOdd, freq[c - 'a']);
      }
    }
    return maxEven - maxOdd;
  }
};

class Solution {
 public:
  int maxDistance(string s, int k) {
    int posx = 0, posy = 0, negx = 0, negy = 0, ans = 0;
    for (auto i : s) {
      if (i == 'N') posy++;
      if (i == 'S') negy++;
      if (i == 'E') posx++;
      if (i == 'W') negx++;
      int need1 = min(posx, negx), need2 = min(posy, negy),
          val = min(k, need1 + need2);
      ans = max(ans, max(posx, negx) - min(posx, negx) + max(posy, negy) -
                         min(posy, negy) + 2 * val);
    }
    return ans;
  }
};

struct Node {
  int data;
  Node* next;
  Node* child;
};

Node* merge(Node* a, Node* b) {
  if (!a) return b;
  if (!b) return a;
  Node* result;
  if (a->data > b->data) {
    result = b;
    result->child = merge(a, b->child);
  } else {
    result = a;
    result->child = merge()
  }
  return result;
}

Node* flatten(Node* head) {
  if (!head || !head->next) return head;
  head->next = flatten(head->next);
  head = merge(head, head->next);
  return head;
}

class Solution {
 public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int maxL = 0, inc = 0, dec = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      /* code */
      if (nums[i] > nums[i + 1]) {
        dec++;
        inc = 1;
      } else if (nums[i] < nums[i + 1]) {
        inc++;
        dec = 1;
      } else {
        inc = 1;
        dec = 1;
      }
      maxL = max({maxL, inc, dec});
    }
    return maxL;
  }
};

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  const int INF = 1e9;

  long long minimumCost(string source, string target, vector<char>& original,
                        vector<char>& changed, vector<int>& cost) {
    vector<vector<int>> minCost(26, vector<int>(26, INF));
    for (int i = 0; i < 26; i++) {
      minCost[i][i] = 0;
    }
    for (int i = 0; i < original.size(); i++) {
      int u = original[i] - 'a';
      int v = changed[i] - 'a';
      minCost[u][v] =
          min(minCost[u][v], cost[i]);  // Keep the minimum edge cost
    }

    // Step 2: Run Floyd-Warshall Algorithm
    for (int k = 0; k < 26; k++) {      // Intermediate node
      for (int i = 0; i < 26; i++) {    // Start node
        for (int j = 0; j < 26; j++) {  // End node
          if (minCost[i][k] < INF && minCost[k][j] < INF) {
            minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
          }
        }
      }
    }

    long long totalCost = 0;

    for (int i = 0; i < source.size(); i++) {
      int from = source[i] - 'a';
      int to = target[i] - 'a';

      if (from == to) continue;

      if (minCost[from][to] == INF) return -1;

      totalCost += minCost[from][to];
    }

    return totalCost;
  }
};

class Solution {
 public:
  int countPaths(int n, vector<vector<int>>& roads) {
    const int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> graph(n);
    for (auto& road : roads) {
      int u = road[0], v = road[1], time = road[2];
      graph[u].push_back({v, time});
      graph[v].push_back({u, time});
    }
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<>>
        pq;
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    while (!pq.empty()) {
      int dist = pq.top().first, node = pq.top().second;
      pq.pop();

      if (dist > dist[node]) continue;

      for (auto [neighbour, ] :) }
  }
};

class Solution {
 public:
  int balancedStringSplit(string s) {
    int balance = 0, ans = 0;
    for (char c : s) {
      if (c == 'L') {
        balance++;
      } else if (c == 'R') {
        balance--;
      }

      if (balance == 0) ans++;
    }
    return ans;
  }
};

class Solution {
 public:
  int findUnsortedSubarray(std::vector<int>& nums) {
    int n = nums.size();
    int left = -1, right = -1;
    int maxSeen = INT_MIN, minSeen = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (nums[i] < maxSeen) {
        right = i;
      }
      maxSeen = std::max(maxSeen, nums[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] > minSeen) {
        left = i;
      }
      minSeen = std::min(minSeen, nums[i]);
    }

    return (left == -1) ? 0 : (right - left + 1);
  }
};

class Solution {
 public:
  int movesToMakeZigzag(vector<int>& nums) {
    int moves1 = 0, moves2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      int left = (i > 0) ? nums[i - 1] : INT_MAX;
      int right = (i < nums.size() - 1) ? nums[i + 1] : INT_MAX;
      if (i % 2 == 0) {
        if (nums[i] >= min(left, right)) {
          moves1 += nums[i] - min(left, right) + 1;
        }
      } else {
        if (nums[i] <= max(left, right)) {
          moves2 += max(left, right) - nums[i] + 1;
        }
      }
    }
    return min(moves1, moves2);
  }
};

class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int maxs = nums[0], ans = nums[0];
    for (size_t i = 1; i < nums.size() - 1; i++) {
      /* code */
      if (nums[i] > nums[i - 1]) {
        maxs += nums[i];
      } else {
        maxs = nums[i];
      }
      ans = max(ans, maxs);
    }
    return ans;
  }
};

int getMaxPositiveFeedback(char* videoFeedback) {
  string fb(videoFeedback);
  int n = fb.length();
  int max_pf = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      string temp_fb = fb;

      for (int k = 0; k < i; ++k) {
        if (temp_fb[k] == '0') {
          temp_fb[k] = '1';
        } else {
          temp_fb[k] = '0';
        }
      }

      for (int k = j + 1; k < n; ++k) {
        if (temp_fb[k] == '0') {
          temp_fb[k] = '1';
        } else {
          temp_fb[k] = '0';
        }
      }

      int current_pf = 0;
      for (char bit : temp_fb) {
        if (bit == '1') {
          current_pf++;
        }
      }
      max_pf = max(max_pf, current_pf);
    }
  }
  return max_pf;
}

class Solution {
 public:
  int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int n = nums.size();
    int minSum = INT_MAX;
    int currentSum = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
      currentSum += nums[right];
      if (right - left + 1 > r) {
        currentSum -= nums[left];
        left++;
      }
      if (right - left + 1 >= l) {
        minSum = min(minSum, currentSum);
      }
    }

    return minSum;
  }
};

class Solution {
 public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    int minLength = INT_MAX;

    for (int i = 0; i < n; i++) {
      int currOr = 0;
      for (int j = i; j < n; j++) {
        currOr |= nums[j];
        if (currOr >= k) {
          minLength = min(minLength, j - i + 1);
          break;
        }
      }
    }

    return (minLength == INT_MAX) ? -1 : minLength;
  }
};

class Solution {
 public:
  int maximumLengthSubstring(string s) {
    int left = 0;
    int n = s.size(), maxl = 0;
    unordered_map<char, int> freq;

    for (int i = 0; i < n; i++) {
      /* code */
      freq[s[i]]++;
      while (freq[s[left]] > 2) {
        freq[s[left]]--;
        left++;
      }
      maxl = max(maxl, i - left + 1);
    }
    return maxl;
  }
};

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int target = accumulate(nums.begin(), nums.end(), 0) - x;
    if (target < 0) return -1;

    int n = nums.size();
    int left = 0, sum = 0, maxLength = -1;
    for (int right = 0; right < n; right++) {
      sum += nums[right];
      while (left <= right && sum > target) {
        sum -= nums[left++];
      }
      if (sum == target) {
        maxLength = max(maxLength, right - left + 1);
      }
    }
    return (maxLength == -1) ? -1 : n - maxLength;
  }
};
class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> result(n, 0);
    if (k == 0) return result;
    vector<int> extendedCode(code.begin(), code.end());
    extendedCode.insert(extendedCode.end(), code.begin(), code.end());
    int sum = 0, start = (k > 0) ? 1 : n + k;
    for (int i = start; i < start + abs(k); i++) {
      sum += extendedCode[i];
    }
    for (int i = 0; i < n; i++) {
      result[i] = sum;
      sum -= extendedCode[start];
      sum += extendedCode[start + abs(k)];
      start++;
    }
    return result;
  }
};

class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    vector<pair<int, int>> jobs;
    for (int i = 0; i < difficulty.size(); i++) {
      jobs.push_back({difficulty[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());

    int maxproft = 0, j = 0, maxyfar = 0;
    ;
    for (int ability : worker) {
      while (j < n && jobs[j].first <= ability) {
        maxyfar = max(maxyfar, jobs[j].second);
        j++;
      }
      maxproft += maxyfar;
    }
    return maxproft;
  }
};
class Solution {
 public:
  bool isValid(int x, vector<int>& arr2, int d) {
    int left = 0, right = arr2.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (abs(arr2[mid] - x) <= d) return false;
      if (arr2[mid] < x)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return true;
  }
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(begin(arr2), end(arr2));
    int count = 0;
    for (int x : arr1) {
      if (isValid(x, arr2, d)) count++;
    }
    return count;
  }
};

class Solution {
 public:
  int customBinarySearchNegative(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < 0) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right + 1;
  }

  int customBinarySearchPositive(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > 0) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return nums.size() - left;
  }

  int maximumCount(vector<int>& nums) {
    int negativeCount = customBinarySearchNegative(nums);
    int positiveCount = customBinarySearchPositive(nums);

    return max(negativeCount, positiveCount);
  }
};

class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int t) {
    vector<int> res;
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < t) {
        left = mid + 1;
      } else if (nums[mid] > t) {
        right = mid - 1;
      } else {
        res.push_back(mid);
        break;
      }
    }

    if (res.empty()) return {};
    int firstIndex = res[0];
    for (int i = firstIndex + 1; i < nums.size(); ++i) {
      if (nums[i] == t) {
        res.push_back(i);
      } else {
        break;
      }
    }
    return res;
  }
};

class Solution {
 public:
  int countPairs(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    int count = 0;
    while (i < j) {
      if (nums[i] + nums[j] < target) {
        count += (j - i);
        i++;
      } else {
        j--;
      }
    }

    return count;
  }
};
class Solution {
 public:
  int sumOfMultiples(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
      if (i % 3 == 0 || i % 7 == 0 || i % 5 == 0) {
        sum += i;
      }
    }
    return sum;
  }
};

class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> mp;
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j >= 0; j--) {
        int product = nums[i]* [j];
        ans += 8 * mp[product];
        mp[product]++;
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int mostWordsFound(vector<string>& sentences) {
    int maxFound = -1;
    for (string& s : sentences) {
      int current = 1;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
          current++;
        }
      }
      maxFound = max(maxFound, current);
    }
    return maxFound;
  }
};

class Solution {
 public:
  int countDigits(int num) {
    int ans = 0;
    string value = to_string(num);
    for (int i = value.size() - 1; i >= 0; i--) {
      if (num % stoi(value[i]) == 0) {
        ans++;
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int negativeCount = 0;
    for (int& x : nums) {
      if (x < 0) {
        negativeCount++;
      }
      if (x == 0) return 0;
    }

    return negativeCount % 2 != 0 ? -1 : 1;
  }
};

class Solution {
 public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i - 1] % 2 != 0 && arr[i] % 2 != 0 && arr[i + 1] % 2 != 0) {
        return true;
      }
    }
    return false;
  }
};

class Solution {
 public:
  int subtractProductAndSum(int n) {
    int sum = 0, product = 1;

    while (n > 0) {
      /* code */
      int digit = n % 10;
      sum += digit;
      sum *= digit;
      n /= 10;
    }
    return product - sum;
  }
};
class Solution {
 public:
  string triangleType(vector<int>& nums) {
    if (nums[0] == nums[1] == nums[2]) {
      return "equilateral";
    } else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]) {
      return "isosceles";
    } else if () {
      return "scalene";
    }
    return "none";
  }
};

class Solution {
 public:
  int digitSinglesum(int num) {
    int ans = 0;
    while (num > 0) {
      ans += num % 10;
      num /= 10;
    }
    return ans;
  }
  int differenceOfSum(vector<int>& nums) {
    int elementSum = accumulate(nums.begin(), nums.end(), 0);
    int digitSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 9) {
        digitSum += digitSinglesum(nums[i]);
      } else {
        digitSum += nums[i];
      }
    }
    return elementSum - digitSum;
  }
};

class Solution {
 public:
  bool isPalindorme(string& s) {
    int l = 0, h = s.size() - 1;
    while (l < s) {
      if (s[l] != s[h]) {
        return false;
      }
      l++;
      h--;
    }
    return true;
  }
  string firstPalindrome(vector<string>& words) {
    for (string& word : words) {
      if (isPalindorme(word)) {
        return word;
      }
    }
    return "";
  }
};

class Solution {
 public:
  bool isPalindrome(string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - i - 1]) {
        return false;
      }
    }
    return true;
  }

  string firstPalindrome(vector<string>& words) {
    for (string& word : words) {
      if (isPalindrome(word)) {
        return word;
      }
    }
    return "";
  }
};

class Solution {
 public:
  int differenceOfSums(int n, int m) {
    int first = 0, second = 0;
    for (int i = 1; i <= n; i++) {
      if (i % m != 0) {
        first += i;
      } else {
        second += i;
      }
    }
    return first - second;
  }
};
class Solution {
 public:
  int differenceOfSums(int n, int m) {
    int val = 0;
    for (int i = 1; i <= n; i++) {
      if (i % m != 0) {
        val += i;
      } else {
        val -= i;
      }
    }
    return val;
  }
};

class Solution {
 public:
  bool judgeCircle(string moves) {
    int x = 0;
    int y = 0;
    for (char ch : moves) {
      if (ch == 'U') {
        x++;
      } else if (ch == 'D') {
        x--;
      } else if (ch == 'L') {
        y++;
      } else if (ch == 'R') {
        y--;
      }
    }
    if (x == 0 && y == 0) {
      return true;
    }
    return false;
  }
};

class Solution {
 public:
  int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int ans = 0;
    for (size_t i = 0; i < hours.size(); i++) {
      /* code */
      if (hours[i] >= target) ans++;
    }

    return ans;
  }
};

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> st;
    for (int x : nums) {
      st.push_back(to_string(x))
    };

    sort(st.begin(), st.end(),
         [](string& a, string& b) { return a + b > b + a; });

    if (st[0] == "0") return "0";

    string result;
    for (string& s : st) {
      result += s;
    }
    return result;
  }
};

class MyCalendar {
 public:
  vector<pair<int, int>> booking;
  int binarySearch(int starttime) {
    int low = 0, high = booking.size();
    while (left < high) {
      int mid = low + (high - low) / 2;
      if (booking[mid].first >= starttime) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
      return left;
    };
  }
  MyCalendar() {}

  bool book(int startTime, int endTime) {
    int pos = binarySearch(startTime);
    if (pos < booking.size()&&) }
};

class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> res;
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> diff1;
    for (int num : set1) {
      if (set2.find(num) == set2.end()) {
        diff1.push_back(num);
      }
    }
    vector<int> diff2;
    for (int num : set2) {
      if (set1.find(num) == set1.end()) {
        diff2.push_back(num);
      }
    }
    res.push_back(diff1);
    res.push_back(diff2);

    return res;
  }
};

class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> diff1, diff2;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        if (i == 0 || nums1[i] != nums1[i - 1]) {  // Avoid duplicates
          diff1.push_back(nums1[i]);
        }
        i++;
      } else if (nums1[i] > nums2[j]) {
        // nums2[j] is smaller, it's unique to nums2
        if (j == 0 || nums2[j] != nums2[j - 1]) {  // Avoid duplicates
          diff2.push_back(nums2[j]);
        }
        j++;
      } else {
        // nums1[i] == nums2[j], move both pointers
        i++;
        j++;
      }
    }

    // Handle remaining elements in nums1
    while (i < nums1.size()) {
      if (i == 0 || nums1[i] != nums1[i - 1]) {  // Avoid duplicates
        diff1.push_back(nums1[i]);
      }
      i++;
    }

    // Handle remaining elements in nums2
    while (j < nums2.size()) {
      if (j == 0 || nums2[j] != nums2[j - 1]) {  // Avoid duplicates
        diff2.push_back(nums2[j]);
      }
      j++;
    }

    // Add the results to res
    res.push_back(diff1);
    res.push_back(diff2);

    return res;
  }
};

class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    vector<int> check(10001, 0);
    for (int dec : deck) {
      check[dec]++;
    }

    for (int x : check) {
      if (check[x] % 2 != 0) return false;
    }
    return true;
  }
};

class Solution {
 public:
  void inorder(vector<int>& v, TreeNode* root) {
    if (root == nullptr) return;
    inorder(v, root->left);
    v.push_back(root->val);
    inorder(v, root->right);
  }

  TreeNode* construct(vector<int>& arr, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(arr[mid]);

    node->left = construct(arr, left, mid - 1);
    node->right = construct(arr, mid + 1, right);

    return node;
  }

  TreeNode* balanceBST(TreeNode* root) {
    vector<int> sorted;
    inorder(sorted, root);
    return construct(sorted, 0, sorted.size() - 1);
  }
};

class NumberContainers {
 public:
  unordered_map<int, int> indexTomap;
  unordered_map<int, set<int>> numberToIndexs;
  NumberContainers() {}

  void change(int index, int number) {
    if (indexTomap.count(index)) {
      int olddigit = indexTomap[index];
      numberToIndexs[olddigit].erase(index);
      if (numberToIndexs[olddigit].empty()) {
        numberToIndexs.erase(olddigit);
      }
    }
    indexTomap[index] = number;
    numberToIndexs[number].insert(index);
  }

  int find(int number) {
    if (numberToIndexs.find(number) != numberToIndexs.end() &&
        !numberToIndexs[number].empty()) {
      return *numberToIndexs[number].begin();
    }
    return -1;
  }
};

class Solution {
 public:
  char repeatedCharacter(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
      freq[c - '0']++;
      if (freq[c] > 1) return c;
    }
    return '';
  }
};

class Solution {
 public:
  int rearrangeCharacters(string s, string target) {
    vector<int> freq(26, 0), freqT(26, 0);
    ;
    for (char c : s) {
      freq[c - 'a']++;
    }
    for (char c : s) {
      freqT[c - 'a']++;
    }
    int ans = INT_MAX;
    for (char ch : target) {
      ans = min(ans, freq[ch - 'a'] / freqT(ch - 'a'));
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

class Solution {
 public:
  bool digitCount(string num) {
    vector<int> bodyCount(10, 0);
    for (char c : num) {
      bodyCount[c - '0']++;
    }
    for (int i = 0; i < num.length(); i++) {
      if (bodyCount[s[i]] != s[i]) return false;
    }
    return true;
  }
};

class Solution {
 public:
  int rev(int n) {
    int ans = 0;
    while (n > 0) {
      ans = ans * 10 + n % 10;
      n = n % 10;
    }
    return ans;
  }
  int mod = 1e9 + 7;

  int countNicePairs(vector<int>& nums) {
    unordered_map<long long, long long> fr;
    long long goodPairs = 0;

    for (long long n : nums) {
      long long dif = n - rev(n);
      goodPairs = (goodPairs + fr[dif]) % mod;
      fr[dif]++;
    }
    return goodPairs;
  }
};

class Solution {
 public:
  int longestPalindrome(string s) {
    unordered_map<char, int> mp;
    for (char c : s) {
      mp[c]++;
    }
    int length = 0;
    bool doesHaveOddsingle = false;
    for (auto it : mp) {
      if (it.second % 2 == 0) {
        length += it.second;
      } else if (it.second % 2 != 0) {
        doesHaveOddsingle = true;
        length += it.second - 1;
      }
    }
    if (doesHaveOddsingle) length++;

    return length;
  }
};

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;
    mp[0] = -1;
    int maxLenght = INT_MIN, prefixSum = 0;

    for (int i = 0; i < nums.size(); i += 1) {
      prefixSum += (nums[i] == 1) ? 1 : -1;
      if (mp.find(prefixSum) != mp.end()) {
        maxLenght = max(maxLenght, i - mp[prefixSum]);
      } else {
        mp[prefixSum] = i;
      }
    }
    return maxLenght;
  }
};

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = -1;
    int prefixSum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i += 1) {
      prefixSum += nums[i];
      int rem = prefixSum % k;
      if (rem < 0) rem += k;
      if (mp.find(rem) != mp.end()) {
        if (i - mp[rem] > 1) return true;
      } else {
        mp[rem] = i;
      }
    }
    return false;
  }
};

// 10,15,9,15
// 6 12 18 24 30 36 42 48 54 60

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> seen, repeated;
    vector<string> res;
    for (int i = 0; i < s.size(); i++) {
      string temp = s.substr(i, 10);
      if (seen.find(temp) != seen.end()) {
        repeated.insert(temp);
      } else {
        seen.insert(temp);
      }
    }

    for (const string& seq : repeated) {
      res.push_back(seq);
    }
    return res;
  }
};

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> pairSum;
    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        pairSum[nums1[i] + nums2[j]]++;
      }
    }
    int count = 0;
    for (int i = 0; i < nums3.size(); i++) {
      for (int j = 0; j < nums4.size(); j++) {
        int target = -(nums3[i] + nums4[j]);
        if (pairSum.find(target) != pairSum.end()) {
          count += pairSum[target];
        }
      }
    }
    return count;
  }
};

class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> idx;
    vector<string> result;
    int minSum = INT_MAX;
    for (int i = 0; i < list1.size(); i++) {
      idx[list1[i]] = i;
    }
    for (int j = 0; j < list2.size(); j++) {
      if (idx.find(list2[j]) != idx.end()) {
        int sum = j + idx[list2[j]];
        if (sum < minSum) {
          minSum = sum;
          result = {list2[j]};
        } else if (sum == minSum) {
          result.push_back(list2[j]);
        }
      }
    }

    return result;
  }
};

class Solution {
 public:
  int countElements(vector<int>& nums) {
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int num : nums) {
      minVal = min(minVal, num);
      maxVal = max(maxVal, num);
    }
    int cnt = 0;
    for (int n : nums) {
      if (n > minVal && n < maxVal) cnt++;
    }
    return cnt;
  }
};

class Solution {
 public:
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < nums[i + 1] + nums[i + 2]) {
        return nums[i] + nums[i + 1] + nums[i + 2];
      }
    }
    return 0;
  }
};

class Solution {
 public:
  string maximumTime(string time) {
    if (time[0] == '?')
      time[0] = (time[1] == '?' || time[1] <= '3') ? '2' : '1';
    if (time[1] == '?') time[1] = (time[0] == '2') ? '3' : '9';
    if (time[3] == '?') time[3] = '5';
    if (time[4] == '?') time[4] = '9';

    return time;
  }
};

class Solution {
 public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<vector<int>> tree(n);
    vector<int> ans(n, 0);
    vector<bool> visited(n, false);
    for (auto& edge : edges) {
      tree[edge[0]].push_back(edge[1]);
      tree[edge[1]].push_back(edge[0]);
    }
    function<vector<int>(int)> dfs = [&](int node) -> vector<int> {
      visited[node] = true;
      vector<int> count(26, 0);
      count[labels[node] - 'a']++;
      for (int child : tree[node]) {
        if (!visited[child]) {
          vector<int> childCount = dfs(child);
          for (int i = 0; i < 26; i++) {
            count[i] += childCount[i];
          }
        }
      }

      ans[node] = count[labels[node] - 'a'];
      return count;
    };

    dfs(0);

    return ans;
  }
};

class Solution {
 public:
  string removeOccurrences(string s, string part) {
    stack<char> st;
    int n = part.size();
    for (char c : s) {
      st.push(c);
      if (st.size() >= n) {
        string temp = "";
        stack<char> tempStack = st;
        for (int i = 0; i < n; i++) {
          temp = tempStack.top() + temp;
          tempStack.pop();
        }
        if (temp == part) {
          for (int i = 0; i < n; i++) {
            st.pop();
          }
        }
      }
    }
    string result = "";
    while (!st.empty()) {
      result = st.top() + result;
      st.pop();
    }
    return result;
  }
};

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    vector<int> freq(26, 0);
    stack<char> s;
    vector<bool> inResult(26, false);

    for (char c : s) freq[s - 'a']++;
    for (char ch : s) {
      freq[c - 'a']--;
      if (inResult[c - 'a']) continue;
    }
  }
};

class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& arr) {
    int target = accumulate(begin(arr), end(arr), 0);
    if (target % 3 != 0) return false;
    int t = target / 3;
    int count = 0, sum = 0;
    for (int n : arr) {
      sum += n;
      if (sum == t) {
        count++;
        sum = 0;
      }
    }
    return count >= 3;
  }
};

class Solution {
 public:
  string strWithout3a3b(int a, int b) {
    string res;
    while (a > 0 || b > 0) {
      bool writea = false;
      if (res.size() > 2 && res[res.size() - 1] == res[res.size() - 2]) {
        if (res.back() == 'a') {
          writea = false;
        } else {
          writea = true;
        }
      } else {
        if (a >= b) {
          writea = true;
        } else {
          writea = false;
        }
      }
      if (writea) {
        res.push_back('a');
        a--;
      } else {
        res.push_back('b');
        b--;
      }
    }
    return res;
  }
};

class Solution {
 public:
  string strWithout3a3b(int a, int b) {
    string res;
    while (a > 0 || b > 0) {
      if (a > b) {
        if (a > 1)
          res += "aa", a -= 2;
        else
          res += "a", a--;
        if (b > 0) res += "b", b--;
      } else if (b > a) {
        if (b > 1)
          res += "bb", b -= 2;
        else
          res += "b", b--;
        if (a > 0) res += "a", a--;
      } else {
        res += "a", a--;
        res += "b", b--;
      }
    }
    return res;
  }
};

class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), greater<int>());

    vector<int> res;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      res.push_back(nums[i]);
      if (sum > total - sum) break;
    }
    return res;
  }
};

class Solution {
 public:
  int findMinFibonacciNumbers(int k) {
    vector<int> fib = {1, 1};
    while (fib.back() < k) {
      fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int count = 0;
    int i = fib.size() - 1;
    while (k > 0) {
      if (fib[i] <= k) {
        k -= fib[i];
        count++;
      }
      i--;
    }

    return count;
  }
};

class Solution {
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int row = rowSum.size(), cols = colSum.size();
    vector<vector<int>> matrix(row, vector<int>(cols, 0));
    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < cols; j++) {
        int val = min(rowSum[i], colSum[j]);
        matrix[i][j] = val;
        rowSum[i] -= val;
        colSum[j] -= val;
      }
    }
    return matrix;
  }
};

class Solution {
 public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int rows = moveTime.size();
    int cols = moveTime[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0});
    vector<vector<int>> mintime(rows, vector<int>(cols, INT_MAX));
    mintime[0][0] = 0;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int time = it[0], r = it[1], c = it[2];

      if (r == rows - 1 && c == cols - 1) {
        return time;
      }
      for (auto dir : directions) {
        int nr = r + dir.first, nc = c + dir.second;

        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
          int waiting = max(time + 1, moveTime[nr][nc]);

          if (waiting < mintime[nr][nc]) {
            mintime[nr][nc] = waiting;
            pq.push({waiting, nr, nc});
          }
        }
      }
    }
    return -1;
  }
};

class Solution {
 public:
  int maxDistance(vector<vector<int>>& arrays) {
    int res = INT_MIN;
    int maxVal = arrays[0].back();
    int minVal = arrays[0][0];

    for (int i = 1; i < arrays.size(); i += 1) {
      res = max(res, abs(arrays[i][0] - maxVal));
      res = max(res, abs(arrays[i].back() - minVal));
      maxVal = max(maxVal, arrays[i].back());
      minVal = min(minVal, arrays[i][0]);
    }

    return res;
  }
};

class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    sort(begin(nums), end(nums));
    return max(nums[0] * nums[n - 1] * nums[n - 2],
               nums[n - 1] * nums[n - 2] * nums[n - 3]);
  }
};

class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    int maxsum = -1;
    unordered_map<int, int> mp;
    for (int num : nums) {
      int digtsum = 0, temp = num;
      while (temp) {
        digtsum += temp % 10;
        temp /= 10;
      }
      if (mp.count(digtsum)) {
        maxsum = max(maxsum, mp[digtsum] + num);
      }
      mp[digtsum] = max(mp[digtsum], num);
    }
    return maxsum;
  }
};
class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();
    if (m * n != r * c) return mat;
    vector<vector<int>> res(r, vector<int>(c));
    int index = 0;
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        res[index / c][index % c] = mat[i][j];
        index++;
      }
    }
    return res;
  }
};

class Solution {
 private:
  void prepareAdj(vector<vector<int>>& pairs, vector<list<int>>& adj) {
    for (int i = 0; i < pairs.size(); i++) {
      int u = pairs[i][0];
      int v = pairs[i][1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  void dfs(int node, vector<bool>& vis, vector<list<int>>& adj,
           vector<char>& chars, vector<int>& indices, string& s) {
    chars.push_back(s[node]);
    indices.push_back(node);

    vis[node] = 1;

    for (int neigh : adj[node]) {
      if (!vis[neigh]) {
        dfs(neigh, vis, adj, chars, indices, s);
      }
    }
  }

 public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.length();

    vector<list<int>> adj(n);
    prepareAdj(pairs, adj);

    vector<bool> visited(n, 0);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        vector<char> chars;
        vector<int> indices;

        dfs(i, visited, adj, chars, indices, s);

        sort(begin(chars), end(chars));
        sort(begin(indices), end(indices));

        for (int j = 0; j < chars.size(); j++) {
          s[indices[j]] = chars[j];
        }
      }
    }

    return s;
  }
};

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    sort(begin(nums), end(nums));
    int dup = -1, miss = -1;

    for (size_t i = 0; i < nums.size(); i++) {
      /* code */
      if (nums[i] == nums[i + 1]) {
        dup = nums[i];
      } else if (nums[i] + 1 != nums[i + 1]) {
        miss = nums[i] + 1;
      }
    }
    if (nums.back() != nums.size()) miss = nums.size();
    return {dup, miss};
  }
};

class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freq;
    for (int n : arr1) freq[n]++;
    vector<int> res;
    for (int n : arr2) {
      while (freq[n] > 0) {
        res.push_back(n);
        freq[n]--;
      }
      freq.erase(n);
    }
    vector<int> v;
    for (auto it : freq) {
      int count = it.second;
      int n = it.first;
      while (count-- > 0) {
        v.push_back(n);
      }
    }
    sort(begin(v), end(v));
    res.insert(res.end(), v.begin(), v.end());
    return res;
  }
};

class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    sort(target.begin(), target.end());
    sort(arr.begin(), arr.end());
    return target == arr;
  }
};

class Solution {
 public:
  double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    double n = arr.size();
    double rem = n / 20;
    double sum = 0;
    for (double i = rem; i < n - rem; i++) {
      sum += arr[i];
    }

    return (sum / n - rem);
  }
};

class Solution {
 public:
  string sortSentence(string s) {
    vector<string> words;
    stringstream ss(s);
    string word;

    while (ss >> word) {
      words.push_back(word);
    }

    sort(words.begin(), words.end(),
         [&](const string& a, const string& b) { return a.back() < b.back(); });
    string res;
    for (int i = 0; i < words.size(); i++) {
      words[i].pop_back();
      res += words[i];
      if (i < words.size() - 1) res += " ";
    }
    return res;
  }
};

class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;
    vector<int> freq1(26, 0), fre2(26, 0);

    vector<bool> occurence1(26, false), occurence2(26, false);

    for (char c : word1) {
      freq1[c - 'a']++;
      occurence1[c - 'a'] = true;
    }
    for (char c : word2) {
      fre2[c - 'a']++;
      occurence2[c - 'a'] = true;
    }
    if (occurence1 != occurence2) return false;
    sort(freq1.begin(), freq1.end());
    sort(fre2.begin(), fre2.end());
    return true;
  }
};

class Solution {
 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int rows = grid1.size(), cols = grid1[0].size();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid2[i][j] == 1 && grid1[i][j] == 0) {
          dfs(grid2, i, j);
        }
      }
    }
    int count = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid2[i][j] == 1) {
          count++;
          dfs(grid2, i, j);
        }
      }
    }
    return count;
  }
  void dfs(vector<vector<int>>& grid, int i, int j) {
    int rows = grid.size(), cols = grid[0].size();
    if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) return;

    grid[i][j] = 0;
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }
};
