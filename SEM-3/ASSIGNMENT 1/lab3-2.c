#include<stdio.h>
struct student { 
char name[20];
int age;
float marks;
struct student *next ;
};

int main(){
struct student s1,s2,s3;
s1.next=&s2;
s2.next=&s3;
s3.next=NULL;
printf("Enter details of s1:\n");
scanf("%s%d%f",&s1.name,&s1.age,&s1.marks);

printf("Enter details of s2:\n");
scanf("%s%d%f",&s1.next->name,&s1.next->age,&s1.next->marks);

printf("Enter details of s3:\n");
scanf("%s%d%f",&s1.next->next->name,&s1.next->next->age,&s1.next->next->marks);

printf("Details of s1:\n");
printf("%s\t%d\t%f\n",s1.name,s1.age,s1.marks);

printf("Details of s2:\n");
printf("%s\t%d\t%f\n",s1.next->name,s1.next->age,s1.next->marks);

printf("Details of s3:\n");
printf("%s\t%d\t%f\n",s1.next->next->name,s1.next->next->age,s1.next->next->marks);

struct student *ptr=&s1;
printf("Details of s1:\n");
printf("%s\t%d\t%f\n",ptr->name,ptr->age,ptr->marks);


printf("Details of s2:\n");
printf("%s\t%d\t%f\n",ptr->next->name,ptr->next->age,ptr->next->marks);

printf("Details of s3:\n");
printf("%s\t%d\t%f\n",ptr->next->next->name,ptr->next->next->age,ptr->next->next->marks);

float avg=(ptr->marks+ptr->next->marks+ptr->next->next->marks)/3;
printf("Average marks:%f",avg);




}