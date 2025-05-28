// // // #include<stdio.h>
// // // #include<stdlib.h>
// // // typedef struct Node{
// // // int data;
// // // struct Node *left;
// // // struct Node *right;
// // // }node;
// // // void linkedListTraversal(struct Node *ptr)
// // // {
// // //     while (ptr != NULL)
// // //     {
// // //         printf("Element: %d\n", ptr->data);
// // //         ptr = ptr->right;
// // //     }
// // // }b
// // // struct Node * insertAtFirst(struct Node *head, int data){
// // //     struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
// // //     ptr->data = data;
// // //     ptr->left=NULL;
// // //     ptr->right = head;
// // //     head=ptr;
// // //     return head;
// // // }
// // // struct Node * insertAtEnd(struct Node *head, int data){
// // //     struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
// // //     ptr->data = data;
// // //  head;   struct Node * p = 

// // //     while(p->right!=NULL){
// // //         p = p->right;
// // //     }
// // //     p->right = ptr;
// // //     ptr->left=p;
// // //     ptr->right = NULL;
// // //     return head;
// // // }
// // // struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
// // //     struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
// // //     ptr->data = data;

// // //     ptr->right = prevNode->right;
// // //     prevNode->right = ptr;
// // //     ptr->left=prevNode;

// // //     return head;
// // // }
// // // struct Node * deleteFirst(struct Node * head){
// // //     struct Node * ptr = head;
// // //     head = head->right;
// // //     head->left=NULL;
// // //     free(ptr);
// // //     return head;
// // // }
// // // struct Node * deleteAtLast(struct Node * head){
// // //     struct Node *p = head;
// // //     struct Node *q = head->right;
// // //     while(q->right !=NULL)
// // //     {
// // //         p = p->right;
// // //         q = q->right;
// // //     }

// // //     p->right = NULL;
// // //     free(q);
// // //     return head;
// // // }
// // // struct Node * deleteByValue(struct Node * head, int value){
// // //     struct Node *p = head;
// // //     struct Node *q = head->right;
// // //     while(q->data!=value && q->right!= NULL)
// // //     {
// // //         p = p->right;
// // //         q = q->right;
// // //     }

// // //     if(q->data == value){
// // //         p->right = q->right;
// // //         if(q->right != NULL) {  // Ensure q->right is not NULL before updating its left
// // //             q->right->left = p;
// // //         }

// // //         free(q);
// // //     }
// // //     return head;
// // // }

// // // int main(){
// // //     struct Node *head;
// // //     struct Node *second;
// // //     struct Node *third;
// // //     struct Node *fourth;

// // //     // Allocate memory for nodes in the linked list in Heap
// // //     head = (struct Node *)malloc(sizeof(struct Node));
// // //     second = (struct Node *)malloc(sizeof(struct Node));
// // //     third = (struct Node *)malloc(sizeof(struct Node));
// // //     fourth = (struct Node *)malloc(sizeof(struct Node));

// // //     // Link first and second nodes
// // //     head->data = 7;
// // //     head->left=NULL;
// // //     head->right= second;

// // //     // Link second and third nodes
// // //     second->data = 11;
// // //     second->left=head;
// // //     second->right = third;

// // //     // Link third and fourth nodes
// // //     third->data = 41;
// // //     third->left=second;
// // //     third->right = fourth;

// // //     // Terminate the list at the third node
// // //     fourth->data = 66;
// // //     fourth->left=third;
// // //     fourth->right = NULL;
// // //     linkedListTraversal(head);
// // //    head= insertAtFirst(head,25);
// // //      linkedListTraversal(head);
// // // // insertAtEnd(head,30);
// // // // linkedListTraversal(head);
// // // // insertAfterNode(head,second,50);
// // // // printf("bye\n");
// // // // linkedListTraversal(head);
// // // // head=deleteFirst(head);
// // // // printf("bye\n");
// // // // linkedListTraversal(head);
// // // // deleteAtLast(head);
// // // // printf("bye\n");
// // // // linkedListTraversal(head);
// // // // deleteByValue(head,41);
// // // // printf("bye\n");
// // // // linkedListTraversal(head);
// // // // int target=11;
// // // // struct Node *Cur=head;
// // // // //search the nodes in a linked list
// // // // //search until the target value is found or the end of the list is reached
// // // // while (Cur != NULL && Cur -> data != target) {
// // // // Cur = Cur -> right;
// // // // }
// // // // int found;
// // // // //determine if the target is found or ran off the end of the list
// // // // if (Cur != NULL)
// // // // {
// // // // found = 1;
// // // // }
// // // // else
// // // // {
// // // // found = 0;
// // // // }
// // // // printf("%d",found);

