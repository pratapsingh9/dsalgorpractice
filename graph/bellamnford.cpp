#include <climits>
#include <iostream>
#include <vector>

void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
  vector<int> distance(V, INT_MAX);
  distance[source] = 0;
  for (int i = 0; i < V - 1; ++i) {
    for (int j = 0; j < E; ++j) {
      int u = edges[j].src;
      int v = edges[j].dest;
      int weight = edges[j].weight;
      if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
        distance[v] = distance[u] + weight;
      }
    }
  }
  for (int j = 0; j < E; ++j) {
    int u = edges[j].src;
    int v = edges[j].dest;
    int weight = edges[j].weight;
    if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
      cout << "Graph contains a negative weight cycle." << endl;
      return;
    }
  }
  cout << "Vertex\tDistance from Source" << endl;
  for (int i = 0; i < V; ++i) {
    if (distance[i] == INT_MAX) {
      cout << i << "\t" << "Infinity" << endl;
    } else {
      cout << i << "\t" << distance[i] << endl;
    }
  }
}
int main() {
  int V = 5;  // Number of vertices
  int E = 8;  // Number of edges
  vector<Edge> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
                        {1, 4, 2},  {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

  int source = 0;
  bellmanFord(V, E, edges, source);

  return 0;
}
