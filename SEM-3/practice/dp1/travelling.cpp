#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int tsp(int n, vector<vector<int>>& dist) {
    int N = 1 << n; // Total combinations
    vector<vector<int>> dp(N, vector<int>(n, INF));
    
    dp[1][0] = 0; // Starting at city 0

    for (int mask = 1; mask < N; ++mask) {
        for (int u = 0; u < n; ++u) {
            if ((mask & (1 << u)) == 0) continue;

            for (int v = 0; v < n; ++v) {
                if (mask & (1 << v)) continue;
                int nextMask = mask | (1 << v);
                dp[nextMask][v] = min(dp[nextMask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }

    // Return to starting city (0)
    int res = INF;
    for (int i = 1; i < n; ++i)
        res = min(res, dp[N - 1][i] + dist[i][0]);

    return res;
}

int main() {
    int n = 4;
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum cost of travelling: " << tsp(n, dist) << endl;

    return 0;
}
