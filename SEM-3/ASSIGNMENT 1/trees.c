// // #include<stdio.h>
// // #include<stdlib.h>

// // struct node{
// //     int data;
// //     struct node* left;
// //     struct node* right;
// // };

// // struct node* createNode(int data){
// //     struct node *n; // creating a node pointer
// //     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
// //     n->data = data; // Setting the data
// //     n->left = NULL; // Setting the left and right children to NULL
// //     n->right = NULL; // Setting the left and right children to NULL
// //     return n; // Finally returning the created node
// // }

// // int main(){
// //     /*
// //     // Constructing the root node
// //     struct node *p;
// //     p = (struct node *) malloc(sizeof(struct node));
// //     p->data = 2;
// //     p->left = NULL;
// //     p->right = NULL;

// //     // Constructing the second node
// //     struct node *p1;
// //     p1 = (struct node *) malloc(sizeof(struct node));
// //     p->data = 1;
// //     p1->left = NULL;
// //     p1->right = NULL;

// //     // Constructing the third node
// //     struct node *p2;
// //     p2 = (struct node *) malloc(sizeof(struct node));
// //     p->data = 4;
// //     p2->left = NULL;
// //     p2->right = NULL;
// //     */
   
// //     // Constructing the root node - Using Function (Recommended)
// //     struct node *p = createNode(2);
// //     struct node *p1 = createNode(1);
// //     struct node *p2 = createNode(4);

// //     // Linking the root node with left and right children
// //     p->left = p1;
// //     p->right = p2;
// //     return 0;
// // }







// //preorder
// // #include<stdio.h>
// // #include<stdlib.h>

// // struct node{
// //     int data;
// //     struct node* left;
// //     struct node* right;
// // };

// // struct node* createNode(int data){
// //     struct node *n; // creating a node pointer
// //     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
// //     n->data = data; // Setting the data
// //     n->left = NULL; // Setting the left and right children to NULL
// //     n->right = NULL; // Setting the left and right children to NULL
// //     return n; // Finally returning the created node
// // }

// // void preOrder(struct  node* root){
// //     if(root!=NULL){
// //         printf("%d ", root->data);
// //         preOrder(root->left);
// //         preOrder(root->right);
// //     }
// // }

// // int main(){
     
// //     // Constructing the root node - Using Function (Recommended)
// //     struct node *p = createNode(4);
// //     struct node *p1 = createNode(1);
// //     struct node *p2 = createNode(6);
// //     struct node *p3 = createNode(5);
// //     struct node *p4 = createNode(2);
// //     // Finally The tree looks like this:
// //     //      4
// //     //     / \
// //     //    1   6
// //     //   / \
// //     //  5   2  

// //     // Linking the root node with left and right children
// //     p->left = p1;
// //     p->right = p2;
// //     p1->left = p3;
// //     p1->right = p4;

// //     preOrder(p);
// //     return 0;
// // }






// //postorder
// // #include<stdio.h>
// // #include<stdlib.h>

// // struct node{
// //     int data;
// //     struct node* left;
// //     struct node* right;
// // };

// // struct node* createNode(int data){
// //     struct node *n; // creating a node pointer
// //     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
// //     n->data = data; // Setting the data
// //     n->left = NULL; // Setting the left and right children to NULL
// //     n->right = NULL; // Setting the left and right children to NULL
// //     return n; // Finally returning the created node
// // }

// // void preOrder(struct  node* root){
// //     if(root!=NULL){
// //         printf("%d ", root->data);
// //         preOrder(root->left);
// //         preOrder(root->right);
// //     }
// // }

// // void postOrder(struct  node* root){
// //     if(root!=NULL){
// //         postOrder(root->left);
// //         postOrder(root->right);
// //         printf("%d ", root->data);
// //     }
// // }

// // int main(){
     
// //     // Constructing the root node - Using Function (Recommended)
// //     struct node *p = createNode(4);
// //     struct node *p1 = createNode(1);
// //     struct node *p2 = createNode(6);
// //     struct node *p3 = createNode(5);
// //     struct node *p4 = createNode(2);
// //     // Finally The tree looks like this:
// //     //      4
// //     //     / \
// //     //    1   6
// //     //   / \
// //     //  5   2  

