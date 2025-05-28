/* Bhavik Agarwal (bhavik_2001) */
#include<bits/stdc++.h>
using namespace std;

int helper(int ind, int n, vector<int> &p, vector<int> &f, vector<int> &dp){
    if(ind >= n){
        return 0;
    }

    if(dp[ind] != -1) return dp[ind];

    return dp[ind] = max(p[ind] + helper(ind+f[ind]+1,n,p,f,dp),helper(ind+1,n,p,f,dp));
}

int main(){
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 0;i<n;i++){
        cin >> p[i];
    }

    vector<int> f(n);
    for(int i = 0;i<n;i++){
        cin >> f[i];
    }

    vector<int> dp(n,-1);

    // Time Complexity : O(n)
    // Space Complexity : O(n)
    cout << helper(0,n,p,f,dp) << endl;

}