#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createcll(int a[], int n)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data=a[0];
    head->left=NULL;
    struct Node *prev=head;
    for(int i=1;i<n;i++){
       struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); 
       temp->data=a[i];
       prev->right=temp;
       temp->left=prev;
       temp->right=NULL;
       prev=temp;
    } 
    return head;
 }
 void printcll(struct Node *head){
struct Node *ptr=head;
printf("Elements:");
while(ptr!=NULL){
    printf("%d\t",ptr->data);
    ptr=ptr->right;
    }
    printf("\n");
 }
 struct Node* reversedll(struct Node *head){
    struct Node *ptr=head;
    while(ptr->right!=NULL){
        ptr=ptr->right;
    } 
    head=ptr;
    struct Node *next=head;
    struct Node *temp=ptr->left;
    while(ptr->right!=NULL){
        next->right=temp;
        temp->left=next;

        //ptr=ptr->right;
    }
return head;
 }
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    struct Node *head = createcll(a, n);
    printcll(head);
    //head=reversedll(head);
       // printcll(head);

}