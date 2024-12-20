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

vector<int> preorder(TreeNode* root) {
  stack<TreeNode*> st;
  st.push(root);
  vector<int> result;
  while (!st.empty()) {
    TreeNode* curr = st.top();
    st.pop();
    if (curr != nullptr) {
      if (curr->left) st.push(curr->left);
      if (curr->right) st.push(curr->right);
    }
    result.push_back(curr->val);
  }
  return result;
}

class Solution {
 public:
  vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> result;
    if (start > end) {
      result.push_back(nullptr);
      return result;
    }
    if (memo.find({start, end}) != memo.end()) {
      return memo[{start, end}];
    }
    for (int root = start; root <= end; root++) {
      vector<TreeNode*> leftSubTree = generateTrees(start, root - 1);
      vector<TreeNode*> rightSubTree = generateTrees(root + 1, end);
      for (TreeNode* left : leftSubTree) {
        for (TreeNode* right : rightSubTree) {
          TreeNode* currentNode = new TreeNode(root);
          currentNode->left = left;
          currentNode->right = right;
          result.push_back(currentNode);
        }
      }
    }
    memo[{start, end}] = result;
    return result;
  }
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    unordered_map<pair<int, int>, vector<TreeNode*>> memo;
    return generateTreesUtil(1, n, memo);
  }
};

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> result = {0};
    for (int i = 0; i < n; ++i) {
      int size = result.size();
      for (int j = size - 1; j >= 0; --j) {
        result.push_back(result[j] | (1 << i));
      }
    }
    return result;
  }
};

class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> s;
    return dfs(root, k, s);
  }
  bool dfs(TreeNode* root, int k, unordered_set<int>& s) {
    if (root == nullptr) return false;
    if (s.count(k - root->val) != s.end()) {
      return true;
    }

    s.insert(root->val);

    return dfs(root->left, k, s) || dfs(root->right, k, s);
  }
};

class Solution {
 public:
  vector<int> largestValues(TreeNode* root) {
    if (root == nullptr) return {};
    queue<TreeNode*> q;
    vector<int> ans;
    q.push(root);
    while (!q.empty()) {
      vector<int> temp;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        temp.push_back(root->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      ans.push_back(*max_element(temp.begin(), temp.end()));
    }
    return ans;
  }
};

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
      int curr = max(nums[i] + prev2, prev1);
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
int maxDepth(Node* root) {
  queue<pair<Node*, int>> q;
  q.push({root, 1});
  int maxy = 0;
  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    maxy = max(maxy, it.second);
    for (Node* kid : root->children) {
      q.push({kid, it.second + 1});
    }
  }
  return maxy;
}
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
    for (auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    return dfs(0, -1, graph, hasApple);
  }

  int dfs(int node, int parent, vector<vector<int>>& graph,
          vector<bool>& hasApple) {
    int time = 0;
    for (int neighbor : graph[node]) {
      if (neighbor == parent) continue;
      int childTime = dfs(neighbor, node, graph, hasApple);
      if (childTime > 0 || hasApple[neighbor]) {
        time += childTime + 2;
      }
    }
    return time;
  }
};

class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int start = 0;
    int ans = 0;
    int countZero = 0;
    for (int end = 0; end < nums.size(); end++) {
      /* code */
      if (nums[end] == 0) {
        countZero++;
      }
      while (countZero > k) {
        if (nums[start] == 0) {
          countZero--;
        }
        start++;
      }
      ans = max(ans, end - start + 1);
    }
    return ans;
  }
};

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int zeroCount = 0;
    int oneCount = 0;
    int ans = 0;
    int l = 0;
    for (int r = 0; r < s.size(); r++) {
      /* code */
      if (s[r] == '0') {
        zeroCount++;
      } else {
        oneCount++;
      }
      while (oneCount < zeroCount * zeroCount) {
        if (s[l] == '0') {
          zeroCount--;
        } else {
          oneCount--;
        }
        l++;
      }
      ans += (r - l + 1);
    }
    return ans;
  }
};

class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int odd = 0, even = 0, ans = 0, l = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] % 2 == 0) {
        even++;
      } else {
        odd++;
      }
      while (odd > k) {
        if (nums[l] % 2 != 0) {
          odd--;
        }
        l++;
      }
      if (odd == k) ans++;
    }
    return ans;
  }
};

