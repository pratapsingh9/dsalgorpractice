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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  bool isCompleteTree(TreeNode* root) {
    if (root == nullptr) return true;
    queue<TreeNode*> q;
    q.push(root);
    bool foundNUll = false;
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node->left) {
        if (foundNUll) return false;
        q.push(node->left);
      } else {
        foundNUll = true;
      }

      if (node->right) {
        if (foundNUll) return false;
        q.push(node->right);

      } else {
        foundNUll = true;
      }
    }
    return true;
  }
};

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
  }
};

TreeNode* delNodeTree(TreeNode* root) {
  if (root == nullptr) return root;
  root->left = delNodeTree(root->left);
  root->right = delNodeTree(root->right);
  if (root->left == nullptr && root->right) {
    return root->right;
  }
  if (root->right == nullptr && root->left) {
    return root->left;
  }
  return root;
}

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

class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }

  dfs(TreeNode* root, int ans) {
    if (root == nullptr) return 0;
    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);

    ans = max(ans, left + right);
    return 1 + max(left, right)
  }
};
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

TreeNode* convertedListToBst(ListNode* head) {
  if (!head) return nullptr;

  TreeNode* root = new TreeNode(head->val);
  head = head->val;

  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* currNode = q.front();
    q.pop();
    currNode->left = new TreeNode(head->val);
    q.push(currNode->left);
    head = head->next;

    if (head) {
      currNode->right = new TreeNode(head->val);
      q.push(currNode->right);
      head = head->next;
    }
  }
  return root;
}

bool areIsomorphic(TreeNode* tree1, TreeNode* tree2) {
  if (!tree1 && !tree2) return true;
  if (!tree1 || !tree2) return false;
  if (tree1->val != tree2->val) return false;
  return (tree1->val == tree2->val) ||
         (areIsomorphic(tree1->left, tree2->right) &&
          areIsomorphic(tree1->right, tree2->left));
}

bool mirrorTree(TreeNode* a, TreeNode* b) {
  if (!a && !b) return true;
  if (a->val != b->val) return false;
  if (a == nullptr || b = nullptr) return false;
  return mirrorTree(a->left, b->right) || mirrorTree(a->right, b->left);
}

class Solution {
 public:
  int solve(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;

    if (!root->left) return solve(root->right) + 1;
    if (!root->right) return solve(root->left) + 1;

    int left = solve(root->left);
    int right = solve(root->right);
    return min(left, right) + 1;
  }
  int minDepth(TreeNode* root) { return solve(root); }
};

class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};

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
  typedef pair<int, int> P;
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<bool> visited(n, false);
  int minCost = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    P it = pq.top();
    int Node = it.second;
    int Weight = it.first;

    if (visited[Node]) continue;
    minCost += Weight;
    visited[Node] = true;
    for (auto& adj : graph[Node]) {
      int nextNode = adj.first;
      int nextWeith = adj.second;
      if (!visited[nextNode]) {
        pq.push({nextWeith, nextNode});
      }
    }
  }
}

int primMST(int n, vector<vector<pair<int, int>>>& graph) {
  typedef pair<int, int> P;
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<bool> inMst(n, false);

  pq.push({0, 0});
  int minCost = 0;
  while (!pq.empty()) {
    P it = pq.top();
    pq.pop();
    if (inMst[it.second]) continue;

    minCost += it.first;
    inMst[it.second] = true;
    for (auto adj : graph[it.second]) {
      int nxtNode = adj.first;
      int weightNode = adj.second;

      if (!inMst[nxtNode]) {
        pq.push({weightNode, nxtNode});
      }
    }
  }
}

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

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];

    while (left < right) {
      int mid = left + (right - left) / 2;
      int count = midorEqual(matrix, mid);

      if (k < count) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
  }
  return left;
};

class Solution {
 public:
  bool compare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < quality.size(); i++) {
      vec.push_back({quality[i], wage[i]});
    }
    sort(vec.begin(), vec.end(), compare);

    priority_queue<int> pq;
    int quality = 0;
    int currSum = 0;

    for (auto& worker : vec) {
      int wage = worker.first;
      int quality = worker.second;

      quality += quality;
      pq.push(wage);

      if (pq.size() > k) {
        quality -= pq.top();
        pq.pop();
      }

      if (pq.size() == k) {
        int cost = (w / q)
      }
    }
  }
};

