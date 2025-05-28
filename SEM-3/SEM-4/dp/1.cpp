#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
#include <climits>

using namespace std;

int countOnes(const string &s) {
    return count(s.begin(), s.end(), '1');
}

vector<string> generateBinaryCodes(int n, int l) {
    vector<string> codes;
    for (int i = 0; i < (1 << l); i++) { 
        string binary = bitset<16>(i).to_string();
        codes.push_back(binary.substr(16 - l));
    }
    sort(codes.begin(), codes.end(), [](string &a, string &b) {
        return countOnes(a) < countOnes(b);
    });
    return codes;
}

int minOnesDP(vector<int> &freq, int l) {
    int n = freq.size();
    vector<string> codes = generateBinaryCodes(n, l);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    dp[0][0] = 0; 

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) { 
            int ones = countOnes(codes[j - 1]) * freq[i - 1]; 
            if (dp[i - 1][j - 1] != INT_MAX)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + ones);
        }
    }

    int result = INT_MAX;
    for (int j = n; j >= 1; j--) result = min(result, dp[n][j]);

    return result;
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n, l;
        cin >> n >> l; 
        string s;
        cin >> s;

        map<char, int> freq;
        for (char c : s) freq[c]++;

        vector<int> freqVec;
        for (auto &p : freq) freqVec.push_back(p.second);
        sort(freqVec.rbegin(), freqVec.rend()); 

        cout << minOnesDP(freqVec, l) << endl; 
    }

    return 0;
}
