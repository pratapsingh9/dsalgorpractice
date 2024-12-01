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
    if (visited.count(current)) {
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
    queue<pair<int, string>> q;
    unordered_set<string> visted;
    q.push({0, start});
    while (!q.empty()) {
      string current = q.front().second;
      int moves = q.front().first;

      q.pop();
      if (current == target) return moves;

      int zeroIdx = current.find('0');
      for (int neighbour : neighbors[zeroIdx]) {
        string temp = current;
        swap(temp[zeroIdx], temp[neighbour]);

        if (visted.find(temp) == visted.end()) {
          q.push({moves + 1, temp});
          visted.insert(temp);
        }
      }
    }
    return -1;
  }
};

void sieve(int n) {
  vector<bool> isPrims(n + 1, true);
  isPrims[0] = isPrims[1] = false;
  for (int i = 2; i < sqrt(n); i++) {
    if (isPrims[i]) {
      for (int j = i * i; i <= n; j += i) {
      }
    }
  }
}

class Solution {
 public:
  int search(vector<int> &nums, int target) {
    int st = 0, end = nums.size() - 1;

    while (st <= end) {
      int mid = st + (end - st) / 2;
      if (nums[mid] == target) {
        return target;
      }

      if (nums[st] <= nums[end]) {
        if (nums[st] <= target && nums[mid] >= target) {
          end = mid - 1;
        } else {
          st = mid + 1;
        }
      } else if (nums[mid] <= target && nums[end] >= target) {
        if () }
    }
  }
};

class Solution {
 public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int start = 0, int end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (arr[mid] > arr[mid + 1]) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};

int findKRotation(vector<int> &arr) {
  // Code Here
  int low = 0, high = arr.size() - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) {
      high = mid - 1;
    } else if (arr[mid] > arr[high]) {
      low = mid + 1;
    }
  }
  return low;
}

class Solution {
 public:
  bool search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) return true;
      if (nums[left] == nums[mid]) {
        left++;
        continue;
      }
      if (nums[left] <= nums[mid]) {
        if (target >= nums[left] && nums[mid] > target) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (target > nums[mid] && nums[right] = > target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return false;
  }
};

class Solution {
 public:
  bool solve(vector<int> &piles, int h, int k) {
    int hour = 0;
    for (int pile : piles) {
      hour += ceil((double)pile / k);
    }
    return hour <= h;
  }
  int minEatingSpeed(vector<int> &piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int res = high;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (solve(piles, h, mid)) {
        high = mid - 1;
        res = mid;
      } else {
        low = mid + 1;
      }
    }
    return res;
  }
};

