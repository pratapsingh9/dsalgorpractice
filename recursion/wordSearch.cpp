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

vector<int> generateParenthis(int n) {
  vector<string> ans;
  generate(n, 0, 0, "", ans);
  return ans;
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
