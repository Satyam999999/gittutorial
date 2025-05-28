//1

int countCombinationsRecursive(int coins[], int n, int amount, int index) {
    if (amount == 0) return 1;

    if (amount < 0 || index >= n) return 0;

    return countCombinationsRecursive(coins, n, amount - coins[index], index) +
           countCombinationsRecursive(coins, n, amount, index + 1);
}

//2
int parent[1000];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unionSet(int x, int y) {
    parent[find(x)] = find(y);
}

int minCostToConnectCities(int connections[][3], int m, int N) {
    for (int i = 0; i <= N; i++) parent[i] = i;
    
    sort(connections, connections + m, [](const int a[], const int b[]) {
        return a[2] < b[2];
    });
    
    int cost = 0, edgesUsed = 0;
    for (int i = 0; i < m; i++) {
        int u = connections[i][0], v = connections[i][1], w = connections[i][2];
        if (find(u) != find(v)) {
            unionSet(u, v);
            cost += w;
            edgesUsed++;
        }
    }
    return (edgesUsed == N - 1) ? cost : -1;
}

//3
#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > maxi)
            maxi = arr[i];
    int hsh[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
        hsh[arr[i]]++;
    int j = 0;
    for (int i = 0; i <= maxi; i++)
    {
        while (hsh[i])
        {
            arr[j] = i;
            j++;
            hsh[i]--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++)  //O(n)
        cin >> coins[i];
    int amount;
    cin >> amount;
    countSort(coins, n);  //O(n+max)

    int minCount = 0;
    int i = n - 1;
    while (amount >= coins[0] && i >= 0)  //O(amount/min)
    {
        if (amount >= coins[i])
        {
            amount -= coins[i];
            minCount++;
        }
        else
            i--;
    }

    if (amount == 0)
        cout << minCount << endl;
    else
        cout << -1 << endl;
}

//4
int minCostConnectPoints(int points[][2], int n) {
    int minDist[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        visited[i] = false;
    }
    minDist[0] = 0;
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }
        
        visited[u] = true;
        result += minDist[u];
        
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }
    return result;
}

int minCostConnectPoints(int points[][2], int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n, false);
    pq.push({0, 0});
    int result = 0;
    int edgesUsed = 0;
    
    while (!pq.empty() && edgesUsed < n) {
        auto [cost, u] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        result += cost;
        edgesUsed++;
        
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                pq.push({dist, v});
            }
        }
    }
    return result;
}

#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void primMST(vector<vector<pair<int, int>>> &adj, int V) {
    vector<int> parent(V, -1); 
    vector<int> key(V, INF);   
    vector<bool> inMST(V, false);\

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;  
    pq.push({0, 0}); 

    while (!pq.empty()) {
        int u = pq.top().second; 
        pq.pop();

        if (inMST[u]) continue; 
        inMST[u] = true;

   
        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Add edges: {vertex1, vertex2, weight}
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}
    };

    // Convert edges to adjacency list
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Run Prim's Algorithm
    primMST(adj, V);

    return 0;
}

