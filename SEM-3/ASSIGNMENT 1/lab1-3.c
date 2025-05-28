#include <stdio.h>
int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int a[m][n];
    //option 1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
      
      //optin 2
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(j == (m-1 )|| j== 0){
                printf("%d\n",&a[j][i]);
            }
        }
       }

// option 3



//option 4
int k;
printf("ENTER k");
scanf("%d",&k);
int ans[10];
int z=0;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
if(i==j){
    ans[z++]=a[i][j];
}
}
}
for(int i=0;i<z-1;i++){
    if(ans[i]>ans[i+1]){
        int temp=ans[i];
        ans[i]=ans[i+1];
        ans[i+1]=temp;
    }
}
printf("kthsmallest number : %d\n",ans[k-1]);


//option 5
 int *ptr = &a[0][0];  
    printf("Elements of the array using base address:\n");

    for (int i = 0; i < m * n; i++) {
        printf("%d\t ", *(ptr+i));  
    }

    printf("\n");

    return 0;
}