// // // }







// #include <stdio.h>
// #include <stdlib.h>
// typedef struct Node
// {
//     int data;
//     // struct Node *left;
//     struct Node *right;
// } node;
// void printll(struct Node *head)
// {
//     struct Node *temp = head;
//     while (temp != NULL)
//     {
//         printf("Element:%d\n", temp->data);
//         temp = temp->right;
//     }
// }
// struct Node *insertelement(struct Node *head, int val)
// {
 
//   struct Node* temp=head;
//     while(temp->right != NULL){
//         temp=temp->right;
//     }
//     struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));;
//     temp1->data=val;
//     temp->right=temp1;
//     return head;

// }

// void linkedListTraversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->right;
//     }
// }
// struct Node *inserteleathead(struct Node *head, int data){
//  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data=data;
//     ptr->right = head;
//     head = ptr;
//     return head;
// }
// int main(){
//    struct Node *head;
// //     // struct Node *second;
// //     // struct Node *third;
// //     // struct Node *fourth;

// //     // Allocate memory for nodes in the linked list in Heap
   // head = (struct Node *)malloc(sizeof(struct Node));
    // int n = 5;
    // int first;
    // scanf("%d", &first);
    // head->data = first;
    // for (int i = 1; i < n; i++)
    // {
    //     int val;
    //     scanf("%d", &val);
    //     insertelement(head, val);
    // }
// // //     // second = (struct Node *)malloc(sizeof(struct Node));
// // //     // third = (struct Node *)malloc(sizeof(struct Node));
// // //     // fourth = (struct Node *)malloc(sizeof(struct Node));
    //     head->data=10;
    //     head=inserteleathead(head,20);
    //    head= inserteleathead(head,30);
    //    head= inserteleathead(head,40);
    //    head= inserteleathead(head,50);
    //    head= inserteleathead(head,60);
// // //         //  printll(head);
   // linkedListTraversal(head);
 //}


// // // void insertAtKthPos(struct Node** head, int data, int k) {
// // //     struct Node* newNode = createNode(data);

// // //     // If inserting at the head
// // //     if (k == 1) {
// // //         newNode->next = *head;
// // //         if (*head != NULL)
// // //             (*head)->prev = newNode;
// // //         *head = newNode;
// // //         return;
// // //     }

// // //     struct Node* temp = *head;
// // //     int count = 1;

// // //     // Traverse to the (k-1)th node
// // //     while (count < k - 1 && temp != NULL) {
// // //         temp = temp->next;
// // //         count++;
// // //     }

// // //     // If position is out of range
// // //     if (temp == NULL) {
// // //         printf("Position out of range\n");
// // //         return;
// // //     }

// // //     newNode->next = temp->next;
// // //     if (temp->next != NULL)
// // //         temp->next->prev = newNode;

// // //     temp->next = newNode;
// // //     newNode->prev = temp;
// // // }




// // #include <stdio.h>
// // #include <stdlib.h>
// // typedef struct Node
// // {
// //     int data;
// //     struct Node *left;
// //     struct Node *right;
// // } node;
// // void printll(struct Node *head)
// // {
// //     struct Node *temp = head;
// //     while (temp != NULL)
// //     {
// //         printf("Element:%d\n", temp->data);
// //         temp = temp->right;
// //     }
// // }
// // struct Node* convertarrtoll(int n,int arr[]) {
// //     struct Node *head= (struct Node*)malloc(sizeof(struct Node));
// //     head->data=arr[0];
// //     struct Node *prev=head;
// //     for(int i=1;i<n;i++){
// //         struct Node *temp= (struct NODE*)malloc(sizeof(struct Node*));
// //         temp->data=arr[i];
// //         temp->left=prev;
// //         prev->right=temp;
// //         temp->right=NULL;
// //         prev=temp;
// //     } 
// //     return head;
// // }
// // struct Node* insertathead(struct Node *head,int data) {
// // struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
// // temp->data = data;
// // temp->right=head;
// // head->left=temp;
// // temp->left=NULL;
// // head = temp;
// // return head;

