#include <iostream>
using namespace std;

const int d = 256;         // number of characters in the input alphabet
const int q = 101;         // a prime number to mod the hash (to avoid collisions)

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for text window
    int h = 1;

    // The value of h would be "pow(d, m-1) % q"
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++) {
        // Check the hash values
        if (p == t) {
            // If the hash values match, check characters one by one
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

        // Calculate hash for next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    rabinKarp(text, pattern);
    return 0;
}
