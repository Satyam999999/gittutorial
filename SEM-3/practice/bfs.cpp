#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<int> adj[], vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int V = 5;  
    vector<int> adj[V] = {
        {1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}
    };

    vector<bool> visited(V, false);
    cout << "BFS Traversal: ";
    bfs(0, adj, visited);

    return 0;
}
