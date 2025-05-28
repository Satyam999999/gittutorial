#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp( pair<int, int> &a, pair<int, int> &b){
return a.second < b.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> start(n);
        vector<int> duration(n);
        vector<int> end(n);
        for (int i = 0; i < n; i++)
        {
            cin >> start[i] >> duration[i];
            end[i] = start[i] + duration[i];
        }
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
        {
a[i] = make_pair(start[i], end[i]);
        }
        sort(a.begin(), a.end(),cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        int cnt = 1;
        pq.push(a[0].second);
        for (int i = 1; i < n; i++)
        {
            if (a[i].first >= pq.top())
            {
                pq.pop();
                cnt++;
            }
            pq.push(a[i].second);
        }
        cout << cnt << endl;
    }
}