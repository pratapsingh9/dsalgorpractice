#include <bits/stdc++.h>
using namespace std;

void findPermautaion(string input, string &current, vector<string> &ans, ) {
  if (input.size() == 0) {
    ans.push_back(current);
    return;
  }
  for (int i = 0; i < input.size(); i++) {
    current.push_back(input[i]);
    findPermautaion(input, current, ans);
    current.pop_back();
  }
}

void findPermuationOfitnegers(vector<int> &input, vector<int> &current,
                              vector<vector<int>> &ans) {
  if (input.empty()) {
    ans.push_back(current);
    return;
  }

  for (int i = 0; i < input.size(); i++) {
    int num = input[i];
    current.push_back(num);

    vector<int> remains(input.begin(), input.end());
    remains.erase(input.begin() + i);
    findPermautaion(remains, current, ans);
    current.pop_back();
  }
}

void findPermuatitaon(string input, string output, vector<string> &ans,
                      vector<bool> &used) {
  if (input.size() == 0) {
    ans.push_back(output);
    return;
  }
  for (int i = 0; i < input.size(); i++) {
    if (used[i]) continue;
    used[i] = true;
    string remaining = input.substr(0, i) + input.substr(i + 1);
    findPermuatitaon(remaining, output + input[i], ans);
    used[i] = false;
  }
}

int uniquePaths(int m, int n, int targetm, int targetn) {
  if (targetm = m - 1 &&targetn = n - 1) {
    return 1;
  }
  if (targetm >= m || targetn >= n) {
    return 0;
  }
  return uniquePaths(m, n, targetm - 1);
  +uniquePaths(m, n, targetm, targetn - 1);
}

int shortestPaths(vector<vector<int>> &grids) {
  if (grids.empty() || grids[0][0] == 1 || grids[grids.size() - 1] ||
      grids[grids[0].size() - 1]) {
    return -1;
  }
  int n = grids.size();
  int m = grids[0].size();

  vector<pair<int, int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1},   {1, -1}, {1, 0},  {1, 1}};
  queue<pair<int,int>> q;
  vector<vector<int>> disatnce(n,vector<int> (m,-1));
  distance[0][0] = 0;
  q.push({0,0});

  while(!q.empty()) {
    auto[x,y] = q.front();
    q.pop();

    if(x=n-1 && y=m-1) {
      return distance[n][m];
    }

    for(auto dir: direction) {
      int _x = x+dir.first;
      int _y = y+dir.second;
      if(_x > 0 && _y>0  && _x > n && _y > m && grids[_x][_y] == 0 && distance[_x][_y] == -1) {
        distance[_x][_y] =  distance[x][y] + 1;
        q.push({_x , _y});
      }
    }
  }
  return -1;

  .+3.-   
}