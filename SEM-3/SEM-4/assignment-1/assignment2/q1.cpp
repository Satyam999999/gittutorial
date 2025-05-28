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
       
        a[i]=rand()%100;
    }
quicksort(a,0,n-1);
    int target;
    cin>>target;
    int start1=clock();
    int recursiveans=recursivebinary(a,0,n-1,target);
    int end1=clock();
    cout<<"Recursive"<<endl;
    cout<<"Position is :"<<recursiveans<<" "<<"Time: "<<double(end1-start1)<<endl;
    int start2=clock();
    int iterativeans=iterativebinary(a,n,target);
    int end2=clock();
cout<<"Iterative"<<endl;
    cout<<"Position is:"<<iterativeans<<" "<<"Time: "<<double(end2-start2)<<endl;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // Partition function for QuickSort
// int partition(vector<pair<float, int>>& ratioIndex, int low, int high) {
//     float pivot = ratioIndex[high].first; // Choosing last element as pivot
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         if (ratioIndex[j].first > pivot) { // Sorting in descending order
//             i++;
//             swap(ratioIndex[i], ratioIndex[j]);
//         }
//     }
//     swap(ratioIndex[i + 1], ratioIndex[high]);
//     return i + 1;
// }

// // QuickSort function
// void quickSort(vector<pair<float, int>>& ratioIndex, int low, int high) {
//     if (low < high) {
//         int pi = partition(ratioIndex, low, high);

//         quickSort(ratioIndex, low, pi - 1);
//         quickSort(ratioIndex, pi + 1, high);
//     }
// }

// // Function to solve fractional knapsack
// float knapsack(vector<pair<int, int>>& items, int capacity) {
//     int n = items.size();
//     vector<pair<float, int>> ratioIndex;

//     // Calculate value/weight ratio and store with index
//     for (int i = 0; i < n; i++) {
//         float ratio = (float)items[i].first / items[i].second;
//         ratioIndex.push_back({ratio, i});
//     }

//     // Sort using QuickSort based on ratio
//     quickSort(ratioIndex, 0, n - 1);

//     float totalValue = 0.0;

//     // Process items in sorted order
//     for (auto& ri : ratioIndex) {
//         int idx = ri.second;
//         int value = items[idx].first;
//         int weight = items[idx].second;

//         if (capacity >= weight) { // If we can take full item
//             capacity -= weight;
//             totalValue += value;
//         } else { // Take fraction of item
//             totalValue += value * ((float)capacity / weight);
//             break; // Knapsack is full
//         }
//     }

//     return totalValue;
// }

// int main() {
//     vector<pair<int, int>> items = {{60, 10}, {100, 20}, {120, 30}};
//     int capacity = 50;

//     float maxValue = knapsack(items, capacity);
//     cout << "Maximum Value in Knapsack: " << maxValue << endl;

//     return 0;
// }
