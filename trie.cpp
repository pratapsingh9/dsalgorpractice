#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  /* data */
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

void

    void
    insert(TrieNode* root, string word) {
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