// //     // Linking the root node with left and right children
// //     p->left = p1;
// //     p->right = p2;
// //     p1->left = p3;
// //     p1->right = p4;

// //     preOrder(p);
// //     printf("\n");
// //     postOrder(p);
// //     return 0;
// // }




// //inorder
// // #include<stdio.h>
// // #include<stdlib.h>

// // struct node{
// //     int data;
// //     struct node* left;
// //     struct node* right;
// // };

// // struct node* createNode(int data){
// //     struct node *n; // creating a node pointer
// //     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
// //     n->data = data; // Setting the data
// //     n->left = NULL; // Setting the left and right children to NULL
// //     n->right = NULL; // Setting the left and right children to NULL
// //     return n; // Finally returning the created node
// // }

// // void preOrder(struct  node* root){
// //     if(root!=NULL){
// //         printf("%d ", root->data);
// //         preOrder(root->left);
// //         preOrder(root->right);
// //     }
// // }

// // void postOrder(struct  node* root){
// //     if(root!=NULL){
// //         postOrder(root->left);
// //         postOrder(root->right);
// //         printf("%d ", root->data);
// //     }
// // }

// // void inOrder(struct  node* root){
// //     if(root!=NULL){
// //         inOrder(root->left);
// //         printf("%d ", root->data);
// //         inOrder(root->right);
// //     }
// // }

// // int main(){
     
// //     // Constructing the root node - Using Function (Recommended)
// //     struct node *p = createNode(4);
// //     struct node *p1 = createNode(1);
// //     struct node *p2 = createNode(6);
// //     struct node *p3 = createNode(5);
// //     struct node *p4 = createNode(2);
// //     // Finally The tree looks like this:
// //     //      4
// //     //     / \
// //     //    1   6
// //     //   / \
// //     //  5   2  

// //     // Linking the root node with left and right children
// //     p->left = p1;
// //     p->right = p2;
// //     p1->left = p3;
// //     p1->right = p4;

// //     preOrder(p);
// //     printf("\n");
// //     postOrder(p);
// //     printf("\n");
// //     inOrder(p);
    
// //     return 0;
// // }





// // #include<stdio.h>
// // #include<stdlib.h>

// // struct node{
// //     int data;
// //     struct node* left;
// //     struct node* right;
// // };

// // struct node* createNode(int data){
// //     struct node *n; // creating a node pointer
// //     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
// //     n->data = data; // Setting the data
// //     n->left = NULL; // Setting the left and right children to NULL
// //     n->right = NULL; // Setting the left and right children to NULL
// //     return n; // Finally returning the created node
// // }

// // void preOrder(struct  node* root){
// //     if(root!=NULL){
// //         printf("%d ", root->data);
// //         preOrder(root->left);
// //         preOrder(root->right);
// //     }
// // }

// // void postOrder(struct  node* root){
// //     if(root!=NULL){
// //         postOrder(root->left);
// //         postOrder(root->right);
// //         printf("%d ", root->data);
// //     }
// // }

// // void inOrder(struct  node* root){
// //     if(root!=NULL){
// //         inOrder(root->left);
// //         printf("%d ", root->data);
// //         inOrder(root->right);
// //     }
// // }

// // int isBST(struct  node* root){
// //     static struct node *prev = NULL;
// //     if(root!=NULL){
// //         if(!isBST(root->left)){
// //             return 0;
// //         }
// //         if(prev!=NULL && root->data <= prev->data){
// //             return 0;
// //         }
// //         prev = root;
// //         return isBST(root->right);
// //     }
// //     else{
// //         return 1;
// //     }
// // }

// // int main(){
     
// //     // Constructing the root node - Using Function (Recommended)
// //     struct node *p = createNode(5);
// //     struct node *p1 = createNode(3);
// //     struct node *p2 = createNode(6);
// //     struct node *p3 = createNode(1);
// //     struct node *p4 = createNode(4);
// //     // Finally The tree looks like this:
// //     //      5
// //     //     / \
// //     //    3   6
// //     //   / \
// //     //  1   4  

// //     // Linking the root node with left and right children
// //     p->left = p1;
// //     p->right = p2;
// //     p1->left = p3;
// //     p1->right = p4;

