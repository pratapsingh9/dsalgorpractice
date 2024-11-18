#include <bits/stdc++.h>

#include <stack>
using namespace std;

// Define a binary tree node
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr) return nullptr;

  if (root == p || root == = q) return root;

  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);

  if (left && right) return root;

  return (left != nullptr) ? left : right;
}

class BSTIterator {
 public:
  stack<int> st;

  void pushLeft(TreeNode* root) {
    while (root != nullptr) {
      st.push(root);
      root = root->left;
    }
  }
  BSTIterator(TreeNode* root) { pushLeft(root); }

  int next() {
    TreeNode* node = st.top();
    st.pop();

    if (node->right != nullptr) {
      pushLeft(node->right);
    }
    return node->val;
  }

  bool hasNext() { return !st.empty(); }
};

TreeNode* lowestCommnbst(TreeNode* root, int p, int q) {
  if (root == nullptr) return NULL;
}

TreeNode* loweestCommonBsts(TreeNode* root, int p, int q) {
  if (root == nullptr) return nullptr;
  if (root == p || root == q) return root;
  if (root->val > p && root->val) return root;
}

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
  printPathNodesToAllLevel(root->left) && printPathNodesToAllLevel(root->right);
}

bool checkSameTree(TreeNode* root, TreeNode* node) {
  if (root == nullptr && node == nullptr) return true;
  if (!root || !node) return false;
  if (root->val != node->val) return false;

  return checkSameTree(root->left, node->left) &&
         checkSameTree(root->right, node->right);
}

bool checkedBalanecedd(TreeNode* root) {
  if (root == nullptr) {
    return false;
  }
  int ltor = maxDepty(root->left);
  int rtor = maxDepty(root->right);

  if (abs(ltor - rtor) > 1) {
    return false;
  }
  return checkedBalanecedd(root->right) && checkBalancedBst(root->left);
}

bool checkBalancedBst(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  int ltor = maxDepty(root->left);
  int rtol = maxDepty(root->right);

  if (abs(ltor - rtol) > 1) {
    return false;
  }

  return checkBalancedBst(root->right) && checkBalancedBst(root->left);
}

int maxDepty(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + max(maxDepty(root->left), maxDepty(root->right));
}

void postOrder(TreeNode* root) {
  if (root == NULL) return;
  stack<TreeNode*> st;
  st.push(root);
  while (!st.empty() || root != nullptr) {
    TreeNode* curr = st.top();
    st.pop();

    if (curr->left) }
}
void postOrder(TreeNode* root) {
  if (root == nullptr) return;
  stack<TreeNode*> st;
  TreeNode* curr = root;
  st.push(root);
  while (curr != nullptr || !st.empty()) {
    TreeNode* value = st.top();
    st.pop();
    cout << value->val << " ";
    if (value->left) {
      st.push(value->left);
    }
    if (value->right) {
      st.push(value->right);
    }
  }
}

void preOrderTraverssal(TreeNode* root) {
  if (root == nullptr) return;

  stack<TreeNode*> st;
  TreeNode* curr = root;
  st.push(root);
  while (curr != nullptr || !st.empty()) {
    TreeNode* curr = st.top();
    st.pop();
    if (curr->left) {
      st.push(curr->left);
    }
    if (curr->right) {
      st.push(curr->right);
    }
  }
}

void inorderTraversalIterative(TreeNode* root) {
  if (root == nullptr) return;
  stack<TreeNode*> st;
  TreeNode* curr = root;
  while (curr != nullptr || !st.empty()) {
    while (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    }
    TreeNode* node = st.top();
    st.pop();
    cout << node->val << endl;

    curr = curr->right;
  }
}
void inorderTraversaliterative(TreeNode* root) {
  if (root == nullptr) return;
  stack<TreeNode*> st;
  TreeNode* curr = root;

  while (curr != nullptr || !st.empty()) {
    while (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    }
    TreeNode* value = st.top();
    st.pop();
    cout << value->val << endl;
    curr = curr->right;
  }
}

