#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int count = (n / i) - 1;
            if (count > 0)
                ans += count;
        }
        cout << ans << endl;
    }
    return 0;
}
