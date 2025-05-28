#include<iostream>
using namespace std;
int kthelement(int a[],int b[],int k,int n){
    int i=0,j=0;
    while(k>0 && i<n && j<n){
        k--;
        if(a[i]<b[j]) {
        if(k==0) return a[i];
        i++;
        }
        else {
            if(k==0) return b[j];
            j++;
        }

    }
    while(j<n and k){
        k--;
        if(k==0) return b[j];
            j++; 
    }
      while(i<n){
        k--;
        if(k==0) return a[i];
            i++; 
    }
    return 0;
}
int main(){
    int a[5]={1,2,3,4,5};
    int b[5]={3,5,7,9,11};
    int k;
    cin>>k;
    int n=5;
    int ans=kthelement(a,b,k,n);
    cout<<ans;
}
