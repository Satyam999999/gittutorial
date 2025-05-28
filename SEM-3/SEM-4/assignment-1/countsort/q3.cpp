#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
     int count[128];
     int m=128;

     for(int i=0;i<m;i++){
        count[i]=0;
     }

   for(int i=0;i<n;i++){
count[s[i]]++; 
   } 

    string bucket[n+1];
    for(int i=0;i<n+1;i++){
        bucket[i]="";
    } 

  for(int i=0;i<128;i++){
    if(count[i]>0){
        bucket[count[i]]+=string(count[i],i);
    }
  }

    string result="";
    for (int i = n; i > 0; --i) {
        if (!bucket[i].empty()) result += bucket[i];
    }
cout<<result<<endl;
}