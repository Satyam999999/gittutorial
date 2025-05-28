#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;

        int n = 1;
        int ans = 0;
        int temp_k = 0;
        while (k != temp_k)
        {
            if (k >= 5 * n)
            {
                ans = n * 10 - 1;
                temp_k = temp_k + 5 * n;
                n = n * 10;
            }
            else if (k >= n)
            {
                ans = n * 2 - 1;
                temp_k = temp_k + n;
                n = n * 2;
            }
            else
            {
                ans = ans + k - temp_k;
                break;
            }
        }
        cout << 1 << " " << ans << endl;
    }
}