class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capital) {
    vector<pair<int, int>> vec;

    for (int i = 0; i < profits.size(); i++) {
      vec.push_back({capital[i], profits[i]});
    }
    sort(vec.begin(), vec.end());

    int i = 0;

    priority_queue<int> pq;
    while (k--) {
      while (i < profits.size() && vec[i].first <= w) {
        pq.push(vec[i].second);
        i++;
      }

      w += pq.top();
      pq.pop();
    }
    return w;
  }
};
class Solution {
 public:
  typedef pair<int, char> P;
  string longestDiverseString(int a, int b, int c) {
    priority_queue<P> pq;

    if (a > 0) pq.push({a, 'a'});
    if (c > 0) pq.push({c, 'c'});
    if (b > 0) pq.push({b, 'b'});

    string ans = "";
    while (!pq.empty()) {
      char currChar = pq.top().second;
      int currCount = pq.top().first;
      pq.pop();
      if (ans.size() >= 2 && ans[ans.size() - 1] == currChar &&
          ans[ans.size() - 2] == currChar) {
        if (!pq.empty()) {
          P node = pq.top();
          pq.pop();
          ans.push_back(node.second);
          if (node.first - 1 > 0) pq.push({node.first - 1, node.second});
          pq.push({currCount, currChar});
        } else {
          break;
        }
      } else {
        ans.push_back(currChar);
        if (currCount - 1 > 0) {
          pq.push({currCount - 1, currChar});
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());

    int ans = 0, res = 0;

    for (int n : nums1) {
      if (s2.count(n) > 0) {
        ans++;
      }
    }

    for (int num : nums2) {
      if (s.count(num) > 0) {
        res++;
      }
    }

    return {ans, res};
  }
};

class Solution {
 public:
  int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int n : nums) {
      mp[n]++;
    }
    int sum = 0;
    for (auto it : mp) {
      if (it.second == 1) {
        sum += it.first;
      }
    }
    return sum;
  }
};

#include <algorithm>
#include <vector>

class Solution {
 public:
  int sumOfUnique(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if ((i == 0 || nums[i] != nums[i - 1]) &&
          (i == nums.size() - 1 && nums[i] != nums[i - 1])) {
        sum += nums[i];
      }
    }
    return sum;
  }
};

class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (int n : arr) {
      mp[n]++;
    }
    unordered_set<int> s;

    for (const auto& it : mp) {
      int count = it.second;

      if (s.count(count) > 0) {
        return false;
      }
      s.insert(count);
    }
    return true;
  }
};

class Solution {
 public:
  int maximum69Number(int num) {
    string val = to_string(num);
    for (char& ch : val) {
      if (ch == '6') {
        ch = '9';
        break;
      }
    }
    return stoi(val);
  }
};

class Solution {
 public:
  int maximizeSum(vector<int>& nums, int k) {
    int maxEle = *max_element(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < k; i++) {
      ans += maxEle + i;
    }
    return ans;
  }
};

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(begin(g), end(g));
    sort(begin(s), end(s));

    int i = 0;
    int j = 0;
    int ans = 0;
    while (i < g.size() && j < s.size()) {
      if (g[i] <= s[j]) {
        // j++;
        i++;
        ans++;
      }
      j++;
    }
    return ans;
  }
};

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int totalSum = 0;
    for (int num : nums) {
      totalSum += num;
    }
    if (abs(target) > totalSum) {
      return 0;
    }
    vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, -1));
    return helper(nums, target, 0, 0, dp, totalSum);
  }

  int helper(vector<int>& nums, int target, int idx, int currentSum,
             vector<vector<int>>& dp, int totalSum) {
    if (idx == nums.size()) {
      return currentSum == target ? 1 : 0;
    }
    if (abs(currentSum) > totalSum) {
      return 0;
    }
    int dpIndex = currentSum + totalSum;
    if (dp[idx][dpIndex] != -1) {
      return dp[idx][dpIndex];
    }
    int add =
        helper(nums, target, idx + 1, currentSum + nums[idx], dp, totalSum);
    int minus =
        helper(nums, target, idx + 1, currentSum - nums[idx], dp, totalSum);
    dp[idx][dpIndex] = add + minus;
    return dp[idx][dpIndex];
  }
};

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(s, 0, n - 1, dp);
  }

  int helper(string s, int start, int end, vector<vector<int>>& dp) {
    if (start > end) {
      return 0;
    }
    if (start == end) return 1;
    if (s[start] == s[end]) {
      dp[start][end] = 2 + helper(s, start + 1, end - 1, dp);
    } else {
      dp[start][end] =
          max(helper(s, start + 1, end, dp), helper(s, start, end - 1, dp));
    }

    return dp[start][end];
  }
};

