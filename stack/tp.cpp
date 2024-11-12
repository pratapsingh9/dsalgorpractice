#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* findLcaofBinaryTree(TreeNode* root, int n, int m) {
  if (root == nullptr) return nullptr;

  TreeNode* l = findLcaofBinaryTree(root->left, n, m);
  TreeNode* r = findLcaofBinaryTree(root->right, n, m);

  if (l && r) return root;

  return l != nullptr ? l : r;
}

TreeNode* mergeBst(TreeNode* p, TreeNode* r) {
  if (p == nullptr) return r;
  if (r == nullptr) return p;
  if (p == nullptr && r == nullptr) return nullptr;

  TreeNode* node = new TreeNode(r->val + p->val);
  node->left = mergeBst(p->left, r->left);
  node->right = mergeBst(p->left, r->left);

  return node;
}

TreeNode* findLca(TreeNode* root, int n, int m) {
  if (root == nullptr) return nullptr;
  if (root->val == n || root->val == m) return root;
  if (n > root->val && m > root->val) return findLca(root->right, n, m);
  if (n < root->val && m < root->val) return findLca(root->left, n, m);

  return root;
}

void inorderTarget(TreeNode* root, vector<int>& vec) {
  if (root == nullptr) {
    return;
  }

  inorderTarget(root->left, vec);
  vec.push_back(root->val);
  inorderTarget(root->right, vec);
}

bool findTarget(TreeNode* root, int target) {
  vector<int> vec;
  inorderTarget(root, vec);

  int f = 0, l = vec.size() - 1;
  while (f < l) {
    int ans = vec[f] + vec[l];

    if (ans == target) return true;
    if (ans > target)
      l--;
    else {
      f++;
    }
  }

  return false;
}

TreeNode* minValueInorderSuccessor(TreeNode* root) {
  if (!root) return nullptr;
  TreeNode* curr = root;
  while (curr && curr->left) {
    curr = curr->left;
  }
  return root;
}

TreeNode* deleteNode(TreeNode* root, int val) {
  if (root == nullptr) return nullptr;

  if (val > root->val) {
    root->right = deleteNode(root->right, val);
  }
  if (val < root->val) {
    root->left = deleteNode(root->left, val);
  }

  else {
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      return nullptr;
    }
    if (root->right == nullptr && root->left) {
      TreeNode* node = root->left;
      delete root;
      return node;
    }

    if (root->left == nullptr && root->right) {
      TreeNode* node = root->right;
      delete root;
      return node;
    }

    else {
      TreeNode* successor = minValueInorderSuccessor(root->right);
      root->val = successor->val;
      root->right = deleteNode(root->right, successor->val);
    }
  }
}

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;

    q.push(root);
    bool ltor = true;
    while (!q.empty()) {
      int s = q.size();
      vector<int> temp(s);
      for (int i = 0; i < s; i++) {
        TreeNode* curr = q.front();
        q.pop();
        temp[i] = ltor ? i : s - i - 1;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
      ans.push_back(temp);
      ltor = !ltor;
    }
    return ans;
  }
};
class Solution {
 public:
  TreeNode* minValueNode(TreeNode* root) {
    TreeNode* curr = root;
    while (curr && curr->left != nullptr) {
      curr = curr->left;
    }
    return curr;
  }

  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    }

    else {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr
      } else if (root->left == nullptr) {
        TreeNode* node = root->right;
        delete root;
        return node;
      } else if (root->right == nullptr) {
        TreeNode* node = root->left;
        delete root;
        return node;
      }
      TreeNode* inorderSuccesors = minValueNode(root->right);
      root->val = inorderSuccesors->val;
      root->right = deleteNode(root->right, inorderSuccesors->val);
    }
    return root;
  }
};
void printPathNodesToAllLevel(TreeNode* root, vector<string>& vec, string ans) {
  if (root == nullptr) {
    return;
  }
  if (ans.empty()) {
    ans += (to_string(root->val));
  } else {
    ans += "->" + to_string(root->val);
  }
  if (!root->left && !root->right) {
    vec.push_back(ans);
    return;
  }
  printPathNodesToAllLevel(root->left, vec, ans);
  printPathNodesToAllLevel(root->right, vec, ans);
}