// // }
// // struct Node* insertattail(struct Node *head,int data){
// //     struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
// // temp->data = data;
// // struct Node *p=head;
// // while(p->right!=NULL){
// //     p=p->right;
// // }
// // p->right=temp;
// // temp->left=p;
// // temp->right=NULL;
// // return head;
// // }
// // struct Node* deletehead(struct Node *head){
// // struct Node *temp=head;
// // head=head->right;
// // head->left=NULL;
// // free(temp);
// // return head;


// // }
// // struct Node* deletetail(struct Node *head){
// // struct Node *temp=head;
// // while(temp->right!=NULL){
// //     temp=temp->right;
// // }
// // temp->left->right=NULL;
// // free(temp);
// // }
// // int main(){
// //     int arr[]={1,2,3,4,5};
// //    struct Node *head=convertarrtoll(5,arr);
// //     printll(head);
// //     head=insertathead(head,10);
// //     printll(head);
// //     insertattail(head,50);
// //     printll(head);
// //  head=deletehead(head);
// //  printll(head);
// //  deletetail(head);
// //  printll(head);
// /







// #include <stdio.h>
// #include <stdlib.h>
 
// struct stack
// {
//     int size;
//     int top;
//     int *arr;
// };
 
// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// int main()
// {
//     // struct stack s;
//     // s.size = 80;
//     // s.top = -1;
//     // s.arr = (int *) malloc(s.size * sizeof(int));
 
//     struct stack *s=(struct stack *)malloc(sizeof(struct stack));
//     s->size = 80;
//     s->top = -1;
//     s->arr = (int *)malloc(s->size * sizeof(int));
//      // Check if stack is empty
//     if(isEmpty(s)){
//         printf("The stack is empty\n");
//     }
//     else{
//         printf("The stack is not empty");
//     }
//     // Pushing an element manually
//     s->arr[0] = 7;
//     s->top++;
 
//     // Check if stack is empty
//     if(isEmpty(s)){
//         printf("The stack is empty");
//     }
//     else{
//         printf("The stack is not empty\n");
//     }
    
// }







// #include<stdio.h>
// #include<stdlib.h>
 
// struct stack{
//     int size ;
//     int top;
//     int * arr;
// };
// struct Node{
//     int data;
//     struct Node* next;
// };

 
// int isEmpty(struct stack* ptr){
//     if(ptr->top == -1){
//             return 1;
//         }
//         else{
//             return 0;
//         }
// }
 
// int isFull(struct stack* ptr){
//     if(ptr->top == ptr->size - 1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
 
// void push(struct stack* ptr, int val){
//     if(isFull(ptr)){
//         printf("Stack Overflow! Cannot push %d to the stack\n", val);
//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }
 
// int pop(struct stack* ptr){
//     if(isEmpty(ptr)){
//         printf("Stack Underflow! Cannot pop from the stack\n");
//         return -1;
//     }
//     else{
//         int val = ptr->arr[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }
 
// int peek(struct stack* sp, int i){
//     int arrayInd = sp->top -i + 1;
//     if(arrayInd < 0){
//         printf("Not a valid position for the stack\n");
//         return -1;
//     }
//     else{
//         return sp->arr[arrayInd];
//     }
// }
// int stackTop(struct stack* sp){
//     return sp->arr[sp->top];
// }
 
// int stackBottom(struct stack* sp){
//     return sp->arr[0];
// }
// int main(){
//     struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
//     sp->size = 50;
//     sp->top = -1;
//     sp->arr = (int *) malloc(sp->size * sizeof(int));
//     printf("Stack has been created successfully\n");
 
