#include <bits/stdc++.h>
#include <string.h>
#include <strings.h>
using namespace std;

class Solution {
 public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (const auto& wall : walls) {
      grid[wall[0]][wall[1]] = -1;
    }
    for (const auto& guard : guards) {
      grid[guard[0]][guard[1]] = -2;
    }
    for (const auto& guard : guards) {
      int x = guard[0];
      int y = guard[1];
      for (const auto& [dx, dy] :
           vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
        int nx = x + dx;
        int ny = y + dy;

        while (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] != -1 &&
               grid[nx][ny] != -2) {
          if (grid[nx][ny] == 0) {
            grid[nx][ny] = -3;
          }
          nx += dx;
          ny += dy;
        }
      }
    }
    int unguardedCount = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          unguardedCount++;
        }
      }
    }
    return unguardedCount;
  }
};

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trustCount(n + 1, 0);

    for (auto& t : trust) {
      trustCount[t[0]]--;
      trustCount[t[1]]++;
    }

    for (int i = 1; i <= n; i++)
      if (trustCount[i] == n - 1) return i;
    return -1;
  }
};

class Solution {
 public:
  vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    vector<pair<int, pair<int, int>>> cells;
    for (int i = 0; i < m; i++) {
      /* code */
      for (int j = 0; j < n; j++) {
        /* code */
        cells.push_back({matrix[i][j], {i, j}});
      }
    }

    sort(cells.begin(), cells.end());

    for (auto& cell : cells) {
      int x = cell.second.first;
      int y = cell.second.second;

      for (auto& dir : directions) {
        int newX = dir.first + x;
        int newY = dir.second + y;

        if (newX >= 0 && newY >= 0 && newX < m && newY < n &&
            matrix[x][y] < matrix[newX][newY]) {
          dp[x][y] = max(dp[x][y], dp[newX][newY] + 1);
        }
      }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
      /* code */
      for (int j = 0; j < n; j++) {
        res = max(res, matrix[i][j]);
      }
    }
    return res;
  }
};

int lcs(string s1, string s2, int i, int j) {
  if (i == 0 || j == 0) {
    return 0;
  }

  if (s1[i - 1] == s2[j - 1]) {
    return 1 + lcs(s1, s2, i - 1, j - 1);
  }

  return max(lcs(s1, s2, i - 1, j), lcs(s1, s2, i, j - 1));
}

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int n : nums) {
      total += n;
    }
    if (total % 2 != 0) return false;
    int target = total / 2;
    vector<vector<bool>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < target; j++) {
        if (nums[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j] +
        } else {
          // dp[i][j] = dp[i][j-1];
          dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
        }
      }
    }
    return dp[n][target];
  }
};
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int n : nums) {
      total += n;
    }
    if (total % 2 != 0) return false;
    vector<vector<int>> dp(total / 2 + 1, vector<int>(nums.size(), -1));
    return solve(nums, total / 2, 0, dp);
  }
  bool solve(vector<int>& nums, int target, int index,
             vector<vector<int>>& dp) {
    if (target == 0) {
      return true;
    }
    if (target > 0 || index > nums.size() - 1) {
      return false;
    }
    if (dp[target][index] != -1) return dp[target][index];
    bool include = solve(nums, target - nums[index], index + 1, dp);
    bool exclude = solve(nums, target, index + 1, dp);
    dp[target][index] = include || exclude;
    return dp[target][index];
  }
};

bool canPossible(vector<int>& stalls, int k, int mid) {
  int count = 1;
  int lastPostion = stalls[0];
  for (int i = 1; i < stalls.size(); i++) {
    if (stalls[i] - lastPostion >= mid) {
      count++;
      lastPostion = stalls[i];
      if (count == k) return true;
    }
  }
  return false;
}

int agrresizeCows(vector<int>& stalls, int k) {
  sort(stalls.begin(), stalls.end());
  int low = 1;
  int high = stalls.back() - stalls[0];

  int res = 0;
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (canPossible(stalls, k, mid)) {
      res = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return res;
}

class Solution {
 public:
  bool isPossible(vector<int>& nums, int threshold, int mid) {
    int sum = 0;
    for (int n : nums) {
      sum += (n + mid - 1) / mid;
    }
    return sum <= threshold;
  }
  int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int res = high;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (isPossible(nums, threshold, mid)) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return res;
  }
};

