#include<stdio.h>
#include<string.h>
int main(){
    char a[50];
    char b[50];
    printf("ENTER TWO STRINGS\n");
scanf("%s",a);
scanf("%s",b);
int len1=strlen(a);
int len2=strlen(b);
char *ptr1 = &a[0];
char *ptr2 = &b[0];
printf("length of string 1 is %d and length of string 2 is %d\n",len1,len2);
if(len1!=len2){
printf("THEY ARE NOT IDENTICAL\n");
}

   else {
    int k=1;
    for(int i=0;i<=len1;i++){
if(*(ptr1+i) != *(ptr2+i)){
    k=0;
    break;
}
    }
    if(k==1){
        printf("THEY ARE IDENTICAL\n");

    }
    else{
        printf("THEY ARE NOT IDENTICAL\n");
    }
}
    return 0;
}