//     printf("Before pushing, Full: %d\n", isFull(sp));
//     printf("Before pushing, Empty: %d\n", isEmpty(sp));
//     //     push(sp, 1);
//     // push(sp, 23);
//     // push(sp, 99);
//     // push(sp, 75);
//     // push(sp, 3);
//     // push(sp, 64);
//     // push(sp, 57);
//     // push(sp, 46);
//     // push(sp, 89);
//     // push(sp, 6);  
//     // push(sp, 5);  
//     // push(sp, 75);  
//     int n;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         int val;
//         scanf("%d",&val);
//         push(sp,val);
//     }
//         // Printing values from the stack
//     for (int j = 1; j <= sp->top + 1; j++)
//     {
//         printf("The value at position %d is %d\n", j, peek(sp, j));
//     }
//     printf("The top most value of this stack is %d\n", stackTop(sp));
//     printf("The bottom most value of this stack is %d\n", stackBottom(sp));
//     return 0;
// }







// #include<stdio.h>
// #include<stdlib.h>
 
// struct Node{
//     int data;
//     struct Node * next;
// };
 
// void linkedListTraversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next; 
//     }
// }
 
// int isEmpty(struct Node* top){
//     if (top==NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
 
// int isFull(struct Node* top){
//     struct Node* p = (struct Node*)malloc(sizeof(struct Node));
//     if(p==NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
 
// struct Node* push(struct Node* top, int x){
//     if(isFull(top)){
//         printf("Stack Overflow\n");
//     }
//     else{
//         struct Node* n = (struct Node*) malloc(sizeof(struct Node));
//         n->data = x;
//         n->next = top;
//         top = n;
//         return top;
//     }
// }
 
// int pop(struct Node** top){
//     if(isEmpty(*top)){
//         printf("Stack Underflow\n");
//     }
//     else{
//         struct Node* n = *top;
//         *top = (*top)->next;
//         int x = n->data;
//         free(n);
//         return x; 
//     }
// }
 
// int main(){
//     struct Node* top = NULL;
//     top = push(top, 78);
//     top = push(top, 7);
//     top = push(top, 8);
    
//     linkedListTraversal(top);
//     int element = pop(&top); 
//     printf("Popped element is %d\n", element);
//     linkedListTraversal(top);
//         int element1 = pop(&top); 
//     printf("Popped element is %d\n", element1);
//     linkedListTraversal(top);

//     return 0;
// }







// #include<stdio.h>
// #include<stdlib.h>
 
// struct Node{
//     int data;
//     struct Node * next;
// };
 
// struct Node* top = NULL;
 
// void linkedListTraversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next; 
//     }
// }
 
// int isEmpty(struct Node* top){
//     if (top==NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
 
// int isFull(struct Node* top){
//     struct Node* p = (struct Node*)malloc(sizeof(struct Node));
//     if(p==NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
 
// struct Node* push(struct Node* top, int x){
//     if(isFull(top)){
//         printf("Stack Overflow\n");
//     }
//     else{
//         struct Node* n = (struct Node*) malloc(sizeof(struct Node));
//         n->data = x;
//         n->next = top;
//         top = n;
//         return top;
//     }
// }
 
// int pop(struct Node* tp){
//     if(isEmpty(tp)){
//         printf("Stack Underflow\n");
//     }
//     else{
//         struct Node* n = tp;
//         top = (top)->next;
//         int x = n->data;
//         free(n);
//         return x; 
//     }
// }
 
// int peek(int pos){
//     struct Node* ptr = top;
//     for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
//     {
//         ptr = ptr->next;
//     }
//     if(ptr!=NULL){
//         return ptr->data;
//     }
//     else{
//         return -1;
//     }
// }
// int stackTop(){
//     return top->data;
// }

 
// int main(){
//     top = push(top, 28);
//     top = push(top, 18);
//     top = push(top, 15);
//     top = push(top, 7);
    
//     linkedListTraversal(top);
//     for (int i = 1; i <= 4; i++)
//     { 
//         printf("Value at position %d is : %d\n", i, peek(i));
//     }
//         top = push(top, 28);
//     top = push(top, 18);
//     top = push(top, 15);
//     top = push(top, 7);
//         for (int i = 1; i <= 8; i++)
//     {
//         printf("Value at position %d is : %d\n", i, peek(i));
//     }
// printf("Top is %d \n ",stackTop());

//     return 0;
// }





// #include <stdio.h>
// #include <stdlib.h>

