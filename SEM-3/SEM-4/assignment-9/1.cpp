#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int m = s.size(), n = t.size();
    int j = 0; 

    for (int i = 0; i < m && j < n; i++) {
        if (s[i] == t[j]) {
            j++;
    
    }
    }
    return j == n; 
}

int main() {
    string s, t;
    cin >> s >> t;

    int q, k;
    cin >> q >> k;

    while (q--) {
        int i, j;
        cin >> i >> j;

        string modifiedS = s.substr(0, i - 1) + s.substr(j);

        if (isSubsequence(modifiedS, t)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}