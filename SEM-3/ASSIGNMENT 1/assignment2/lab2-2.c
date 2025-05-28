#include<stdio.h>
#include<string.h>
void reverse(int *a,int n){
    for(int i=0;i<n/2;i++){
        int temp = *(a+i);
        *(a+i) = *(a+n-1-i);
        *(a+n-1-i) = temp;
}
for(int i=0;i<n;i++){
    printf("%d\t",*(a+i));
}

void swap(int *a,int n,int x,int y){
    int temp=*(a+x);
    *(a+x)=*(a+y);
    *(a+y)=temp;
    for(int i=0;i<n;i++){
    printf("%d\t",*(a+i));
}
}

}
int main(){
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    int a[n];
    int sum=0;
    printf("Enter inetgers in sorted manner\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        }
         int *ptr= &a[0];
    for(int i=0;i<n;i++){
        printf("Value of a[%d] is %d and Address is %d\n",i,a[i],(ptr+i));
    }
    printf("Sum of all elements is %d\n",sum);
    // int number;
    // scanf("%d",&number);
printf("Array after reversing is\n");
    reverse(a,n);
printf("\n");
printf("Enter the index no. to exchange");
int x,y;
scanf("%d%d",&x,&y);
printf("Array after exchange is\n");
swap(a,n,x,y);


    return 0;
    }
   
