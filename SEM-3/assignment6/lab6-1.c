// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// struct stack{
//     int size;
//     int top;
//     char *arr;
// };
// int isempty(struct stack *st){
//     if(st->top == -1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int isfull(struct stack *st){
//     if(st->top == st->size-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// void push(struct stack *st,char val){
//     if(isfull(st)){
//         printf("Stack is Full");
//     }
//     else{
//         st->top++;
//         st->arr[st->top]=val;
//     }
// }
// char pop(struct stack *st){
//     if(isempty(st)){
//         printf("Stack is empty");
//     }
//     else{
//         char n=st->arr[st->top];
//         st->top--;
//         return n;
//     }
//     return 0;
// }
// int isoperator(char ch){
// if(ch == '(' || ch == ')' || ch == '+' || ch == '-'|| ch== '*' || ch == '/'){
//     return 1;
// }
// else{
//     return 0;
// }
// }
// int precedence(char ch){
//     if(ch=='*' || ch == '/'){
//         return 2;
//     }
//     else if(ch=='+' || ch=='-'){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// char stackattop(struct stack *st){
//     return st->arr[st->top];
// }
// void infixtopostfix(char *infix){
//     struct stack *st=(struct stack*)malloc(sizeof(struct stack));
//     st->size=50;
//     st->top=-1;
//     st->arr=(char*)malloc(st->size*sizeof(char));
//     char *postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
//     int i=0;
//     int j=0;
//     while(infix[i]!='\0'){
//         if(!isoperator(infix[i])){
//             postfix[j]=infix[i];
//             i++;
//             j++;
//         }
//         else if(infix[i]==')'){
//             while(st->arr(st->top)!= '('){
//                postfix[j]= pop(st);
//                j++;
//             }
//             pop(st);
//         }
//         else if(precedence(infix[i])>=precedence(stackattop(st))){
// push(st,infix[i]);
// i++;
//         }
//         else {
// postfix[j]=pop(st);
// j++;
//         }

//     }
//     while(!isempty(st)){
//         postfix[j]=pop(st);
//         j++;
//     }
//     postfix[j]='\0';
//     for(int i=0;i<strlen(postfix);i++){
//         printf("%c",postfix[i]);
//     }
//     printf("\n");
// }
// int main(){ 
// char infix[] = "a*(b+c)/d";
// infixtopostfix(infix);

// }





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isempty(struct stack *st) {
    return st->top == -1;
}

int isfull(struct stack *st) {
    return st->top == st->size - 1;
}

void push(struct stack *st, char val) {
    if (isfull(st)) {
        printf("Stack is Full\n");
    } else {
        st->top++;
        st->arr[st->top] = val;
    }
}

char pop(struct stack *st) {
    if (isempty(st)) {
        printf("Stack is empty\n");
        return '\0';
    } else {
        char n = st->arr[st->top];
        st->top--;
        return n;
    }
}

int isoperator(char ch) {
    return ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return 0;
    }
}

char stackattop(struct stack *st) {
    if (!isempty(st)) {
        return st->arr[st->top];
    }
    return '\0';
}

void infixtopostfix(char *infix) {
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 50;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0') {
        if (!isoperator(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(st, infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while (stackattop(st) != '(') {
                postfix[j++] = pop(st);
            }
            pop(st); 
            i++;
        } else {
            while (!isempty(st) && precedence(stackattop(st)) >= precedence(infix[i])) {
                postfix[j++] = pop(st);
            }
            push(st, infix[i]);
            i++;
        }
    }

    while (!isempty(st)) {
        postfix[j++] = pop(st);
    }
    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}
   

int main() {
    char infix[] = "a*(b+c)/d";
    infixtopostfix(infix);
    return 0;
}




INSERT INTO LOAN VALUES (11,"Napier town",900), (14, "Wright Town", 1500), (15 ,"S street",1500), (16 ,"S street", 1300), (17 ,"Wright Town", 1000), (23 ,"Cross square", 2000), (93,"Mehgawan",500);

INSERT INTO borrower VALUES
("Amit", 16),
("Charu", 93),
("Priya", 15),
("Yash ",14),
("Vinay", 17),
("Divya", 11),
("Divya", 23),
("Sakshi", 17);

INSERT INTO account VALUES ("Stadium", "Delhi" ,710000), ("Wright town", "Delhi" ,9000000), ("Mehgawan", "Hyderabad", 400000), ("North town","Raipur", 3700000), ("S street", "Hyderabad" ,1700000), ("Pownal" ,"Bilaspur", 300000), ("Cross square" ,"Nagpur" ,2100000), ("Napier town","Hyderabad", 8000000);