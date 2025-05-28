#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int NUM = 1000000007;
    while (t--)
    {
        int n;
        int k;
        cin >> n >> k;
        string s;
        cin >> s;
        int dp[n+1] = {0};
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == 0)
                continue;
            int num = 0;
            for (int j = i; j < n; j++)
            {
                num = num * 10 + (s[j] - '0');
                if (num >= k)
                    break;
                dp[j + 1] = (dp[j + 1] + dp[i]) % NUM;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}
