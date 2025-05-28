
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int findMinSubarrayWithKDistinct(vector<int>& arr, int K) {
    unordered_map<int, int> freq;
    int distinct = 0, minLen = INT_MAX;
    int left = 0;

    for (int right = 0; right < arr.size(); ++right) {
        if (freq[arr[right]] == 0) {
            distinct++;
        }
        freq[arr[right]]++;

        while (distinct == K) {
            minLen = min(minLen, right - left + 1);
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) {
                distinct--;
            }
            left++;
        }
    }

    return minLen;
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

        int result = findMinSubarrayWithKDistinct(arr, K);
        cout << result << endl;
    }

    return 0;
}



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int longestDecreasingSubsequence(vector<int>& A) {
//     vector<int> dp;
//     for (int num : A) {
//         // Use lower_bound on reversed logic (greater instead of less)
//         auto it = lower_bound(dp.begin(), dp.end(), -num);
//         if (it == dp.end()) {
//             dp.push_back(-num);
//         } else {
//             *it = -num;
//         }
//     }
//     return dp.size();
// }

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         int N;
//         cin >> N;
//         vector<int> A(N);
//         for (int i = 0; i < N; i++) {
//             cin >> A[i];
//         }

//         int result = longestDecreasingSubsequence(A);
//         cout << result << endl;
//     }

//     return 0;
// }