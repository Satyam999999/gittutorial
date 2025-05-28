#include<iostream>
using namespace std;
double maxbooks(int bookprice[],int pages[],int n,int x){
double ratio[4];
double page=0;
for(int i=0;i<n;i++){
    ratio[i]=double(pages[i])/double(bookprice[i]);
}
double maxi;
int index;
while(x>0){
    index=-1;
maxi=0;
    for(int i=0;i<n;i++){
if(ratio[i]>maxi){
    maxi=ratio[i];
    index=i;
}
}
if(bookprice[index]<=x){
    x-=bookprice[index];
page+=pages[index];
}
else{
    page+=x*ratio[index];
x=0;
   }
ratio[index]=0;

}
return page;
}
int main(){
    int n=4;
    int bookprice[4]={4,8,5,3};
    int pages[4]={5,12,8,1};
    int x=10;
    cout<<maxbooks(bookprice,pages,n,x);
}