#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}






// #include<stdio.h>
// #include<stdlib.h>
 
// struct circularQueue
// {
//     int size;
//     int f;
//     int r;
//     int* arr;
// };
 
 
// int isEmpty(struct circularQueue *q){
//     if(q->r==q->f){
//         return 1;
//     }
//     return 0;
// }
 
// int isFull(struct circularQueue *q){
//     if((q->r+1)%q->size == q->f){
//         return 1;
//     }
//     return 0;
// }
 
// void enqueue(struct circularQueue *q, int val){
//     if(isFull(q)){
//         printf("This Queue is full");
//     }
//     else{
//         q->r = (q->r +1)%q->size;
//         q->arr[q->r] = val; 
//         printf("Enqued element: %d\n", val);
//     }
// }
 
// int dequeue(struct circularQueue *q){
//     int a = -1;
//     if(isEmpty(q)){
//         printf("This Queue is empty");
//     }
//     else{
//         q->f = (q->f +1)%q->size;
//         a = q->arr[q->f]; 
//     }
//     return a;
// }
 
 
// int main(){
//     struct circularQueue q;
//     q.size = 4;
//     q.f = q.r = 0;
//     q.arr = (int*) malloc(q.size*sizeof(int));
    
//     // Enqueue few elements
//     enqueue(&q, 12);
//     enqueue(&q, 15);
//     enqueue(&q, 1); 
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("Dequeuing element %d\n", dequeue(&q));
//     printf("Dequeuing element %d\n", dequeue(&q)); 
//     enqueue(&q, 45);
//     enqueue(&q, 45);
//     enqueue(&q, 45);
 
//     if(isEmpty(&q)){
//         printf("Queue is empty\n");
//     }
//     if(isFull(&q)){
//         printf("Queue is full\n");
//     }
 
//     return 0;
// }





// #include <stdio.h>
// #include <stdlib.h>
 
// struct Node *f = NULL;
// struct Node *r = NULL;
 
// struct Node
// {
//     int data;
//     struct Node *next;
// };
 
// void linkedListTraversal(struct Node *ptr)
// {
//     printf("Printing the elements of this linked list\n");
//     while (ptr != NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }
 
// void enqueue(int val)
// {
//     struct Node *n = (struct Node *) malloc(sizeof(struct Node));
//     if(n==NULL){
//         printf("Queue is Full");
//     }
//     else{
//         n->data = val;
//         n->next = NULL;
//         if(f==NULL){
//             f=r=n;
//         }
//         else{
//             r->next = n;
//             r=n;
//         }
//     }
// }
 
// int dequeue()
// {
//     int val = -1;
//     struct Node *ptr = f;
//     if(f==NULL){
//         printf("Queue is Empty\n");
//     }
//     else{
//         f = f->next;
//         val = ptr->data;
//         free(ptr);
//     }
//     return val;
// }
 
// int main()
// {
//     linkedListTraversal(f);
//     printf("Dequeuing element %d\n", dequeue());
//     enqueue(34);
//     enqueue(4);
//     enqueue(7);
//     enqueue(17);
//     linkedListTraversal(f);
//     printf("Dequeuing element %d\n", dequeue());
//     printf("Dequeuing element %d\n", dequeue());
//     printf("Dequeuing element %d\n", dequeue());
//     printf("Dequeuing element %d\n", dequeue());
//     linkedListTraversal(f);
//     return 0;
// }













