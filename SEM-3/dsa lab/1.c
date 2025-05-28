#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *right;
};
struct Node* createcll(int a[],int n){
    struct Node *head=(struct Node* )malloc(sizeof(struct Node));
    head->data=a[0];
struct Node *prev= head;
    for(int i=1;i<n;i++){
            struct Node *temp=(struct Node* )malloc(sizeof(struct Node));
            temp->data=a[i];
            prev->right=temp;
            temp->right=head;
            prev=temp;
 }
 return head;
}
void print(struct Node *head){
   struct Node *ptr= head;
    printf("Elements : \n");
    do{
        printf("%d\t",ptr->data);
        ptr=ptr->right;
    }while(ptr != head);
printf("\n");
}
struct Node* deletekth(struct Node *head,int k){
      struct Node *ptr= head;
      
      for(int i=1;i<k-1;i++){
         ptr=ptr->right;
      }
      struct Node*temp=ptr->right;
      ptr->right=temp->right;
      free(temp);
      return head; 
}

     
    


int main(){
int n;
printf("Enter No of elements :\n ");
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
struct Node *head=createcll(a,n);
print(head);
int m;
printf("Enter the node no . you want to delete ");
scanf("%d",&m);
head=deletekth(head,m);
print(head);
}

