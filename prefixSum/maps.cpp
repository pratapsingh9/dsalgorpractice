#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int pivotInteger(int n) {
    int sum = (n * (n + 1)) / 2;
    int cumSum = 0;
    for (size_t i = 1; i <= n; i++) {
      /* code */
      cumSum += i;
      if (cumSum == sum - cumSum + i) return i;
    }
    return -1;
  }
};

int countSubarraysWithSum(vector<int>& arr, int target) {
  unordered_map<int, int> mp;
  mp[0] = 1;
  int prefixsum = 0, count = 0;

  for (int num : arr) {
    prefixsum += num;
    if (mp.find(prefixsum - target) != mp.end()) {
      count += mp[prefixsum - target];
    }
    mp[prefixsum]++;
  }
  return count;
}

int countNiceSubarrays(vector<int>& arr, int K) {
  unordered_map<int, int> mp;
  mp[0] = 1;
  int prefixsum = 0, count = 0;
  for (int num : arr) {
    prefixsum += num;
    if (mp.find(prefixsum - k) != mp.end()) {
      count += mp[prefixsum - k];
    }
    mp[prefixsum]++;
  }
  return count;
}

class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (isWater[r][c] == 1) {
          height[r][c] = 0;
          q.push({r, c});
        }
      }
    }
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      for (const auto& dir : direction) {
        int nr = r + dir[0], nc = c + dir[1];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && height[nr][nc] == -1) {
          height[nr][nc] = height[r][c] + 1;
          q.push({nr, nc});
        }
      }
    }
    return height;
  }
};

void solvePrefixquery() {
  int n;
  cin >> n;
  vector<int> array(n);
  for (int i = 0; i < n; i++) cin >> array[i];
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int yp
  }
}

#include <iostream>
#include <vector>

using namespace std;

int ass() {
  int n, q;
  cin >> n >> q;

  vector<long long> arr(n + 1, 0);
  vector<long long> diff(n + 1, 0);

  // Input the array
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  // Process the queries
  while (q--) {
    int type, l, r;
    cin >> type >> l >> r;

    if (type == 1) {
      long long x;
      cin >> x;
      diff[l] += x;
      if (r + 1 <= n) diff[r + 1] -= x;
    } else {
      long long sum = 0;
      for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        arr[i] += diff[i];
        diff[i] = 0;
      }
      for (int i = l; i <= r; i++) {
        sum += arr[i];
      }
      cout << sum << endl;
    }
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int rwmpas() {
  int n, q;
  cin >> n >> q;

  vector<int> arr(n + 1, 0);
  vector<long long> prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    long long sum = 0;
    for (int i = l; i <= r; i++) {
      if (arr[i] > x) {
        sum += arr[i];
      }
    }
    cout << sum << endl;
  }

  return 0;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<long long> arr(n + 1, 0);
  vector<long long> diff(n + 1, 0);

  for (int i = 1; i < n; i++) cin >> arr[i];

  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;

    diff[l] += x;
    diff[r + 1] -= x;
  }

  long long totalSum = 0;
  long long running_sum = 0;
  for (int i = 1; i <= n; i++) {
    running_sum += diff[i];
    arr[i] += running_sum;
    totalSum += arr[i];
  }

  cout << totalSum << endl;
}

class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<int> rcount(rows, 0), Ccount(cols, 0);
    for (size_t i = 0; i < rows; i++) {
      /* code */
      for (size_t j = 0; j < cols; j++) {
        /* code */

        if (grid[i][j] == 1) {
          /* code */
          rcount[i]++;
          Ccount[j] + pratap96 + ;
        }
      }
    }
    int servers = 0;
    for (size_t i = 0; i < rows; i++) {
      /* code */
      for (size_t j = 0; j < cols; j++) {
        /* code */
        if (grid[i][j] == 1 && (rcount[i] > 1 || Ccount[j] > 1)) {
          servers++;
        }
      }
    }
    return servers;
  }
};

