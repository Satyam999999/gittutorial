#include<iostream>
using namespace std;
void merge(int a[],int l,int m,int h){
int n1=m-l+1;
int n2=h-m;
int x[n1];
int y[n2];
for(int i=0;i<n1;i++) x[i]=a[l+i];
for(int i=0;i<n2;i++) y[i]=a[m+1+i];
int b=0;
int c=0;
int k=l;
while(b<n1 && c<n2){
    if(x[b]<=y[c]) a[k++]=x[b++];
    else a[k++]=y[c++];
}
while(b<n1) a[k++]=x[b++];
while(c<n2) a[k++]=y[c++];




}
void mergesort(int a[],int l,int h){
    if(l<h){
int m=l+(h-l)/2;
mergesort(a,l,m);
mergesort(a,m+1,h);
merge(a,l,m,h);
    }

}

void multiply(int a[],int l,int h){
    if(l<h){
int m=l+(h-l)/2;
for(int i=l;i<=h;i++) a[i]*=2;
multiply(a,l,m);    
multiply(a,m+1,h);
}
}
int main(){
int a[5]={4,5,3,6,1};
multiply(a,0,5);
for(int i=0;i<5;i++){
    cout<<a[i]<<" ";
}
}