// // Stack structure
// struct stack {
//     int size;
//     int top;
//     char* arr;
// };

// // Function to initialize the stack
// int isEmpty(struct stack* s) {
//     return s->top == -1;
// }

// // Function to check if the stack is full
// int isFull(struct stack* s) {
//     return s->top == s->size - 1;
// }

// // Function to push an element to the stack
// void push(struct stack* s, char value) {
//     if (!isFull(s)) {
//         s->arr[++(s->top)] = value;
//     }
// }

// // Function to pop an element from the stack
// char pop(struct stack* s) {
//     if (!isEmpty(s)) {
//         return s->arr[(s->top)--];
//     }
//     return '\0'; // If the stack is empty
// }

// // Function to check if the given pairs of brackets match
// int isMatchingPair(char left, char right) {
//     return (left == '(' && right == ')') ||
//            (left == '[' && right == ']') ||
//            (left == '{' && right == '}');
// }

// // Function to check for balanced parentheses, brackets, and braces
// int parenthesisMatch(char* exp) {
//     // Create and initialize the stack
//     struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
//     sp->size = 100;
//     sp->top = -1;
//     sp->arr = (char*)malloc(sp->size * sizeof(char));

//     for (int i = 0; exp[i] != '\0'; i++) {
//         // If it's an opening bracket, push it to the stack
//         if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
//             push(sp, exp[i]);
//         }
//         // If it's a closing bracket, check for matching
//         else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
//             if (isEmpty(sp)) {
//                 return 0; // No matching opening bracket
//             }
//             char poppedChar = pop(sp);
//             if (!isMatchingPair(poppedChar, exp[i])) {
//                 return 0; // Mismatched brackets
//             }
//         }
//     }

//     // If the stack is empty, all brackets were balanced 
//     if (isEmpty(sp)) {
//         return 1; // Balanced
//     } else {
//         return 0; // Not balanced
//     }
// }

// int main() {
//     char exp[] = "{[()]}"; // Example expression

//     if (parenthesisMatch(exp)) {
//         printf("Balanced\n");
//     } else {
//         printf("Not Balanced\n");
//     }

//     return 0;
// }








// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
 
// struct stack
// {
//     int size;
//     int top;
//     char *arr;
// };
 
// int stackTop(struct stack* sp){
//     return sp->arr[sp->top];
// }
 
// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// void push(struct stack* ptr, char val){
//     if(isFull(ptr)){
//         printf("Stack Overflow! Cannot push %d to the stack\n", val);
//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }
 
// char pop(struct stack* ptr){
//     if(isEmpty(ptr)){
//         printf("Stack Underflow! Cannot pop from the stack\n");
//         return -1;
//     }
//     else{
//         char val = ptr->arr[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }
// int precedence(char ch){
//     if(ch == '*' || ch=='/')
//         return 3;
//     else if(ch == '+' || ch=='-')
//         return 2; 
//     else
//         return 0;
// }
 
// int isOperator(char ch){
//     if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
//         return 1;
//     else
//         return 0;
// }
// char* infixToPostfix(char* infix){
//     struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
//     sp->size = 10; 
//     sp->top = -1;
//     sp->arr = (char *) malloc(sp->size * sizeof(char));
//     char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
//     int i=0; // Track infix traversal
//     int j = 0; // Track postfix addition 
//     while (infix[i]!='\0')
//     {
//         if(!isOperator(infix[i])){
//             postfix[j] = infix[i];
//             j++;
//             i++;
//         }
//         else{
//             if(precedence(infix[i])> precedence(stackTop(sp))){
//                 push(sp, infix[i]);
//                 i++;
//             }
//             else{
//                 postfix[j] = pop(sp);
//                 j++;
//             }
//         }
//     }
//     while (!isEmpty(sp))    
//     {
//         postfix[j] = pop(sp);
//         j++;
//     }
//     postfix[j] = '\0';
//     return postfix;
// }
// int main()
// {
//     char * infix = "x-y/z-k*d";
//     printf("postfix is %s", infixToPostfix(infix));
//     return 0;
// }






// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX 100

// // Stack structure
// struct Stack {
//     int top;
//     char items[MAX];
// };

// // Function to initialize the stack
// void init(struct Stack *s) {
//     s->top = -1;
// }

