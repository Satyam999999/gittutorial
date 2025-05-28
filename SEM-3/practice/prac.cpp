// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// // Check if a number ends with an odd digit
// bool isValid(int num) {
//     return (num % 10) % 2 == 1;
// }

// pair<int, int> findRange(int K) {
//     vector<int> indices;
//     int count = 0;
//     int left = 1, right = 1;
//     int bestL = -1, bestR = -1, minLen = INT_MAX;

//     while (right <= 100000) {
//         if (isValid(right)) count++;

//         while (count >= K) {
//             if (count == K && (right - left + 1) < minLen) {
//                 minLen = right - left + 1;
//                 bestL = left;
//                 bestR = right;
//             }
//             if (isValid(left)) count--;
//             left++;
//         }
//         right++;
//     }

//     if (bestL == -1) return {-1, -1};
//     return {bestL, bestR};
// }

// int main() {
//     int Q;
//     cin >> Q;
//     while (Q--) {
//         int K;
//         cin >> K;
//         pair<int, int> res = findRange(K);
//         if (res.first == -1) cout << "-1\n";
//         else cout << res.first << " " << res.second << "\n";
//     }
//     return 0;
// }
// #include <iostream>
// #include <vector>
// using namespace std;

// const int MOD = 1e9 + 7;

// int countWays(string &s, int k) {
//     int n = s.length();
//     vector<int> dp(n + 1, 0);
//     dp[0] = 1; // Empty string has 1 way to split

//     for (int i = 1; i <= n; ++i) {
//         long long num = 0;
//         for (int j = i - 1; j >= 0; --j) {
//             if (s[j] == '0') continue; // Skip leading zeros
//             num = 0;
//             for (int t = j; t < i; ++t)
//                 num = num * 10 + (s[t] - '0');

//             if (num >= k) break;
//             dp[i] = (dp[i] + dp[j]) % MOD;
//         }
//     }
//     return dp[n];
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         int N, K;
//         cin >> N >> K;
//         string S;
//         cin >> S;
//         cout << countWays(S, K) << "\n";
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

int countValidPairs(int N) {
    vector<long long> val(N + 1);
    for (int i = 1; i <= N; ++i) {
        val[i] = (1LL << i) - 1; // 2^i - 1
    }

    int count = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (val[j] % val[i] == 0)
                count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << countValidPairs(N) << "\n";
    }
    return 0;
}
