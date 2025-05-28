#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to build the prefix-suffix (LPS) array for the pattern
void buildLPSArray(const string& pattern, vector<int>& lps) {
    int m = pattern.size();
    int length = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;  // LPS[0] is always 0
    int i = 1;

    // Loop to fill the LPS array
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];  // fall back to the previous possible prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform the KMP pattern matching
void KMPSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // Preprocess the pattern to create the LPS array
    vector<int> lps(m, 0);
    buildLPSArray(pattern, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern

    // Loop to scan through the text and pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        // If we find a complete match of the pattern
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  // Use the LPS array to avoid unnecessary re-checking
        }

        // Mismatch after j matches
        else if (i < n && pattern[j] != text[i]) {
            // We don't need to start from the beginning of the pattern
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

///////////////////////////////////////////////////////////////
// MAIN FUNCTION
///////////////////////////////////////////////////////////////

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    KMPSearch(text, pattern);

    return 0;
}
