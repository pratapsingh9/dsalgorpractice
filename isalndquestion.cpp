#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
  if (i < 0 || j < 0 || i < grid.size() || j < grid[0].size()) {
    return;
  }

  grid[i][j] = 0;
  dfs(grid, i + 1, j, rows, cols);
  dfs(grid, i - 1, j, rows, cols);
  dfs(grid, i, j - 1, rows, cols);
  dfs(grid, i, j + 1, rows, cols);
}
void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
  if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) {
    return;
  }
  grid[i][j] = 0;
  dfs(grid, i - 1, j, rows, cols);  // up
  dfs(grid, i + 1, j, rows, cols);  // down
  dfs(grid, i, j - 1, rows, cols);  // left
  dfs(grid, i, j + 1, rows, cols);  // right
}
int numIslands(vector<vector<int>>& grid) {
  int rows = grid.size();
  if (rows == 0) return 0;  // Edge case: empty grid
  int cols = grid[0].size();
  int islandCount = 0;  // To count the number of islands
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 1) {
        dfs(grid, i, j, rows, cols);
        islandCount++;  // Increase the count of islands
      }
    }
  }

  return islandCount;
}

int main() {
  vector<vector<int>> grid =
  { {1, 1, 0, 0, 0},
    {1, 1, 0, 0, 1},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1} }

  cout << numIslands(grid)
       << endl;
  return 0;
}

// int main() {
//     // Example grid (1: land, 0: water)
//     vector<vector<int>> grid = {
//         {1, 1, 0, 0, 0},
//         {1, 1, 0, 0, 1},
//         {0, 0, 0, 1, 1},
//         {0, 0, 0, 0, 0},
//         {1, 0, 1, 0, 1}
//     };

//     cout << "Number of islands: " << numIslands(grid) << endl;

//     return 0;
// }
