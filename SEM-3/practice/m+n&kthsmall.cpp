#include<iostream>
using namespace std;
int ksmallest(int a[], int n, int b[], int m, int k) {
    int i = 0, j = 0, l = 0;
    
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            l++;
            if (l == k) return a[i];
            i++;
        } else {
            l++;
            if (l == k) return b[j];
            j++;
        }
    }

    while (i < n) {
        l++;
        if (l == k) return a[i];
        i++;
    }

    while (j < m) {
        l++;
        if (l == k) return b[j];
        j++;
    }

    return -1; 
}

int main(){
    int a[4]={1,4,6,8};
    int b[5]={3,4,5,6};
    int n=4;
    int m=5;
    int k;
    cin>>k;
    int kthelement=ksmallest(a,n,b,m,k);
    cout<<kthelement;
}