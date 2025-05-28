#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    char *arr;
};
int isempty(struct stack *st){
    if(st->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct stack *st){
    if(st->top == st->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *st,char val){
    if(isfull(st)){
        printf("Stack is Full");
    }
    else{
        st->top++;
        st->arr[st->top]=val;
    }
}
char pop(struct stack *st){
    if(isempty(st)){
        printf("Stack is empty");
    }
    else{
        char n=st->arr[st->top];
        st->top--;
        return n;
    }
    return 0;
}
int ismatching(char left,char right){
return (left=='(' && right==')')||
(left=='{' && right =='}')||
(left=='[' && right==']');
}
int balanced(char *exp){
    struct stack *st=(struct stack*)malloc(sizeof(struct stack));
    st->size=50;
    st->top=-1;
    st->arr=(char*)malloc(st->size*sizeof(char));
for(int i=0;exp[i]!='\0';i++){
    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
push(st,exp[i]);
    }
    else{
        if(isempty(st)){
            return 0;
        }
        char popped=pop(st);
        if(!ismatching(popped,exp[i])){
            return 0;
        }
    }
}
if(isempty(st)){
    return 1;
}
else{
    return 0;
}

}
int main(){
    char exp[]="[()][()()]()";
    if(balanced(exp)){
        printf("Balanced\n");
    }
    else{
        printf("Not Balanced\n");
    }
}