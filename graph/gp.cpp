#include <bits/stdc++.h>
#include <strings.h>

using namespace std;
void dfs(vector<vector<char>> &grid, int i, int j) {
  if (i < 0 || j < 0 || i > grid.size() || j > grid[0].size()) {
    return;
  }
  grid[i][j] = '0';
  dfs(grid, i + 1, j);
  dfs(grid, i - 1, j);
  dfs(grid, i, j + 1);
  dfs(grid, i, j - 1);
}

int numberOfIslands(vector<vector<char>> &grid) {
  int num_ofIsland = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == '1') {
        num_ofIsland++;
        dfs(grid, i, j);
      }
    }
  }
  return num_ofIsland;
}

void dfss(vector<vector<char>> &grid, int i, int j, char replacement) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
    return;
  }

  if(grid[i][j] != '0') {
    return ;
  }

  grid[i][j] = replacement;

    dfs(grid, i + 1, j, replacement); // down
    dfs(grid, i - 1, j, replacement); // up
    dfs(grid, i, j + 1, replacement); // right
    dfs(grid, i, j - 1, replacement); // left

}

void replaceowithZero(vector<vector<char>> &grid, char replacement) {
  for (auto ele : grid) {
    for (auto n : grid[ele]) {
      if (grid[ele][n] == '0') {
        dfss(grid, ele, n, replacement)
      }
    }
  }
}

int main() {
  vector<vector<char>> grid = {{'1', '0', '0', '1'},
                               {'0', '0', '1', '0'},
                               {'1', '0', '0', '1'},
                               {'0', '1', '1', '0'}};
  char replacement = "x";

  replaceowithZero(grid, replacement);
}