// //     // preOrder(p);
// //     // printf("\n");
// //     // postOrder(p); 
// //     // printf("\n");
// //     inOrder(p);
// //     printf("\n");
// //     // printf("%d", isBST(p)); 
// //     if(isBST(p)){
// //         printf("This is a bst" );
// //     }
// //     else{
// //         printf("This is not a bst");
// //     }
// //     return 0;
// // }




// // #include<stdio.h>
// // #include<stdlib.h>

// // struct node{
// //     int data;
// //     struct node* left;
// //     struct node* right;
// // };

// // struct node* createNode(int data){
// //     struct node *n; // creating a node pointer
// //     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
// //     n->data = data; // Setting the data
// //     n->left = NULL; // Setting the left and right children to NULL
// //     n->right = NULL; // Setting the left and right children to NULL
// //     return n; // Finally returning the created node
// // }

// // void preOrder(struct  node* root){
// //     if(root!=NULL){
// //         printf("%d ", root->data);
// //         preOrder(root->left);
// //         preOrder(root->right);
// //     }
// // }

// // void postOrder(struct  node* root){
// //     if(root!=NULL){
// //         postOrder(root->left);
// //         postOrder(root->right);
// //         printf("%d ", root->data);
// //     }
// // }

// // void inOrder(struct  node* root){
// //     if(root!=NULL){
// //         inOrder(root->left);
// //         printf("%d ", root->data);
// //         inOrder(root->right);
// //     }
// // }

// // int isBST(struct  node* root){
// //     static struct node *prev = NULL;
// //     if(root!=NULL){
// //         if(!isBST(root->left)){
// //             return 0;
// //         }
// //         if(prev!=NULL && root->data <= prev->data){
// //             return 0;
// //         }
// //         prev = root;
// //         return isBST(root->right);
// //     }
// //     else{
// //         return 1;
// //     }
// // }

// // struct node * search(struct node* root, int key){
// //     if(root==NULL){
// //         return NULL;
// //     }
// //     if(key==root->data){
// //         return root;
// //     }
// //     else if(key<root->data){
// //         return search(root->left, key);
// //     }
// //     else{
// //         return search(root->right, key);
// //     }
// // }

// // int main(){
     
// //     // Constructing the root node - Using Function (Recommended)
// //     struct node *p = createNode(5);
// //     struct node *p1 = createNode(3);
// //     struct node *p2 = createNode(6);
// //     struct node *p3 = createNode(1);
// //     struct node *p4 = createNode(4);
// //     // Finally The tree looks like this:
// //     //      5
// //     //     / \
// //     //    3   6
// //     //   / \
// //     //  1   4  

// //     // Linking the root node with left and right children
// //     p->left = p1;
// //     p->right = p2;
// //     p1->left = p3;
// //     p1->right = p4;

// //     struct node* n = search(p, 3);
// //     if(n!=NULL){
// //     printf("Found: %d\n", n->data);
// //     }
// //     else{
// //         printf("Element not found");
// //     }
// //     return 0;
// // }




// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };

// struct node* createNode(int data){
//     struct node *n; // creating a node pointer
//     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
//     n->data = data; // Setting the data
//     n->left = NULL; // Setting the left and right children to NULL
//     n->right = NULL; // Setting the left and right children to NULL
//     return n; // Finally returning the created node
// }

// void preOrder(struct  node* root){
//     if(root!=NULL){
//         printf("%d ", root->data);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }

// void postOrder(struct  node* root){
//     if(root!=NULL){
//         postOrder(root->left);
//         postOrder(root->right);
//         printf("%d ", root->data);
//     }
// }

// void inOrder(struct  node* root){
//     if(root!=NULL){
//         inOrder(root->left);
//         printf("%d ", root->data);
//         inOrder(root->right);
//     }
// }

// int isBST(struct  node* root){
//     static struct node *prev = NULL;
//     if(root!=NULL){
//         if(!isBST(root->left)){
//             return 0;
//         }
//         if(prev!=NULL && root->data <= prev->data){
//             return 0;
//         }
//         prev = root;
//         return isBST(root->right);
//     }
//     else{
//         return 1;
//     }
// }

