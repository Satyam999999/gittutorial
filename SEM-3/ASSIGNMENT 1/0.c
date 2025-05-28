// //#include<stdio.h>
// // int func(int arr[],int n){
// //     for(int i=0;i<5;i++){
// //         printf("%d\t",arr[i]);
// //     }
// //     printf("\n");
// // }
// // // int func(int *arr,int n){
// // //     for(int i=0;i<5;i++){
// // //         printf("%d\t",*(arr+i));
// // //     }
// // //     printf("\n");
// // }
// // int main() {
// //     int arr[5];
// //     int n=5;
// //     for(int i=0;i<5;i++){
// //         scanf("%d",&arr[i]);
// //     }
// //     for(int i=0;i<5;i++){
// //         printf("%d\t",arr[i]);
// //     }
// //     printf("\n");
// //     return 0;
// // }


  #include <stdio.h>
 #include <stdlib.h>
 struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
 
    ptr->next = head;
    return ptr; 
}
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    
    return head;
}
// Case 1: Deleting the first element from the linked list
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// Case 3: Deleting the last element
struct Node * deleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}
// Case 4: Deleting the element with a given value from the linked list
struct Node * deleteByValue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}



int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
 
    linkedListTraversal(head);
    head=insertAtFirst(head, 10);
    printf("HI\n");
    linkedListTraversal(head);
    insertAtEnd( head,20);
    printf("Bye\n");
    linkedListTraversal(head);
    printf("\nLinked List after inserting 25 after the second node:\n");
 insertAfterNode(head, second, 25);
 printf("\nLinked List after inserting 25 after the second node:\n");
     linkedListTraversal(head);
head=deleteFirst(head);
printf("\nLinked List after inserting 25 after the second node:\n");
 linkedListTraversal(head);
deleteAtLast(head);
printf("\nLinked List after inserting 25 after the second node:\n");
 linkedListTraversal(head);
deleteByValue(head, 25);
printf("\nLinked List after inserting 25 after the second node:\n");
 linkedListTraversal(head);

}
  

 // #include<stdio.h>
// #include<stdlib.h>
 
// struct stack{
//     int size ;
//     int top;
//     int * arr;
// };