#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int adjMatrix[MAX][MAX];  // Adjacency matrix
int visited[MAX];          // Visited array for DFS and BFS

// Queue structure and operations
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize a queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// Enqueue function
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->items[++q->rear] = value;
    }
}

// Dequeue function
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = q->items[q->front];
        if (q->front >= q->rear) {  // Reset the queue after last dequeue
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
    return item;
}

// Function to add an edge to the adjacency matrix
void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;  // For undirected graph; remove this line for directed graph
}

// BFS function using enqueue and dequeue
void bfs(int startVertex, int numVertices) {
    Queue q;
    initQueue(&q);

    visited[startVertex] = 1;     // Mark the starting vertex as visited
    enqueue(&q, startVertex);     // Enqueue the starting vertex

    while (!isEmpty(&q)) {        // While the queue is not empty
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            // If there is an edge and the vertex is not visited
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;     // Mark as visited
                enqueue(&q, i);     // Enqueue the vertex
            }
        }
    }
}

// DFS function
void dfs(int vertex, int numVertices) {
    visited[vertex] = 1;  // Mark the vertex as visited
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        // If there is an edge and the vertex is not visited
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i, numVertices);  // Recursive DFS call
        }
    }
}

// Main function to test BFS and DFS
int main() {
    int numVertices = 6;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Adding edges using addEdge function
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);

    // Run BFS
    printf("BFS starting from vertex 0:\n");
    bfs(0, numVertices);

    // Reset visited array for DFS
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Run DFS
    printf("\nDFS starting from vertex 0:\n");
    dfs(0, numVertices);

    return 0;
}
