#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

f
void adding(vector<pair<int,int>> adj[] , int u , int v , int weight) {
  adj[u].push_back({v , weight});
  adj[v].push_back({u , weight});
}

void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

void printGraph(const vector<pair<int, int>> adj[], int V) {
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ":\n";
        for (auto edge : adj[i]) {
            cout << "  -> " << edge.first << " (Weight: " << edge.second << ")\n";
        }
        cout << endl;
    }
}



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
    int V = 5; 
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    printGraph(adj, V);
    return 0;
}