class Solution {
 public:
  bool inRange(int x1, int y1, int r, int x2, int y2) {
    long long dx = x2 - x1;
    long long dy = y2 - y1;
    return dx * dx + dy * dy <= (long long)r * r;
  }
  void dfs(int bomb, const vector<vector<int>>& graph,
           unordered_set<int>& visited) {
    visited.insert(bomb);
    for (int neighbor : graph[bomb]) {
      if (visited.find(neighbor) == visited.end()) {
        dfs(neighbor, graph, visited);
      }
    }
  }
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> graph(n);
  }
};

class Solution {
 public:
  int dfs(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    visited[start] = true;
    int count = 1;
    for (int neighbour : graph[start]) {
      if (!visited[neighbour]) {
        count += dfs(neighbour, visited);
      }
    }
    return count;
  }
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        long long dx = bombs[j][0] - bombs[i][0];
        long long dy = bombs[j][1] - bombs[i][1];
        long long distance = dx * dx + dy * dy;
        long long radiusSquare = bombs[i][2] * bombs[i][2];
        if (distance <= radiusSquare) {
          graph[i].push_back(j);
        }
      }
    }

    int count = INT_MIN;
    for (int i = 0; i < n; i++) {
      vector<bool> visited(n, false);
      count = max(count, dfs(graph, i, visited));
    }
    return count;
  }
};

class Solution {
 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<vector<bool>> connectedGraph(n, vector<bool>(false));
    vector<int> indegree(n);

    for (auto road : roads) {
      int a = road[0], b = road[1];
      indegree[a]++;
      indegree[b]++;
      connectedGraph[a][b] = true;
      connectedGraph[b][a] = true;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int score = indegree[i] + indegree[j];
        ans = max(score, ans - connectedGraph[i][j]);
      }
    }
    return ans;
  }
};

class Solution {
 public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> degree(n);
    for (const auto& road : roads) {
      degree[road[0]]++;
      degree[road[1]]++;
    }
    sort(degree.begin(), degree.end());
    long long value = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (degree[i] * value);
      value++;
    }
    return sum;
  }
};

int sumOfDigits(int num) {
  int sum = 0;

  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }

  return sum;
}
void solve() {
  int n;
  cin >> n;

  while (n--) {
  }
}

class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxy = *max_element(candies.begin(), candies.end());
    vector<bool> answer(candies.size(), false);
    for (size_t i = 0; i < candies.size(); i++) {
      /* code */
      if (candies[i] + extraCandies >= maxy) {
        answer[i] = true;
      } else {
        continue;
      }
    }
    return answer;
  }
};

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int flag = 0;
    for (int i = 0; i < flowerbed.size(); i++) {
      bool left = (i == 0 || flowerbed[i - 1] == 0);
      bool right = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);

      if (flowerbed[i] == 0 && left && right) {
        flag++;
        i++;
      }
    }
    return flag > n;
  }
};

class Solution {
 public:
  int beautySum(string s) {
    int total = 0;
    for (int i = 0; i < s.size(); i++) {
      vector<int> freq(26, 0);
      for (int j = i; j < s.size(); j++) {
        freq[s[j] - 'a']++;
        int maxFreq = 0, , minFreq = INT_MAX;

        for (int count : freq) {
          if (count > 0) {
            maxFreq = max(maxFreq, count);
            minFreq = min(minFreq, count);
          }
        }
        total += (maxFreq - minFreq);
      }
    }
    return total;
  }
};

class Solution {
 public:
  int pairSum(ListNode* head) {
    if (!head) return 0;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* curr = slow;
    while (curr) {
      ListNode* nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }

    int maxSum = 0;
    ListNode* firstHalf = head;
    ListNode* secondHalf = prev;
    while (secondHalf) {
      maxSum = max(maxSum, firstHalf->val + secondHalf->val);
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    return maxSum;
  }
};

class Solution {
 public:
  int pairSum(ListNode* head) {
    vector<int> vec;
    ListNode* curr = head;
    while (curr != nullptr) {
      vec.push_back(curr->val);
      curr = curr->next;
    }

    int st = 0, end = vec.size() - 1;
    int maxy = INT_MIN;
    while (st <= end) {
      maxy = max(maxy, vec[st] + vec[end]);
      st++;
      end--;
    }

    return maxy;
  }
};

class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    queue<pair<string, int>> q;
    if (dead.count('0000')) {
      /* code */
      return -1;
    }
    q.push({"0000", 0});
    visited.insert("0000");
    while (!q.empty()) {
      int steps = q.front().second;
      string current = q.front().first;
      q.pop();

      if (current == target) return step;
      for (int i = 0; i < 4; i++) {
        string next = current;
        next[i] = (current[i] - '0' + 1) % 10 + '0';
        if (!dead.count(next) && visited.count(next)) {
          q.push({next, steps + 1});
          visited.insert(next);
        }

        next[i] = (current[i] - '0' + 9) % 10 + '0';
        if (!dead.count(next) && visited.count(next)) {
          q.push({next, steps + 1});
          visited.insert(next);
        }
      }
    }
    return -1;
  }
};
class Solution {
 public:
  int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool found = false;

