#include<iostream>
using namespace std;
int combination(int coins[],int n,int amount,int index){
    if(amount==0) return 1;
    if(index>=n || amount<0) return 0;
    return combination(coins,n,amount,index+1)+combination(coins,n,amount-coins[index],index);
}
int main(){
    int amount;
    int n;
    cin>>amount;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++) cin>>coins[i];
cout<<combination(coins,n,amount,0)<<endl;
}