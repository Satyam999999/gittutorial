#include <iostream>
#include <vector>
using namespace std;

int maxSize(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) { 
                dp[i] = max(dp[i], dp[j] + 1); 
            }
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp[i]);
    }

    return maxi;
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

        int result = maxSize(arr);
        cout << result << endl;
    }

    return 0;
}