// // Function to push an element onto the stack
// void push(struct Stack *s, char c) {
//     if (s->top < MAX - 1) {
//         s->items[++(s->top)] = c;
//     }
// }

// // Function to pop an element from the stack
// char pop(struct Stack *s) {
//     if (s->top != -1) {
//         return s->items[(s->top)--];
//     }
//     return '\0';  // If stack is empty
// }

// // Function to check if the stack is empty
// int isEmpty(struct Stack *s) {
//     return s->top == -1;
// }

// // Function to check if the given characters are matching pairs
// int isMatchingPair(char left, char right) {
//     return (left == '(' && right == ')') ||
//            (left == '[' && right == ']') ||
//            (left == '{' && right == '}');
// }

// // Function to check if parentheses are balanced
// int isBalanced(char exp[]) {
//     struct Stack stack;
//     init(&stack);

//     for (int i = 0; exp[i] != '\0'; i++) {
//         if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
//             push(&stack, exp[i]);
//         } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
//             if (isEmpty(&stack) || !isMatchingPair(pop(&stack), exp[i])) {
//                 return 0;  // Not balanced
//             }
//         }
//     }

//     return isEmpty(&stack);  // Stack should be empty if balanced
// }

// int main() {
//     char expression[MAX];

//     // Example 1: Balanced expression
//     strcpy(expression, "{[()]}");
//     printf("Expression: %s -> ", expression);
//     if (isBalanced(expression)) {
//         printf("Balanced\n");
//     } else {
//         printf("Not Balanced\n");
//     }

//     // Example 2: Not Balanced expression
//     strcpy(expression, "{[(])}");
//     printf("Expression: %s -> ", expression);
//     if (isBalanced(expression)) {
//         printf("Balanced\n");
//     } else {
//         printf("Not Balanced\n");
//     }

//     return 0;
// }








// void reverse(char str[])
// {
//     // Create a stack of capacity
//     // equal to length of string
//     int n = strlen(str);
//     Stack* stack = createStack(n);
 
//     // Push all characters of string to stack
//     int i;
//     for (i = 0; i < n; i++)
//         push(stack, str[i]);
 
//     // Pop all characters of string and
//     // put them back to str
//     for (i = 0; i < n; i++)
//         str[i] = pop(stack);
// }







// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>  // For isdigit() and isalpha()
// #include <string.h>

// #define MAX 100  // Maximum size of the stack

// // Stack structure
// struct Stack {
//     int top;
//     char items[MAX];
// };

// // Function to initialize the stack
// void initStack(struct Stack *s) {
//     s->top = -1;
// }

// // Function to check if the stack is empty
// int isEmpty(struct Stack *s) {
//     return s->top == -1;
// }

// // Function to check if the stack is full
// int isFull(struct Stack *s) {
//     return s->top == MAX - 1;
// }

// // Function to push an element to the stack
// void push(struct Stack *s, char item) {
//     if (isFull(s)) {
//         printf("Stack Overflow!\n");
//         return;
//     }
//     s->items[++s->top] = item;
// }

// // Function to pop an element from the stack
// char pop(struct Stack *s) {
//     if (isEmpty(s)) {
//         printf("Stack Underflow!\n");
//         return '\0';
//     }
//     return s->items[s->top--];
// }

// // Function to return the top element of the stack
// char peek(struct Stack *s) {
//     if (isEmpty(s)) {
//         return '\0';
//     }
//     return s->items[s->top];
// }

// // Function to check precedence of operators
// int precedence(char op) {
//     switch (op) {
//         case '+':
//         case '-':
//             return 1;
//         case '*':
//         case '/':
//             return 2;
//         case '^':
//             return 3;
//         default:
//             return 0;
//     }
// }

// // Function to check if the character is an operator
// int isOperator(char ch) {
//     return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
// }

// // Function to convert infix expression to postfix expression
// void infixToPostfix(char infix[], char postfix[]) {
//     struct Stack s;
//     initStack(&s);
//     int i = 0, j = 0;

//     while (infix[i] != '\0') {
//         char ch = infix[i];

