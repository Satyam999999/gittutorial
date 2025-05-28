#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0;
    for (int i = 1; i < m;) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

void KMP(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  // continue for overlapping matches
        } 
        else if (i < n && text[i] != pattern[j]) {
            j = (j == 0) ? 0 : lps[j - 1];
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMP(text, pattern);
    return 0;
}