void preorder(TreeNode* root) {
  if (root == nullptr) return;
  stack<TreeNode*> st;
  TreeNode* curr = root;
  st.push(root);
  while (curr != nullptr || !st.empty()) {
    TreeNode* curr = st.top();
    st.pop();
    cout << curr->val << " ";
    if (curr->right) {
      st.push(curr->right);
    }
    if (curr->left) {
      st.push(curr->left);
    }
  }
}

void rightView(TreeNode* root) {
  if (root == nullptr) return;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();

    for (int i = 1; i <= n; i++) {
      /* code */
      TreeNode* curr = q.front();
      q.pop();
      if (i == n) cout << curr->val << endl;
      if (curr->left) q.push(curr->left);
      if (curr->right) q.push(curr->right);
    }
  }
}

void leftView(TreeNode* root) {
  if (root == nullptr) return;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      TreeNode* curr = q.front();
      q.pop();

      if (i == 0) {
        cout << curr->val << endl;
      }
      if (curr->right) q.push(curr->right);
      if (curr->left) q.push(curr->left);
    }
  }
}

void inorderTraversal(TreeNode* root) {
  stack<TreeNode*> s;
  TreeNode* curr = root;
  while (curr != nullptr || !s.empty()) {
    while (curr != nullptr) {
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();
    cout << curr->val << endl;
    curr = curr->right;
  }
}

int maxAns = 0;

int findMaxDiameter(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  int l = findMaxDiameter(root->left);
  int r = findMaxDiameter(root->right);

  maxAns = max(maxAns, l + r);

  return 1 + max(l, r);
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  // Inorder traversal of the tree
  printPathNodesToAllLevel(root);

  return 0;
}

class Solution {
 public:
  int maxVowels(string s, int k) {
    int count = 0;
    int maxCount = 0;
    for (int right = 0; right < s.size(); right++) {
      if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
          s[right] == 'o' || s[right] == 'u') {
        count++;
      }

      if (right > k) {
        if (s[right - k] == 'a' || s[right - k] == 'e' || s[right - k] == 'i' ||
            s[right - k] == 'o' || s[right - k] == 'u') {
          count--;
        }
      }

      maxCount = max(count, maxCount);
    }
    return maxCount;
  }
};

class Solution {
 public:
  vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    vector<int> result;
    vector<int> count(101, k);

    for (int i = 0; i < k; i++) {
      count[nums[i] + 50]++;
    }

    auto findXtheSmalles = [&]() {
      int curr = 0;
      for (int i = 0; i < 50; i++) {
        curr++
      }
    }
  }
};

class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int maxSum = 0;
    for (int i = 0; i < k; i++) {
      maxSum += cardPoints[i];
    }
    int ans = maxSum;
    for (int i = 0; i < n - k; i++) {
      maxSum = maxSum - cardPoints[i - k - 1] + cardPoints[i + k + 1];
      maxSum = maxSum - cardPoints[i - k - 1] + cardPoints[i + k + 1];
      ans = max(ans, maxSum);
    }
    return ans;
  }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int n = nums.size();
    if (k == = 1) return nums;
    int maxAns = *max_element(nums.begin(), nums.begin() + k);

    res.push_back(maxAns);

    for (int i = k; i < n; i++) {
      if (nums[i - k] == maxAns) {
        maxAns = *max_element(nums.begin() + i - k + 1, nums.begin() + i + 1);

      } else {
        maxAns = max(maxAns, nums[i]);
      }

      res.push_back(nums[i]);
    }
    return res;
  }
};

class Solution {
 public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    unordered_map<char, int> mp;
    unordered_map<string, int> substringFreq
    int start = 0;
    int ans = 0;
    for (int right = 0; right < s.size(); right++) {
      mp[s[right]]++;
      if(right-start+1 > minSize) {
        mp[s[start]]--;
        if(mp[s[start]]==0) {
          mp.erase(s[start]);
        }
        start++;
      }
      if(right-start+1 == minSize) {
        if(mp.size() <= maxLetters) {
          string nodes = s.substr(start,minSize);
          substringFreq[nodes]++;
          ans=max(ans,substringFreq[nodes]);
        }
      }
    }
    return ans;
  }
};


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
    }
};