class Solution {
 public:
  typedef pair<int, int> P;
  int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<P> q;
    int maxDist = -1;

    for (int i = 0; i < n; i++) {
      /* code */
      for (int j = 0; j < n; j++) {
        /* code */
        if (grid[i][j] == 1) q.push({i, j});
      }
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
      int s = q.size();

      for (int i = 0; i < s; i++) {
        P top = q.front();
        int x = top.first;
        int y = top.second;
        q.pop();

        for (auto it : directions) {
          int newX = it.first + x;
          int newY = it.second + y;

          if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
              grid[newX][newY] == 0) {
            grid[newX][newY] = grid[x][y] + 1;
            q.push({newX, newY});
            maxDist = max(maxDist, grid[newX][newY] - 1);
          }
        }
      }
    }
    return maxDist;
  }
};

class Solution {
 public:
  typedef pair<int, int> P;

  void dfs(vector<vector<pair<int, int>>>& graph, int node,
           vector<bool>& visited, int& minDistance) {
    visited[node] = true;
    for (auto& edge : graph[node]) {
      int neighbour = edge.first;
      int weight = edge.second;
      minDistance = min(minDistance, weight);
      if (!visited[neighbour]) {
        dfs(graph, neighbour, visited, minDistance);
      }
    }
  }

  int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto& edge : roads) {
      int a = edge[0];
      int b = edge[1];
      int distance = edge[2];
      graph[a].emplace_back(b, distance);
      graph[b].emplace_back(a, distance);
    }
    int minDist = INT_MAX;
    vector<bool> visited(n + 1, false);
    dfs(graph, 1, visited, minDist);

    return minDist;
  }
};

void dfscountDistinctIslandsUtil(vector<vector<int>>& grid,
                                 vector<vector<bool>>& visited, int x, int y,
                                 int rows, int cols) {
  if (x > rows || y > cols || x < 0 || y < 0 || grid[x][y] == 0 ||
      visited[x][y]) {
    if (x == y) {
      continue;
    }
    return;
  }

  visited[x][y] = true;
  dfscountDistinctIslandsUtil(grid, visited, x - 1, y, rows, cols);
  dfscountDistinctIslandsUtil(grid, visited, x, y - 1, rows, cols);
  dfscountDistinctIslandsUtil(grid, visited, x, y + 1, rows, cols);
  dfscountDistinctIslandsUtil(grid, visited, x + 1, y, rows, cols);
}

int countDistinctIslands(vector<vector<int>>& grid) {
  // code here
  int row = grid.size();
  int cols = grid[0].size();
  vector<vector<bool>> visited(row, vector<bool>(cols));
  int val = 0;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < cols; j++) {
      /* code */
      if (grid[i][j] == 1 && !visited[i][j]) {
        val++;
        dfscountDistinctIslandsUtil(grid, visited, i, j, row, cols);
      }
    }
  }
  return val;
}

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int row = mat.size();
    int cols = mat[0].size();
    vector<vector<int>> ans(row, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < cols; j++) {
        if (mat[i][j] == 0) {
          q.push({i, j});
          ans[i][j] = 0;
        }
      }
    }
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
      auto it = q.front();
      int x = it.first;
      int y = it.second;
      q.pop();

      for (auto v : directions) {
        int newX = v.first + x;
        int newY = v.second + y;

        if (newX >= 0 && newY >= 0 && newX < row && newY < cols) {
          if (ans[x][y] + 1 < ans[newX][newY]) {
            ans[newX][newY] = 1 + ans[x][y];
            q.push({newX, newY});
          }
        }
      }
    }
    return ans;
  }
};
int solve(const vector<int>& nums) {
  int n = (int)nums.size();
  int ans = 0, curr = 0;
  unordered_map<int, int> mp;
  for (int start = 0; start < count; start++) {
    /* code */
    int curr = mp[start];
    if (mp.count(curr) && mp[curr] >= start) {
    }
  }
}
class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int radius = 0;
    int j = 0;
    for (int house : houses) {
      while (j < houses.size() - 1 && heaters[j] - house) {
      }
    }
    return radius;
  }
};

int secondLargest(vector<int>& arr) {
  int largest = INT_MIN, secondLargest = INT_MIN;
  for (int num : arr) {
    if (num > largest) {
      secondLargest = largest;
      largest = num;
    } else if (num > secondLargest && num < largest) {
      secondLargest = num;
    }
  }
}

