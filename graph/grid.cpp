#include <bits/stdc++.h>
using namespace std;


void dfss(vector<vector<char>> &grid, int i, int j, char replacement) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
        return;
    }

    if (grid[i][j] != '0') {
        return;
    }

    grid[i][j] = replacement;

    dfss(grid, i + 1, j, replacement); 
    dfss(grid, i - 1, j, replacement); 
    dfss(grid, i, j + 1, replacement); 
    dfss(grid, i, j - 1, replacement); 
}


void replaceowithZero(vector<vector<char>> &grid, char replacement) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '0') {
                dfss(grid, i, j, replacement);
            }
        }
    }
}


void printGrid(const vector<vector<char>> &grid) {
    for (const auto &row : grid) {
        for (char value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    vector<vector<char>> grid = {
        {'1', '0', '0', '1'},
        {'0', '0', '1', '0'},
        {'1', '0', '0', '1'},
        {'0', '1', '1', '0'}
    };

    char replacement = 'x';

    replaceowithZero(grid, replacement);
    printGrid(grid);

    return 0;
}
