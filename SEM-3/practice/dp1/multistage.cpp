#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int shortestPath(int n, vector<vector<pair<int, int>>>& graph, int source, int destination) {
    vector<int> cost(n, INF);
    cost[destination] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (auto edge : graph[i]) {
            int v = edge.first;
            int w = edge.second;
            cost[i] = min(cost[i], w + cost[v]);
        }
    }

    return cost[source];
}

int main() {
    int n = 8; // Number of vertices

    // Adjacency list of the graph
    vector<vector<pair<int, int>>> graph(n);

    // Define edges (from -> to, weight)
    graph[0] = {{1, 1}, {2, 2}, {3, 5}};
    graph[1] = {{4, 4}, {5, 11}};
    graph[2] = {{4, 9}, {5, 5}};
    graph[3] = {{5, 1}};
    graph[4] = {{6, 3}};
    graph[5] = {{6, 1}};
    graph[6] = {{7, 2}};

    int source = 0, destination = 7;

    int result = shortestPath(n, graph, source, destination);
    cout << "Minimum cost from node " << source << " to node " << destination << " is: " << result << endl;

    return 0;
}
