#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;



int main() {
	 int V = 5;  // Number of vertices
    vector<vector<pii>> adj(V);  // Adjacency list

    adj[0].push_back({1, 1});  // 0 -> 1 with weight 1
    adj[0].push_back({0, 4});  // 0 -> 4 with weight 0
    adj[1].push_back({0, 2});  // 1 -> 2 with weight 0
    adj[2].push_back({1, 3});
    adj[4].push_back({1, 1}); 
    adj[4].push_back({1, 2});
    adj[4].push_back({0, 3}); 

    int source = 0;
    zeroOneBFS(source, adj, V);

    return 0;
}