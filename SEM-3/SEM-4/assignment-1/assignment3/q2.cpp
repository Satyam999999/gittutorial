#include<iostream>
using namespace std;
int main(){
    int n=5;
   int a[5]={4,5,3,6,1};
    int target;
    cin>>target;
    //linear search
    for(int i=0;i<n;i++){
        if(a[i]==target){
            cout<<"Target found :"<<i<<endl;
        }
    }
}