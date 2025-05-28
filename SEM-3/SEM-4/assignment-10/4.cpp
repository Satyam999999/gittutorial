#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); 

    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) { 
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int func(vector<int>& arr) {
    return LIS(arr); 
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int Length = func(arr);

        cout << (N - Length) << endl;
    }

    return 0;
}