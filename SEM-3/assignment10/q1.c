#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
struct student{
    char name[20];
    int id;
    float marks;
    };
 int table[size]={0};

int hash(int key){
    return key%size;
}
int insert(char name[],int key,float value){
    for(int i=0;i<size;i++){
        if(table[i]==key){
            printf("Duplicate Element is not allowed\n");
            return 0;
        }
    }
    int index=hash(key);
    while(table[index]!=0){
        index=(index+1)%size;
    }
    table[index]=key;
    return 0;
}
int search(int key){
    int index=hash(key);
    while((table[index]) != key && index<9){
        index=(index+1)%size;
    }
    if(table[index]==key){
return index;
    }
    else{
    return -1;
    }

    
}
void delete(int key){
    int index=hash(key);
    while(table[index] != key ){
        index=(index+1)%size;
    }
    table[index]=0;
}
void print(){
    for(int i=0;i<size;i++){
        printf("Key->%d\n",(table[i]));
    }
}
int main(){
int id;
float marks;
char name[20];
int n;
printf("Enter no of students:\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%d%f%s",&id,&marks,name);
insert(name,id,marks);    
}
print();
int number;
printf("Enter the id you want to search");
scanf("%d",&number);
if(search(number) == -1){
printf("Not found\n");
}
else{
    printf("%d\n",search(number));
}
printf("Enter the id you want to delete");
int number1;
scanf("%d",&number1);
delete(number1);
print();
}