TreeNode* deletebset(TreeNode* root, int key) {}

TreeNode* insertBst(TreeNode* root, int value) {
  if (root == nullptr) return new TreeNode(value);
  if (root->val > value) {
    if (root->left == nullptr) {
      root->left = new TreeNode(value);
    } else {
      insertBst(root->left, value);
    }
  } else {
    if (root->right == nullptr) {
      root->right = new TreeNode(value);
    } else {
      insertBst(root->right, value);
    }
  }
  return root;
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->left->right = new TreeNode(5);
  vector<string> vs;
  printPathNodesToAllLevel(root, vs, "");

  for (const string& path : vs) {
    cout << path << endl;
  }

  return 0;
}

int minCost(vector<int> arr) {
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto& ele : arr) {
    pq.push(ele);
  }
  long long int ans = 0;
  while (pq.size() > 1) {
    int f = pq.top();
    pq.pop();
    int l = pq.top();
    pq.pop();
    ans += f + l;
    pq.push(f + l);
  }

  return ans;
}

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> s;
    int maxy = 0;
    int l = 0;

    for (int right = 0; right < s.size(); right++) {
      while (s.find(s[right]) != s.end()) {
        s.erase(s[left]);
        l++;
      }

      s.insert(s[right]);

      maxy = max(maxy, right - l + 1);
    }
    return maxy;
  }
};
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(128, -1);
    int maxl = 0;
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      char ch
    }
  }
};
bool searchMatrix(vector<vector<int>>& matrix, int k) {
  int m = matrix.size();
  int n = matrix[0].size();
  if (n == 0 || m == 0) return false;

  int left = 0;
  int right =
}

// graph connected compnetns quesiton
void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited) {
  visited[i] = true;
  for (auto it : adj[i]) {
    if (!visited[it]) {
      dfs(it, adj, visited);
    }
  }
}

int countComppnet(vector<vector<int>>& edge, int n) {
  vector<vector<int>> adj(n);
  for (auto& edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }
  vector<bool> vis(n, false);
  int components = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, adj, vis);
      components++;
    }
  }
  return components;
}

class Solution {
 public:
  typedef pair<int, TreeNode*> P;
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    queue<P> q;
    q.push({1, root});
    while (!q.empty()) {
      P node = q.front();
      q.pop();
      int depth = node.first;
      if (node.second->left == nullptr && node.second->right == nullptr) {
        return depth;
      }
      if (node.second->left) {
        q.push({node.first + 1, node.second->left});
      }
      if (node.second->right) {
        q.push({node.first + 1, node.second->right});
      }
    }
    return 0;
  }
};

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildTree(nums, 0, nums.size() - 1);
  }
  TreeNode* buildTree(vector<int>& nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = buildTree(nums, start, mid - 1);
    node->right = buildTree(nums, mid + 1, end);

    return node;
  }
};
unordered_map<int, int> inorderMap;
TreeNode* build(vector<int> preorder, vector<int>& inorder, int preindex,
                int instart, int inEnd) {
  if (instart > inEnd) {
    return nullptr;
  }

  int rootVale = inorderMap[preindex++];
  TreeNode* root = new TreeNode(rootVale);
  int inIdx = inorderMap.at(rootVale);

  root->left = build(preorder, inorder, preindex, instart, inIdx - 1);
  root->right = build(preorder, inorder, preindex, inIdx + 1, inEnd);
  return root;
}

TreeNode* buildTree(vector<int> preorder, vector<int>& inorder) {
  for (int i = 0; i < inorder.size(); i++) {
    inorderMap[inorder[i]] = i;
  }

  int preOrderIndex = 0;
  return build(preorder, inorder, 0, 0, inorder.size() - 1);
}

