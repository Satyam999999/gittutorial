/* Bhavik Agarwal (bhavik_2001) */
#include <bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 256

int getNextState(string pattern, int M, int state, int x){

	if (state < M && x == pattern[state]){
		return state+1;
    }

    int ns,i;
	for (ns = state; ns > 0; ns--){
		if(pattern[ns-1] == x){
			for (i = 0; i < ns-1; i++){
				if (pattern[i] != pattern[state-ns+1+i]){
					break;
                }
            }
			if (i == ns-1){
				return ns;
            }
		}
	}

	return 0;
}

void computeTF(string pattern, int M, int TF[][NO_OF_CHARS]){
	for (int state = 0; state <= M; ++state){
		for (int x = 0; x < NO_OF_CHARS; ++x){
			TF[state][x] = getNextState(pattern, M, state, x);
        }
    }
}

void search(string pattern, string text){
	int m = pattern.size();
	int n = text.size();

	int TF[m+1][NO_OF_CHARS];

	computeTF(pattern, m, TF);

    // for(int i = 0;i<=m;i++){
    //     for(int j = 0;j<256;j++){
    //         cout << TF[i][j] << " ";
    //     }
    //     cout << endl;
    // }

	int i, state=0;
	for (i = 0; i < n; i++){
		state = TF[state][text[i]];
		if (state == m){
			cout<< "Pattern found at index " << i-m+1 <<endl;
        }
	}
}

int main() {
	string text = "aaababaabaababaab";
	string pattern = "aabab";

	search(pattern, text);

	return 0;
}
