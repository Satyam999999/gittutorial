#include <iostream>
using namespace std;

bool isShuffle(string X, string Y, string Z) {
    int i = 0, j = 0, k = 0;
    int n = X.size(), m = Y.size(), z = Z.size();

    if (z != n + m) return false;

    while (k < z) {
        if (i < n && Z[k] == X[i]) {
            i++;
        } else if (j < m && Z[k] == Y[j]) {
            j++;
        } else {
            return false;
        }
        k++;
    }

    return (i == n && j == m);
}

int main() {
    string X = "abc", Y = "def", Z = "dabecf";
    if (isShuffle(X, Y, Z))
        cout << "Valid Shuffle\n";
    else
        cout << "Invalid Shuffle\n";

    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;

// bool isShuffle(string X, string Y, string Z) {
//     int n = X.size(), m = Y.size();
//     if (Z.size() != n + m) return false;

//     vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//     dp[0][0] = true;

//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= m; j++) {
//             if (i > 0 && X[i - 1] == Z[i + j - 1])
//                 dp[i][j] = dp[i][j] || dp[i - 1][j];
//             if (j > 0 && Y[j - 1] == Z[i + j - 1])
//                 dp[i][j] = dp[i][j] || dp[i][j - 1];
//         }
//     }

//     return dp[n][m];
// }

// int main() {
//     string X = "abc", Y = "def", Z = "dabecf";
//     if (isShuffle(X, Y, Z))
//         cout << "Valid Shuffle\n";
//     else
//         cout << "Invalid Shuffle\n";
//     return 0;
// }