//         // If the character is an operand, add it to postfix
//         if (isalnum(ch)) {
//             postfix[j++] = ch;
//         }
//         // If the character is '(', push it to stack
//         else if (ch == '(') {
//             push(&s, ch);
//         }
//         // If the character is ')', pop from stack until '(' is found
//         else if (ch == ')') {
//             while (!isEmpty(&s) && peek(&s) != '(') {
//                 postfix[j++] = pop(&s);
//             }
//             pop(&s);  // Pop '(' from stack
//         }
//         // If the character is an operator
//         else if (isOperator(ch)) {
//             while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
//                 postfix[j++] = pop(&s);
//             }
//             push(&s, ch);
//         }
//         i++;
//     }

//     // Pop all remaining operators from the stack
//     while (!isEmpty(&s)) {
//         postfix[j++] = pop(&s);
//     }

//     postfix[j] = '\0';  // Null-terminate the postfix expression
// }

// int main() {
//     char infix[MAX], postfix[MAX];

//     printf("Enter infix expression: ");
//     scanf("%s", infix);

//     infixToPostfix(infix, postfix);

//     printf("Postfix expression: %s\n", postfix);

//     return 0;
// }










// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// // Node class represents a
// // node in a linked list
// class Node {
// public:
//     // Data stored in the node
//     int data;   
    
//     // Pointer to the next node in the list
//     Node* next;      

//     // Constructor with both data and
//     // next node as parameters
//     Node(int data1, Node* next1) {
//         data = data1;
//         next = next1;
//     }

//     // Constructor with only data as a
//     // parameter, sets next to nullptr
//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//     }
// };

// // Function to reverse a linked list
// // using the 3-pointer approach
// Node* reverseLinkedList(Node *head)
// {
//    // Initialize'temp' at
//    // head of linked list
//    Node* temp = head;  
   
//    // Initialize pointer 'prev' to NULL,
//    // representing the previous node
//    Node* prev = NULL;  
   
//    // Traverse the list, continue till
//    // 'temp' reaches the end (NULL)
//    while(temp != NULL){  
//        // Store the next node in
//        // 'front' to preserve the reference
//        Node* front = temp->next;  
       
//        // Reverse the direction of the
//        // current node's 'next' pointer
//        // to point to 'prev'
//        temp->next = prev;  
       
//         // Move 'prev' to the current
//         // node for the next iteration
//        prev = temp;  
       
//         // Move 'temp' to the 'front' node
//         // advancing the traversal
//        temp = front; 
//    }
   
//    // Return the new head of
//    // the reversed linked list
//    return prev;  
// }

// // Function to print the linked list
// void printLinkedList(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main() {
//     // Create a linked list with
//     // values 1, 3, 2, and 4
//     Node* head = new Node(1);
//     head->next = new Node(3);
//     head->next->next = new Node(2);
//     head->next->next->next = new Node(4);

//     // Print the original linked list
//     cout << "Original Linked List: ";
//     printLinkedList(head);

//     // Reverse the linked list
//     head = reverseLinkedList(head);

//     // Print the reversed linked list
//     cout << "Reversed Linked List: ";
//     printLinkedList(head);

//     return 0;
// }








// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// // Define a Node class for doubly linked list
// class Node {
// public:
//     // Data stored in the node
//     int data;   
//     // Pointer to the next node in the list 
//     //(forward direction)
//     Node* next;     
//     // Pointer to the previous node in the list
//     //(backward direction)
//     Node* back;     

//     // Constructor for a Node with both data,
//     //a reference to the next node,
//     //and a reference to the previous node
//     Node(int data1, Node* next1, Node* back1) {
//         data = data1;
//         next = next1;
//         back = back1;
//     }

//     // Constructor for a Node with data,
//     //and no references to the next and
//     //backious nodes (end of the list)
//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//         back = nullptr;
//     }
// };

// // Function to convert an array
// // to a doubly linked list
// Node* convertArr2DLL(vector<int> arr) {
//     // Create the head node with
//     //the first element of the array
    
//     Node* head = new Node(arr[0]);
    
//     // Initialize 'prev' to the head node
//     Node* prev = head;            

//     for (int i = 1; i < arr.size(); i++) {
//         // Create a new node with data from the
//         //array and set its 'back' pointer to
//         //the previous node
        
