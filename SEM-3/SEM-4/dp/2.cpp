
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct Edge {
    int to;
    int cost;
};

int main() {
    int n, m;
    cin >> n;
   cin >> m;
    
    vector<vector<Edge>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        if(u < v)
            graph[u].push_back({v, c});
    }
    
    const int INF = INT_MAX;
    vector<int> dp(n + 1, INF);
    vector<int> nextCity(n + 1, -1);
    
    dp[n] = 0;
    
    for (int i = n - 1; i >= 1; i--) {
        for (auto& edge : graph[i]) {
            int j = edge.to;
            int cost = edge.cost;
            if (dp[j] != INF && cost + dp[j] < dp[i]) {
                dp[i] = cost + dp[j];
                nextCity[i] = j;
            }
        }
    }
    
    if (dp[1] == INF) {
        cout << "No path from city 1 to city " << n << " exists." << endl;
    } else {
        cout << "Minimum cost from city 1 to city " << n << " is: " << dp[1] << endl;
        cout << "Path: ";
        int curr = 1;
        while (curr != -1) {
            cout << curr;
            curr = nextCity[curr];
            if (curr != -1)
                cout << " -> ";
        }
        cout << endl;
    }
    
    return 0;
}