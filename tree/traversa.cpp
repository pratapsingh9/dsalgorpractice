#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string decodeMessage(string key, string message) {
    unordered_map<char, int> map;
    char currentChar = 'a';

    for (char c : key) {
      if (c != ' ' && map.find(c) == map.end()) {
        map[c] = currentChar++;
      }
    }
    string decodedString = "";
    for (char c : message) {
      if (c == ' ') {
        decodedString += ' ';
      } else {
        decodeMessage += map[c];
      }
    }
    return decodedString;
  }
};

class Solution {
 public:
  void generateCombineHelper(vector<vector<int>> &result, vector<int> &temp,
                             int n, int k, int start) {
    if (temp.size() == k) {
      result.push_back(temp);
      return;
    }
    if (start > n) return;
    temp.push_back(start);
    // include
    generateCombineHelper(result, temp, n, k, start + 1);
    temp.pop_back(start);
    generateCombineHelper(result, temp, n, k, start + 1);
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> ans;
    generateCombineHelper(result, ans, n, k, 1);
    return result;
  }
};

class Solution {
 public:
  int duplicateNumbersXOR(vector<int> &nums) {
    unordered_set<int> seen;
    int ans = 0;
    for (int num : nums) {
      if (seen.count(num)) {
        ans ^= num;
      } else {
        seen.insert(num);
      }
    }
    return ans;
  }
};

class Solution {
 public:
  vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
      mp[nums[i]] = i;
    }

    for (vector<int> &operation : operations) {
      int oldValue = operation[0];
      int newValue = operation[1];

      int idx = mp[oldValue];
      nums[idx] = newValue;

      mp[newValue] = idx;
      mp.erase(oldValue);
    }

    return nums;
  }
};

class Solution {
 public:
  int findPermutationDifference(string s, string t) {
    unordered_map<char, int> indexMap;
    for (int i = 0; i < s.size(); i++) {
      indexMap[s[i]] = i;
    }

    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
      /* code */
      char ch = t[i];
      char sindex = indexMap[ch];
      answer += abs(sindex - i);
    }
    return answer;
  }
};

class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    vector<int> positon(26, -1);
    int ans = -1;

    for (int i = 0; i < s.size(); i++) {
      /* code */
      if (positon[s[i] - 'a'] == -1) {
        positon[s[i] - 'a'] = i;
      } else {
        ans = max(ans, i - positon[s[i] - 'a'] - 1);
      }
    }
    return ans;
  }
};

class Solution {
 public:
  string clearDigits(string s) {
    int i = 0;
    while (i < s.size()) {
      if (isdigit[s[i]]) {
        int j = i - 1;
        while (j >= 0 && isdigit(s[j])) {
          j--;
        }

        if (j >= 0) {
          s.erase(j, 2);
          i = j;
        } else {
          s.erase(i, 1);
        }
      } else {
        i++;
      }
    }
    return s;
  }
};

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, char> stot, ttos;

    for (int i = 0; i < s.size(); i++) {
      /* code */
      char schar = s[i];
      char tchar = t[i];

      if (stot.count()) }
  }
};

class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    long long sum = 0;
    int shortestNum = INT_MAX;
    int negativeCount = 0;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      /* code */
      for (int j = 0; j < n; j++) {
        /* code */
        sum += abs(matrix[i][j]);
        if (matrix[i][j] < 0) {
          negativeCount++;
        }
        shortestNum = min(shortestNum, abs(matrix[i][j]));
      }
    }
    return negativeCount % 2 == 0 ? sum : sum - (2 * shortestNum);
  }
};

vector<vector<int>> changedMatrix(vector<vector<int>> &matrix) {
  int shortestNum = 0;
  int negativeCount = 0;
  int n = matrix.size();
  int minRow = -1, minColumn = -1;
  for (int i = 0; i < n; i++) {
    /* code */
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] < 0) {
        negativeCount++;
      }
      if (abs(matrix[i][j]) < shortestNum) {
        shortestNum = abs(matrix[i][j]);
        minRow = i;
        minColumn = j;
      }
    }
  }
}

class NumArray {
 public:
  vector<int> prefixSum;
  NumArray(vector<int> &nums) {
    prefixSum.resize(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    return prefixSum[right + 1] - prefixSum[left];
  }
};

class NumArray {
 public:
  vector<int> prefix;
  NumArray(vector<int> &nums) {
    prefix.push_back(0);
    for (int num : nums) {
      prefix.push_back(prefix.back() + num);
    }
  }

  int sumRange(int left, int right) { return prefix[right + 1] - prefix[left]; }
};

class Solution {
 public:
  vector<int> leftRightDifference(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefixSum(n, 0);
    vector<int> suffixSum(n, 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    suffixSum[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i++) {
      suffixSum[i] = suffixSum[i + 1] + nums[i];
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      int leftSum = (i == 0) ? 0 : prefixSum[i - 1];
      int rightSum = (i == n - 1) ? 0 : suffixSum[i + 1];
      ans[i] = abs(leftSum - rightSum);
    }

    return ans;
  }
};

class Solution {
 public:
  bool isVowel(char ch) {
    static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.count(ch);
  }
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    vector<int> answer;
    vector<int> prefixWords(words.size(), 0);
    for (int i = 0; i < words.size(); i++) {
      const string &currentString = words[i];
      int n = currentString.size();
      if (isVowel(currentString[0]) && isVowel(currentString[n - 1])) {
        prefixWords[i] = 1;
      }
    }
    for (int i = 1; i < prefixWords.size(); i++) {
      prefixWords[i] += prefixWords[i - 1];
    }
    for (auto &query : queries) {
      int left = query[0];
      int right = query[1];
      int value = prefixWords[right];
      if (left > 0) value -= prefixWords[left - 1];
      answer.push_back(value);
    }
    return answer;
  }
};

class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    int totalSum = 0;
    int n = nums.size();
    int leftSum = 0;
    vector<int> answer(nums.size(), 0);
    for (int num : nums) {
      totalSum += num;
    }