// struct node * searchIter(struct node* root, int key){
//     while(root!=NULL){
//         if(key == root->data){
//             return root;
//         }
//         else if(key<root->data){
//             root = root->left;
//         }
//         else{
//             root = root->right;
//         }
//     }
//     return NULL;
// }

// int main(){
     
//     // Constructing the root node - Using Function (Recommended)
//     struct node *p = createNode(5);
//     struct node *p1 = createNode(3);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(1);
//     struct node *p4 = createNode(4);
//     // Finally The tree looks like this:
//     //      5
//     //     / \
//     //    3   6
//     //   / \
//     //  1   4  

//     // Linking the root node with left and right children
//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;

//     struct node* n = searchIter(p, 6);
//     if(n!=NULL){
//     printf("Found: %d", n->data);
//     }
//     else{
//         printf("Element not found");
//     }
//     return 0;
// }





// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };

// struct node* createNode(int data){
//     struct node *n; // creating a node pointer
//     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
//     n->data = data; // Setting the data
//     n->left = NULL; // Setting the left and right children to NULL
//     n->right = NULL; // Setting the left and right children to NULL
//     return n; // Finally returning the created node
// }

// void preOrder(struct  node* root){
//     if(root!=NULL){
//         printf("%d ", root->data);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }

// void postOrder(struct  node* root){
//     if(root!=NULL){
//         postOrder(root->left);
//         postOrder(root->right);
//         printf("%d ", root->data);
//     }
// }

// void inOrder(struct  node* root){
//     if(root!=NULL){
//         inOrder(root->left);
//         printf("%d ", root->data);
//         inOrder(root->right);
//     }
// }

// int isBST(struct  node* root){
//     static struct node *prev = NULL;
//     if(root!=NULL){
//         if(!isBST(root->left)){
//             return 0;
//         }
//         if(prev!=NULL && root->data <= prev->data){
//             return 0;
//         }
//         prev = root;
//         return isBST(root->right);
//     }
//     else{
//         return 1;
//     }
// }

// struct node * searchIter(struct node* root, int key){
//     while(root!=NULL){
//         if(key == root->data){
//             return root;
//         }
//         else if(key<root->data){
//             root = root->left;
//         }
//         else{
//             root = root->right;
//         }
//     }
//     return NULL;
// }

// void insert(struct node *root, int key){
//    struct node *prev = NULL;
//    while(root!=NULL){
//        prev = root;
//        if(key==root->data){
//            printf("Cannot insert %d, already in BST", key);
//            return;
//        }
//        else if(key<root->data){
//            root = root->left;
//        }
//        else{
//            root = root->right;
//        }
//    }
//    struct node* new = createNode(key);
//    if(key<prev->data){
//        prev->left = new;
//    }
//    else{
//        prev->right = new;
//    }

// }

// int main(){
     
//     // Constructing the root node - Using Function (Recommended)
//     struct node *p = createNode(5);
//     struct node *p1 = createNode(3);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(1);
//     struct node *p4 = createNode(4);
//     // Finally The tree looks like this:
//     //      5
//     //     / \
//     //    3   6
//     //   / \
//     //  1   4  

//     // Linking the root node with left and right children
//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;

//     insert(p, 16);
//     printf("%d", p->right->right->data);
//     return 0;
// }





// #include<stdio.h>
// #include<stdlib.h>
 
// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };
 
// struct node* createNode(int data){
//     struct node *n; // creating a node pointer
//     n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
//     n->data = data; // Setting the data
//     n->left = NULL; // Setting the left and right children to NULL
//     n->right = NULL; // Setting the left and right children to NULL
//     return n; // Finally returning the created node
// }
 
// void preOrder(struct  node* root){
//     if(root!=NULL){
//         printf("%d ", root->data);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }
 
// void postOrder(struct  node* root){
//     if(root!=NULL){
//         postOrder(root->left);
//         postOrder(root->right);
//         printf("%d ", root->data);
//     }
// }
 
// void inOrder(struct  node* root){
//     if(root!=NULL){
//         inOrder(root->left);
//         printf("%d ", root->data);
//         inOrder(root->right);
//     }
// }
 
