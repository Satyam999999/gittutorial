#include<iostream>
using namespace std;
//selectionsort
void selectionsort(int a[],int start,int end){
    for(int i=start;i<end-1;i++){
int min=i;
for(int j=i+1;j<end;j++){
    if(a[j]<a[min]){
        min=j;
    }
}
swap(a[i],a[min]);
    }
}
int main(){
    int n;
    cin>>n;
    //nested loop
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    int a[5]={4,5,3,6,1};
selectionsort(a,0,5);
for(int i=0;i<5;i++){
    cout<<a[i]<<" ";
}
}