TreeNode* buildPost(vector<int> postOrder, vector<int> inorder, int postidx,
                    int instart, int inNed) {
  if (instart > inNed) {
    return nullptr;
  }
  int rootvals = postOrder[postidx--];
  TreeNode* root = new TreeNode(rootvals);
  int inIdx = inorderMap.at(rootvals);

  root->left = buildPost(postOrder, inorder, postidx, instart, inIdx - 1);
  root->right = build(postOrder, inorder, postidx, inIdx + 1, inNed);
  return root;
}

TreeNode* buildTree(vector<int> postOrder, vector<int> inorder) {
  for (int i = 0; i < inorder.size(); i++) {
    inorderMap[inorder[i]] = i;
  }
  return buildPost(postOrder, inorder, postOrder.size() - 1, 0,
                   inorder.size() - 1);
}

class Solution {
 public:
  int height(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + max(height(root->left), height(root->right));
  }

  bool isBalanced(TreeNode* root) {
    if (!root) return true;
    int l = height(root->left);
    int r = height(root->right);

    if (abs(l - r) > 1) return false;

    return isBalanced(root->left) && isBalanced(root->right);
  }
};

class Solution {
 public:
  void findPredecessorSuccessor(TreeNode* root, int key, TreeNode*& predecessor,
                                TreeNode*& successor) {
    if (!root) return;
    if (key > root->val) {
      predecessor = root;
      findPredecessorAndSuccessor(root->right, key, predecessor, successor);
    } else if (key < root->val) {
      successor = root;
      findPredecessorAndSuccessor(root->left, key, predecessor, successor);
    }

    else {
      if (root->left) {
        TreeNode* temp = root->left;
        while (temp->right) {
          temp = temp->right;
        }
        predecessor = temp;
      }

      if (root->right) {
        TreeNode* temp = root->right;
        while (temp->right) {
          temp = root->left;
        }
        return temp;
      }
    }
  }

  pair<TreeNode*, TreeNode*> findPredecessorAndSuccessor(TreeNode* root,
                                                         int key) {
    TreeNode* predecessor = nullptr;
    TreeNode* successor = nullptr;

    findPredecessorSuccessor(root, key, predecessor, successor);

    return {predecessor, successor};
  }
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (root == p || root == q) return root;

    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);

    if (l and r) return root;

    if (l)
      return l;
    else
      return r;
  }
};

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int zero = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[zero]);
        zero++;
      }
    }
    for (int i = zero; i < nums.size(); i++) {
      nums[zero] = 0;
    }
  }
};

class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                        int cCenter) {
    vector<pair<int, vector<int>>> cellsWithDistance;
    for (int i = 0; i < rows; i++) {
      /* code */
      for (int j = 0; j < cols; j++) {
        /* code */
        int dist = abs(i - rCenter) + abs(j - cCenter);
        cellsWithDistance.push_back({dist, {i, j}});
      }
    }
    sort(cellsWithDistance.begin(), cellsWithDistance.end());

    vector<vector<int>> ans;

    for (const auto& res : cellsWithDistance) {
      ans.push_back(res.second);
    }
    return ans;
  }
};

void dfshelper(int i, vector<vector<int>>& graph, vector<bool>& vis) {
  vis[i] = true;
  for (int j = 0; j < graph[i].size(); j++) {
    if (graph[i][j] == 1 && !vis[j]) {
      // vis[]
      dfs(j, graph, vis);
    }
  }
}

void dfs(vector<vector<int>>& graph, int v) {
  vector<bool> visited(v, false);

  for (int i = 0; i < v; i++) {
    if (!visited[i]) {
      dfshelper(i, graph, visited);
    }
  }
}