// int isBST(struct  node* root){
//     static struct node *prev = NULL;
//     if(root!=NULL){
//         if(!isBST(root->left)){
//             return 0;
//         }
//         if(prev!=NULL && root->data <= prev->data){
//             return 0;
//         }
//         prev = root;
//         return isBST(root->right);
//     }
//     else{
//         return 1;
//     }
// }
 
// struct node * searchIter(struct node* root, int key){
//     while(root!=NULL){
//         if(key == root->data){
//             return root;
//         }
//         else if(key<root->data){
//             root = root->left;
//         }
//         else{
//             root = root->right;
//         }
//     }
//     return NULL;
// }
 
// void insert(struct node *root, int key){
//     struct node *prev = NULL;
//     while(root!=NULL){
//         prev = root;
//         if(key==root->data){
//             printf("Cannot insert %d, already in BST", key);
//             return;
//         }
//         else if(key<root->data){
//             root = root->left;
//         }
//         else{
//             root = root->right;
//         }
//     }
//     struct node* new = createNode(key);
//     if(key<prev->data){
//         prev->left = new;
//     }
//     else{
//         prev->right = new;
//     }
// }

// struct node *inOrderPredecessor(struct node* root){
//     root = root->left;
//     while (root->right!=NULL)
//     {
//         root = root->right;
//     }
//     return root;
// }

// struct node *deleteNode(struct node *root, int value){

//     struct node* iPre;
//     if (root == NULL){
//         return NULL;
//     }
//     if (root->left==NULL&&root->right==NULL){
//         free(root);
//         return NULL;
//     }

//     //searching for the node to be deleted
//     if (value < root->data){
//         root-> left = deleteNode(root->left,value);
//     }
//     else if (value > root->data){
//         root-> right = deleteNode(root->right,value);
//     }
//     //deletion strategy when the node is found
//     else{
//         iPre = inOrderPredecessor(root);
//         root->data = iPre->data;
//         root->left = deleteNode(root->left, iPre->data);
//     }
//     return root;
// }
 
// int main(){
     
//     // Constructing the root node - Using Function (Recommended)
//     struct node *p = createNode(5);
//     struct node *p1 = createNode(3);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(1);
//     struct node *p4 = createNode(4);
//     // Finally The tree looks like this:
//     //      5
//     //     / \
//     //    3   6
//     //   / \
//     //  1   4  
 
//     // Linking the root node with left and right children
//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;

//     inOrder(p);
//     printf("\n");
//     deleteNode(p, 5);
//     inOrder(p);

//     return 0;
// }





// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };

// // Function to create a new node
// struct node* createNode(int data){
//     struct node *n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
//     n->data = data; // Setting the data
//     n->left = NULL; // Setting the left and right children to NULL
//     n->right = NULL; // Setting the left and right children to NULL
//     return n; // Finally returning the created node
// }

// // Function to find the minimum value in the BST
// int findMin(struct node* root) {
//     if (root == NULL) {
//         printf("The tree is empty\n");
//         return -1; // Return -1 if the tree is empty
//     }
    
//     struct node* current = root;
//     while (current->left != NULL) {
//         current = current->left;
//     }
//     return current->data; // Return the leftmost node's data
// }

// // Function to find the maximum value in the BST
// int findMax(struct node* root) {
//     if (root == NULL) {
//         printf("The tree is empty\n");
//         return -1; // Return -1 if the tree is empty
//     }
    
//     struct node* current = root;
//     while (current->right != NULL) {
//         current = current->right;
//     }
//     return current->data; // Return the rightmost node's data
// }

// // Example usage in main function
// int main() {
//     // Construct the BST
//     struct node *p = createNode(5);
//     struct node *p1 = createNode(3);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(1);
//     struct node *p4 = createNode(4);
    
//     // Linking the nodes to form the tree
//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;
    
//     // Find the minimum and maximum values in the BST
//     int minValue = findMin(p);
//     int maxValue = findMax(p);
    
//     printf("Minimum value in the BST is %d\n", minValue);
//     printf("Maximum value in the BST is %d\n", maxValue);
    
//     return 0;
// }





#include<stdio.h>
#include<stdlib.h>

