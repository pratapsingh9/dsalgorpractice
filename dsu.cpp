#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
 private:
  vector<int> parent, rank;

 public:
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int findEle(int x) {
    if (parent[x] != x) {
      parent[x] = findEle(parent[x])
    }
  }

  int findEle(int x) {
    if (parent[x] != x) {
      parent[x] = findEle(parent[x]);
    }
    return parent[x];
  }

  int findElement(int x) {
    if (parent[x] != x) {
      parent[x] = find(x);
    }
    return parent[x];
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  int findParent(int x) {
    if (parent[x] != x) {
      parent[x] = findParent(parent[x]);
    }
    return parent[x];
  }

  void unionSet(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) {
        parent[rooty] = rootx;
      } else if (rank[rootx] < rank[rooty]) {
        parent[rootx] = rooty;
      } else {
        parent[rooty] = rootx;
      }
    }
    
    void unionSets(int x, int y) {
      int rootX = find(x);
      int rootY = find(y);

      if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
          parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
          parent[rootX] = rootY;
        } else {
          parent[rootY] = rootX;
          rank[rootX]++;
        }
      }
    }

    void displayParents() {
      for (int i = 0; i < parent.size(); ++i) {
        cout << "Node " << i << " -> Parent " << parent[i] << endl;
      }
    }
  };
} 

int main() {
  int n = 5;
  UnionFind uf(n);
  uf.unionSets(0, 1);
  uf.unionSets(2, 3);
  uf.unionSets(1, 2);
  uf.displayParents();
  return 0;
}