    auto dfs = [&](int x, int y, auto&& dfs_ref) -> void {
      if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] ||
          grid[x][y] == 0)
        return;
      visited[x][y] = true;  // Mark as visited
      q.push({x, y});        // Add to BFS queue
      for (auto dir : directions) {
        dfs_ref(x + dir.first, y + dir.second, dfs_ref);
      }
    };

    for (int i = 0; i < n; i++) {
      if (found) break;  // Stop after finding the first island
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          dfs(i, j, dfs);  // Start DFS from the first cell of the first island
          found = true;
          break;
        }
      }
    }

    int steps = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto [x, y] = q.front();
        q.pop();
        for (auto dir : directions) {
          int nx = x + dir.first, ny = y + dir.second;
          if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
            if (grid[nx][ny] == 1) {
              return steps;  // Found the second island
            }
            visited[nx][ny] = true;  // Mark water as visited
            q.push({nx, ny});        // Add water cell to the queue
          }
        }
      }
      steps++;
    }

    return -1;  // Should never be reached if input is valid
  }
};

class Solution {
 public:
  vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  typedef pair<int, pair<int, int>> P;
  int minimumEffortPath(vector<vector<int>>& h) {
    int m = h.size();
    int n = h[0].size();
    vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    priority_queue<P, vector<P>, greater<P>> pq;
    result[0][0] = 0;
    pq.push({0, {0, 0}});

    auto isSafe = [&](int x, int y) {
      return x >= 0 && x < m && y >= 0 && y < n;
    };
    while (!pq.empty()) {
      int diff = pq.top().first;
      auto cordinates = pq.top().second;
      int x = cordinates.first, y = cordinates.second;
      pq.pop();
      for (auto& dir : dirs) {
        int newX = dir.first + x;
        int newY = dir.second + y;
      }
    }
  }
};
class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
    vector<vector<int>> blueGraph(n), redGraph(n);

    for (auto& edge : redEdges) {
      redGraph[edge[0]].push_back(edge[1]);
    }
    for (auto& edge : blueEdges) {
      blueGraph[edge[0]].push_back(edge[1]);
    }

    vector<int> answer(n, -1);
    vector<vector<bool>> visited(n, vector<bool>(2, false));

    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({0, 1});
    visited[0][1] = visited[0][1] = true;
    int distance = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        /* code */
        int node = q.front().first;
        int color = q.front().second;

        q.pop();

        if (answer[node] == -1) answer[node] = distance;

        if (color == 0) {
          for (int neighbour : blueGraph[node]) {
            if (!visited[neighbour][1]) {
              visited[neighbour][1] = true;
              q.push({neighbour, 1});
            }
          }
        } else if (color == 1) {
          for (int neighbour : redGraph[node]) {
            if (!visited[neighbour][0]) {
              visited[neighbour][0] = true;
              q.push({neighbour, 0});
            }
          }
        }
      }

      ++distance;
    }
    return answer;
  }
};

void bfs(vector<vector<int>>& graph, int node) {
  queue<int> q;
  unordered_set<int> visited;
  visited.insert(node);
  q.push(node);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
  }
}

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adjList,
                     int start) {
  vector<int> dist(n, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  dist[start] = 0;
  pq.push({0, start});
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto neighbour : adjList[u]) {
      int v = neighbour.first;
      int weight = neighbour.second;

      if (dist[v] > weight + dist[u]) {
      }
    }
  }
}

