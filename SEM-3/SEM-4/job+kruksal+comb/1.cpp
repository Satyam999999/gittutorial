#include<iostream>
using namespace std;
int count(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    int ways=0;
    for(int i=1;i<=6;i++){
     ways+=count(n-i);
    }
    return ways;
}
int main(){
    int n;
    cin>>n;
    cout<<count(n)<<endl;
}