void floodFillalgo(vector<vector<int>>& graph, int x, int y, int target,
                   int replacement) {
  if (x < 0 || y < 0 || x >= graph.size() || y >= graph[0].size() ||
      graph[x][y] != target) {
    return;
  }

  graph[x][y] = replacement;
  floodFillalgo(graph, x + 1, y, target, replacement);
  floodFillalgo(graph, x, y + 1, target, replacement);
  floodFillalgo(graph, x, y - 1, target, replacement);
  floodFillalgo(graph, x - 1, y, target, replacement);
}
class Solution {
 public:
  int dx[4] = {1, 0, 0, -1};  // Corresponds to D, L, R, U
  int dy[4] = {0, -1, 1, 0};
  void findPathSolve(int x, int y, vector<vector<int>>& graph,
                     vector<vector<bool>>& visited, string path,
                     vector<string>& result) {
    int n = graph.size();
    if (x == n - 1 && y == n - 1) {
      result.push_back(path);  // Add the path to the result
      return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];  // Calculate the new row
      int ny = y + dy[i];  // Calculate the new column
      if (nx >= 0 && ny >= 0 && nx < n && ny < n && graph[nx][ny] == 1 &&
          !visited[nx][ny]) {
        if (i == 0) path.push_back('D');  // Down
        if (i == 1) path.push_back('L');  // Left
        if (i == 2) path.push_back('R');  // Right
        if (i == 3) path.push_back('U');  // Up
        findPathSolve(nx, ny, graph, visited, path, result);
        path.pop_back();
      }
    }

    // Unmark the current cell as visited for backtracking
    visited[x][y] = false;
  }

  // Main function to find all paths
  vector<string> findPaths(vector<vector<int>>& graph, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> result;

    // If the starting cell is blocked, return an empty result
    if (graph[0][0] == 0) return result;

    // Start the backtracking from the top-left corner (0, 0)
    findPathSolve(0, 0, graph, visited, "", result);
    return result;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> graph = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  int n = 4;
  vector<string> result = sol.findPaths(graph, n);
  if (result.empty()) {
    cout << "-1" << endl;
  } else {
    for (const string& path : result) {
      cout << path << endl;
    }
  }
  return 0;
}

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int parent) {
  vis[node] = true;
  for (auto& nieghbour : adj[node]) {
    if (!vis[node]) {
      if (dfs(nieghbour, adj, vis, node)) {
        return true;
      }
    } else if (nieghbour != parent) {
      return true;
    }
  }

  return false;
}

bool detectCycle(int V, vector<vector<int>>& adj) {
  vector<bool> visited(V, false);
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      if (dfs(i, adj, visited, -1)) {
        return true;
      }
    }
  }

  return false;
}

bool detectCycleUsingKahn(vector<vector<int>>& graph, int V) {
  vector<int> inDegree(v, 0);
  for (int i = 0; i < V; i++) {
    // inDegree[]
    for (auto it : graph[i]) {
      inDegree[it]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (inDegree[i] == 0) q.push(i);
  }
  int count = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    count++;

    for (auto it : graph[node]) {
      inDegree[it]--;
      if (inDegree[it] == 0) q.push(it);
    }
  }
  return count != V;
}

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

// Checks if the position is valid within the chessboard
bool isValid(int x, int y, int N) {
  return (x >= 1 && x <= N && y >= 1 && y <= N);
}

int knightMoves(int N, int startX, int startY, int targetX, int targetY) {
  queue<pair<pair<int, int>, int>> q;
  q.push({{startX, startY}, 0});

  vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));

  visited[startX][startY] = true;

  while (!q.empty()) {
    auto curent = q.front();
    q.pop();

    int x = curent.first.first;
    int y = curent.first.second;
    int dist = curent.second;
    if (x == targetX && targetY == y) {
      return dist;
    }

    for (int i = 0; i < 4; i++) {
      int newX = x + dx[i];
      int newY = y + dy[i];

      if (isValid(newX, newY, N) && !visited[newX][newY]) {
        visited[newX][newY] = true;

        q.push({{newX, newY}, dist + 1});
      }
    }
  }
  return -1;
}