class Solution {
 public:
  bool canShip(vector<int> &weights, int days, int capacity) {
    int total = 0, requiredDays = 1;
    for (int weight : weights) {
      if (total + weight > capacity) {
        requiredDays++;
        total = weight;
        if (requiredDays > days) return false;
      } else {
        total += weight;
      }
    }
    return true;
  }
  int shipWithinDays(vector<int> &weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end());
    int result = high;
    while (left < high) {
      int mid = low + (high - low) / 2;
      if (canShip(weights, days, mid)) {
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
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto &flight : flights) {
      graph[flight[0]].push_back({flight[1], flight[2]});
    }

    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    int minCost = 0;
    int stops = 0;
    while (!q.empty() && stops <= k) {
      auto curr = q.front();
      int node = curr.first;
      int currCost = curr.second;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int newCost = curr
      }
    }
  }
};

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    if (source == target) return 0;

    unordered_map<int, vector<int>> stopToBuses;  // Map each stop to buses
    for (int bus = 0; bus < routes.size(); ++bus) {
      for (int stop : routes[bus]) {
        stopToBuses[stop].push_back(bus);
      }
    }
    queue<int> q;
    unordered_set<int> visitedBuses;
    unordered_set<int> visitedStops;
    int busesTaken = 0;
    for (int bus : stopToBuses[source]) {
      q.push(bus);
      visitedBuses.insert(bus);
    }
    while (!q.empty()) {
      ++busesTaken;
      int levelSize = q.size();

      for (int i = 0; i < levelSize; ++i) {
        int currentBus = q.front();
        q.pop();

        for (int stop : routes[currentBus]) {
          if (stop == target) return busesTaken;
          if (visitedStops.find(stop) == visitedStops.end()) {
            visitedStops.insert(stop);
            for (int nextBus : stopToBuses[stop]) {
              if (visitedBuses.find(nextBus) == visitedBuses.end()) {
                q.push(nextBus);
                visitedBuses.insert(nextBus);
              }
            }
          }
        }
      }
    }
    return -1;
  }
};
class Solution {
 public:
  typedef pair<int, pair<int, int>> P;
  int minimumObstacles(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    deque<pair<int, int>> q;
    dist[0][0] = 0;
    q.push_front({0, 0});
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;

      q.pop_front();

      for (auto &dir : directions) {
        int newX = dir.first + x;
        int newY = dir.second + y;

        if (newX >= 0 && newY >= 0 && newX < m && newY < n) {
          int newCost = dist[x][y] + grid[newX][newY];
          if (dist[newX][newY] > newCost) {
            dist[newX][newY] = newCost;
            if (grid[newX][newY] == 0) {
              q.push_front({newX, newY});
            } else {
              q.push_back({newX, newY});
            }
          }
        }
      }
    }
    return dist[m - 1][n - 1];
  }
};
class Solution {
 public:
  typedef pair<int, pair<int, int>> P;
  int minimumObstacles(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, {0, 0}});
    while (!pq.empty()) {
      auto current = pq.top();
      int x = current.second.first;
      int y = current.second.second;
      int distance = current.first;

      for (auto &dir : directions) {
        int newX = dir.first + x;
        int newY = dir.second + y;
        if (newX >= 0 && newY >= 0 && newX < m && newY < n) {
          int weight = (grid[newX][newY] == 1) ? 1 : 0;
          int newCost = weight + distance;

          if (dist[newX][newY] > newCost) {
            dist[newX][newY] = newCost;
            pq.push({newCost, {newX, newY}});
          }
        }
      }
    }
    return dist[m - 1][n - 1];
  }
};
class Solution {
 public:
  typedef long long LL;
  int maximumCandies(vector<int> &candies, long long k) {
    long long low = 1, right = *max_element(candies.begin(), candies.end());
    long long res = 0;

    while (low <= right) {
      LL mid = low + (right - low) / 2;
      LL children = 0;
      for (int pile : candies) {
        children += pile / mid;

        if (children >= k) {
          res = mid;
          low = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return res;
  }
};
class Solution {
 public:
  typedef pair<int, pair<int, int>> P;
  int minimumTime(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (grid[0][1] > 1 && grid[1][0] > 1) {
      return -1;
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, {0, 0}});
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!pq.empty()) {
      int currentTime = pq.top().first;
      int x = pq.top().second.first;
      int y = pq.top().second.second;
      pq.pop();
      if (visited[x][y]) continue;
      visited[x][y] = true;
      if (x == m - 1 && y == n - 1) {
        return currentTime;
      }
      for (auto &dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (newX >= 0 && newY >= 0 && newX < m && newY < n &&
            !visited[newX][newY]) {
          int newTime = currentTime + 1;
          if (newTime % 2 != grid[newX][newY] % 2) {
            newTime++;
          }
          pq.push({newTime, {newX, newY}});
        }
      }
    }

    return -1;
  }
};

class Solution {
 public:
  int minimumTime(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    // If we can't move right or down from start, it's impossible
    if (grid[0][1] > 1 && grid[1][0] > 1) {
      return -1;
    }

    // Directions: down, up, right, left
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Priority queue to store {time, x, y}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // Distance matrix to track minimum time to reach each cell
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    // Start from top-left cell at time 0
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      int time = curr[0];
      int x = curr[1];
      int y = curr[2];
      if (x == m - 1 && y == n - 1) {
        return time;
      }
      if (time > dist[x][y]) continue;
      for (auto &dir : directions) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          int newTime = max(time + 1, grid[nx][ny]);
          if (newTime < dist[nx][ny]) {
            dist[nx][ny] = newTime;
            pq.push({newTime, nx, ny});
          }
        }
      }
    }
    return -1;  // Cannot reach bottom-right cell
  }
};

