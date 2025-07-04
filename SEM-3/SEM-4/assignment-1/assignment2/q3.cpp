#include<iostream>
using namespace std;
int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<=high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
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
void iterativequicksort(int a[],int low,int high){
    stack<int> stack;
    stack.push(low);
    stack.push(high);
    while(!stack.empty()){
         high=stack.top();
        stack.pop();
         low=stack.top();
        stack.pop();
        int pi=partition(a,low,high);
        if(pi-1>low){
            stack.push(low);
            stack.push(pi-1);
        }
        if(pi+1<high){
            stack.push(pi+1);
            stack.push(high);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    cout<<"Recursive:"<<endl;
      for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
    int b[n];
     for(int i=0;i<n;i++){
        cin>>b[i];
    }

     iterativequicksort(b,0,n-1);
     cout<<"Iterative"<<endl;
      for(int i=0;i<n;i++){
        cout<<b[i];
    }
}