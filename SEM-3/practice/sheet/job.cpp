#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxPoints(const vector<int>& p, const vector<int>& f) {
    int n = p.size();
    vector<int> dp(n + 1, 0); // dp[n] = 0

    for (int i = n - 1; i >= 0; --i) {
        int next = i + f[i] + 1;
        int take = p[i] + (next < n ? dp[next] : 0);
        int skip = dp[i + 1];
        dp[i] = max(take, skip);
    }

    return dp[0];
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n), f(n);
    
    cout << "Enter points (p[i]): ";
    for (int i = 0; i < n; ++i) cin >> p[i];
    
    cout << "Enter frustration skips (f[i]): ";
    for (int i = 0; i < n; ++i) cin >> f[i];

    cout << "Maximum points: " << maxPoints(p, f) << endl;
    return 0;
}
