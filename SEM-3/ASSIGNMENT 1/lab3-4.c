#include<stdio.h>

struct EMPLOYEE { 
int emp_id;
char name[50];
float salary ; 
};
int main(){
    struct EMPLOYEE emp [ 5 ] ;
    printf("Enter details:\n");
    for(int i=0;i<5;i++){
        scanf("%d%s%f",&emp[i].emp_id,&emp[i].name,&emp[i].salary);
    }
     printf("Details of Employees:\n");
    for(int i=0;i<5;i++){
        printf("%d\t%s\t%f\n",emp[i].emp_id,emp[i].name,emp[i].salary);
    }
    printf("Size of each Employee record:\n");
    for(int i=0;i<5;i++){
        printf("%d\n",sizeof(emp[i]));
    }
    printf("Address of each employee record:\n");
    for(int i=0;i<5;i++){
        printf("%d\n",&emp[i]);
    }
    

}