class Solution {
 public:
  int minAddToMakeValid(string s) {
    int open = 0, close = 0;
    for (char ch : s) {
      if (c == '(') {
        open++;
      } else if (c == ')') {
        if (open > 0) {
          open--;
        } else {
          close++;
        }
      }
    }
    return open + close;
  }
};

class Solution {
 public:
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> answer(seq.size(), 0);
    int currDepth = 0;
    for (int i = 0; i < seq.size(); i++) {
      /* code */
      if (seq[i] == '(') {
        currDepth++;
        answer[i] = currDepth % 2;
      } else {
        answer[i] = currDepth % 2;
        currDepth--;
      }
    }
    return answer;
  }
};

class Solution {
 public:
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> answer(seq.size(), 0);
    stack<int> st;
    for (int i = 0; i < seq.size(); i++) {
      if (seq[i] == '(') {
        st.push(st.size());
        answer[i] = st.size() % 2;
      } else if (seq[i] == ')') {
        answer[i] = st.size() % 2;
        st.pop();
      }
    }
    return answer;
  }
};

string addBinary(string s1, string s2) {
  int i = s1.size() - 1;
  int j = s2.size() - 1;
  string answer = "";
  int carry = 0;
  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) {
    }
  }
}

class Solution {
 public:
  int solve(vector<int> &arr, int index, int delted) { if }
  int maximumSum(vector<int> &arr) {
    int maxSum = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
      maxSum = max(maxSum, solve(arr, i, 0));
    }

    return maxSum;
  }
};

class Solution {
 public:
  vector<int> topStudents(vector<string> &positive_feedback,
                          vector<string> &negative_feedback,
                          vector<string> &report, vector<int> &student_id,
                          int k) {
    unordered_set<string> positive(positive_feedback.begin(),
                                   positive_feedback.end());
    unordered_set<string> negative(negative_feedback.begin(),
                                   negative_feedback.end());

    auto comp =
        [](const pair<int, int> &a, const pair<int, int> &b) {
          if (a.first == b.first) {
            return a.second > b.second;
          }

          return a.first > b.first;
        }

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
        pq(comp);
    for (int i = 0; i < report.size(); i++) {
      int points = 0;
      string &curr = report[i];

      string word;

      for (char c : curr) {
        if (c == ' ') }
    }
  }
};

class Solution {
 public:
  void backtrack(vector<int> &nums, vector<vector<int>> &result,
                 vector<int> &current, vector<bool> &visited) {
    if (current.size() == nums.size()) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (visited[i]) continue;
      if (i > 0 && nums[i] == nums[i - 1] && !visited[i]) continue;

      visited[i] = true;
      current.push_back(nums[i]);
      backtrack(nums, result, current, visited);
      visited[i] = false;
      current.pop_back();
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> visited(nums.size(), false);

    sort(nums.begin(), nums.end());

    backtrack(nums, result, current, visited);

    return result;
  }
};
class Solution {
 public:
  bool binarySearch(vector<int> &arr, int i, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (mid == i) {
        if (mid > low)
          mid--;
        else
          mid++;
      }

      if (arr[mid] == target) return true;

      if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return false;
  }

  bool checkIfExist(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
      if (binarySearch(arr, i, arr[i] * 2)) {
        return true;
      }
    }
    return false;
  }
};

class Solution {
 public:
  bool lemonadeChange(vector<int> &bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
      if (bill == 5) {
        five++;
      } else if (bill == 10) {
        if (five > 0) {
          five--;
          ten++
        } else {
          return false;
        }
      } else {
        if (ten > 0 && five > 0) {
          ten--;
          five--;

        } else if (five >= 3) {
          five -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};

class Solution {
 public:
  int minimizeArrayValue(vector<int> &nums) {
    
  }
};