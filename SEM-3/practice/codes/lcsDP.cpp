#include <iostream>
#include <vector>
using namespace std;

int lcs(string X, string Y) {
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i=1; i<=m; ++i)
        for (int j=1; j<=n; ++j)
            dp[i][j] = (X[i-1] == Y[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);

    return dp[m][n];
}

int main() {
    string X = "AGGTAB", Y = "GXTXAYB";
    cout << "Length of LCS: " << lcs(X, Y) << endl;
    return 0;
}