class Solution {
 public:
  int m;
  int n;
  vector<vector<bool>> visited;
  int borderColor = -1;
  int initialColor = -1;
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  bool isBorder(int row, int col, vector<vector<int>>& grid) {
    if (row == 0 || row == m - 1 || col == 0 || col == n - 1) return true;
    int currCol = grid[row][col];

    if ((grid[row][col + 1] != currCol && visited[row][col + 1] == false) ||
        (grid[row + 1][col] != currCol && visited[row + 1][col] == false) ||
        (grid[row][col - 1] != currCol && visited[row][col - 1] == false) ||
        (grid[row - 1][col] != currCol && visited[row - 1][col] == false))
      return true;

    return false;
  }

  void dfs(int row, int col, vector<vector<int>>& grid) {
    if (row < 0 || row >= m || col < 0 || col >= n ||
        visited[row][col] == true || grid[row][col] != initialColor)
      return;

    visited[row][col] = true;
    if (isBorder(row, col, grid)) grid[row][col] = borderColor;

    for (auto d : dir) {
      int newRow = row + d[0];
      int newCol = col + d[1];

      dfs(newRow, newCol, grid);
    }
  }

  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                  int color) {
    m = grid.size();
    n = grid[0].size();
    visited.resize(m, vector<bool>(n, false));
    borderColor = color;
    initialColor = grid[row][col];

    dfs(row, col, grid);

    return grid;
  }
};

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dfs(int i, int j, vector<vector<int>>& matrix) {
  int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int longest = 1;

  for (auto& dir : directions) {
    int newX = dir[0] + i;
    int newY = dir[1] + j;
    if (newx >= 0 && newX < matrix.size() && newY >= 0 &&
        newY < matrix[0].size() && matrix[newX][newY] > matrix[i][j]) {
      longest = max(longest, 1 + dfs(newX, newY, matrix));
    }
  }
  return longest;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
  if (matrix.empty()) return 0;

  int rows = matrix.size(), cols = matrix[0].size();
  int result = 0;
  for (int i = 0; i < rows; i++) {
    /* code */
    for (int j = 0; j < cols; j++) {
      /* code */
      result = max(result, dfs(i, j, matrix));
    }
  }
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  vector<pair<int, int>> directions = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                                       {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

  bool dfs(vector<vector<char>>& board, string& word, int x, int y, int index) {
    if (index == word.size()) {
      return true;
    }
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
        board[x][y] != word[index]) {
      return false;
    }
    char temp = board[x][y];
    board[x][y] = '#';

    for (auto& dir : directions) {
      int newX = dir.first + x;
      int newY = dir.second + y;

      if (dfs(board, word, newX, newY, index + 1)) {
        return true;
      }
    }
    board[x][y] = temp;
    return false;
  }
};

class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    const int INF = ie9;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (size_t i = 0; i < n; i++) {
      /* code */
      dist[i][i] = 0;
    }

    for (auto& edge : edges) {
      int u = edge[0], v = edge[1], dist = edge[2];
      dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dist[i][k] != INF && dist[k][j] != INF) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
  }
};
class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int c = 0;
    for (int n : nums) {
      if (i < k) c++;
    }
    return c;
  }
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      /* code */
      int size = q.size();
      Node* prev = nullptr;
      for (int i = 0; i < size; i++) {
        Node* curr = q.front();
        q.pop();
        curr->next = prev;
        prev = t;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
    }
    return root;
  }
};

class Solution {
 public:
  int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> geneBank(bank.begin(), bank.end());
    if (geneBank.find(endGene) == geneBank.end()) {
      return -1;
    }
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    q.push({startGene, 0});
    visited.insert(startGene);
    while (!q.empty()) {
      auto [currentGene, steps] = q.front();
      q.pop();
      if (currentGene == endGene) {
        return steps;
      }
      for (int i = 0; i < 8; ++i) {
        char original = currentGene[i];
        for (char c : {'A', 'C', 'G', 'T'}) {
          if (c == original) continue;
          currentGene[i] = c;
          if (geneBank.find(currentGene) != geneBank.end() &&
              visited.find(currentGene) == visited.end()) {
            q.push({currentGene, steps + 1});
            visited.insert(currentGene);
          }
        }
        currentGene[i] = original;
      }
    }
    return -1;
  }
};
