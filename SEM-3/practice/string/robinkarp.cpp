#include <bits/stdc++.h>
using namespace std;

#define d 256  // number of characters in the input alphabet

void rabinKarp(string text, string pattern, int q) {
    int n = text.size();
    int m = pattern.size();

    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    int p = 0; // hash value for pattern
    int t = 0; // hash value for text window

    // Initial hash calculation for pattern and first window
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide pattern over text
    for (int i = 0; i <= n - m; i++) {
        // If hash values match, check characters one by one
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "aaababaabaababaab";
    string pattern = "aabab";

    int q = 101;  // A prime number for modulo

    rabinKarp(text, pattern, q);

    return 0;
}
