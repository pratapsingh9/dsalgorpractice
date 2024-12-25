#include <bits/stdc++.h>
using namespace std;

class UnionFind {
 private:
  vector<int> parent, rank;

 public:
  UnionFind(int x) {
    parent.resize(x);
    rank.resize(x, 0);
    for (int i = 0; i < x; i++) {
      parent[i] = i;
    }
  }

  int findElement(int x) {
    if (parent[x] == x) {
      return x;
    }

    return parent[x] = x;
  }

  bool unionFInd(int x, int y) {
    int rootx = findElement(x);
    int rooty = findElement(y);

    if (rootx = rooty) return false;

    if (rank[rootx] > rank[rooty]) {
      rank[rooty] = rootx;
    } else if (rank[rootx] < rank[rooty]) {
      rank[rootx] = rooty;
    } else {
      rank[rooty] = rootx;
    }
  }

  bool unionFind(int x, int y) {
    int rootX = findElement(x);
    int rootY = findElement(y);

    if (rootX == rootY) return false;

    if (rank[rootX] > rank[rootY]) {
      rank[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
      rank[rootX] = rootY;
    } else {
      rank[rootY] = rootX;
    }
    return true;
  }

  int findEle(int x) {
    if (x == parent[x]) {
      return x;
    }
    parent[x] = findEle(x);
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(x);
    }
    return parent[x];
  }
  bool unionFind(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return false;

    if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else if (rank[rootY] > rank[rootX]) {
      rank[rootX] = rootY;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
    return true;
  }
}

bool
findCycle(int n, vector<pair<int, int>> &edges)
{
  UnionFind uf(n);

  for (const pair<int, int> edge : edges) {
    int u = edge.first;
    int v = edge.second;

    if (!uf.unionFind(u, v)) {
      return true;
    }
  }
  return true;
}

int main() { return 0; }

class Solution {
 public:
  void sortColors(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] == 0) {
        swap(nums[l], nums[i]);
        i++;
        l++;
      } else if (nums[i] == 2) {
        swap(nums[r], nums[i]);
        r--;
      } else {
        i++;
      }
    }
  }
};

void swaping(vector<int> &nums) {
  int lastPos = 0;
  int i = 0;
  int r = nums.size() - 1;
  while (i <= r) {
    if (nums[i] > 0) {
      swap(nums[i], nums[lastPos]);
      lastPos++;
    }
    i++;
  }
}

Node *cloneGrpah(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }
}

class Solution {
 public:
  int trailingZeroes(int n) { return n / 5 + n / 25 + n / 125; }
};

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr != nullptr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (list1 and list2) {
      if (list1->val > list2->val) {
        tail->next = list2->val;
        list1 = list1->next;
      } else {
        tail->next = list1->val;
        list2->next;
      }
      tail = tail->next;
    }
    if (list1) {
      tail->next = list1;
    }
    if (list2) tail->next = list2;

    return dummy->next;
  }
};

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  // Function to check if a substring is a palindrome
  bool isPalindrome(string &s, int start, int end) {
    while (start < end) {
      if (s[start] != s[end]) return false;
      start++;
      end--;
    }
    return true;
  }

  // Backtracking function with memoization
  vector<vector<string>> solve(string &s, int index,
                               vector<vector<vector<string>>> &dp) {
    // Base case: if we've processed the entire string
    if (index == s.size()) {
      return {{}};
    }
    if (!dp[index].empty()) {
      return dp[index];
    }

    vector<vector<string>> result;
    for (int i = index; i < s.size(); i++) {
      if (isPalindrome(s, index, i)) {
        string currentSubstring = s.substr(index, i - index + 1);
        vector<vector<string>> subPartitions = solve(s, i + 1, dp);
        for (auto &partition : subPartitions) {
          partition.insert(partition.begin(), currentSubstring);
          result.push_back(partition);
        }
      }
    }

    dp[index] = result;
    return result;
  }

  // Main function to return all palindrome partitions
  vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<vector<string>>> dp(n);
    return solve(s, 0, dp);
  }
};

class Solution {
 public:
  bool solve(string s, vector<string> &wordDict,
             unordered_map<string, bool> &memo) {
    if (s.empty()) return true;
    if (memo.find(s) != memo.end()) return memo[s];
    for (string &word : wordDict) {
      if (s.find(word) == 0) {
        if (solve(s.substr(word.length()), wordDict)) {
          memo[s] = true;
          return memo[s];
        }
      }
    }
    memo[s] = false;
    return memo[s];
  }
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_map<string, bool> memo;
    return solve(s, wordDict, memo);
  }
};

