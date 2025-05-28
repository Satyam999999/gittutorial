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
// int height(struct node* root) {
//     if (root == NULL) {
//         return 0; // Height of an empty tree is -1 (or 0 if you prefer)
//     }
    
//     // Recursively calculate the height of left and right subtrees
//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
    
//     // Height of the current node is 1 + the greater of the two subtree heights
//     return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
// }
// struct node* insert(struct node* root, int data) {
//     // Base case: If the tree is empty, return a new node
//     if (root == NULL) {
//         return createNode(data);
//     }
    
//     // Otherwise, recur down the tree
//     if (data < root->data) {
//         root->left = insert(root->left, data);
//     }
//     else if (data > root->data) {
//         root->right = insert(root->right, data);
//     }
    
//     // Return the (unchanged) node pointer
//     return root;
// }
// int findMin(struct Node* root) {
//     if (root == NULL) {
//         return INT_MAX; // Return a large value if the tree is empty
//     }
    
//     // Get the minimum value from the left subtree
//     int minValue = findMin(root->left);
    
//     // Return the minimum of the current node's data and the minimum from the left subtree
//     return root->data < minValue ? root->data : minValue;
// }

// // Function to find the maximum value in the binary tree
// int findMax(struct Node* root) {
//     if (root == NULL) {
//         return INT_MIN; // Return a small value if the tree is empty
//     }
    
//     // Get the maximum value from the right subtree
//     int maxValue = findMax(root->right);
    
//     // Return the maximum of the current node's data and the maximum from the right subtree
//     return root->data > maxValue ? root->data : maxValue;
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