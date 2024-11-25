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

class Solution {
 public:
  vector<int> goodIndices(vector<int> &nums, int k) {
    int n = nums.size();
    if (n < 2 * k) return {};
    vector<int> left(n + 1, 1);
    vector<int> right(n + 1, 1);
    for (int i = 1; i < n; i++) {
      if (nums[i] <= nums[i - 1]) {
        left[i] = left[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] <= nums[i + 1]) {
        right[i] = 1 + right[i + 1];
      }
    }

    vector<int> result;
    for (int i = k; i < n; i++) {
      if (left[i - 1] >= k && right[i + 1] >= k) {
        result.push_back(i);
      }
    }

    return result;
  }
};

class Solution {
 public:
  int kthFactor(int n, int k) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (n % i == 0) {
        cnt += 1;
        if (cnt == k) return i;
      }
    }
    return -1;
  }
};

class Solution {
 public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                        vector<vector<int>> &items2) {
    vector<vector<int>> answer;
    vector<int> valueMap(1000, 0);
    for (vector<int> &vec : items1) {
      int value = vec[0];
      int weight = vec[1];

      valueMap[value] += weight;
    }

    for (vector<int> &vec : items2) {
      int value = vec[0];
      int weight = vec[1];
      valueMap[value] += weight;
    }

    for (int i = 0; i < valueMap.size(); i++) {
      if (valueMap[i] != 0) {
        answer.push_back({i, valueMap[i]});
      }
    }
    return answer;
  }
};

class Solution {
 public:
  bool isPathCrossing(string path) {
    int x = 0, y = 0;
    unordered_set<string> set;
    set.insert("0,0");
    for (char direction : path) {
      if (direction == 'N')
        y++;
      else if (direction == 'S')
        y--;
      else if (direction == 'E')
        x++;
      else if (direction == 'W')
        x--;

      string currentpath = to_string(x) + "," + to_string(y);
      if (set.count(currentpath)) return true;
      set.insert(currentpath);
    }
    return false;
  }
};

class Solution {
 public:
  int distributeCandies(vector<int> &candyType) {
    unordered_set<int> set(candyType.begin(), candyType.end());
    int size = candyType.size() / 2;
    return min(set.size(), size);
  }
};
class Solution {
 public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string start = "";
    for (int i = 0; i < 2; i++) {
      /* code */
      for (int j = 0; j < 3; j++) {
        start += to_string(board[i][j]);
      }
    }
    string target = "123450";
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5},
                                     {0, 4}, {1, 3, 5}, {2, 4}};

    queue<pair<int, string>> q;
    q.push({0, start});
    unordered_set<string> visited;
    visited.insert(start);

    while (!q.empty()) {
      auto it = q.front();
      string currentString = it.second;
      int moves = it.first;
      if (currentString == target) {
        return moves;
      }

      int zeroIdx = currentString.find('0');
      for (int neighbour : neighbors[zeroIdx]) {
        string tempString = currentString;
        swap(tempString[zeroIdx], tempString[neighbour]);

        if (visited.find(tempString) == visited.end()) {
          q.push({moves + 1, tempString});
          visited.insert(tempString);
        }
      }
    }
    return -1;
  }
};
class Solution {
 public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string start = "";
    for (int i = 0; i < 2; i++) {
      /* code */
      for (int j = 0; j < 3; j++) {
        start += to_string(board[i][j]);
      }
    }
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5},
                                     {0, 4}, {1, 3, 5}, {2, 4}};

    string target = "123450";
    int moves = 0;
    queue<string> q;
    unordered_set<string> visited;
    q.push(start);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        string currentString = q.front();
        q.pop();
        if (currentString == target) return moves;
        int zeroindex = currentString.find('0');
        for (int neighbour : neighbors[zeroindex]) {
          string tempString = currentString;
          swap(tempString[zeroindex], tempString[neighbour]);
          if (visited.find(tempString) == visited.end()) {
            visited.insert(tempString);
            q.push(tempString);
          }
        }
      }
      moves++;
    }
    return -1;
  }
};

class Solution {
 public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string start = "";
    for (int i = 0; i < 2; i++) {
      /* code */
      for (int j = 0; j < 3; j++) {
        start += to_string(board[i][j]);
      }
    }
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5},
                                     {0, 4}, {1, 3, 5}, {2, 4}};

    string target = "123450";
    unordered_set<string> visited;
    int minMovs = INT_MAX;
    dfs(start, target, neighbors, visited, 0, minMovs);
    if (minMovs == INT_MAX) return -1;
    return minMovs;
  }
  void dfs(string start, string &target, vector<vector<int>> &neighbors,
           unordered_set<string> &visited, int moves, int &minMoves) {
    if (start == target) {
      minMoves = min(moves, minMoves);
      return;
    }
    if (visited.count(start)) return;
    int zeroIdx = start.find('0');

    for (int negibour : neighbors[zeroIdx]) {
      string temp = start;
      swap(temp[zeroIdx], temp[negibour]);
      dfs(temp, target, neighbors, visited, moves + 1, minMoves);
    }

    visited.erase(start);
  }
};
class Solution {
 public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string start = "";
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        start += to_string(board[i][j]);
      }
    }

    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5},
                                     {0, 4}, {1, 3, 5}, {2, 4}};

    string target = "123450";
    unordered_set<string> visited;
    int minMoves = INT_MAX;

    dfs(start, target, neighbors, visited, 0, minMoves);
    return minMoves == INT_MAX ? -1 : minMoves;
  }

 private:
  void dfs(string current, string &target, vector<vector<int>> &neighbors,
           unordered_set<string> &visited, int moves, int &minMoves) {
    if (current == target) {
      minMoves = min(moves, minMoves);
      return;
    }
    if (visited.count(current) || moves >= minMoves) {
      return;
    }
    visited.insert(current);
    int zeroIdx = current.find('0');
    for (int neighbor : neighbors[zeroIdx]) {
      string nxtstr = current;
      swap(nxtstr[zeroIdx], nxtstr[neighbor]);
      dfs(nxtstr, target, neighbors, visited, moves + 1, minMoves);
    }
    visited.erase(current);
  }
};