class Solution {
 public:
  int helper(vector<int>& nums, int i) {
    int ans = 1;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] > nums[i]) {
        ans = max(ans, 1 + helper(nums, j));
      }
    }
    return ans;
  }
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, helper(nums, i));
    }
    return ans;
  }
};

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    return solve(grid, m, n, 0, 0);
  }
  int solve(vector<vector<int>>& grid, int m, int n, int i, int j) {
    if (i >= m || j >= n) {
      return INT_MAX;
    }
    if (i == m - 1 && j == n - 1) return grid[i][j];

    int left = solve(grid, m, n, i + 1, j);
    int down = solve(grid, m, n, i, j + 1);

    return grid[i][j] + min(left, down);
  }
};

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return helper(word1, word2, m, n, memo);
  }

  int helper(string word1, string word2, int m, int n,
             vector<vector<int>>& memo) {
    if (m == 0) return n;
    if (n == 0) return m;
    if (memo[m][n] != -1) return memo[m][n];
    if (word1[m - 1] == word2[n - 1]) {
      memo[m][n] = helper(word1, word2, m - 1, n - 1, memo);
    } else {
      int insert = helper(word1, word2, m, n - 1, memo);
      int deleteop = helper(word1, word2, m - 1, n, memo);
      int replace = helper(word1, word2, m - 1, n - 1, memo);
      memo[m][n] = 1 + min({insert, deleteop, replace});
    }
    return memo[m][n];
  }
};

class Solution {
 public:
  int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return solve(nums, nums.size() - 1, memo);
  }
  int solve(vector<int>& nums, int n, vector<int>& memo) {
    if (n < 0) return 0;
    int robHouse = nums[n] + solve(nums, n - 2);
    int skip = solve(nums, n - 1);
    memo[n] = min(robHouse, skip);
    return memo[n];
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
    int target = total / 2;
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= nums.size(); i++) {
      dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= nums.size(); i++) {
      for (int j = 1; j <= target; j++) {
        // If we don't include nums[i-1], the answer is the same as the previous
        // row
        dp[i][j] = dp[i - 1][j];

        // If we include nums[i-1], we check if it's possible to form the
        // remaining sum
        if (j >= nums[i - 1]) {
          dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
        }
      }
    }

    return dp[nums.size()][target];
  }
};
bool canPartitionWithDifference(vector<int>& nums, int target) {
  int total = 0;
  for (int n : nums) {
    total += n;
  }

  if ((total + target) % 2 != 0 || total + target < 0) {
    return false;
  }
  return solves(nums, nums.size() - 1, newta)
}

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;

    if (root == nullptr) return res;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int s = q.size();
      vector<int> level;

      for (int i = 0; i < s; i++) {
        Node* top = q.front();
        q.pop();

        level.push_back(top->val);
        for (Node* child : top->children) {
          q.push(child);
        }
      }
      res.push_back(level);
    }
    return res;
  }
};

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < n; i++) {
      int curr = max(nums[i] + prev2,
                     prev1);  // dp[i] = max(nums[i] + dp[i-2], dp[i-1])
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};
class Solution {
 public:
  int maxDepth(Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    int maxD = 0;
    while (!q.empty()) {
      auto it = q.front();
      q.pop();
      maxD = max(maxD, it.second);

      for (Node* child : root->children) {
        q.push({child, it.second + 1});
      }
    }
    return maxD;
  }
};

