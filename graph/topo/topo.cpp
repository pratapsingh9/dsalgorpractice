#include <bits/stdc++.h>
using namespace std;

// topo sort Normal wla

void dfs(int node, vector<int> adj[], vector<bool> vis, stack<int> &st) {
  vis[node] = true;
  for (int neigbour : adj[node]) {
    if (!vis[neigbour]) {
      dfs(neigbour, adj, vis, st);
    }
  }
  st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
  vector<int> vis(v, false);
  stack<int> Stack;

  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      dfs(i, adj, vis, Stack);
    }
  }
}

vector<int> topoSortBfsKahn(vector<int> adj[], int V) {
  vector<int> inDegree(V, 0);
  for (int i = 0; i < V; i++) {
    for (auto it : adj[i]) {
      inDegree[it]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> ans;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (auto it : adj[node]) {
      inDegree[it]--;
      if (inDegree[it] == 0) q.push(it);
    }
  }
  return ans;
}

// topo Sort Kahn,s Algorathims
vector<int> topoSortUsingBfs(vector<int> adj[], int V) {
  vector<int> inDegree(V, 0);
  // getting Indgree

  for (int i = 0; i < V; i++) {
    for (auto it : adj[i]) {
      inDegree[it]++;
    }
  }

  queue<int> q;

  for (int i = 0; i < inDegree.size(); i++) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> topoOrder;
  while (!q.empty()) {
    int top = q.front();
    q.pop();

    topoOrder.push_back(top);

    for (auto it : adj[top]) {
      inDegree[it]--;
      if (inDegree[it] == 0) {
        q.push(it);
      }
    }
  }
  return topoOrder;
}

bool detectCycleGraph(int V, vector<int> adj[]) {
  vector<int> indegree(V, 0);
  for (int i = 0; i < V; i++) {
    for (auto it : adj[i]) {
      indegree[it]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < indegree.size(); i++) {
    if (indegree[i] == 0) q.push(i);
  }

  int count = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    count++;
    for (auto it : adj[node]) {
      indegree[it]--;
      if (indegree[it] == 0) q.push(it);
    }
  }
  if (count == V) return false;
  return true;
}


