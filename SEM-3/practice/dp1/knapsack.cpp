#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items and the maximum weight capacity: ";
    cin >> n >> W;

    vector<int> wt(n), val(n);
    
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}
