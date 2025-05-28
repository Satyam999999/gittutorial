#include<iostream>
using namespace std;
int maximum(int days[],int n){
    int maxi=0;
for(int i=0;i<n;i++){
    if(days[i]>maxi) maxi=days[i];
}
return maxi;
}
int main(){
int n;
cin>>n;
int id[n];
int days[n];
for(int i=0;i<n;i++){
   cin>>id[i];
}

for(int i=0;i<n;i++){
   cin>>days[i];
}
int maxi=maximum(days,n);
int count[maxi+1];
for(int i=0;i<=maxi;i++){
    count[i]=0;
}
for(int i=0;i<n;i++){
    count[days[i]]=id[i];
}

for(int i=maxi;i>=0;i--){
if(count[i]) cout<<count[i]<<"-"<<i<<endl;
}
    }