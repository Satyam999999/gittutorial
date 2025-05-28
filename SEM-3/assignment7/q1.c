#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *left;
struct Node *right;
};
struct Node* createnode(int data){
 struct Node* n= (struct Node*)malloc(sizeof(struct Node));
 n->data=data;
 n->left=NULL;
 n->right=NULL;
 return n;
}
struct Node* createbst(struct Node* root,int data){
if(root==NULL){
    return createnode(data);
}
if(data<root->data){
    root->left=createbst(root->left,data);
}
else if(data>root->data){
    root->right=createbst(root->right,data);
}
return root;
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root){
    if(root!=NULL){
         printf("%d\t",root->data);
        preorder(root->left);
         preorder(root->right);
    }
}
void postorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
       inorder(root->right);
        printf("%d\t",root->data);
    }
}
struct Node *insert(struct Node *root,int val){
    struct Node *prev = NULL;
    while(root!=NULL){
        prev=root;
        if(val==root->data){
            printf("Element already exists");
        }
        else if(val<root->data){
            root=root->left;
        }
        else if(val>root->data){
            root=root->right;
        }
    }
struct Node *new=createnode(val);
if(val<prev->data){
    prev->left=new;
}
else{
    prev->right=new;
}
return root;
}
struct Node *inorderpredecessor(struct Node* root){
root=root->left;
while(root->right!=NULL){
    root=root->right;
}
return root;
}
struct Node *delete(struct Node *root,int val){
    struct Node *pred;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }
    if(val<root->data){
        root->left=delete(root->left,val);
    }
    else if(val>root->data){
        root->right=delete(root->right,val);
    }
    else{
        pred=inorderpredecessor(root);
        root->data=pred->data;
        root->left=delete(root->left,pred->data);
    }
    return root;
}
void range(struct Node* root,int min,int max){
        if(root!=NULL){
            if(root->data>min && root->data<max){
         printf("%d\t",root->data);
            }
        range(root->left,min,max);
         range(root->right,min,max);
    }
}
int main(){
int n;
struct Node *root=NULL;
printf("Enter no. of nodes");
scanf("%d",&n);
for(int i=0;i<n;i++){
    int val;
    scanf("%d",&val);
    root=createbst(root,val);
}
 inorder(root);
 printf("\n");
 preorder(root);
 printf("\n");
//  postorder(root);
 insert(root,2);
 inorder(root);
 printf("\n");
delete(root,6);
 inorder(root);
 printf("\n");
 preorder(root);
 printf("\n");
 int min,max;
 printf("Enter min and max");
 scanf("%d%d",&min,&max);
 range(root,min,max);
}