class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    int wordIndex = 0, searchIndex = 0;
    for (int i = 0; i < sentence.size(); i++) {
      /* code */
      if (sentence[i] == ' ') {
        wordIndex++;
        searchIndex = 0;
        continue;
      } else {
        if (searchWord[searchIndex] == sentence[i] &&
            searchIndex < searchWord.size()) {
          searchIndex++;
          if (searchIndex == searchWord.size()) {
            return wordIndex;
          }
        } else {
          while (i < sentence.size() && sentence[i] != ' ') {
            i++;
          }
          wordIndex++;
          searchIndex = 0;
        }
      }
    }
    return -1;
  }
};

class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    istringstream iss(sentence);
    string word;
    int index = 1;
    while (iss >> word) {
      if (isSolve(word, searchWord)) {
        return index;
      }
      index += 1;
    }
    return -1;
  }
  bool isSolve(string& word, string& searchWord) {
    if (word.size() > searchWord.size()) {
      return false;
    }

    return word.substr(0, searchWord.length()) == searchWord;
  }
};

bool hasZerosubarray(vector<int>& nums) {
  unordered_set<int> s;
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    /* code */
    sum += nums[i];
    if (s.find(sum) != s.end()) {
      return true;
    }
    s.insert(sum);
  }
  return false;
}

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int cumSum = 0, count = 0;
    mp[0] = 1;
    for (int num : nums) {
      cumSum += num;
      if (mp.find(cumSum - k) != mp.end()) {
        count += mp[cumSum - k];
      }
      mp[cumSum]++;
    }
    return count;
  }
};

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int n = nums.size();
    vector<int> sorted = nums;
    unordered_map<int, int> mp;
    vector<int> result(n, 0);
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i++) {
      if (mp.find(sorted[i]) == mp.end()) {
        mp[sorted[i]] = i;
      }
    }
    for (size_t i = 0; i < n; i++) {
      result[i] = mp[nums[i]];
    }
    return result;
  }
};

class Solution {
 public:
  char findTheDifference(string s, string t) {
    vector<int> sfreq(26, 0);
    for (char c : s) {
      sfreq[c - 'a']++;
      // sfreq[c-'a']
    }
    for (char c : t) {
      sfreq[c - 'a']--;
      if (sfreq[c - 'a'] < 0) {
        return c;
      }
    }
    return '\0';
  }
};

class Solution {
 public:
  string addSpaces(string s, vector<int>& spaces) {
    int n = spaces.size();
    int j = 0;
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
      if (j < n && i == spaces[j]) {
        answer += ' ';
        j++;
      }
      answer += s[i];
    }
    return answer;
  }
};

bool compareString(string first, string second) {
  string s1 = "sfkhh#";
  string s2 = "sfkhh";
  for (size_t i = 0; i < s1.size(); i++) {
    /* code */
    if (s1[i] == '#' && i > 0) {
      s1.erase(i - 1, 1);
    }
  }
}

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int smallestPositive = 1;
    for (int num : nums) {
      if (num == smallestPositive) {
        smallestPositive++;
      }
    }
    return smallestPositive;
  }
};

class Solution {
 public:
  bool equalFrequency(string word) {
    vector<int> freq(26, 0);
    for (char c : word) {
      freq[c - 'a']++;
    }
    for (auto entry : freq) {
    }
    return false;
  }
};

class Solution {
 public:
  int helper(int maxNum, unordered_map<int, int>& mp,
             unordered_map<int, int>& memo) {
    if (maxNum <= 0) return 0;
    if (memo.find(maxNum) != memo.end()) {
      return memo[maxNum];
    }
    int skipCurrent = helper(maxNum - 1, mp, memo);
    int takeCurrent = helper(maxNum - 2, mp, memo) + mp[maxNum] * maxNum;
    memo[maxNum] = max(skipCurrent, takeCurrent);
    return memo[maxNum];
  }
  int deleteAndEarn(vector<int>& nums) {
    if (nums.empty()) return 0;
    unordered_map<int, int> mp;
    int maxNum = 0;
    for (int& n : nums) {
      mp[n]++;
      maxNum = max(maxNum, n);
    }
    unordered_map<int, int> memo;
    return helper(maxNum, mp, memo);
  }
};

