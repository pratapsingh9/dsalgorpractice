#include <bits/stdc++.h>

#include <iostream>
using namespace std;

bool Isanagram(string s, string t) {
  if (s.size() != t.size()) return false;
  vector<int> freq(26, 0);
  for (int i = 0; i < s.size(); i++) {
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']--;
  }
  for (int ele : freq) {
    if (ele != 0) return false;
  }

  return true;
}

bool Isanagram(string s, string t) {
  if (s.size() != t.size()) return false;
  vector<int> freq(26, 0);
  for (int i = 0; i < 26; i++) {
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']--;
  }
  for (int ele : freq) {
    if (ele != 0) return false;
  }
  return true;
}

bool isAnagram(string s, string t) {
  if (s.length() != t.length()) return false;
  vector<int> freq(26, 0);
  for (int i = 0; i < s.length(); i++) {
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']++;
  }
  for (auto ele : freq) {
    if (ele != 0) return false;
  }
  return true;
}

void showFrequency(string s) {
  vector<int> frequency(26, 0);

  for (auto ele : s) {
    if (isalpha(ele)) {
      frequency[tolower(ele) - 'a']++;
    }
  }

  for (int i = 0; i < 26; i += 1) {
    if (frequency[i] > 0) {
      cout << char(i + 'a') << " have appeared " << frequency[i] << endl;
    }
  }
}

int main() {
  string s = "pratapsinghsidoiya";

  showFrequency(s);
}

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < N; i++) cin >> A[i];  // Front values
    for (int i = 0; i < N; i++) cin >> B[i];  // Back values

    int maxy1 = 0;
    int maxy2 = 0;
  }
}

int main() {
  // your code goes here
  solve();
}
int currencyRequired(int amount) {
  // 500
  vector<int> ans(2000, 500, 200, 100, 50, 20, 10, 5, 1);
  int res = 0;
  for (int i = 0; i < ans.size(); i++) {
    while (amount > ans[i]) {
      amount -= ans[i];
      res++;
    }
  }
  return res;
}

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    // Handle empty matrix
    if (mat.empty() || mat[0].empty()) return {};

    int m = mat.size();     // number of rows
    int n = mat[0].size();  // number of columns
    vector<int> result;
    result.reserve(m * n);  // Reserve space for optimization

    bool goingUp = true;

    int row = 0, col = 0;

    while (result.size() < m * n) {
      result.push_back(mat[row][col]);

      if (goingUp) {
        if (col == n - 1) {
          row++;
          goingUp = false;
        } else if (row == 0) {
          col++;
          goingUp = false;
        } else {
          row--;
          col++;
        }
      } else {
        if (row == m - 1) {
          col++;
          goingUp = true;
        } else if (col == 0) {
          row++;
          goingUp = true;
        } else {
          row++;
          col--;
        }
      }
    }

    return result;
  }
};

class Solution {
 public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      pq.push({nums[i], i});
    }
    vector<int> ans(n, 0);
    while (k--) {
      int number = pq.top().first;
      int index = pq.top().second;
      pq.pop();
      int newValue = number * multiplier;
      ans[index] = newValue;
      pq.push({newValue, index});
    }
    return ans;
  }
};

class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> inDegree(n, 0);
    for (auto& egde : edges) {
      inDegree[egde[0]]++;
      inDegree[egde[1]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (inDegree[i] == n - 1) {
        return i;
      }
    }
    return -1;
  }
};

class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    vector<int> freq(26, 0);
    for (char c : s) {
      freq[c - 'a']++;
    }
    priority_queue<pair<char, int>> pq;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > 0) {
        pq.push({(char)(i + 'a'), freq[i]});
      }
    }
    string answer;
    while (!pq.empty()) {
      char ch = pq.top().first;
      int frequency = pq.top().second;
      pq.pop();
      int ableToused = min(repeatLimit, frequency);
      answer.append(ableToused, ch);
      frequency -= ableToused;
      if (frequency > 0) {
        if (!pq.empty()) {
          int nextCh = pq.top().first;
          int nxtFrequency = pq.top().second;
          pq.pop();
          answer.push_back(nextCh);
          nxtFrequency--;
          if (nxtFrequency > 0) {
            pq.push({nextCh, nxtFrequency});
          }
          pq.push({ch, frequency});
        }
      }
    }
    return answer;
  }
};

