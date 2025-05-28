#include <bits/stdc++.h>
using namespace std;

#define d 256 // number of characters in input alphabet

void rabinKarp(string text, string pattern, int q) {
    int n = text.size();
    int m = pattern.size();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text window
    int h = 1;

    // The value of h would be "pow(d, m-1) % q"
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
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

            // We might get negative value of t
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    int q = 101; // A prime number
    rabinKarp(text, pattern, q);
    return 0;
}
