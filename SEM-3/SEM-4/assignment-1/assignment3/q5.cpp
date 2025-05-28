#include<iostream>
using namespace std;
void Algo1(int a[],int start,int end){
    for(int i=start;i<end-1;i++){
int min=i;
for(int j=i+1;j<end;j++){
    //flag=false
    if(a[j]<a[min]){
        min=j;
       // flag=true;
    }
    
}
swap(a[i],a[min]);
    }
}

void Algo2(int a[],int start,int end){
    for(int i=start;i<end-1;i++){
int max=i;
for(int j=i+1;j<end;j++){
    if(a[j]>a[max]){
        max=j;
    }
}
swap(a[i],a[max]);
    }
}
int main(){
int a[5]={4,5,3,6,1};
Algo1(a,0,5);
for(int i=0;i<5;i++){
    cout<<a[i]<<" ";
}
cout<<endl;
int b[5]={8,10,6,12,2};
Algo2(b,0,5);
for(int i=0;i<5;i++){
    cout<<b[i]<<" ";
}
}