class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    if (nums.empty()) return 0;
    unordered_map<int, int> freq;
    int maxNum = 0;
    for (int& n : nums) {
      freq[n]++;
      maxNum = max(maxNum, n);
    }

    vector<int> dp(maxNum + 1, 0);
    dp[0] = 1;
    dp[1] = mp[1] * 1;

    for (int i = 2; i <= maxNum; i++) {
      int skipcurrent = dp[i - 1];
      int includeCurrent = dp[i - 2] + mp[i] * i;
      dp[i] = max(skipcurrent, includeCurrent);
    }

    return dp[maxNum];
  }
};

class Solution {
 public:
  long long solver(int n, vector<int>& power) {
    if (i < 0) return 0;

    long long exclude = solver(n - 1, power);
    long long include = solver(n - 2, power) + power[n];

    return max(exclude, include);
  }
  long long maximumTotalDamage(vector<int>& power) {
    int n = power.size();
    return solver(n - 1, power);
  };
};

class Solution {
 public:
  int solver(vector<int>& nums, int i, int& total) {
    if (i < 2) return 0;
    int count = 0;
    if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2])) {
      count = 1 + solver(nums, i - 1, total);
      total += count;
      return count;
    } else {
      solver(nums, i - 1, total);
      return 0;
    }
  }
  int numberOfArithmeticSlices(vector<int>& nums) {
    int total = 0;
    solver(nums, nums.size() - 1, total);
    return total;
  }
};
class Solution {
 public:
  int solver(vector<int>& nums, int i, int& total, vector<int>& memo) {
    if (i < 2) return 0;
    if (memo[i] != -1) return memo[i];
    int count = 0;
    if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2])) {
      count = 1 + solver(nums, i - 1, total, memo);
      total += count;
    } else {
      solver(nums, i - 1, total, memo);
    }
    return memo[i] = count;
  }
  int numberOfArithmeticSlices(vector<int>& nums) {
    int total = 0;
    int n = nums.size();
    vector<int> memo(n - 1, -1);
    solver(nums, nums.size() - 1, total, memo);
    return total;
  }
};

class Solution {
 public:
  int solve(vector<int>& arr, int index, int difference) {
    if (index < 0) {
      return 0;
    }
    int maxLength = 1;
    for (int i = index - 1; i >= 0; i--) {
      if (arr[i]) }
  }
  int longestSubsequence(vector<int>& arr, int difference) {}
};

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> result(n + 1);
    for (int i = 0; i <= n; i++) {
      result[i] = result[i >> 1] + (i & 1);
    }
    return result;
  }
};

class Solution {
 public:
  int solve(vector<int>& arr, int index, int k) {
    if (index == arr.size()) {
      return 0;
    }

    int maxSum = 0;
    int maxValueInpartition = arr[index];
    for (int j = 1; j <= k && index + j <= arr.size(); j++) {
      maxValueInpartition = maxValueInpartition(maxValueInpartition, arr[j]);
      maxSum = max(maxSum, maxValueInpartition * j + solve(arr, index + j, k));
    }
    return maxSum;
  }
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    return solve(arr, 0, k);
  }
};

class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq;

    for (int x : piles) {
      pq.push(x);
    }
    int sum = 0;
    while (k--) {
      int x = pq.top();
      pq.pop();
      pq.push(x - (x / 2));
    }
    while (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
    return sum;
  }
};

class Solution {
 public:
  int halveArray(vector<int>& nums) {
    priority_queue<int> pq;
    int steps = 0;
    double total_sum = 0;
    for (int x : nums) {
      pq.push(x);
      total_sum += x;
    }
    double reducedSum = total_sum;
    double target = total_sum / 2;
    while (reducedSum > target) {
      double val = pq.top();
      pq.pop();
      reducedSum -= val / 2;
      pq.push(val / 2);
      steps++;
    }
    return steps;
  }
};

class Solution {
 public:
  string clearStars(string s) {
    string result;
    for (char c : s) {
      if (c == '*') {
        if (!result.empty()) {
          result.pop_back();
        }
      } else {
        result.push_back();
      }
    }
    return result;
  }
};

class Solution {
 public:
  void reverse(string& s, int start, int end) {
    while (start < end) {
      swap(s[start], s[end]);
      start++;
      end--;
    }
  }
  string reversePrefix(string word, char ch) {
    int i = 0;
    while (i < word.size() && word[i] != ch) {
      i++;
    }

    if (i < word.size()) {
      reverse(word, 0, i);
    }
    return word;
  }
};

