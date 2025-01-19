#include <bits/stdc++.h>
using namespace std;

// first one is weight and second one is node name
typedef pair<int, int> pii;

void dfsIteratives(vector<vector<int>> &graph, int start, int V) {
  vector<bool> visited(V, false);
  stack<int> s;
  s.push(start);

  while (!s.empty()) {
    int node = s.top();
    s.pop();

    if (!visited[node]) {
      visited[node] = true;
      cout << node << endl;
      for (auto &ele : graph[node]) {
        if (!visited[ele]) {
          s.push(ele);
        }
      }
    }
  }
}

void dfsIterative(vector<vector<int>> &graph, int start, int V) {
  vector<bool> visited(V, false);
  stack<int> st;
  s.push(start);
  while (!s.empty()) {
    int node = s.top();
    s.pop();
    if (!visited[node]) {
      visited[node] = true;
      cout << node << endl;
      for (auto &ele : graph[node]) {
        if (!visited[ele]) {
          s.push(ele);
        }
      }
    }
  }
}

void dijkistraa() {}

void dfs(int node, vector < vectornt >> &graph, vector<bool> &visited) {
  visited[node] = true;
  for (auto &ele : graph[node]) {
    if (!visited[ele]) {
      dfs(ele, graph, visited);
    }
  }
}

void bfs(vector<vector<int>> &graph, int node, int V) {
  vector<int> visited(V, false);
  queue<int> q;
  visited[node] = true;
  q.push(node);

  while (!q.empty()) {
    int node = q.front();

    q.pop();
    cout << node << endl;

    for (auto &ele : graph[node]) {
      if (!visited[ele]) {
        visited[ele] = true;
        q.push(ele);
      }
    }
  }
}

void dijkistraAlgo(int src, vector<vector<pii>> &graph, int V) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    int node = pq.top().second;
    pq.pop();
    for (const auto neighbour : graph[node]) {
      int distance = neighbour.first;
      int currNode = neighbour.second;
      if (dist[node] + distance < dist[currNode]) {
        dist[currNode] = dist[node] + distance;
        pq.push({distance[currNode], currNode});
      }
    }
  }
}

void dijkistraAlgos(int source, vector<vector<pii>> &graph, int V) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  vector<int> distance(V, INT_MAX);
  distance[source] = 0;

  pq.push({0, source});

  while (!pq.empty()) {
    int node = q.top().second;
    pq.pop();

    for (auto &neighbor : graph[node]) {
      int currentNode = neighbor.second;
      int weight = neighbor.first;

      if (distance[node] + weight < distance[currentNode]) {
        distance[currentNode] = distance[node] + weight;
        pq.push({distance[currentNode] + currentNode});
      }
    }
  }
}

void dijkistraAlgo(int source, vector<vector<pii>> &graph, int V) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> visited(V, false);
  distance[source] = 0;
  pq.push({0, source});

  while (!pq.empty()) {
    int node = pq.top().first;
    pq.pop();

    for (auto &ele : graph[node]) {
      int sourceNode = ele.second;
      int weight = ele.first;
      if (weight + distance[node] < distance[sourceNode]) {
        distance[sourceNode] = weight + distance[node];
        pq.push({distance[sourceNode], sourceNode});
      }
    }
  }

  cout << "Distance from the " << source << " is this" << endl;

  for (int i = 0; i < V; i += 1) {
    if (distance[i] == INT_MAX) {
      cout << "value is not present at the index" << endl;
    } else {
      cout << "Node :" << i << " from them is " << distance[i] << endl;
    }
  }
}

vector<int> disjkistra(int source, vector<vector<pii>> &graph, int V) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> distance(V, INT_MAX);
  distance[source] = 0;
  pq.push({0, source});
  while (!pq.empty()) {
    int node = pq.top().second;
    pq.pop();
    for (auto const &it : graph[node]) {
      int secondNode = it.second;
      int weight = it.first;
      if (distance[node] + weight < distance[secondNode]) {
        distance[secondNode] = weight + distance[node];
        pq.push({distance[secondNode], secondNode});
      }
    }
  }
  return distance;
}

void dijkistraAlgo(int source, vector<vector<pii>> &graph, int V) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> distance(V, INT_MAX);
  distance[source] = 0;
  pq.push({0, source});

  while (!pq.empty()) {
    int node = pq.top().second;
    pq.pop();

    for (auto &neighbor : graph[node]) {
      int passed_node = neighbor.second;
      int weight = neighbor.first;

      if (distance[node] + weight < distance[passed_node]) {
        distance[passed_node] = distance[node] + weight;
        pq.push({distance[passed_node], passed_node});
      }
    }
  }

  cout << "Value of i from the source is " << src << endl;

  for (int i = 0; i < V; i++) {
    if (distance[i] == INT_MAX) {
      cout << "Cannot able to reach i" << endl;
    } else {
      cout << "Node :" << i << " from them is " << distance[i] << endl;
    }
  }
}

void dijkstra(int src, vector<vector<pii>> &adj, int V) {
  priority_queue<pii, vector<pii>, greater<pii>> q;
  vector<int> distance(V, INT_MAX);

  distance[src] = 0;
  q.push({0, src});

  while (!q.empty()) {
    int currentNode = q.top().second;
    q.pop();

    for (auto &neighbor : adj[currentNode]) {
      int passed_node = neighbor.second;
      int weight_to_node = neighbor.first;

      // Relaxation: Update distance if a shorter path is found
      if (weight_to_node + distance[currentNode] < distance[passed_node]) {
        distance[passed_node] = weight_to_node + distance[currentNode];
        q.push({distance[passed_node], passed_node});
      }
    }
  }

  cout << "Shortest distances from the source node " << src << " are:" << endl;

  for (int i = 0; i < V; i++) {
    if (distance[i] == INT_MAX) {
      cout << "Node " << i << " is unreachable" << endl;
    } else {
      cout << "Distance to node " << i << ": " << distance[i] << endl;
    }
  }
}

void topologicalSort(int node, vector<bool> &visited, stack<int> &Stack,
                     const vector<vector<pair<int, int>>> &adj) {
  visited[node] = true;
  for (const auto &neighbour : adj[node]) {
    int currNode = neighbour.first;
    if (!visited[currNode]) {
      topologicalSort(currNode, visited, Stack, adj);
    }
  }
  Stack.push(node);
}

vector<int> shortestPathIntoDag(vector<vector<pair<int, int>>> &graph, int V,int src) {
  stack<int> st;
  vector<int> visited(V, false);
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      dfs(i, visited, st, graph);
    }
  }
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;
  while (!st.empty()) {
    int node = st.top();
    st.pop();
    for (const auto &it : graph[node]) {
      int w = it.second;
      int nodes = it.first;
      if (dist[node] + w < dist[nodes]) {
        dist[nodes] = dist[node] + w;
      }
    }
  }
  return dist;
}
bool isBiperaties(vector<vector<int>> &graph) {
  int n = graph.size();
  vector<int> color(n, -1);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      q.push(i);
      color[i] = 0;
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int n : graph[node]) {
          if (color[n] == -1) {
            color[n] = 1 - color[node];
            q.push(n);
          } else if (color[node] == color[n]) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main() {
  int V = 5;
  vector<vector<pii>> adj(V);

  adj[0].push_back({10, 1});
  adj[0].push_back({5, 4});
  adj[1].push_back({1, 2});
  adj[2].push_back({4, 3});
  adj[4].push_back({3, 1});
  adj[4].push_back({9, 2});
  adj[4].push_back({2, 3});

  int source = 0;
  dijkstra(source, adj, V);

  return 0;
}
class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
      return -1;
    }
  }
};