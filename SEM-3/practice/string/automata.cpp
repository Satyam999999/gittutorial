#include <bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 256

// Function to get the next state from current state and input character
int getNextState(string pattern, int M, int state, int x) {
    if (state < M && x == pattern[state])
        return state + 1;

    for (int ns = state; ns > 0; ns--) {
        if (pattern[ns - 1] == x) {
            bool flag = true;
            for (int i = 0; i < ns - 1; i++) {
                if (pattern[i] != pattern[state - ns + 1 + i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return ns;
        }
    }
    return 0;
}

// Build the transition function
void computeTF(string pattern, int M, vector<vector<int>> &TF) {
    for (int state = 0; state <= M; ++state) {
        for (int x = 0; x < NO_OF_CHARS; ++x) {
            TF[state][x] = getNextState(pattern, M, state, x);
        }
    }
}

// Pattern search using Finite State Automaton
void search(string pattern, string text) {
    int M = pattern.size();
    int N = text.size();

    // Transition table
    vector<vector<int>> TF(M + 1, vector<int>(NO_OF_CHARS));

    computeTF(pattern, M, TF);

    int state = 0;

    for (int i = 0; i < N; i++) {
        state = TF[state][text[i]];
        if (state == M) {
            cout << "Pattern found at index " << (i - M + 1) << endl;
        }
    }
}

int main() {
    string text = "aaababaabaababaab";
    string pattern = "aabab";

    search(pattern, text);

    return 0;
}
//o((search)n+(preprocessing)m*256) and o(m*256)