class Solution {
 public:
  bool isPalindrome(string s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
  bool validPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        return isPalindrome(s, left + 1, right) ||
               isPalindrome(s, left, right - 1);
      }

      left++;
      right--;
    }
    return true;
  }
};

class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    string result = "";
    int i = 0;
    int j = 0;
    while (i < word1.size() && j < word2.size()) {
      result += word1[i++];
      result += word2[j++];
    }

    while (i < word1.size()) {
      result += word1[i++];
    }
    while (j < word2.size()) {
      result += word2[j++];
    }
    return result;
  }
};

class Solution {
 public:
  string makeSmallestPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        char ch = min(s[left], s[right]);
        s[left] = s[right] = ch;
      }
      left++;
      right--;
    }
    return s;
  }
};

class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> result(n, INT_MAX);
    vector<int> position;
    for (int i = 0; i < n; i++) {
      if (s[i] == c) {
        position.push_back(i);
      }
    }
    for (int i = 0; i < n; i++) {
      /* code */
      int minDist = INT_MAX;
      for (int pos : position) {
        minDist = min(minDist, abs(i - pos));
      }
      result[i] = minDist;
    }
    return result;
  }
};

class Solution {
 public:
  string largestMerge(string word1, string word2) {
    string merge = "";
    int i = 0, j = 0;

    while (i < word1.size() && j < word2.size()) {
      if (word1.substr(i) > word2.substr(j)) {
        merge += word1[i++];
      } else {
        merge += word2[j++];
      }
    }
    if (i < word1.size()) {
      merge += word1.substr(i);
    }
    if (j < word2.size()) {
      merge += word2.substr(j);
    }

    return merge;
  }
};
class Solution {
 public:
  string largestMerge(string word1, string word2) {
    string merge = "";
    int i = 0, j = 0;

    while (i < word1.size() && j < word2.size()) {
      if (word1[i] > word2[j]) {
        merge += word1[i++];
      } else if (word1[i] < word2[j]) {
        merge += word2[j++];
      } else {
        if (word1.substr(i) > word2.substr(j)) {
          merge += word1[i++];
        } else {
          merge += word2[j++];
        }
      }
    }

    merge += word1.substr(i);
    merge += word2.substr(j);

    return merge;
  }
};

class Solution {
 public:
  string largestMerge(string word1, string word2) {
    string merge = "";
    int i = 0, j = 0;

    while (i < word1.size() && j < word2.size()) {
      if (word1[i] > word2[j]) {
        merge += word1[i++];
      } else if (word1[i] < word2[j]) {
        merge += word2[j++];
      } else {
        if (word1.substr(i) > word2.substr(j)) {
          merge += word1[i++];
        } else {
          merge += word2[j++];
        }
      }
    }

    merge += word1.substr(i);
    merge += word2.substr(j);

    return merge;
  }
};

class Solution {
 public:
  int countBinarySubstrings(string s) {
    int prev = 0, curr = 1, answer = 0;
    for (int i = 1; i < s.size(); i++) {
      /* code */
      if (s[i] == s[i - 1]) {
      }
    }
  }
};

class Solution {
 public:
  int minimumLength(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j && s[i] == s[j]) {
      char ch = s[i];
      while (i <= j && s[i] == ch) {
        i++;
      }
      while (i <= j && s[j] == ch) {
        j--;
      }
    }
    return j - i + 1;
  }
};

class Solution {
 public:
  long long minimumSteps(string s) {
    int n = s.size();
    long long swaps = 0;
    int white = 0;
    for (int i = 0; i < n; ++i) {
      /* code */
      if (s[i] == '1') {
        swaps += white;
      } else {
        white++;
      }
    }
    return swaps;
  }
};

class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int n = nums.size();
    int oddIndex = 1;
    int evenindex = 0;

    while (oddIndex < n && evenindex < n) {
      while (evenindex < n && nums[evenindex] % 2 == 0) {
        evenindex += 2;
      }
      while (oddIndex < n && nums[oddIndex] % 2 == 1) {
        oddIndex += 2;
      }

      if (evenindex < n && oddIndex < n) {
        swap(nums[evenindex], nums[oddIndex]);
      }
    }
    return nums;
  }
};