    for (int i = 0; i < nums.size(); i++) {
      /* code */
      int rightsum = totalSum - leftSum - nums[i];
      int leftCount = i;
      int rightCount = n - i - 1;

      answer[i] =
          (nums[i] * leftCount - leftSum) + (rightsum - rightCount * nums[i]);
      // answer[i] = abs((nums[i] * n) - totalSum);
      leftSum += nums[i];
    }
    return answer;
  }
};

class Solution {
 public:
  typedef long long ll;
  bool isWorking(vector<int> &beans, ll x, ll total) {
    int n = beans.size();
    for (int i = 0; i < n; i++) {
      ll removal = total - (ll)(n * o)
    }
  }
  long long minimumRemoval(vector<int> &beans) {
    sort(begin(beans), end(beans));
    int n = beans.size();
    ll total = 0;
    for (int num : beans) total += num;
    long long low = 0, high = total, result = total;

    while (low <= high) {
      ll mid = low + (high - low) / 2;
      if (isWorking(beans, mid, total)) {
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
  typedef long long ll;

  long long minimumRemoval(vector<int> &jellyBeans) {
    int totalBags = jellyBeans.size();
    sort(jellyBeans.begin(), jellyBeans.end());
    vector<long long> beanAccumulation(totalBags, 0);
    beanAccumulation[0] = jellyBeans[0];

    for (int i = 1; i < totalBags; ++i) {
      beanAccumulation[i] = beanAccumulation[i - 1] + jellyBeans[i];
    }

    long long fullBeanCount = beanAccumulation[totalBags - 1];
    long long beanEviction = LLONG_MAX;

    for (int i = 0; i < totalBags; ++i) {
      long long removalCost =
          fullBeanCount - (long long)(totalBags - i) * jellyBeans[i];
      beanEviction = min(beanEviction, removalCost);
    }

    return beanEviction;
  }
};

class ProductOfNumbers {
 public:
  vector<int> prefixSum;
  ProductOfNumbers() { prefixSum.push_back(1); }

  void add(int num) {
    if (num == 0) {
      prefixSum.clear();
      prefixSum.push_back(1);
    } else {
      prefixSum.push_back(prefixSum.back() * num);
    }
  }

  int getProduct(int k) {
    int size = prefixSum.size();
    if (k >= size) return 0;
    return prefixSum.back() / prefixSum[n - k - 1];
  }
};

class TrieNode {
  TrieNode *children[26];
  bool isEndOfWord;

  TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
}

class WordDictionary {
 public:
  TrieNode *root;
  WordDictionary() { root = new TrieNode(); }

  void addWord(string word) {
    TrieNode *crawler = root;
    for (char c : word) {
      int index = c - 'a';
      if (!crawler->children[index]) {
        crawler->children[index] = new TrieNode();
      }
      crawler = crawler->children[index];
    }
    crawler->isEndOfWord = true;
  }

  bool search(string word) { return searchHelper(word, root, 0); }

  bool searchHelper(const string &word, TrieNode *root, int index) {
    if (index == word.size()) {
      return root->isEndOfWord;
    }

    char c =
  }
};

class Solution {
 public:
  string reorganizeString(string s) {
    vector<int> freq(26, 0);

    for (char c : s) {
      freq[c - 'a']++;
    }

    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++) {
      /* code */
      if (freq[i] > 0) {
        pq.push({freq[i], 'a' + i});
      }
    }
    if (pq.top().first > (s.size() + 1) / 2) {
      return "";
    }

    string result = "";
    while (pq.size() > 1) {
      auto first = pq.top();
      pq.pop();
      auto second = pq.top();
      pq.pop();
      result += first.second;
      result += second.second;

      if (--first.first > 0) pq.push(first);
      if (--second.first > 0) pq.push(second);
    }
    if (!pq.empty()) {
      result += pq.top().second;
    }
    return result;
  }
};

class Solution {
 public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = heights.size();
    for (int i = 1; i < n; i++) {
      /* code */
      int diff = heights[i] - heights[i - 1];
      if (diff <= 0) continue;

      pq.push(diff);
      // pq m push karidya agar ladders ki kami pad rhi h toh bricks use kardi
      // for chotha difference kids
      if (pq.size() > ladders) {
        // chotha hieghts ko hata diya isse
        bricks -= pq.top();
        pq.pop();
      }
      // bricks bhi kahatam toh return krardon kaha tak gaye apan
      if (bricks < 0) return i - 1;
    }
    return heights.size() - 1;
  }
};

struct Song {
  string name;
  int listenCount;
  time_t lastPlayed;

  Song(string n, int l, time_t t) : name(n), listenCount(l), lastPlayed(t) {}
};

class Solution {
 public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());

    int left = 0, rigth = people.size() - 1;
    int answer = 0;
    while (left <= rigth) {
      if (people[left] + people[rigth] <= limit) {
        left += 1;
      }
      rigth -= 1;
      answer++;
    }
    return answer;
  }
};


class Solution{
  public:
  int numberRescueBoats(vector<int> &boats , int limit) {
    sort(boats.begin(), boats.end());
    int left = 0, right = boats.size() - 1;
    int answer = 0;
    while(left <= right) {
      if(boats[left] + boats[right] <= limit) {
        left += 1;
      }
      right -= 1;
      answer++;
    }
    return answer;
  }
}