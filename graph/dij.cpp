#include <iostream>
#include <vector>
using namespace std;


void adding(vector<pair<int,int>> adj[] , int u , int v , int weight) {
  adj[u].push_back({v , weight});
  adj[v].push_back({u , weight});
}

 // Function to add an edge to the weighted graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    // Add edge from u to v with weight
    adj[u].push_back(make_pair(v, weight));
    // Add edge from v to u with weight (if undirected graph)
    adj[v].push_back(make_pair(u, weight));
}

// Function to print the weighted graph
void printGraph(const vector<pair<int, int>> adj[], int V) {
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ":\n";
        for (auto edge : adj[i]) {
            cout << "  -> " << edge.first << " (Weight: " << edge.second << ")\n";
        }
        cout << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    // Create an adjacency list of size V
    vector<pair<int, int>> adj[V];

    // Add edges with weights
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);

    // Print the graph
    printGraph(adj, V);

    return 0;
}
