#include<stdio.h>
#define MAX 100
int heap[MAX];
int size=0;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
// void insert(int data){
//     size++;
//     heap[size]=data;
//     int i=size;
//     while(i>1&&heap[i]>heap[i/2]){
//         swap(&heap[i],&heap[i/2]);
//         i=i/2;
//     }
// }
void heapify(int a[],int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=size&&a[left]>a[largest]){
        largest=left;
    }
    if(right<=size&&a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&a[largest],&a[i]);
        heapify(a,largest);
    }
}
void maxheap(int a[],int n){
    for(int i=n/2;i>=1;i--){
        heapify(a,i);
    }
}
// void heapsort(){
//     // for(int i=size/2;i>=1;i--){
//     //     heapify(i);
//     // }
//     int og_size=size;
//     for(int i=size;i>=2;i--){
//         swap(&heap[i],&heap[1]);
//         size--;
//         heapify(1);
//     }
// for(int i=1;i<=og_size;i++){
//     printf("%d\t",heap[i]);
// }
// printf("\n");
// }
// int deletemax(){
//     int max=heap[1];
//     heap[1]=heap[size];
//     size--;
//     heapify(1);
//     return max;
// }
// int id(){
//     return 1;
// }
// void increase(int id){
// printf("Enter the increased no of resources:");
// int a;
// scanf("%d",&a);
// swap(&a,&heap[id]);
// }
void printheap(int a[],int n){
for(int i=1;i<=n;i++){
printf("%d\t",a[i]);
}
printf("\n");
}
int main(){
    int n;
    int a[n];
    int b[n];
    printf("Enter no of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;
        scanf("%d%d",&a[i],&b[i]);
        }
maxheap(a,n);
printheap(a,n);
// printheap();
// //a
// printf("Process id with maximum resources:%d\n",id());
// //b
// printf("Enter the process id you want to increase: ");
// int id;
// scanf("%d",&id);
// increase(id);
// printheap();
// //c
// deletemax();
// printf("After removing the process having maximum resources:\n");
// printheap();
// //d
// printf("Enter required number of resources you want to insert:");
// int data;
// scanf("%d",&data);
// insert(data);
// printheap();
// //e
// printf("Sorted Array:\n")
// heapsort();

}