#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int src, vector<vector<pii>>& adj, int V) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;
  pq.push({0, src});

  // While the priority queue is not empty
  while (!pq.empty()) {
    int u = pq.top().second;  // Get the node with the smallest distance
    int d = pq.top().first;   // Get the current shortest distance
    pq.pop();                 // Remove the top element

    // Iterate over all neighbors of node u
    for (auto neighbor : adj[u]) {
      int v = neighbor.first;        // Neighbor node
      int weight = neighbor.second;  // Weight of edge u -> v

      // If a shorter path is found
      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;  // Update the shortest path
        pq.push({dist[v], v});       // Push the updated distance and node
      }
    }
  }

  // Print the shortest distances from the source node to all other nodes
  cout << "Node\tDistance from Source\n";
  for (int i = 0; i < V; ++i) {
    cout << i << "\t" << dist[i] << "\n";
  }
}

void dijkistraAlgo(int src , vector<vector<pii>> &adj, int v) {
    
}


int main() {
  int V = 5;

  vector<vector<pii>> adj(V);
  adj[0].push_back({1, 10});
  adj[0].push_back({4, 5});
  adj[1].push_back({2, 1});
  adj[1].push_back({4, 2});
  adj[2].push_back({3, 4});
  adj[3].push_back({0, 7});
  adj[4].push_back({1, 3});
  adj[4].push_back({2, 9});
  adj[4].push_back({3, 2});

  dijkistraAlgo(0,adj,V);

  return 0;

}

// int main() {
//     // Number of nodes (vertices) in the graph
//     int V = 5;

//     // Adjacency list: adj[node] = list of (neighbor, weight)
//     vector<vector<pii>> adj(V);

//     // Add edges (u, v, weight)
//     adj[0].push_back({1, 10});
//     adj[0].push_back({4, 5});
//     adj[1].push_back({2, 1});
//     adj[1].push_back({4, 2});
//     adj[2].push_back({3, 4});
//     adj[3].push_back({0, 7});
//     adj[4].push_back({1, 3});
//     adj[4].push_back({2, 9});
//     adj[4].push_back({3, 2});

//     // Run Dijkstra's algorithm from source node 0
//     dijkstra(0, adj, V);

//     return 0;
// }
