#include<iostream>
using namespace std;
#include<climits>

int main(){
    int n;
    cin>>n;
    int a[n];
    int maxi=INT_MIN;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    int freq[maxi+1];
      for(int i=0;i<n;i++) {
     freq[i]=0;
    }
     for(int i=0;i<n;i++) {
     freq[a[i]]++;
    }
    int k=0;
    int ans[n];
    for(int i=0;i<maxi+1;i++){
if(freq[i]!=0) ans[k++]=i;

    }
   for(int i=0;i<k;i++) {
        cout<<ans[i]<<" ";
    }
}