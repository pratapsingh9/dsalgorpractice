#include <bits/stdc++.h>
using namespace std;

vector<list<int>> unw_graph;
int v;

void addEdge(int src, vector<list<int>> &graph, int dest, bool bi_dir = false) {
  graph[src].push_back(dest);
  if (bi_dir) {
    graph[dest].push_back(src);
  }
}

void display() {
  for (int i = 0; i < unw_graph.size(); i++) {
    cout << i << " -> ";
    for (auto ele : unw_graph[i]) {
      cout << ele << " ";
    }
    cout << endl;
  }
}

bool BiperateGraphUtil(int node, vector<int> &colors, int value) {
  colors[node] = value;
  for (auto ele : unw_graph[node]) {
    if (colors[ele] == -1) {
      if (!BiperateGraphUtil(ele, colors, 1 - value)) {
        return false;
      } else if (colors[ele] == value) {
        return false;
      }
    }
  }

  return true;
}
bool biperateGraphDfs() {
  vector<int> color(v, -1);
  for (int i = 0; i < v; i++) {
    if (color[i] == -1) {
      if (!BiperateGraphUtil(i, color, c)) {
        return false;
      }
    }
  }
  return true;
}

bool biperateGraphsDfsUtils(int node, vector<int> &colors, int value) {
  colors[node] = value;
  for (auto ele : unw_graph[node]) {
    if (colors[ele] == -1) {
      colors[ele] = 1 - colors[node];
      if (!biperateGraphsDfsUtils(ele, colors, 1 - colors[ele])) {
        return false;
      } else if (colors[ele] == colors[node]) {
        return false;
      }
    }
  }
  return true;
}

bool biperateGraphdfs() {
  vector<int> vec(v, -1);
  for (int i = 0; i < v; i++) {
    if (vec[i] == -1) {
      if (!isBiperateGraphs(i, vec, 0)) {
        return false;
      }
    }
  }
}

