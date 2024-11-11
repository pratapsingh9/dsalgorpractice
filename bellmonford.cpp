#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

void floydWarshllAlgo(vector<vector<int>> &graph) {
  int n = graph.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == -1) {
        graph[i][j] = INT_MAX;
      }
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (graph[i][j] == INT_MAX || graph[k][j] == INT_MAX) continue;
        graph[i][j] = min(graph[i])
      }
    }
  }
}

void flyoodsWarshallAlgorithmsDefine(vector<vector<int>> &graph) {
  int n = graph.size();
  // making the -1 thing a graph
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == -1) {
        graph[i][j] == INT_MAX;
      }
    }
  }
  // flyowd warsheel algo core

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (graph[i][j] == INT_MAX || graph[k][j] == INT_MAX) continue;

        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  // making the intmax -1 again

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == INT_MAX) {
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

void belmanFordAlgo(int source, vector<vector<pii>> &graph, int V) {
  vector<int> distance(V, INT_MAX);
  distance[source] = 0;

  for (int i = 0; i < V; i++) {
    for (int u = 0; u < V; u++) {
      for (auto &ele : graph[u]) {
        int node = ele.second;
        int w = ele.first;
        if (distance[u] != INT_MAX && distance[u] + w < distance[node]) {
          distance[node] = distance[u] + w;
        }
      }
    }
  }
  for (int i = 0; i < V; i++) {
    for (auto ele : graph[u]) {
      int node = ele.second;
      int w = ele.first;

      if (distance[i] + w < distance[node]) {
        cout << "Negatyive cycle exits" << endl;
        return;
      }
    }
  }
  cout << "Shortest distances from the sources of " << source << endl;

  for (int i = 0; i < distance.size(); i++) {
    if (distance[i] == INT_MAX) {
      cout << "NOT able to go to node ";
    } else {
      cout << distance[i] << endl;
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

void bellmandFord(int src, vector<vector<pii>> &graph, int v) {
  vector<int> dist(v, false);
  dist[src] = 0;
  for (int i = 0; i < v; i++) {
    for (int u = 0; u < v; u++) {
      for (auto edge : graph[u]) {
        int v =
      }
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

#include <climits>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> adj;

        for (const vector<int>& vec : flights) {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v, cost});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        distance[src] = 0;

        int steps = 0;
        while (!q.empty() && steps <= k)
        {
          /* code */
          int n = q.size();
          while(n--) {
            auto [u , currentDisane ] = q.front();
            q.pop();
            if(u == dst) {
              return currentDisane;
            }

            for(const auto&[v,cost] :adj[u]) {
              int newCost = cost+currentDisane;
              if(newCost < currentDisane)  {
                distance[v] = newCost;
                q.push({v,newCost});
              }
            }
          }
          steps++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    for(int i= 0 ; I)     
    }
}; 