class Solution {
 public:
  bool check(vector<int>& nums, int m, int maxSum) {
    int curr = 0;
    int split = 1;
    for (int n : nums) {
      if (curr + n > maxSum) {
        split++;
        curr = n;
        if (split > m) return false;
      } else {
        curr += n;
      }
    }
    return true;
  }
  int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    int res = high;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (check(nums, k, mid)) {
        res = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return res;
  }
};
bool isAllocationPossible(const vector<int>& books, int students,
                          int maxPages) {
  int studentCOunt = 0;
  int pagesSum = 0;
  for (int pages : books) {
    if (pages > maxPages) {
      return false;
    }

    if (pagesSum + pages > maxPages) {
      studentCOunt++;
      pagesSum = pages;
      if (studentCOunt > students) return false;
    }
  }
  return true;
}

bool isallocate(const vector<int>& books, int students, int maxPages) {
  int studentCOunt = 0;
  int totalPages = 0;
  for (int pages : books) {
    if (totalPages + pages > maxPages) {
      studentCOunt++;
      totalPages = pages;
      if (studentCOunt > students) return false;
    }
    // else
  }
  return true;
}

int allocateMinimumPages(vector<int>& books, int students) {
  if (books.size() < students) {
    return -1;
  }

  int low = *max_element(books.begin(), books.end());
  int high = accumulate(books.begin(), books.end(), 0);
  int res = 0;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (isAllocationPossible(books, students, mid)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return res;
}
class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    int maxPairs = 0;
    while (left < right) {
      int pairSum = nums[left++] + nums[right--];
      maxPairs = max(maxPairs, pairSum);
    }
    return maxPairs;
  }
};

bool canPossibleToCut(vector<int>& sweetness, int k, int sweetnes) {
  int piecs = 0, currSum = 0;
  for (int s : sweetness) {
    currSum += s;
    if (currSum >= sweetnes) {
      piecs++;
      currSum = 0;
    }
  }
  return piecs >= k + 1;
}

int maximizeSweetness(vector<int>& sweetness, int k) {
  int low = 1, high = accumulate(sweetness.begin(), sweetness.end(), 0);

  int result = high;
  while (low <= high) {
    int mid = (high - low) / 2;
    if (canPossibleToCut(sweetness, k, mid)) {
      result = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
}

class Solution {
 public:
  bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] - nums[i] <= maxDiff) {
        count++;
        i++;
      }
    }

    return count >= p;
  }
  int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    int low = 0, high = nums.back() - nums.front();
    int result = high;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      if (canFormPairs(nums, p, mid)) {
        result = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return result;
  }
};

class Solution {
 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int response = 0;
    for (auto& currRow : matrix) {
      vector<int> inverted(n);

      for (int col = 0; col < n; col++) {
        inverted[col] = currRow[col] == 0 ? 1 : 0;
      }
      int count = 0;
      for (auto& row : matrix) {
        if (row == currRow || row == inverted) {
          count++;
        }
      }
      response = max(response, count);
    }
    return response;
  }
};

class Solution {
 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> mp;

    for (const auto& row : matrix) {
      string orignal, reversed;
      for (int nums : row) {
        orignal += to_string(nums);
        int val = nums == 0 ? 1 : 0;
        reversed += to_string(val);
      }

      mp[min(orignal, reversed)]++;
    }

    int maxRows = 0;
    for (const auto& [pattern, count] : mp) {
      maxRows = max(maxRows, count);
    }
    return maxRows;
  }
};
class Solution {
 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> mp;
    int maxSum = 0;
    for (const auto& row : matrix) {
      string orignal, reversed;
      for (int& cell : row) {
        orignal += to_string(cell);
        int revValue = cell == 0 ? 1 : 0;
        reversed += to_string(revValue);
      }
      mp[orignal]++;
      maxSum = max(maxSum, mp[orignal]);
      mp[reversed]++;
      maxSum = max(maxSum, mp[reversed]);
    }
    return maxSum;
  }
};

