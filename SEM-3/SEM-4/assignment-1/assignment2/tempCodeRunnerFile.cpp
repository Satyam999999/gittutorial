#include<iostream>
#include<ctime>
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
    int recursivebinary(int a[],int low,int high,int target){
        if(low>high) return -1;
        int mid=low+(high-low)/2;
        if(a[mid]==target) return mid;
        if(a[mid]>target) return recursivebinary(a,low,mid-1,target);
        else return recursivebinary(a,mid+1,high,target);
    }
int iterativebinary(int a[],int n,int target){
    int low=0;
    int high=n-1;
    while(high>=low){
        int mid=low+(high-low)/2;
         if(a[mid]==target) return mid;
          if(a[mid]>target) high=mid-1;
          else low=mid+1;
    }
    return -1;
}
int main(){
    int n;
    n=100000;
    int a[n];
    for(int i=0;i<n;i++){
       
        a[i]=rand()%100+1;
    }
quicksort(a,0,n-1);
    int target;
    cin>>target;
    int start1=clock();
    int recursiveans=recursivebinary(a,0,n-1,target);
    int end1=clock();
    cout<<recursiveans<<" "<<end1-start1<<endl;
    int start2=clock();
    int iterativeans=iterativebinary(a,n,target);
    int end2=clock();
    cout<<iterativeans<<" "<<end2-start2<<endl;
}