bool biPerateGraph() {
  vector<int> vec(v, -1);
  queue<int> q;
  for (int start = 0; start < v; start++) {
    if (vec[start] == -1) {
      q.push(start);
      vec[start] = 0;

      while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto ele : unw_graph[node]) {
          if (vec[ele] == -1) {
            vec[ele] = 1 - vec[node];
            q.push(ele);
          } else if (vec[ele] == vec[node]) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

bool isBiperateGraph() {
  vector<int> color(v, -1);
  queue<int> q;

  for (int start = 0; start < v; start += 1) {
    q.push(start);
    color[start] = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (auto ele : unw_graph[node]) {
        if (color[ele] == -1) {
          color[ele] = 1 - color[node];
          q.push(ele);
        } else if (color[ele] == color[node]) {
          return false;
        }
      }
    }
  }
  return true;
}

bool isBiperateGraph() {
  vector<int> color(v, -1);
  queue<int> q;

  for (int start = 0; start < v; start++) {
    if (color[start] == -1) {
      queue<int> q;
      color[start] = 0;
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto ele : unw_graph[node]) {
          if (color[ele] = -1) {
            q.push(ele);
            color[ele] = 1 - color[node];
          } else if (color[ele] == color[node]) {
            return false;
          }
        }
      }
    }
  }
  return true;
}
bool IsBiperateGraph() {
  vector<int> color(v, -1);
  for (int start = 0; start < v; start++) {
    if (color[start] == -1) {
      queue<int> q;
      q.push(start);
      color[start] = 0;

      while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto ele : unw_graph[node]) {
          if (color[ele] == -1) {
            color[ele] = 1 - color[node];
            q.push(ele);
          } else if (color[ele] == color[node]) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

void bfs(int start) {
  vector<int> visited(v, false);
  queue<int> q;
  visited[start] = false;
  q.push(start);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << endl;
    for (auto ele : unw_graph[node]) {
      if (!visited[ele]) {
        q.push(ele);
        visited[ele] = true;
      }
    }
  }
}
// breadth first search
void bfs(int start) {
  vector<bool> visited(v, false);
  queue<int> q;

  visited[start] = false;
  q.push(start);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << endl;

    for (auto ele : unw_graph[node]) {
      if (!visited[ele]) {
        visited[ele] = true;
        q.push(ele);
      }
    }
  }
}

void dfsHelper(int start, vector<int> &visited) {
  visited[start] = true;
  cout << start << endl;
  for (auto ele : unw_graph[node]) {
    if (!visited[start]) {
      dfsHelper(ele, visited);
    }
  }
}

void dfsRecusives(int start) {
  vector<int> visited(n, false);
  dfsHelper(start, visited);
}

void dfsCode(int start) {
  vector<int> visited(v, false);
  stack<int> s;

  s.push(start);
  int node;
  while (!s.empty()) {
    node = s.top();
    s.pop();
    if (!visited[node]) {
      cout << node << endl;
      visited[node] = true;
      for (auto ele : unw_graph[node]) {
        if (!visited[ele]) {
          s.push(ele);
        }
      }
    }
  }
}

void dfscode(int start) {
  vector<int> vist(v, false);
  stack<int> s;
  s.push(start);
  int node;
  while (!s.empty()) {
    /* code */
    node = s.top();
    s.pop();
    if (!vist[node]) {
      vist[node] = true;
      cout << node << endl;

      for (auto ele : unw_graph[node]) {
        if (!vist[ele]) {
          /* code */
          vist[ele] = false;
          s.push(node);
        }
      }
    }
  }
}

void dfs(int start) {
  vector<bool> visited(v, false);
  stack<int> s;
  s.push(start);
  while (!s.empty()) {
    /* code */
    int node = s.top();
    s.pop();
    if (!visited[node]) {
      visited[node] = true;
      cout << node << endl;
      for (auto ele : unw_graph[node]) {
        if (!visited[ele]) {
          s.push(ele);
        }
      }
    }
  }
}

void dfs(int start) {
  vector<bool> visited(v, false);
  stack<int> s;
  s.push(start);
  while (!s.empty()) {
    int node = s.top();
    s.pop();

    if (!visited[node]) {
      visited[node] = true;
      cout << node << endl;

      for (auto ele : unw_graph[node]) {
        if (!visited[ele]) {
          /* code */
          s.push(ele);
        }
      }
    }
  }
}

bool hasPath(int start, int src, vector<bool> &visited) {
  if (src == start) {
    return true;
  }

  visited[src] = true;
  for (auto ele : unw_graph[start]) {
    if (!visited[ele]) {
      if (hasPath(ele, src, visited)) {
        return true;
      }
    }
  }
  return false;
}

bool haspath(int start, int src, vector<bool> &visited) {
  if (src == start) {
    return true;
  }
  visited[src] = true;
  for (auto ele : unw_graph[src]) {
    if (!visited[ele]) {
      if (haspath(start, ele, visited)) {
        return true;
      }
    }
  }

  return false;
}

bool isCyclicUtil(int node, vector<bool> &visited, int parent) {
  visited[node] = false;
  for (auto ele : unw_graph[node]) {
    if (!visited[ele]) {
      if (isCyclicUtil(ele, visited, node)) {
        return true;
      }
    }
    if (ele != parent) {
      return false;
    }
  }
  return false;
}

bool isCycleHere(int node, vector<int> &vec, int parent) {
  vec[node] = true;
  for (auto ele : unw_graph[node]) {
    if (!vec[ele]) {
      if (isCycleHere(ele, vec, node)) {
        return true;
      }
    } else {
      if (ele != parent) {
        return true;
      }
    }
  }
  return false;
}

bool isCyclic() {
  vector<bool> vis(v, false);
  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      if (isCycleHere(i, vis, -1)) {
        return true;
      }
    }
  }
  return false;
}

int numberOfIsland

    int
    main() {
  cin >> v;
  unw_graph.resize(v);

  int e;
  cin >> e;

  for (int i = 0; i < e; i++) {
    int src, dest;
    cin >> src >> dest;
    addEdge(src, unw_graph, dest);
  }

  display();
  int start_node;
  cout << "Enter starting node for BFS: ";
  cin >> start_node;
  cout << "BFS traversal starting from node " << start_node << ": ";
  bfs(start_node);
  cout << endl;

  return 0;
}
