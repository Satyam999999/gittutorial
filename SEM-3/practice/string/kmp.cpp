#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to build the LPS (Longest Prefix Suffix) array
void computeLPS(string pattern, vector<int>& lps) {
    int m = pattern.size();
    lps[0] = 0; // lps[0] is always 0
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // try previous LPS
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP pattern searching function
void KMP(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m);
    computeLPS(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // Look for next possible match
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text = "abxabcabcaby";
    string pattern = "abcaby";
    KMP(text, pattern);
    return 0;
}
