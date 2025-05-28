#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} ;
struct Node* insertele(struct Node *head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node*));
    ptr->data= data;
     head->next=ptr;
    ptr->next=NULL;
   return head;
}
void printll(struct Node *ptr){
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct Node* delete(struct Node *head,int index){
    struct Node *ptr1 = head;
   struct Node *ptr2 = head->next;
    while(index != 1){
       ptr1= ptr1->next;
       ptr2= ptr2->next;
        index--;
    }
    ptr1->next=ptr2->next;
    free(ptr2);
    return head;
} 

void rangell(struct Node *head ,int a,int b ){
struct Node *ptr=head;
while(ptr != NULL){
    if(ptr->data > a && ptr->data < b){
        printf("%d\t",ptr->data);
    }
    ptr=ptr->next;
}
printf("\n");
}

int main(){
    int n;
  printf(" Enter number of elements :");
  scanf("%d",&n);
  struct Node *head;
  head=(struct Node*)malloc(sizeof(struct Node*));
  head->data=10;
  printf("Enter data of elements :\n");
  int ele[n];

  for(int i=1;i<n;i++){
    scanf("%d",&ele);
insertele(head,ele);
  }
  printf("Original List :");
printll(head);
delete(head,5);
printf("After Deletion : ");
printll(head);
int a,b;
scanf("%d%d",&a,&b);
rangell(head,a,b);

}