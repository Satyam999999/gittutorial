#include<iostream>
using namespace std;
int partition(int a[],int low,int high){
    int pivot=high;
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<a[pivot]){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
void quicksort(int a[],int low,int high){
    if(low<high){
        int pi=partition(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements"<<endl;
for(int i=0;i<n;i++){
    a[i]=rand()%10+1;
}
for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
}
cout<<endl;
quicksort(a,0,n-1);
cout<<"AFTER SORTING"<<endl;
for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
}


}