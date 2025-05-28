#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int N;
    printf("Enter number of fans\n");
    scanf("%d",&N);
    char name[N];
    int quotient[N];
    printf("maximum number of fans Karishma can meet");
    int T;
    scanf("%d",&T);
    for(int i=0;i<N;i++){
        scanf("%s%d",&name[i],&quotient[i]);
    }
   
for(int i=0;i<N;i++){
    for(int j=0;j<N-1;j++){
        if(quotient[j]>quotient[j+1]){
            int temp=quotient[j];
            quotient[j]=quotient[j+1];
            quotient[j+1]=temp;
             char temp1=name[j];
           name[j]=name[j+1];
            name[j+1]=temp1;
        }
        else if(quotient[j]==quotient[j+1]){
         if(name[j]>name[j+1]){
            int temp=quotient[j];
            quotient[j]=quotient[j+1];
            quotient[j+1]=temp;
             char temp1 =name[j];
           name[j]=name[j+1];
           name[j+1]= temp1;
         }
        }
    }
}

for(int i=0;i<N;i++){
    printf("%d",quotient[i]);
    printf("%c\n",name[i]);
}
int k=N-1;
for(int i=0;i<T;i++){
    printf("%s\n",&name[k]);
    k--;
}

}