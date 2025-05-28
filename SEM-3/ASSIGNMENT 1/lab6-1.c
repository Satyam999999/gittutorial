// #include<stdio.h>
// #include<stdlib.h>
 
// struct stack{
//     int size ;
//     int top;
//     int * arr;
// };
// // struct Node{
// //     int data;
// //     struct Node* next;
// // };
// int main(){
//     struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
//     sp->size = 50;
//     sp->top = -1;
//     sp->arr = (int *) malloc(sp->size * sizeof(int));
    
// }
#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
int isempty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *ptr,int val){
    if(isfull(ptr)){
        printf("Stack is full");

    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack *ptr){
     if(isempty(ptr)){
        printf("Stack is empty");


    }
    else{
        int n=ptr->arr[ptr->top];
        ptr->top--;
        return n; 
    }
}
int peek(struct stack *ptr, int i){
    int index=ptr->top-i+1;
    if(index<0){
        return -1;
    }
    else{
        return ptr->arr[index];
    }
}
void reverse(struct stack *ptr,int n){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
   sp->size = 50;
  sp->top = -1;
  sp->arr = (int *) malloc(sp->size * sizeof(int));
  while(!isempty(ptr)){
    int val=pop(ptr);
    push(sp,val);
  }
  for(int i=1;i<=n;i++){
            printf("%d\t",peek(sp,i));

  }
}
int main(){
   struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
   sp->size = 50;
  sp->top = -1;
  sp->arr = (int *) malloc(sp->size * sizeof(int));
      for(int i=0;i<5;i++){
        int val;
        scanf("%d",&val);
        push(sp,val);
      }
       for(int i=1;i<=5;i++){
        printf("%d\t",peek(sp,i));
      }
reverse(sp,5);
}



//  #include<stdio.h>
//  #include<stdlib.h>
 
//  struct stack{
//  int top;
//  int size;
//  char *arr;
//  };
//  int isempty(struct stack *ptr){
//     if(ptr->top==-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int isfull(struct stack *ptr){
//     if(ptr->top==ptr->size-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// void push(struct stack *ptr,int val){
//     if(isfull(ptr)){
//         printf("Stack is full");

//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top]=val;
//     }
// }
// char pop(struct stack *ptr){
//      if(isempty(ptr)){
//         printf("Stack is empty");


//     }
//     else{
//     char n=ptr->arr[ptr->top];
//         ptr->top--;
//         return n; 
//     }
// }
// int ismatching(char left,char right){
// return (left=='(' && right==')')||
// (left=='{' && right=='}')||
// (left=='[' && right==']');

// }
// int paranthesis(char *exp){
//  struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
//  sp->size = 50;
//     sp->top = -1;
//     sp->arr = (int *) malloc(sp->size * sizeof(int));
//     for(int i=0;exp[i]!='\0';i++){
//         if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
//             push(sp,exp[i]);
//         }
//         else{
//              if(isempty(sp)){
//                  return 0;
//              }
//             char poppedChar=pop(sp);
//             if(!ismatching(poppedChar,exp[i])){
//                 return 0;
//             }
//         }
//     }
//      if (isempty(sp)) {
//         return 1; // Balanced
//     } else {
//         return 0; // Not balanced
//     }
    
// }

// int main(){
//        char exp[] = "{[()]}"; // Example expression

//     if (paranthesis(exp)) {
//         printf("Balanced\n");
//     } else {
//         printf("Not Balanced\n");
//     }

//     return 0;
// }
