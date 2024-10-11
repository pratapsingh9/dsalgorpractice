#include <bits/stdc++.h>
using namespace std;


bool dfs(int node , int parent , vector<int> adj[] , vector<bool> &visisted)  {
	visited[node] = true;

	for(auto ele:adj[node]) {
		if(!visited[node]) {
			if(dfs(ele , node , adj , visited)) {
				return true;
			} 
		} else if(ele != parent) {
			return false;
		}
	}
	return true;
}


bool isCycle(int V, vector<int> adj[]) {
	vector<bool> visited(V,false);

	for(int i = 0; i<V; i++) {
		if(!visited[i]) {
			if(dfs(i , -1 , adj , visited)) {
				return true;
			}
		}
	}
	return false;
}

int main(){

}