class Solution {
 public:
  int shortestSubarray(vector<int>& nums, int k) {
    int left = 0;
    int minLenght = 0;
    int sum = 0;
    for (int right = 0; right < nums.size(); right++) {
      sum += nums[right];
      while (sum > k) {
        sum -= nums[left++];
        minLenght = min(minLenght, right - left + 1);
      }
    }
    return minLenght;
  }
};

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 1) return {{1}};

    vector<vector<int>> result = generate(numRows - 1);
    vector<int> newRow;
    newRow.push_back(1);
    vector<int> beechKiRow;
  }
};

class Solution {
 public:
  string decodeMessage(string key, string message) {}
};

class Solution {
 public:
  string greatestLetter(string s) {
    if (s.empty()) return "";
    unordered_set<char> freqs;
    for (char c : s) {
      freqs.insert(c);
    }
    string answer = "";
    for (char ch = 'Z'; ch >= 'A'; ch--) {
      if (freqs.find(ch) != freqs.end()) {
        if (freqs.find(tolower(ch)) != freqs.end()) {
          answer += ch;
          return ch;
        }
      }
    }
    return answer;
  }
};

class Solution {
 public:
  string greatestLetter(string s) {
    unordered_set<char> upper, lower;
    for (char c : s) {
      if (isupper(c)) {
        upper.insert(c);
      } else {
        lower.insert(c);
      }
    }

    char result = 0;
    for (char c : lower) {
      if (upper.count(toupper(c))) {
        result = max(result, toupper(c));
      }
    }

    return result ? string(1, result) : "";
  }
};

class Solution {
 public:
  int numberOfSpecialChars(string word) {
    vector<int> lower(26, 0), upper(26, 0);
    int answer = 0;
    for (char c : word) {
      if (isupper(c)) {
        upper[c - 'A']++;
      } else {
        lower[c - 'a']++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (upper[i] > 0 && lower[i] > 0) {
        answer++;
      }
    }

    return answer;
  }
};

// aaAbcBC
class Solution {
 public:
  int numberOfSpecialChars(string word) {
    int answer = 0;
    vector<int> firstupper(26, -1), lastLower(26, -1);
    for (int i = 0; i < word.size(); i++) {
      char c = word[i];

      if (isupper(c)) {
        if (firstupper[c - 'A'] == -1) {
          firstupper[c - 'A'] = i;
        }
      } else {
        lastLower[c - 'a'] = i;
      }
    }
    int specialCount = 0;
    for (int i = 0; i < 26; i++) {
      if (firstupper[i] != -1 && lastLower[i] != -1 &&
          lastLower[i] < firstupper[i]) {
        specialCount++;
      }
    }
    return specialCount;
  }
};
class Solution {
 public:
  int numberOfSpecialChars(string word) {
    vector<int> firstUpper(26, INT_MAX);
    vector<int> lastLower(26, -1);
    for (int i = 0; i < word.length(); i++) {
      char c = word[i];
      if (isupper(c)) {
        firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i);
      } else {
        lastLower[c - 'a'] = i;
      }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
      if (firstUpper[i] != INT_MAX && lastLower[i] != -1 &&
          lastLower[i] < firstUpper[i]) {
        count++;
      }
    }
    return count;
  }
};
class Solution {
 public:
  int countSpecialCharacters(string word) {
    vector<int> firstUpper(26, INT_MAX);
    vector<int> lastLower(26, -1);
    for (int i = 0; i < word.length(); i++) {
      char c = word[i];
      if (isupper(c)) {
        firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i);
      } else {
        lastLower[c - 'a'] = i;
      }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
      if (firstUpper[i] != INT_MAX && lastLower[i] != -1 &&
          lastLower[i] < firstUpper[i]) {
        count++;
      }
    }
    return count;
  }
};

