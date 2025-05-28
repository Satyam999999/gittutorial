// Question 1: Sum of subsequences is odd - Find range [L, R] with K such numbers
#include <iostream>
#include <vector>
using namespace std;

bool hasOddSubseqSum(int n) {
    int sum = 0;
    vector<int> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    int size = digits.size();
    int totalSubseq = 1 << size;
    for (int i = 1; i < totalSubseq; i++) {
        int s = 0;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) s += digits[j];
        }
        sum += s;
    }
    return sum % 2 == 1;
}

void findRange(int K) {
    int count = 0;
    int L = -1, R = -1;
    for (int i = 1; i <= 10000; i++) {
        if (hasOddSubseqSum(i)) {
            if (count == 0) L = i;
            count++;
            if (count == K) {
                R = i;
                break;
            }
        }
    }
    if (L == -1) cout << "-1\n";
    else cout << L << " " << R << "\n";
}

// Question 2: Partition string where each segment < K
const int MOD = 1e9 + 7;
int partitionCount(string s, int K) {
    int n = s.length();
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        long long num = 0;
        for (int j = i - 1; j >= 0; --j) {
            num = (s[j] - '0') + num * 10;
            if (num >= K) break;
            dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }
    return dp[n];
}

// Question 3: JP sequence divisible pairs
void solveJP(int N) {
    vector<long long> jp(31);
    for (int i = 1; i <= 30; i++) jp[i] = (1LL << i) - 1;
    int count = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (jp[j] % jp[i] == 0) count++;
        }
    }
    cout << count << endl;
}

// Driver
int main() {
    // Q1: Range with K numbers having odd sum of subsequences
    int Q1; cin >> Q1;
    while (Q1--) {
        int K; cin >> K;
        findRange(K);
    }

    // Q2: Partition strings
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        string S; cin >> S;
        cout << partitionCount(S, K) << endl;
    }

    // Q3: JP power sequence check
    int T2; cin >> T2;
    while (T2--) {
        int N; cin >> N;
        solveJP(N);
    }
    return 0;
}
