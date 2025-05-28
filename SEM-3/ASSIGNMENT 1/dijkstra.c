#include <stdio.h>
#include <limits.h>

#define MAX 100       // Maximum number of vertices
#define INF INT_MAX   // Infinity (no path)

// Function to find the vertex with the minimum distance that hasn't been visited
int minDistance(int dist[], int visited[], int numVertices) {
    int min = INF, minIndex;

    for (int v = 0; v < numVertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Dijkstra's algorithm function
void dijkstra(int adjMatrix[MAX][MAX], int numVertices, int startVertex) {
    int dist[MAX];        // Distance array to hold shortest distance from source to each vertex
    int visited[MAX];     // Visited array to keep track of visited vertices

    // Initialize distances to infinity and visited array to 0 (false)
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[startVertex] = 0;  // Distance from source to itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, visited, numVertices);  // Pick the minimum distance vertex
        visited[u] = 1;  // Mark the picked vertex as processed

        // Update dist[v] for all adjacent vertices of u
        for (int v = 0; v < numVertices; v++) {
            // Update dist[v] if it's not visited, there's an edge from u to v,
            // and total weight of path from source to v through u is smaller than current dist[v]
            if (!visited[v] && adjMatrix[u][v] && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    // Print the shortest distances from startVertex to all vertices
    printf("Vertex\tDistance from Source %d\n", startVertex);
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

// Main function to test Dijkstra's algorithm
int main() {
    int numVertices = 6;
    int adjMatrix[MAX][MAX] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int startVertex = 0;
    dijkstra(adjMatrix, numVertices, startVertex);

    return 0;
}