class Solution {
 public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    int less = 0, equal = 0, more = 0;
    for (int num : nums) {
      if (num < pivot)
        less++;
      else if (num == pivot)
        equal++;
      else
        more++;
    }
    vector<int> result(nums.size());
    int lessIndex = 0;
    int equalIndex = less;
    int moreIndex = less + equal;
    for (int num : nums) {
      if (num < pivot) {
        result[lessIndex++] = num;
      } else if (num == pivot) {
        result[equalIndex++] = num;
      } else {
        result[moreIndex++] = num;
      }
    }

    return result;
  }
};

class Solution {
 public:
  typedef vector<int> v;
  vector<int> rearrangeArray(vector<int>& nums) {
    v postitive;
    v negative;

    for (int n : nums) {
      if (n > 0) {
        postitive.push_back(n);
      } else {
        negative.push_back(n);
      }
    }
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); ++i) {
      /* code */
      if (i % 2 == 0)
        nums[i] = postitive[a++];
      else {
        nums[i] = negative[b++];
      }
    }
    return nums;
  }
};

class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int pos = 0, neg = 1;
    for (int n : nums) {
      if (n > 0) {
        result[pos] = n;
        pos += 2;
      } else if (n < 0) {
        result[neg] = n;
        neg += 2;
      }
    }
    return result;
  }
};

class Solution {
 public:
  long long findScore(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<pair<int, int>> vec;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      /* code */
      vec.push_back({nums[i], i});
    }
    sort(vec.begin(), vec.end());
    long long score = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
      int index = vec[i].second;
      if (!visited[index]) {
        score += vec[i].first;
        if (index > 0) {
          visited[index - 1] = true;
        }
        if (index < n - 1) {
          visited[index + 1] = true;
        }
        visited[index] = true;
      }
    }
    return score;
  }
};

class Solution {
 public:
  typedef pair<int, int> P;
  long long findScore(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    for (int i = 0; i < n; ++i) {
      /* code */
      pq.push({nums[i], i});
    }

    long long score = 0;
    vector<bool> visited(n, false);

    while (!pq.empty()) {
      int value = pq.top().first;
      int index = pq.top().second;

      pq.pop();

      if (visited[index]) continue;

      score += value;
      visited[index] = true;
      if (index > 0) {
        visited[index - 1] = true;
      }
      if (index < n - 1) {
        visited[index + 1] = true;
      }
    }
    return score;
  }
};

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();

    int perimter = 0;

    for (int i = 0; i < r; i++) {
      /* code */
      for (int j = 0; j < c; j++) {
        /* code */
        if (grid[i][j] == 1) {
          perimter += 4;
        }
      }
    }
  }
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    if (root == p || root == q) return root;

    auto l = lowestCommonAncestor(root->left, p, q);
    auto r = lowestCommonAncestor(root->right, p, q);

    if (l & r) return root;

    if (l) return l;

    return r;
  }
};

class Solution {
 public:
  long long continuousSubarrays(vector<int>& nums) {
    long long result = 0;
    int left = 0;
    multiset<int> window;

    for (int right = 0; right < nums.size(); right++) {
      /* code */
      window.insert(nums[right]);
      while (!window.empty() && *window.rbegin() - *window.begin() > 2) {
        window.erase(window.find(nums[left]));
        left++;
      }
      result += right - left + 1;
    }

    return result;
  }
};

class Solution {
 public:
  long long continuousSubarrays(vector<int>& nums) {
    long long result = 0;
    int left = 0;
    map<int, int> frequency;
    for (int right = 0; right < nums.size(); right++) {
      frequency[nums[right]]++;
      while ((frequency.rbegin()->first - frequency.begin()->first) > 2) {
        /* code */
        frequency[nums[left]]--;
        if (frequency[nums[left]] == 0) {
          frequency.erase(nums[left]);
        }
        left++;
      }
      result += right - left + 1;
    }
    return result;
  }
};

#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Function to calculate the change in pass ratio when adding a student
double calcDelta(int passed, int total) {
  return double(passed + 1) / (total + 1) - double(passed) / total;
}

