// #include<stdio.h>
// #include<stdlib.h>
// struct Node{
//     int data;
//     struct Node *left;
//     struct Node *right;

// };
// struct Node* createnode(int data){
//     struct Node *n = (struct Node*)malloc(sizeof(struct Node));
//     n->data=data;
//     n->left=NULL;
//     n->right=NULL;
//     return n;
// }
// void postOrder(struct Node *root){
//     if(root!=NULL){
//     postOrder(root->left);
//     postOrder(root->right);
//     printf("%d",root->data);
//  }
// }
// struct Node* construct(int n,int preOrder[],int inOrder[]){
//     static int k=0;
//     int ans;
// struct Node* root = createnode(preOrder[k++]);
// for(int i=0;i<n;i++){
//     if(inOrder[i]=preOrder[0]){
//     ans=i;
//     }
// }

// }
// int main(){
//     int n;
//     printf("Enter no. of nodes\n");
//     scanf("%d",&n);
//     int preOrder[n];
//     int inOrder[n];
//     printf("Enter preorder elements\n");
//     for(int i=0;i<n;i++){
//         scanf("%d",preOrder[i]);
//     }
//      printf("Enter inorder elements\n");
//     for(int i=0;i<n;i++){
//         scanf("%d",inOrder[i]);
//     }
// construct(n,preOrder,inOrder);



// }
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int inOrder[], int preOrder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;
int current;
    current = preOrder[*preIndex];
    (*preIndex)++;

    struct Node* node = newNode(current);

    if (inStart == inEnd) return node;

    int inIndex = search(inOrder, inStart, inEnd, current);

    node->left = buildTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);

    return node;
}

void printPostOrder(struct Node* node) {
    if (node == NULL) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->data);
}

int main() {
    int preOrder[] = {1,2,4,5,3,6,7};
    int inOrder[] = {4,2,5,1,6,3,7};
    int n1 = sizeof(inOrder) / sizeof(inOrder[0]);
    int preIndex1 = 0;
    struct Node* root1 = buildTree(inOrder, preOrder, 0, n1 - 1, &preIndex1);
    printf("PostOrder traversal for Testcase 1: ");
    printPostOrder(root1);
    printf("\n");

}
