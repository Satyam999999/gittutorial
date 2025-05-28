#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPoints(vector<int>& p, vector<int>& f) {
    int n = p.size();
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++) {
        dp[i + 1] = max(dp[i], p[i] + (i - f[i] >= 0 ? dp[i - f[i]] : 0));
    }
    return dp[n];
}

int main() {
    vector<int> p = {3, 2, 5, 8, 4};  
    vector<int> f = {0, 1, 0, 2, 1};  

    cout << "Maximum points: " << maxPoints(p, f) << endl;
    return 0;
}
