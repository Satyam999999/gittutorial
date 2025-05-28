#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    cout << node << " ";  
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int V = 5;  
    vector<int> adj[V] = {
        {1, 2},  
        {0, 3, 4},  
        {0, 4}, 
        {1}, 
        {1, 2}  
    };

    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    dfs(0, adj, visited);

    return 0;
}
