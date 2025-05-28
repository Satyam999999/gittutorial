
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int Distinct(vector<int>& arr, int K) {
    unordered_map<int, int> freq;
    int distinct = 0, mini = INT_MAX;
    int left = 0;

    for (int right = 0; right < arr.size(); ++right) {
        if (freq[arr[right]] == 0) {
            distinct++;
        }
        freq[arr[right]]++;

        while (distinct == K) {
            mini = min(mini, right - left + 1);
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) {
                distinct--;
            }
            left++;
        }
    }

    return mini;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int result = Distinct(arr, K);
        cout << result << endl;
    }

    return 0;
}

