#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCoins(vector<int>& coins, int M) {
    vector<int> dp(M + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= M; i++) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return dp[M] == INT_MAX ? -1 : dp[M];
}

int main() {
    vector<int> coins = {9, 6, 5, 1};
    
    cout << "Minimum coins for M = 11: " << minCoins(coins, 11) << endl;
    cout << "Minimum coins for M = 7: " << minCoins(coins, 7) << endl;

    return 0;
}
