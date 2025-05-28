#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int L = 2; L <= n; ++L) {
        for (int i = 0; i < n - L + 1; ++i) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
                dp[i][j] = min(dp[i][j],
                               dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1]);
        }
    }
    return dp[0][n-1];
}

int main() {
    vector<int> p = {40, 20, 30, 10, 30};
    cout << "Minimum number of multiplications: " << matrixChainOrder(p) << endl;
    return 0;
}
