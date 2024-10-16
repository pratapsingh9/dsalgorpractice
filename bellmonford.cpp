#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

void flyoodsWarshallAlgorithmsDefine(vector<vector<int>> &graph) {
  int n = graph.size();
  // making the -1 thing a graph
  for(int i = 0 ; i<n;i++) {
    for(int j = 0 ; j<n; j++) {
      if(graph[i][j] == -1) {
        graph[i][j] == INT_MAX;
      }
    }
  }
  // flyowd warsheel algo core

  for(int k = 0; k<n;k++) {
    for(int i = 0; i<n;i++) {
      for(int j = 0 ; j<n; j++) {
        if(graph[i][j] == INT_MAX || graph[k][j] == INT_MAX) continue;

        graph[i][j] = min(graph[i][j] , graph[i][k] + graph[k][j]);
      }
    }
  }

  // making the intmax -1 again

  for(int i = 0 ; i<n; i++) {
    for(int j = 0; j < n; j++) {
        if(matrix[i][j] == INT_MAX) {
        graph[i][j] = -1;
        }
      }
    }
  }

void flyoodsWarshallAlgorithm(vector<vector<int>> &graph) {
  // making the nodes the int max
  int n = graph.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == -1) {
        graph[i][j] = INT_MAX;
      }
    }
  }

  // floyds warsheel algorithm
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) continue;
        raph[i][j] = min(graph[i], graph[j], graph[i][k] + graph[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == INT_MAX) {
        graph[i][j] = -1;
      }
    }
  }
}

void bellmanFordAlgo(int source, vector<vector<pii>> &graph, int v) {
  vector<int> distance(v, INT_MAX);
  distance[source] = 0;

  for (int i = 0; i < v; i++) {
    for (int u = 0; u < v; u++) {
      for (auto &ele : graph[u]) {
        int node = ele.second;
        int weight = ele.first;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[node]) {
          distance[node] = distance[u] + weight;
        }
      }
    }
  }

  for (int u = 0; u < v; u++) {
    for (auto &ele : graph[u]) {
      int node = ele.second;
      int weight = ele.first;

      if (distance[u] != INT_MAX && distance[u] + weight < distance[node]) {
        return;
      }
    }
  }

  cout << "shortest distances from the sources " << source << endl;

  for (int i = 0; i < V; i++) {
    if (distance[i] == INT_MAX) {
      cout << "Node have unreachable" << endl;
    } else {
      cout << "Distacne from source to i is " << i << ": " << distance[i]
           << endl;
    }
  }
}

void bellmanFord(int source, vector<vector<pii>> &graph, int V) {
  vector<int> distance(V, INT_MAX);
  distance[source] = 0;

  // Relax all edges V - 1 times
  for (int i = 0; i < V - 1; i++) {
    for (int u = 0; u < V; u++) {
      for (auto &edge : graph[u]) {
        int v = edge.second;
        int weight = edge.first;

        // Relax the edge
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
          distance[v] = distance[u] + weight;
        }
      }
    }
  }

  // checking for negative weigth cycles
  for (int u = 0; u < V; u++) {
    for (auto &edge : graph[u]) {
      int node = edge.second;
      int weight = edge.first;

      if (distance[u] != INT_MAX && distance[u] + weight < distance[node]) {
        cout << "graph container negative cycles";
        return;
      }
    }
  }

  // Print the distances
  cout << "shortest distances from the sources " << source << endl;

  for (int i = 0; i < V; i++) {
    if (distance[i] == INT_MAX) {
      cout << "Node have unreachable" << endl;
    } else {
      cout << "Distacne from source to i is " << i << ": " << distance[i]
           << endl;
    }
  }
}

int main() {
  int V = 5;
  vector<vector<pii>> adj(V);

  // Adjacency list (first is weight, second is neighbor)
  adj[0].push_back({10, 1});
  adj[0].push_back({5, 4});
  adj[1].push_back({1, 2});
  adj[2].push_back({4, 3});
  adj[4].push_back({3, 1});
  adj[4].push_back({9, 2});
  adj[4].push_back({2, 3});

  int source = 0;

  // Call Bellman-Ford
  bellmanFord(source, adj, V);

  return 0;
}
