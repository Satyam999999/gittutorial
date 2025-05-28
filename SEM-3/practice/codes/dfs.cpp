#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    cout << node << " ";
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int vertices = 5;
    vector<vector<int>> adj(vertices);

    // Example edges
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    dfs(0, adj, visited);
    cout << endl;

    return 0;
}
