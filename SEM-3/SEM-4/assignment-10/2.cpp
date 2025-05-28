#include <iostream>
#include <vector>
using namespace std;
vector<int> dp(100,-1);
int maxi(int n){
    if(dp[n]!=-1) return dp[n];
if(n==0) return 0;
int ans=maxi(n/2)+maxi(n/3)+maxi(n/4);
return dp[n]=max(n,ans);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<maxi(n)<<endl;
    }

}