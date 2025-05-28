#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
struct student{
    char name[20];
    int id;
    float marks;
};
struct student *table=(struct student*)malloc(10*sizeof(struct student));

int hash(int key){
    return key%size;
}
void insert(char name[],int key,float value){
    int index=hash(key);
    while(table[index]!=0){
        index=(index+1)%size;
    }
   struct student *s1 = (struct student*)malloc(sizeof(struct student));
    s1->id = key;
    s1->marks = value;
    strcpy(s1->name,name);
    table[index]=s1;
}
int search(int key){
    int index=hash(key);
    while(((table[index])->id) != key ){
        index=(index+1)%size;
    }
    return index;
}
void delete(int key){
    int index=hash(key);
    while(((table[index])->id) != key ){
        index=(index+1)%size;
    }
    table[index]=0;
}
void print(){
    for(int i=0;i<size;i++){
        printf("Key->%d\n",((table[i])->id));
    }
}
int main(){
    for(int i=0;i<size;i++){
    table[i]=0;
}
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
scanf("%d",&number);
printf("%d\n",search(number));
delete(number);
print();
}