// Structure to define a node of the binary tree
struct node{
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data){
    struct node *n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

// Function to calculate the height of a binary tree
int height(struct node* root) {
    if (root == NULL) {
        return 0; // Height of an empty tree is -1 (or 0 if you prefer)
    }
    
    // Recursively calculate the height of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Height of the current node is 1 + the greater of the two subtree heights
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Example usage in main function
int main() {
    // Construct the binary tree
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    
    // Linking the nodes to form the tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    // Calculate and print the height of the tree
    int treeHeight = height(p);
    printf("The height of the tree is %d\n", treeHeight);
    
    return 0;
}


/*
#include<stdio.h>
#include<malloc.h>

// Structure to define a node of the binary tree
struct node {
    int data;               // Data part
    struct node* left;      // Pointer to left child
    struct node* right;     // Pointer to right child
};

// Function to create a new node
struct node* createNode(int data) {
    // Allocating memory for new node
    struct node *n = (struct node *) malloc(sizeof(struct node));
    
    // Setting data and pointers
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}

// Function to insert a new value in the BST
struct node* insert(struct node* root, int data) {
    // Base case: If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    // Return the (unchanged) node pointer
    return root;
}

// In-order traversal to print the tree
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL; // Initialize the root of the tree as NULL
    int n, val;

    // Get the number of nodes from the user
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    // Loop to insert nodes based on user input
    for(int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val); // Insert the value into the tree
    }

    // Print the tree using in-order traversal
    printf("In-order traversal of the constructed tree: ");
    inOrder(root);
    printf("\n");

    return 0;
}

*/



/*
#include<stdio.h>
#include<stdlib.h>

#define MAX 100 // Maximum number of nodes in the binary tree

// Structure to represent a binary tree using an array
struct BinaryTree {
    int arr[MAX];  // Array to store the tree elements
    int size;      // Current number of nodes in the tree
};

// Function to initialize the binary tree
void initTree(struct BinaryTree* tree) {
    tree->size = 0;  // Initially, the tree is empty
}

// Function to insert an element into the binary tree
void insert(struct BinaryTree* tree, int value) {
    if (tree->size >= MAX) {
        printf("Tree is full, cannot insert more elements.\n");
        return;
    }

    // Insert the value at the next available position
    tree->arr[tree->size] = value;
    tree->size++;
}

// Function to perform in-order traversal on the binary tree stored in the array
void inOrder(struct BinaryTree* tree, int index) {
    if (index >= tree->size) {
        return;
    }

    // Traverse the left subtree
    inOrder(tree, 2 * index + 1);

    // Print the current node
    printf("%d ", tree->arr[index]);

    // Traverse the right subtree
    inOrder(tree, 2 * index + 2);
}

// Function to perform pre-order traversal on the binary tree stored in the array
void preOrder(struct BinaryTree* tree, int index) {
    if (index >= tree->size) {
        return;
    }

    // Print the current node
    printf("%d ", tree->arr[index]);

    // Traverse the left subtree
    preOrder(tree, 2 * index + 1);

    // Traverse the right subtree
    preOrder(tree, 2 * index + 2);
}

// Function to perform post-order traversal on the binary tree stored in the array
void postOrder(struct BinaryTree* tree, int index) {
    if (index >= tree->size) {
        return;
    }

    // Traverse the left subtree
    postOrder(tree, 2 * index + 1);

    // Traverse the right subtree
    postOrder(tree, 2 * index + 2);

    // Print the current node
    printf("%d ", tree->arr[index]);
}

// Main function
int main() {
    struct BinaryTree tree;
    initTree(&tree);

    int n, value;

    // Ask the user for the number of nodes
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    // Insert nodes into the binary tree
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insert(&tree, value);
    }

    // Perform in-order, pre-order, and post-order traversals
    printf("In-order traversal: ");
    inOrder(&tree, 0);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrder(&tree, 0);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(&tree, 0);
    printf("\n");

    return 0;
}

*/



/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN and INT_MAX

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create and initialize a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = value;    // Set the data
    newNode->left = NULL;     // Initialize left child as NULL
    newNode->right = NULL;    // Initialize right child as NULL
    return newNode;           // Return the newly created node
}

// Function to find the minimum value in the binary tree
int findMin(struct Node* root) {
    if (root == NULL) {
        return INT_MAX; // Return a large value if the tree is empty
    }
    
    // Get the minimum value from the left subtree
    int minValue = findMin(root->left);
    
    // Return the minimum of the current node's data and the minimum from the left subtree
    return root->data < minValue ? root->data : minValue;
}

// Function to find the maximum value in the binary tree
int findMax(struct Node* root) {
    if (root == NULL) {
        return INT_MIN; // Return a small value if the tree is empty
    }
    
    // Get the maximum value from the right subtree
    int maxValue = findMax(root->right);
    
    // Return the maximum of the current node's data and the maximum from the right subtree
    return root->data > maxValue ? root->data : maxValue;
}

// Test the functions
int main() {
    // Constructing a sample binary tree manually
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->right->right = createNode(9);

    // Find the minimum and maximum values
    int minValue = findMin(root);
    int maxValue = findMax(root);

    // Print the results
    printf("Minimum value in the binary tree: %d\n", minValue);
    printf("Maximum value in the binary tree: %d\n", maxValue);

    // Free allocated memory (optional)
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}

*/



// #include<stdio.h>
// #include<malloc.h>

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };

