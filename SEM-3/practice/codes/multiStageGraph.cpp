#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int shortestPath(vector<vector<int>>& cost, int n) {
    vector<int> dist(n, INT_MAX);
    dist[n - 1] = 0;

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (cost[i][j] != INT_MAX)
                dist[i] = min(dist[i], cost[i][j] + dist[j]);
        }
    }
    return dist[0];
}

int main() {
    int n = 8;
    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

    cost[0][1] = 1; cost[0][2] = 2;
    cost[1][3] = 3; cost[1][4] = 4;
    cost[2][4] = 2; cost[2][5] = 3;
    cost[3][6] = 6; cost[4][6] = 1;
    cost[5][6] = 2; cost[6][7] = 1;

    cout << "Shortest path cost: " << shortestPath(cost, n) << endl;
    return 0;
}
