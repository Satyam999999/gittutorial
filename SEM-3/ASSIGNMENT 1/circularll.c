// #include<stdio.h>
// #include<stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *next;
// };
// void linkedListTraversal(struct Node *head){
//     struct Node *ptr = head;
//     do{
//         printf("Element is %d\n", ptr->data);
//         ptr = ptr->next;
//     }while(ptr!=head);
// }
// struct Node * insertAtFirst(struct Node *head, int data){
//     struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
//     ptr->data = data;
 
//     struct Node * p = head->next;
//     while(p->next != head){
//         p = p->next;
//     }
//     // At this point p points to the last node of this circular linked list
 
//     p->next = ptr;
//     ptr->next = head;
//     head = ptr;
//     return head;
 
// }
// struct Node* insertAtEnd(struct Node* head, int data) {
//     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr->data = data;
//          struct Node * p = head->next;
//     while(p->next != head ){
//         p = p->next;
//     }
   
//         p->next = ptr;
    
//         ptr->next = head;
//             return head;

// }
// struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
//     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr->data = data;

//         // Insert between prevNode and its next node
//         struct Node* nextNode = prevNode->next;
        
//         ptr->next = nextNode;
//        prevNode->next = ptr;
//           return head;

//     }



// int main(){
    
//     struct Node *head;
//     struct Node *second;
//     struct Node *third;
//     struct Node *fourth;
 
//     // Allocate memory for nodes in the linked list in Heap
//     head = (struct Node *)malloc(sizeof(struct Node));
//     //head=NULL;
//     // second = (struct Node *)malloc(sizeof(struct Node));
//     // third = (struct Node *)malloc(sizeof(struct Node));
//     // fourth = (struct Node *)malloc(sizeof(struct Node));
 
//     // Link first and second nodes
//    // head->data = 4;
//          head=insertAtEnd(head,40);
//                   head=insertAtEnd(head,50);
//          head=insertAtEnd(head,60);
//          head=insertAtEnd(head,70);



// //     head->next = second;
 
// //     // Link second and third nodes
// //     second->data = 3;
// //     second->next = third;
 
// //     // Link third and fourth nodes
// //     third->data = 6;
// //     third->next = fourth;
 
// //     // Terminate the list at the third node
// //     fourth->data = 1;
// //     fourth->next = head;
// //      linkedListTraversal(head);
// //      head=insertAtFirst(head,40);
// //      linkedListTraversal(head);
// //  insertAtEnd(head,50);
// //  linkedListTraversal(head);
// //  insertAfterNode(head,second,70);
//  linkedListTraversal(head);
//     return 0;
// }






#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head) {
    struct Node *ptr = head;
    if (head != NULL) {
        do {
            printf("Element is %d\n", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL) {
        // If the list is empty
        ptr->next = ptr;  // Points to itself
        head = ptr;
    } else {
        struct Node *p = head;
        while (p->next != head) {
            p = p->next;
        }
        // At this point, p points to the last node of the circular linked list
        p->next = ptr;
        ptr->next = head;
        head = ptr;
    }

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL) {
        // If the list is empty
        ptr->next = ptr;  // Points to itself
        head = ptr;
    } else {
        struct Node *p = head;
        while (p->next != head) {
            p = p->next;
        }
        // At this point, p points to the last node of the circular linked list
        p->next = ptr;
        ptr->next = head;
    }

    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    if (prevNode == NULL) {
        return head;
    }

    // Insert between prevNode and its next node
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main() {
    struct Node *head = NULL;

    // Inserting elements at the end
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    head = insertAtEnd(head, 60);
    head = insertAtEnd(head, 70);

    // Traversing the list
    printf("Circular Linked List after inserting at the end:\n");
    linkedListTraversal(head);

    // Inserting an element at the first position
    head = insertAtFirst(head, 30);

    // Traversing the list
    printf("\nCircular Linked List after inserting at the beginning:\n");
    linkedListTraversal(head);

    return 0;
}
