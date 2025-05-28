#include<iostream>
using namespace std;
int max(int a[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
int main(){
      int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements"<<endl;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    cout<<a[i];
}
int maxi=max(a,n);
int freq[maxi];
for(int i=0;i<maxi;i++){
    freq[i]=0;
}
for(int i=0;i<n;i++){
    freq[a[i]]++;
}
int b[100];
int k=0;
for(int i=1;i<=maxi;i++){
if(freq[a[i]]!=0){
    b[k++]=a[i];
    freq[a[i]]=0;
}
}
for(int i=0;i<k;i++){
    cout<<b[i]<<endl;
}

}