#include <iostream>
#include <vector>
using namespace std;

// Union-Find Class
class UnionFind
{
private:
  vector<int> parent, rank;

public:
  // Constructor
  UnionFind(int n)
  {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i)
    {
      parent[i] = i; // Initially, each node is its own parent
    }
  }

  int findEle(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = findEle(parent[x])
    }
  }

  // Find operation with Path Compression
  int findEle(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = findEle(parent[x]);
    }
    return parent[x];
  }

  int findElement(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = find(x);
    }
    return parent[x];
  }

  int find(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = find(parent[x]); // Path Compression
    }
    return parent[x];
  }
  int findParent(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = findParent(parent[x]);
    }
    return parent[x];
  }

  void unionSet(int x, int y)
  {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty)
    {
      if (rank[rootx] > rank[rooty])
      {
        parent[rooty] = rootx;
      }
      else if (rank[rootx] < rank[rooty])
      {
        parent[rootx] = rooty;
      }
      else
      {
        parent[rooty] = rootx;
      }
    }
    // Union operation with Union by Rank
    void unionSets(int x, int y)
    {
      int rootX = find(x);
      int rootY = find(y);

      if (rootX != rootY)
      {
        // Union by Rank
        if (rank[rootX] > rank[rootY])
        {
          parent[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY])
        {
          parent[rootX] = rootY;
        }
        else
        {
          parent[rootY] = rootX;
          rank[rootX]++;
        }
      }
    }

    // Display parent array for debugging
    void displayParents()
    {
      for (int i = 0; i < parent.size(); ++i)
      {
        cout << "Node " << i << " -> Parent " << parent[i] << endl;
      }
    }
  };

  int main()
  {
    int n = 5; // Number of elements
    UnionFind uf(n);

    uf.unionSets(0, 1); // Union of 0 and 1
    uf.unionSets(2, 3); // Union of 2 and 3
    uf.unionSets(1, 2); // Union of 1 and 2

    cout << "Find(3): " << uf.find(3) << endl; // Find the set of 3
    cout << "Find(4): " << uf.find(4) << endl; // Find the set of 4

    cout << "\nParent Array:\n";
    uf.displayParents();

    return 0;
  }