class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    vector<int> charsfreq(26, 0);
    for (char c : chars) {
      charsfreq[c - 'a']++;
    }
    int val = 0;
    for (string& word : words) {
      vector<int> tempFreq(26, 0);
      for (char c : word) {
        tempFreq[c - 'a']++;
      }
      bool flag = true;
      for (int i = 0; i < 26; i++) {
        if (tempFreq[i] > charsfreq[i]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        val += word.size();
      }
    }
    return val;
  }
};
class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    vector<int> charsfreq(26, 0);
    for (char c : chars) {
      charsfreq[c - 'a']++;
    }
    int val = 0;
    for (string& word : words) {
      vector<int> tempFreq = charsfreq;
      bool flag = true;
      for (char c : word) {
        if (--tempFreq[c - 'a'] < 0) {
          flag = false;
          break;
        }
      }
      if (flag) {
        val += word.size();
      }
    }
    return val;
  }
};

class Solution {
 public:
  int minNumber(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set(nums1.begin(), nums1.end());
    int smallcom = 10;
    for (int num : nums2) {
      if (set.count(num)) {
        smallcom = min(smallcom, num);
      }
    }
    if (smallcom != 10) return smallcom;

    int first = *min_element(nums1.begin(), nums1.end());
    int second = *min_element(nums2.begin(), nums2.end());
    if (first > second) {
      return second * 10 + first;
    } else {
      return first * 10 + second;
    }
    // return min(first * 10 + second, second * 10 + first);
  }
};

class Solution {
 public:
  vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                   int x) {
    unordered_map<int, vector<int>> occurrences;
    for (int i = 0; i < nums.size(); i++) {
      occurrences[nums[i]].push_back(i);
    }

    vector<int> answer;
    for (int q : queries) {
      if (q > 0 && q <= occurrences[x].size()) {
        // -1 due to 0 based indexing
        answer.push_back(occurrences[x][q - 1]);
      } else {
        answer.push_back(-1);
      }
    }

    return answer;
  }
};

bool canCut(vector<int>& ropes, int k, int length) {
  int count = 0;
  for (int rope : ropes) {
    count += abs(rope / length);
  }
  return count >= k;
}

class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();

    for (int i = 0; i < m; i++) {
      int empty = n - 1;
      for (int j = n - 1; j >= 0; j--) {
        if (box[i][j] == '#') {
          box[i][j] = '.';
          box[i][empty] = '#';
          empty--;
        } else if (box[i][j] == '*') {
          empty = j - 1;
        }
      }
    }
    vector<vector<char>> rotateBoxed(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
      /* code */
      for (int j = 0; j < n; j++) {
        /* code */
        rotateBoxed[j][i] = box[i][j];
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        rotateBoxed[j][m - i - 1] = box[i][j];
      }
    }
    return rotateBoxed;
  }
};

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (const string& str : strs) {
      string sorted = str;
      sort(sorted.begin(), sorted.end());
      mp[sorted].push_back(str);
    }

    vector<vector<string>> answer;
    for (const auto& pair : mp) {
      answer.push_back(pair.second);
    }
    return answer;
  }
};

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;
    for (int num : numSet) {
      if (!numSet.count(num - 1)) {
        int currentLong = 1;
        int curNum = num;
        while (numSet.count(curNum + 1)) {
          curNum += 1;
          currentLong++;
        }

        longest = max(longest, currentLong);
      }
    }
    return longest;
  }
};
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = vec.size();
    sort(vec.begin(), vec.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      /* code */
      vector<int>& vec = ans.empty() ? intervals[i] : ans.back();
      if (ans.empty() || vec[1] < intervals[i][0]) {
        ans.push_back(intervals[i]);
      } else {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
    }

    return ans;
  }
};

void sieveOfEratosthenes(int n) {
  vector<bool> isPrims(n + 1, false);
  isPrims[0] = isPrims[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (isPrims[i]) {
      for (int j = i * i; j <= n; j+=i) {
        isPrims[j] = false;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    /* code */
    if (isPrims[i]) {
      /* code */
      cout << i << endl;
    }
  }
}

int findGcd(int a , int b) {
  while(b>0) {
    int rem = a%b;
    findGcd(b,a);
  }

  return a;
}

int findsubarraywithSumk(vector<int> &arr , int k ) {
  unordered_map<int,int> prefixCount;
  prefixCount[0]=1;
  int prefixSum = 0 , count = 0;
  for(int num :arr){
    prefixSum+= num;
    if(prefixCount.find(prefixSum-k) != prefixCount.end()) {
      count+= prefixCount[prefixSum-k];
    }

    prefixCount[pref]
  }
}