class Solution {
 public:
  void generateSubsets(int index, vector<int>& nums, vector<int>& current,
                       vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = index; i < nums.size(); i++) {
      current.push_back(nums[i]);
      generateSubsets(index + 1, nums, current, result);
      current.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;

    vector<int> temp;
    sort(nums.begin(), nums.end());

    solve(nums, res, temp, 0);
    return res;
  }
};

class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    vector<int> freq(26, INT_MAX);
    vector<string> ans;
    for (const string& word : words) {
      vector<int> currFreq(26, 0);
      for (char c : word) {
        currFreq[c - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        freq[i] = min(freq[i], currFreq[i]);
      }
    }

    for (int i = 0; i < 26; i++) {
    }
    return ans;
  }
};

class Solution {
 public:
  int numSquares(int n) {
    vector<int> memo(n + 1, -1);
    dp[n] = 0;
    for (int target = 1; target <= n; i++) {
      for (int i = 1; i * i < n; i++) {
        dp[target] = min(dp[target], dp[target - i * i]);
      }
    }
    return dp[n];
    d
  }
  int helper(int target, vector<int>& memo) {
    if (target == 0) return 0;
    if (target <= 0) return INT_MAX;

    if (memo[target] != -1) return memo[target];
    int res = INT_MAX;
    for (int i = 1; i * i <= n; i++) {
      int include = helper(target - i * i, memo);
      if (include != INT_MAX) {
        res = min(res, 1 + include);
      }
    }
    memo[target] = res;
    return memo[target];
  }
};

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    return solve(grid, m, n, 0, 0);
  }
  int solve(vector<vector<int>>& grid, int m, int n, int i, int j) {
    if (i >= m || j >= n) {
      return INT_MAX;
    }
    if (i == m - 1 && j == n - 1) return grid[i][j];

    int left = solve(grid, m, n, i + 1, j) + grid[i][j];
    int down = solve(grid, m, n, i, j + 1) + grid[i][j];

    return min(left, down);
  }
};

#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    // return solve(grid, m, n, 0, 0, memo);
  }

 private:
  int solve(vector<vector<int>>& grid, int m, int n, int i, int j,
            vector<vector<int>>& memo) {
    if (i >= m || j >= n) {
      return INT_MAX;
    }
    if (i == m - 1 && j == n - 1) {
      return grid[i][j];
    }
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    int down = solve(grid, m, n, i + 1, j, memo);
    int right = solve(grid, m, n, i, j + 1, memo);
    memo[i][j] = grid[i][j] + min(down, right);
    return memo[i][j];
  }
};

class Solution {
 public:
  void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int node) {
    visited[node] = true;
    for (int& nei : rooms[node]) {
      if (!visited[nei]) {
        dfs(rooms, visited, node);
      }
    }
  }
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    dfs(rooms, visited, 0);
    for (bool it : visited) {
      if (it == false) {
        return false;
      }
    }
    return true;
  }
};

class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows = maze.size();
    int cols = maze[0].size();
    queue<pair<int, int>> q;
    // set<pair<int,int>> visited;
    q.push({entrance[0], entrance[1]});
    maze[entrance[0]][entrance[1]] = '+';

    int ans = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int x = q.front().first;
        int y = q.front().second;
        if ((x == 0 || x == rows - 1 || y == 0 || y == cols - 1) &&
            (x != entrance[0] || y != entrance[1])) {
          return steps;
        }
        for (pair<int, int>& it : directions) {
          int nx = it.first;
          int ny = it.second;

          if (nx > 0 && nx < rows && ny > 0 && ny < cols &&
              maze[nx][ny] != '+') {
            q.push({nx, ny});
            maze[nx][ny] = '+';
          }
        }
        ans += 1;
      }
    }
    return ans;
  }
};
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, graph, hasApple);
    }

    int dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& hasApple) {
        int time = 0;
        for(int neighbor : graph[node]) {
            if(neighbor == parent) continue; 
            int childTime = dfs(neighbor, node, graph, hasApple);
            if(childTime>0 || hasApple[neighbor] ) {
              time += childTime +2;
            }
        }
        return time;
    }
};