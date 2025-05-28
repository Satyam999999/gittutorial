#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1), f(n + 1);  // 1-based indexing
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        cin >> f[i];

    vector<int> dp(n + 2, 0);  // dp[n+1] = 0 base case

    for (int i = n; i >= 1; --i) {
        int next = i + f[i] + 1;
        if (next > n + 1) next = n + 1;
        dp[i] = max(dp[i + 1], p[i] + dp[next]);
    }

    cout << "Maximum score: " << dp[1] << endl;
    return 0;
}
