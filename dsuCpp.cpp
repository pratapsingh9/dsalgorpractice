#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
  vector<int> parent, rank;

public:
  UnionFind(int x)
  {
    parent.resize(x);
    rank.resize(x, 0);
    for (int i = 0; i < x; i++)
    {
      parent[i] = i;
    }
  }

  int findElement(int x)
  {
    if (parent[x] == x)
    {
      return x;
    }

    return parent[x] = x;
  }

  bool unionFInd(int x, int y)
  {
    int rootx = findElement(x);
    int rooty = findElement(y);

    if (rootx = rooty)
      return false;
    
    if(rank[rootx]  > rank[rooty] ) {
      rank[rooty]= rootx;
    }
    else if(rank[rootx] < rank[rooty]) { 
      rank[rootx] = rooty;
   }else{
      rank[rooty]= rootx;

   }
  }

  bool unionFind(int x, int y)
  {
    int rootX = findElement(x);
    int rootY = findElement(y);

    if (rootX == rootY)
      return false;

    if (rank[rootX] > rank[rootY])
    {
      rank[rootY] = rootX;
    }
    else if (rank[rootX] < rank[rootY])
    {
      rank[rootX] = rootY;
    }
    else
    {
      rank[rootY] = rootX;
    }
    return true;
  }

  int findEle(int x)
  {
    if (x == parent[x])
    {
      return x;
    }
    parent[x] = findEle(x);
  }

  int find(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = find(x);
    }
    return parent[x];
  }
  bool unionFind(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
      return false;

    if (rank[rootX] > rank[rootY])
    {
      parent[rootY] = rootX;
    }
    else if (rank[rootY] > rank[rootX])
    {
      rank[rootX] = rootY;
    }
    else
    {
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

  for (const pair<int, int> edge : edges)
  {
    int u = edge.first;
    int v = edge.second;

    if (!uf.unionFind(u, v))
    {
      return true;
    }
  }
  return true;
}

int main() { return 0; }

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int l = 0;
    int r = nums.size() - 1;
    int i = 0;
    while (i < nums.size())
    {
      if (nums[i] == 0)
      {
        swap(nums[l], nums[i]);
        i++;
        l++;
      }
      else if (nums[i] == 2)
      {
        swap(nums[r], nums[i]);
        r--;
      }
      else
      {
        i++;
      }
    }
  }
};

void swaping(vector<int> &nums)
{
  int lastPos = 0;
  int i = 0;
  int r = nums.size() - 1;
  while (i <= r)
  {
    if (nums[i] > 0)
    {
      swap(nums[i], nums[lastPos]);
      lastPos++;
    }
    i++;
  }
}

Node *cloneGrpah(Node *node)
{
  if (node == nullptr)
  {
    return nullptr;
  }
}