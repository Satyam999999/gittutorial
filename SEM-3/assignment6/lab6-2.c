// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// struct Node
// {
//     int data;
//     struct Node *next;
// };
// int isempty(struct Node *st)
// {
//     if (st == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// int isfull(struct Node *st)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     if (ptr == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
// char push(struct Node *st, char val)
// {
//     if (isfull(st))
//     {
//         printf("Stack is Full");
//     }
//     else
//     {
//         struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//         ptr->data = val;
//         ptr->next = st;
//         st = ptr;
            

//     }
// }
// char pop(struct Node *st)
// {
//     if (isempty(st))
//     {
//         printf("Stack is empty");
//     }
//     else
//     {
//         struct Node *ptr = st;
//         char x=ptr->data;
//         st = st->next;
//         free(ptr);
//         return x;

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
// void postfix(char *exp){
//         struct Node *st=(struct Node*)malloc(sizeof(struct Node));
//         st=NULL;
//             char *postfix = (char*)malloc((strlen(exp)+1)*sizeof(char));
// int i=0;
// int j=0;
//        for(int i=0;exp[i]!='\0';i++){
//         if(!isoperator(exp[i])){
//                postfix[j]=exp[i];   
// j++;
// i++;
//         }
//         else {
//         push(st,exp[i]);
//        }

//        }
//        if(!isempty(st)){
//         postfix[j]=pop(st);
//         j++;
//        }
//   postfix[j]='\0';
//     for(int i=0;i<strlen(postfix);i++){
//         printf("%c",postfix[i]);
//     }
//     printf("\n");       
// }
// int main(){ 
// char exp[] = "a+b/c-d";
//   postfix(exp);

// }





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

int isempty(struct Node *st) {
    return st == NULL;
}

int isfull(struct Node *st) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        return 1;
    } else {
        free(ptr); 
        return 0;
    }
}

struct Node* push(struct Node *st, char val) {
    if (isfull(st)) {
        printf("Stack is Full\n");
        return st;
    } else {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = val;
        ptr->next = st;
        st = ptr;
        return st;
    }
}

char pop(struct Node **st) {
    if (isempty(*st)) {
        printf("Stack is empty\n");
        return '\0';
    } else {
        struct Node *ptr = *st;
        char x = ptr->data;
        *st = (*st)->next;
        free(ptr);
        return x;
    }
}

char stackattop(struct Node *st) {
    if (!isempty(st)) {
        return st->data;
    }
    return '\0';
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

void postfix(char *exp) {
    struct Node *st = NULL;  
    char *postfix = (char *)malloc((strlen(exp) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (exp[i] != '\0') {
        if (!isoperator(exp[i])) {
           
            postfix[j++] = exp[i++];
        } else if (exp[i] == '(') {
            st = push(st, exp[i++]);
        } else if (exp[i] == ')') {
     
            while (!isempty(st) && stackattop(st) != '(') {
                postfix[j++] = pop(&st);
            }
            pop(&st); 
            i++;
        } else {
          
            while (!isempty(st) && precedence(stackattop(st)) >= precedence(exp[i])) {
                postfix[j++] = pop(&st);
            }
            st = push(st, exp[i++]);
        }
    }

    
    while (!isempty(st)) {
        postfix[j++] = pop(&st);
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    free(postfix);
}

int main() {
    char exp[] = "a+b/c-d";
    postfix(exp);
    return 0;
}
