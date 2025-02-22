#include <bits/stdc++.h>
using namespace std;

void zeroOneBFS(int n, vector<pair<int, int>> adj[], int src) {
    deque<int> q;
    vector<int> dist(n, INT_MAX);
    dist[src]=0;
    q.push_back(src);
    while(!q.empty()) {
        int node = q.front();
        q.pop_front();
        for(auto it:adj[node] ) {
            int neighbour = it.first , weight = it.second;
            if(dist[neighbour] > dist[node] + weight) {
                dist[neighbour] = dist[node] + weight;
                if(weight==0) {
                    q.push_front(neighbour);
                }else{
                    q.push_back(neighbour);
                }
            }
        }
    }
}

int main() {
    int n = 6;
    vector<pair<int, int>> adj[6];

    adj[0].push_back({1, 0});
    adj[0].push_back({2, 1});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 0});
    adj[3].push_back({4, 1});
    adj[4].push_back({5, 0});

    zeroOneBFS(n, adj, 0);

    return 0;
}
