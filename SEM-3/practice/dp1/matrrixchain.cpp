#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> &arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // L is chain length
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n-1];
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 30};
    int n = arr.size();

    cout << "Minimum number of multiplications is " 
         << matrixChainMultiplication(arr, n) << endl;

    return 0;
}
