#include<iostream>
#include<vector>
using namespace std;
int maxprofit(int w[], int v[], int p[], int n, int max_weight, int max_volume) {


    vector<vector<int>>dp(max_weight+1,vector<int>(max_volume+1,0));
    for(int i=0;i<n;i++){
        for(int j=w[i];j<=max_weight;j++){
            for(int k=v[i];k<=max_volume;k++){
dp[j][k]=max(dp[j][k],dp[j-w[i]][k-v[i]]+p[i]);
            }
        }
    }
    return dp[max_weight][max_volume];
}
int main(){
    int n;
    cin>>n;
    int w[n],p[n],v[n];
for(int i=0;i<n;i++){
cin>>w[i]>>v[i]>>p[i];
} 
    int max_weight, max_volume;
    cin >> max_weight >> max_volume;
cout<<maxprofit(w, v, p, n, max_weight, max_volume);

}