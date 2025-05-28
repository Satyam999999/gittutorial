#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int matrix[10][10];
void addedge(int a,int b){
matrix[a][b]=1;
matrix[b][a]=1;
}

void dfs(int *visited,int n,int start){
    *(visited+start)=1;
    printf("%d ",start);
    for(int i=1;i<=n;i++){
        if(matrix[start][i]==1 && *(visited+i)==0){
            dfs(&visited,n,i);
        }
    }
}
int main(){
int n=6;
addedge(1,2);
addedge(3,4);
addedge(5,6);
int visited[n];
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
matrix[i][j]=0;
}
for(int i=1;i<=n;i++){
    visited[i]=0;
}
}
int count=0;
for(int i=1;i<=n;i++){
if(visited[i]==0){
    count++;
}
dfs(&visited,n,i);
}
printf("\nTotal groups:%d\n",count);
}
