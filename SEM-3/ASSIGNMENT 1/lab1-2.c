#include<stdio.h>
#include<math.h>
int main(){
    int n;
    int sum=0;
    scanf("%d",&n);
    int m=n;
    while (n>0)
    {
int digit=n%10;
sum+=pow(digit,3);
n=n/10;
    }
    if(sum==m)
  {
printf("YES\n");
  }   
  else{
    printf("NO\n");
  }
}