int minKnightMoves(int N, int startX, int startY, int targetX, int targetY) {
  queue<pair<pair<int, int>, int>> q;
  q.push({{startX, startY}, 0});

  vector<vector<int>> visited(N + 1, vector<bool>(N + 1, false));
  visited[startX][startY] = true;
  while (!q.empty()) {
    auto current = q.front();
    q.pop();
    int x = current.first.first;
    int y = current.first.second;

    int dist = current.second;

    if (x == targetX && y == targetY) {
      return dist;
    }

    for (int i = 0; i < 4; i++) {
      int newX = dx[i] + x;
      int newY = dy[i] + y;

      visited[newX][newY] = true;
      q.push({{newX, newY}, dist + 1});
    }
  }
  return -1;
}

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> graphs(n);

    vector<int> inDegree(n, 0);

    for (int u = 0; u < n; u++) {
      for (int v : graph[u]) {
        graphs[v].push_back(u);
        inDegree[u]++;
      }
    }

    queue<int> q;

    for (int i = 0; i < inDegree.size(); i++) {
      q.push(i);
    }

    vector<int> ansNodes;

    while (!q.empty()) {
      int top = q.front();
      q.pop();
      ansNodes.push_back(top);
      for (int neightours : graphs[top]) {
        inDegree[neightours]--;
        if (inDegree[neightours] == 0) q.push(neightours);
      }
    }
    sort(ansNodes.begin(), ansNodes.end());
    return ansNodes;
  }
};

class Solution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
      if (manager[i] != -1) {
        adj[manager[i]].push_back(i);
      }
    }
    return dfs(i, adj, informTime);
  }

  int dfs(int i, vector<vector<int>>& adj, vector<int>& informTime) {
    int maxTime = 0;
    for (int subroted : adj[i]) {
      maxTime = max(maxTime, dfs(subroted, adj, informTime));
    }
    return maxTime + informTime[i];
  }
};

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {}
};

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int primMST(int n, vector<vector<pair<int, int>>>& graph) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<bool> inMST(n, false);
  pq.push({0, 0});
  int mstCost = 0;
  while (!pq.empty()) {
    auto [weight, node] = pq.top();
    pq.pop();
    if (inMST[node]) continue;
    mstCost += weight;
    inMST[node] = true;
    for (auto& adj : graph[node]) {
      int nxtNode = adj.first;
      int weightNxt = adj.second;
      if (!inMST[nxtNode]) {
        pq.push({weightNxt, nxtNode});
      }
    }
  }

  return mstCost;
}

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }
  bool dfs(vector<vector<char>>& board, string word, int i, int j, int index) {
    if (index == word.size()) return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
        board[i][j] != word[index]) {
      return false;
    }

    char temp = board[i][j];

    board[i][j] = '#';

    bool ans = dfs(board, word, i + 1, j, index + 1) ||
               dfs(board, word, i, j + 1, index + 1) ||
               dfs(board, word, i - 1, j, index + 1) ||
               dfs(board, word, i, j - 1, index + 1);

    board[i][j] = temp;

    return ans;
  }
};

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxy = 0;
    for (int i = 0; i < n; i++) {
      if (i > maxy) return false;

      maxy = max(maxy, i + nums[i]);
      if (maxy >= n - 1) return true;
    }
    return false;
  }
};

void solve(vector<int> nums, vector<vector<int>>& ans, int start) {
  if (start == nums.size()) {
    ans.push_back(nums);
    return;
  }

  for (int i = start; i < nums.size(); i++) {
    swap(nums[i], nums[start]);
    solve(nums, ans, start + 1);
    swap(nums[i], nums[start]);
  }
}

vector<vector<int>> findUnqiuePermuation(vector<int>& nums) {
  vector<vector<int>> ans;
  vector<int> temp;
  solve(nums, ans, temp, int start);
  return ans;
}

void printallChars(string s) {
  sort(s.begin(), s.end());
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      cout << s[i] << endl;
      while (i < s.size() && s[i] == s[i - 1]) {
        i++;
      }
    }
  }
}

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();

    if (n == 0) return 0;
    for (int i = 0; i < m; i++) {
      int j = 0;
      while (j < n && haystack[i + j] == needle[j]) {
        j++;
      }

      if (j == n) return i;
    }

    return -1;
  }
};
