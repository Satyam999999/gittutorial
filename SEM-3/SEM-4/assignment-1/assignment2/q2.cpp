#include<iostream>
using namespace std;
int recursivefactorial(int n){
    if((n==0) || (n==1)) return 1;
    return n* recursivefactorial(n-1);
}
int iterativefactorial(int n){
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
    }
    return ans;
}
int main(){
int n;
cin>>n;
int recursiveans=recursivefactorial(n);
int iterativeans=iterativefactorial(n);

cout<<"Recursive: "<<recursiveans<<endl;
cout<<"Iterative: "<<iterativeans<<endl;
}