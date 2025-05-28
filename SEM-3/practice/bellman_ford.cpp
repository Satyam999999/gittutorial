#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, wt;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // Step 1: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (auto edge : edges) {
            if (dist[edge.u] != 1e9 && dist[edge.u] + edge.wt < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.wt;
            }
        }
    }

    // Step 2: Check for negative weight cycles
    for (auto edge : edges) {
        if (dist[edge.u] != 1e9 && dist[edge.u] + edge.wt < dist[edge.v]) {
            cout << "Graph contains a negative weight cycle.\n";
            return;
        }
    }

    // Print distances
    cout << "Vertex\tDistance from Source " << src << "\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int V = 5, E = 5;
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -3},
        {2, 3, 3},
        {3, 4, -1}
    };

    int source = 0;
    bellmanFord(V, E, edges, source);

    return 0;
}