class Solution {
 public:
  double calcDelta(int passed, int total) {
    return double(passed + 1) / (total + 1) - double(passed) / total;
  }

  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<pair<double, pair<int, int>>> maxHeap;
    for (const auto& cls : classes) {
      int passed = cls[0], total = cls[1];
      maxHeap.push({calcDelta(passed, total), {passed, total}});
    }
    while (extraStudents--) {
      auto top = maxHeap.top();
      maxHeap.pop();
      int passed = top.second.first;
      int total = top.second.second;
      passed++;
      total++;
      maxHeap.push({calcDelta(passed, total), {passed, total}});
    }
    double totalAverage = 0.0;
    for (const auto& cls : classes) {
      auto top = maxHeap.top();
      maxHeap.pop();

      int passed = top.second.first;
      int total = top.second.second;
      totalAverage += double(passed) / total;
    }
    return totalAverage / classes.size();
  }
};

class Solution {
 public:
  int solve(vector<vector<int>>& matrix, int cols) {
    int ans = 0;
    for (int i = 0; i < matrix.size(); i++) {
      ans = max(ans, matrix[i][cols]);
    }
    return ans;
  }
  vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (matrix[i][j] == -1) {
          matrix[i][j] = solve(matrix, j);
        }
      }
    }
    return matrix;
  }
};

class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int total = m * n;
    k = k % total;
    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int newP = (i * n + j + k) % total;
        int newR = (newP / n);
        int newC = (newP % n);

        result[newR][newC] = grid[i][j];
      }
    }

    return result;
  }
};

class Solution {
 public:
  bool canMakeSquare(vector<vector<char>>& grid) {
    for (int i = 0; i < 2; i++) {
      /* code */
      for (int j = 0; j < 2; j++) {
        char a = grid[i][j];
        char b = grid[i][j + 1];
        char c = grid[i + 1][j];
        char d = grid[i + 1][j + 1];

        int blackCount = (a == 'B') + (c == 'B') + (d == 'B') + (b == 'B');
        int whitecount = 4 - blackCount;
        if (whitecount >= 3 || blackCount >= 3) {
          return true;
        }
      }
    }

    return false;
  }
};

class Solution {
 public:
  vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int maxRow = 0;
    int maxOnes = 0;

    for (int i = 0; i < mat.size(); i++) {
      int countOnes = 0;
      for (int j = 0; j < mat[0].size(); j++) {
        if (mat[i][j] == 1) {
          countOnes++;
        }
      }
      if (countOnes > maxOnes) {
        maxOnes = countOnes;
        maxRow = i;
      }
    }
    return {maxRow, maxOnes};
  }
};

class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int row = accounts.size();
    int cols = accounts[0].size();
    int maxy = 0;

    for (int i = 0; i < row; i++) {
      /* code */
      int curr = 0;
      for (int j = 0; j < cols; j++) {
        curr += accounts[i][j];
      }

      maxy = max(curr, maxy);
    }
    return maxy;
  }
};

class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int cols = matrix[0].size();

    vector<int> minrow(row, INT_MAX);
    for (int i = 0; i < row; i++) {
      /* code */
      for (int j = 0; j < cols; j++) {
        minrow[i] = min(minrow[i], matrix[i][j]);
      }
    }

    vector<int> colsMax(cols, INT_MIN);
    vector<int> ans;
    for (int j = 0; j < cols; j++) {
      for (int i = 0; i < row; i++) {
        colsMax[j] = max(colsMax[j], matrix[i][j]);
      }
    }

    for (int i = 0; i < row; i++) {
      /* code */
      for (int j = 0; j < cols; j++) {
        if (matrix[i][j] == minrow[i] && matrix[i][j] == colsMax[j]) {
          ans.push_back(matrix[i][j]);
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    int n = mat.size();
    for (int i = 0; i < n; i++) {
      /* code */
      for (int j = 0; j < n; j++) {
        if (i == j || (i + j == n - 1)) {
          sum += mat[i][j];
        }
      }
    }
    return sum;
  }
};
class Solution {
 public:
  bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0) return false;

    int sqrtNum = static_cast<int>(std::sqrt(num));
    for (int i = 3; i <= sqrtNum; i += 2) {
      if (num % i == 0) return false;
    }
    return true;
  }

  int diagonalPrime(vector<vector<int>>& nums) {
    int n = nums.size();
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j || (i + j == n - 1)) {
          if (isPrime(nums[i][j])) {
            ans = max(ans, nums[i][j]);
          }
        }
      }
    }

    return ans == INT_MIN ? 0 : ans;
  }
};