//         Node* temp = new Node(arr[i], nullptr, prev);
//         // Update the 'next' pointer of the
//         //previous node to point to
//         //the new node
//         prev->next = temp; 
//          // Move 'prev' to the newly created
//          //node for the next iteration
//         prev = temp;       
//     }
//     // Return the head of the doubly linked list
//     return head;  
// }

// // Function to print the elements
// //of the doubly linked list
// void print(Node* head) {
//     while (head != nullptr) {
//         // Print the data in the tail node
//         cout << head->data << " ";  
//          // Move to the next node
//         head = head->next;         
//     }
// }

 
// // Function to reverse a doubly linked list
// // In-place link exchange method
// Node* reverseDLL(Node* head) {
    
//     // Check if the list is empty
//     // or has only one node
//     if (head == NULL || head->next == NULL) {
//         // No change is needed;
//         // return the current head
//         return head; 
//     }
    
//      // Initialize a pointer to
//      // the previous node
//     Node* prev = NULL;  
    
//     // Initialize a pointer to
//     // the current node
//     Node* current = head;   

//     // Traverse the linked list
//     while (current != NULL) {
//         // Store a reference to
//         // the previous node
//         prev = current->back; 
        
//         // Swap the previous and
//         // next pointers
//         current->back = current->next; 
        
//         // This step reverses the links
//         current->next = prev;          
        
//         // Move to the next node
//         // in the original list
//         current = current->back; 
//     }
    
//     // The final node in the original list
//     // becomes the new head after reversal
//     return prev->back;
// }


// int main() {
//     vector<int> arr = {12, 5, 8, 7, 4};
//     Node* head = convertArr2DLL(arr);
//     cout << endl << "Doubly Linked List Initially:  " << endl;
//     print(head);
//     cout << endl << "Doubly Linked List After Reversing " << endl;
    
//      // Insert a node with value 10 at the end
//     head = reverseDLL(head);
//     print(head);

//     return 0;
// }




// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for the linked list
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to insert a node at the end of a linked list
// struct Node* insertEnd(struct Node* head, int data) {
//     if (head == NULL)
//         return createNode(data);
    
//     struct Node* temp = head;
//     while (temp->next != NULL)
//         temp = temp->next;
    
//     temp->next = createNode(data);
//     return head;
// }

// // Function to display the linked list
// void displayList(struct Node* head) {
//     struct Node* temp = head;
//     while (temp != NULL) {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// // Function to add two linked lists without carry
// struct Node* addLists(struct Node* l1, struct Node* l2) {
//     struct Node* result = NULL;
//     struct Node *temp1 = l1, *temp2 = l2;
    
//     // Traverse both lists
//     while (temp1 != NULL || temp2 != NULL) {
//         int sum = 0;
        
//         if (temp1 != NULL) {
//             sum += temp1->data;
//             temp1 = temp1->next;
//         }
//         if (temp2 != NULL) {
//             sum += temp2->data;
//             temp2 = temp2->next;
//         }
        
//         // Insert sum into the result list without considering carry
//         result = insertEnd(result, sum % 10);
//     }
    
//     return result;
// }

// // Helper function to convert an integer to a linked list
// struct Node* numberToList(int num) {
//     struct Node* head = NULL;
    
//     // Edge case for 0
//     if (num == 0) {
//         return createNode(0);
//     }
    
//     while (num > 0) {
//         head = insertEnd(head, num % 10); // Extract digit and create node
//         num /= 10;
//     }
    
//     return head;
// }

// int main() {
//     int num1, num2;
    
//     // Take two non-negative integers as input
//     printf("Enter first number: ");
//     scanf("%d", &num1);
//     printf("Enter second number: ");
//     scanf("%d", &num2);
    
//     // Convert numbers to linked lists
//     struct Node* l1 = numberToList(num1);
//     struct Node* l2 = numberToList(num2);
    
//     // Display the input linked lists
//     printf("First number as linked list: ");
//     displayList(l1);
//     printf("Second number as linked list: ");
//     displayList(l2);
    
//     // Add the two lists without carry
//     struct Node* result = addLists(l1, l2);
    
//     // Display the result linked list
//     printf("Result linked list: ");
//     displayList(result);
    
//     return 0;
// }