class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int, int>> soldierCount;
    for (int i = 0; i < mat.size(); i++) {
      int count = 0;
      for (int v : mat[i]) {
        if (v == 1)
          count++;
        else
          break;
      }
      soldierCount.push_back({count, i});
    }

    sort(soldierCount.begin(), soldierCount.end());
    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(soldierCount[i].second);
    }
    return result;
  }
};

class Solution {
 public:
  typedef pair<int, int> P;
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    priority_queue<P, vector<P>, greater<P>> pq;
    for (int i = 0; i < mat.size(); i++) {
      int count = 0;
      for (int v : mat[i]) {
        if (v == 1)
          count++;
        else
          break;
      }
      pq.push({count, i});
    }

    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    return result;
  }
};

int gcd(int a, int) {
  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int gcdre(int a, int b) {
  if (b == 0) return a;
  return gcdre(b, a % b);
}

class Solution {
 public:
  int countPaths(int n, vector<vector<int>>& roads) {
    const int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> graph(n);
    for (auto road : roads) {
      int u = road[0], v = road[1], weight = road[2];

      graph[u].emplace_back(v, weight);
      graph[v].emplace_back(u, weight);
    }

    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    dist[0] = 0;
    dist[1] = 1;
  }
};

class Solution {
 public:
  bool backtrack(string& current, string& pattern, vector<bool>& visited,
                 string& result) {
    if (current.size() == pattern.size() + 1) {
      result = current;
      return;
    }

    for (int i = 1; i <= 9; i++) {
      if (visited[i]) continue;
      if (!current.empty()) {
        char temp = current.back();
        if ((pattern[current.size() - 1] == 'I' && temp - '0' >= i) ||
            (pattern[current.size() - 1] == 'D' && temp - '0' <= i)) {
          continue;
        }
      }
      visited[i] = true;
      current.push_back(i + '0');
      if (backtrack(current, pattern, visited, result)) return true;
      current.pop_back();
      visited[i] = false;
    }
    return true;
  }
  string smallestNumber(string pattern) {
    int n = pattern.size();
    string result = "";
    vector<bool> visited(10, false);
    backtrack("", pattern, visited, result);
    return result;
  }
};

class Solution {
 public:
  string smallestNumber(string pattern) {
    stack<int> st;
    string result = "";
    int num = 1;

    for (char c : pattern) {
      st.push(c);
      num++;
      if (c == 'I') {
        while (!st.empty()) {
          result += to_string(st.top());
          st.pop();
        }
      }
    }
    st.push(num);
    while (!st.empty()) {
      result += to_string(st.top());
    }
    return result;
  }
};

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
      /* code */
      if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" &&
          tokens[i] != "/") {
        st.push(stoi(tokens[i]));
      } else {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (tokens[i] == "+")
          st.push(a + b);
        else if (tokens[i] == "/")
          st.push(a / b);
        else if (tokens[i] == "-")
          st.push(a - b);
        else if (tokens[i] == "*")
          st.push(a * b);
      }
    }

    return st.top();
  }
};

class Solution {
 public:
  string simplifyPath(string path) {
    stack<string> st;
    string dir;
    path += '/';

    for (char c : path) {
      if (c == '/') {
        if (dir == '..') {
          if (!st.empty()) {
            st.pop();
          }
        } else if (c == '.' && !dir.empty()) {
          st.push(dir);
        }

        dir = "";
      } else {
        dir += c;
      }
    }

    if (st.empty()) return "/";
    string result = "";
    while (!st.empty()) {
      result = "/" + st.top() + result;
      st.pop();
    }
    return result;
  }
};

class Solution {
 public:
  int solve(vector<int>& values) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < values.size(); i++) {
      vec.push_back({values[i], i});
    }
    sort(vec.begin(), vec.end());
    int swaps = 0;
    for (int i = 0; i < values.size(); i++) {
      if (vec[i].second == i)
        continue;
      else {
        ++swaps;
        swap(vec[i], vec[vec[i].second]);
        --i;
      }
    }
    return swaps;
  }
  int minimumOperations(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int totalSwaps = 0;
    while (!q.empty()) {
      int levelsize = q.size();
      vector<int> levelvaleus;

      for (int i = 0; i < levelsize; i++) {
        TreeNode* current = q.front();
        q.pop();
        levelvaleus.push_back(current->val);
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }

      totalSwaps += solve(levelvaleus);
    }

    return totalSwaps;
  }
};