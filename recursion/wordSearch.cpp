#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &graph, string word, int i, int j, int index) {
  if (index == word.size()) return true;
  if (i < 0 || j < 0 || i >= graph.size() || j >= graph[0].size() ||
      graph[i][j] != word[index]) {
    return false;
  }
  char temp = graph[i][j];
  graph[i][j] = '#';
  bool found = dfs(graph, word, i + 1, j, index + 1) ||  // down
               dfs(graph, word, i - 1, j, index + 1) ||  // up
               dfs(graph, word, i, j + 1, index + 1) ||  // right
               dfs(graph, word, i, j - 1, index + 1);    // left
  graph[i][j] = temp;

  return found;
}
void generate(int n, int open, int close, string current, vector<string> &ans) {
  if (current.size() == n * 2) {
    ans.push_back(current);
    return;
  }

  if (open < n) generate(n, open + 1, close, current + '(', ans);
  if (close < open) generate(n, open, close + 1, current + ')', ans);
}

vector<int> generateParenthis(int n) {
  vector<string> ans;
  generate(n, 0, 0, "", ans);
  return ans;
}

bool exist(vector<vector<char>> &graph, string word) {
  for (int i = 0; i < graph.size(); i++) {
    for (int j = 0; j < graph[0].size(); j++) {
      if (graph[i][j] == word[0]) {
        if (dfs(graph, word, i, j, 0)) return true;
      }
    }
  }
  return false;
}
int main() {
  vector<vector<char>> graph = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  string word = "ABCCED";

  if (exist(graph, word)) {
    cout << "Word found in the grid!" << endl;
  } else {
    cout << "Word not found in the grid." << endl;
  }

  return 0;
}

class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.size() < t.size()) {
      return "";
    }

    vector<int> target_freq(128, 0);
    vector<int> required_freq(128, 0);

    for (char c : t) {
      target_freq[c]++;
    }

    int left = 0;
    int minLength = INT_MAX;
    int minStart = 0;
    int required = 0;
    int formedChars = 0;

    for (int i = 0; i < 128; i++) {
      if (target_freq[i] > 0) {
        required++;
      }
    }
    for (int right = 0; right < s.size(); right++) {
      char c = s[right];
      required_freq[c]++;

      if (target_freq[c] > 0 && target_freq[c] == required_freq[c]) {
        formedChars++;
      }
      while (required == formedChars) {
        if (right - left + 1 < minLength) {
          minLength = right - left + 1;
          minStart = left;
        }

        char leftChar = s[left];
        required_freq[leftChar]--;
        if (target_freq[leftChar] > 0 &&
            target_freq[leftChar] < required_freq[leftChar]) {
          required++;
        }
        left++;
      }
    }

    return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
  }
};

class Solution {
 public:
  int maximumUniqueSubarray(vector<int> &nums) {
    unordered_set<int> set;
    int left = 0;
    int ans = 0;
    int currSum = 0;
    for (int right = 0; right < nums.size(); right++) {
      /* code */
      if (set.insert(nums[right]) == set.end()) {
        set.insert(nums[right]);
        currSum += nums[right];
      } else {
        while (set.find(nums[right]) != set.end()) {
          set.erase(nums[left]);
          currSum -= nums[left];
          left++;
        }
        set.insert(nums[right]);
        currSum += nums[right];
      }
      ans = max(ans, currSum);
    }
    return ans;
  }
};

