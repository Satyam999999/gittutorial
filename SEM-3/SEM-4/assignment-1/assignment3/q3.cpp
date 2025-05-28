#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
  for(int i=0;i<n;i++){
       
        for(float j=1;j<n;j*=(3.0/2.0)){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

