#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} ;
void printll(struct Node *ptr){
    printf("Elements of Linked List : ");
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main(){
    struct Node *node1;
    struct Node *node2;
    struct Node *node3;
    struct Node *node4;
  
  node1=(struct Node*)malloc(sizeof(struct Node*));
   node2=(struct Node*)malloc(sizeof(struct Node*));
    node3=(struct Node*)malloc(sizeof(struct Node*));
     node4=(struct Node*)malloc(sizeof(struct Node*));

    struct Node *head = node1;
    head->data=10;
    head->next=node2;
     node2->data=20;
    node2->next=node3;
    node3->data=30;
    node3->next=node4;
    node4->data=40;
    node4->next=NULL;
    printll(head);
 
}