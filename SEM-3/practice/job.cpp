#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> d(n); 
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        maxDeadline = max(maxDeadline, d[i]);
    }

    vector<pair<pair<int, int>, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({{p[i], d[i]}, i});
    }

    sort(jobs.rbegin(), jobs.rend());
    vector<int> seq(maxDeadline + 1, -1);

    int profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].first.second; j > 0; j--) {
            if (seq[j] == -1) {
                seq[j] = jobs[i].second;
                profit += jobs[i].first.first;
                break;
            }
        }
    }

    cout << "Sequence: ";
    for (int i = 1; i < seq.size(); i++) {
        if (seq[i] != -1) {
            cout << "J" << seq[i] + 1 << " ";
        }
    }
    cout << endl;
    cout << "Profit: " << profit << endl;

    return 0;
}
