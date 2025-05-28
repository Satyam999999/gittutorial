#include <stdio.h>
#include <stdlib.h>

typedef struct student_record
{
    char name[50];
    int rollno;
    float total_marks;
} stud;
int main()
{
    int n;
    int sum = 0;
    printf("Enter number of students\n");
    scanf("%d", &n);
    stud *data = (struct student_record *)malloc(n * sizeof(stud));
    printf("Enter student data:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%f", &data[i].name, &data[i].rollno, &data[i].total_marks);
        sum += data[i].total_marks;
    }
    printf("Student Details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%f\t", data[i].name, data[i].rollno, data[i].total_marks);
        printf("\n");
    }
    float avg = sum / n;
    printf("Average marks is :%f\n", avg);
}