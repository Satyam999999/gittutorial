#include<iostream>
using namespace std;
int partition(int a[],int l,int h){
int pivot=a[h];
int j=l-1;
for(int i=l;i<h;i++){
    if(a[i]<pivot){
        j++;
        swap(a[i],a[j]);
    }

}
swap(a[j+1],a[h]);
return j+1;
}
void quicksort(int a[],int l,int h){
    if(l<h){
    int pi=partition(a,l,h);
    quicksort(a,l,pi-1);
    quicksort(a,pi+1,h);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Before Sorting"<<endl;
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
        quicksort(a,0,n-1);
          cout<<"After Sorting"<<endl;
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
        

}