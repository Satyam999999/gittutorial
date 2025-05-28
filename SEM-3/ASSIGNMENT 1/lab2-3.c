#include<stdio.h>
void transpose(int a[],int m,int n){
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
             a[i][j] = a[j][i];
        }
    }
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            prinf("%d",&a[i][j]);
        }
        printf("\n");
    }
    transpose(a,m,n);
    
}
// int p;
//  p = (int )malloc(5 * sizeof(int));
//   printf("%d",sizeof(p));