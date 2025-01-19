#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  char data;
  TrieNode* children[26];  
  bool isEndOfword;
  TrieNode(char value) {
    this->data = value;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    isEndOfword = false;
  }
};
    void insert(TrieNode* root, string word) {
  TrieNode* crawler = root;
  for (char c : word) {
    int idx = c - 'a';
    if (crawler->children[idx] == nullptr) {
      crawler->children[idx] = new TrieNode(c);
    }
    crawler = crawler->children[idx];
  }
  crawler->isEndOfword = true;
}

string shortestUnique(const string& word, TrieNode* root) {
  TrieNode* node = root;
  string prefix;
  for (char c : word) {
    prefix += c;
    int idx = c - 'a';
    if (node->children[idx]->isEndOfword == true) {
      return prefix;
    }
    node = node->children[idx];
  }
  return prefix;
}

// 774
// 445
int minRotation(int input, int unlockCode) {
  int minCost = 0;
  while (input > 0 && unlockCode) {
    int a = input % 10;
    int b = unlockCode % 10;
    minCost += min(abs(a - b), 10 - abs(a - b));
    input = input / 10;
    unlockCode = unlockCode / 10;
  }
  return minCost;
}

vector<int> splitMost(int n) {
  vector<int> result;
  while (n >= 4) {
    result.push_back(4);
    n -= 4;
  }
  if (n == 1) }

bool search(TrieNode* root, string word) {
  TrieNode* crawler = root;
  for (char c : word) {
    int idx = c - 'a';
    if (crawler->children[idx] == nullptr) {
      return false;
    }
    crawler = crawler->children[idx];
  }
  return crawler->isEndOfword;
}

bool deleteHelper(TrieNode* root, string words, int idx) {
  if (idx == words.size()) {
    if (root->isEndOfword) {
      root->isEndOfword = false;
      return true;
    }
    return false;
  }

  int index = words[idx] - 'a';
  TrieNode* crawler = root->children[index];
  if (crawler == nullptr) {
    return false;
  }

  bool canDeleteNode = deleteHelper(crawler, words, idx + 1);

  if (canDeleteNode) {
    if (crawler->isEndOfword = false) {
      delete crawler;
    }
  }
}

void delteWord(TrieNode* root, string words) { deleteHelper(root, words, 0); }

int main() { return 0; }