// // Function to create a new node
// struct node* createNode(int data){
//     struct node *n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
//     n->data = data; // Setting the data
//     n->left = NULL; // Setting the left and right children to NULL
//     n->right = NULL; // Setting the left and right children to NULL
//     return n; // Finally returning the created node
// }

// // Helper function for reverse in-order traversal
// void reverseInOrder(struct node* root, int K, int* count, int* result) {
//     if (root == NULL || *count >= K) return;
    
//     // First, visit the right subtree
//     reverseInOrder(root->right, K, count, result);
    
//     // Increment count and check if current node is the Kth largest
//     (*count)++;
//     if (*count == K) {
//         *result = root->data;
//         return;
//     }
    
//     // Visit the left subtree
//     reverseInOrder(root->left, K, count, result);
// }

// // Function to find the Kth largest element in the BST
// int kthLargest(struct node* root, int K) {
//     int count = 0;
//     int result = -1;  // Default value in case K is larger than the number of nodes in the BST
//     reverseInOrder(root, K, &count, &result);
//     return result;
// }

// // Example usage in main function
// int main() {
//     // Construct the BST
//     struct node *p = createNode(5);
//     struct node *p1 = createNode(3);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(1);
//     struct node *p4 = createNode(4);
    
//     // Linking the nodes to form the tree
//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;
    
//     int K = 3;  // Find the 3rd largest element
//     int result = kthLargest(p, K);
//     printf("The %dth largest element is %d\n", K, result);
    
//     return 0;
// }


// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };

// // Function to create a new node
// struct node* createNode(int data){
//     struct node *n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
//     n->data = data; // Setting the data
//     n->left = NULL; // Setting the left and right children to NULL
//     n->right = NULL; // Setting the left and right children to NULL
//     return n; // Finally returning the created node
// }

// // Helper function for in-order traversal
// void inOrder(struct node* root, int K, int* count, int* result) {
//     if (root == NULL || *count >= K) return;
    
//     // First, visit the left subtree
//     inOrder(root->left, K, count, result);
    
//     // Increment count and check if current node is the Kth smallest
//     (*count)++;
//     if (*count == K) {
//         *result = root->data;
//         return;
//     }
    
//     // Visit the right subtree
//     inOrder(root->right, K, count, result);
// }

// // Function to find the Kth smallest element in the BST
// int kthSmallest(struct node* root, int K) {
//     int count = 0;
//     int result = -1;  // Default value in case K is larger than the number of nodes in the BST
//     inOrder(root, K, &count, &result);
//     return result;
// }

// // Example usage in main function
// int main() {
//     // Construct the BST
//     struct node *p = createNode(5);
//     struct node *p1 = createNode(3);
//     struct node *p2 = createNode(6);
//     struct node *p3 = createNode(1);
//     struct node *p4 = createNode(4);
    
//     // Linking the nodes to form the tree
//     p->left = p1;
//     p->right = p2;
//     p1->left = p3;
//     p1->right = p4;
    
//     int K = 3;  // Find the 3rd smallest element
//     int result = kthSmallest(p, K);
//     printf("The %dth smallest element is %d\n", K, result);
    
//     return 0;
// }
