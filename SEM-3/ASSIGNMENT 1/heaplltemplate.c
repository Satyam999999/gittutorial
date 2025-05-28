#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = root;
    struct Node* parent = NULL;

    while (temp != NULL) {
        parent = temp;

        if (temp->left == NULL) {
            parent->left = newNode;
            newNode->parent = parent;
            break;
        }
        else if (temp->right == NULL) {
            parent->right = newNode;
            newNode->parent = parent;
            break;
        } else {
            temp = (temp->left != NULL) ? temp->left : temp->right;
        }
    }

    while (newNode->parent != NULL && newNode->data > newNode->parent->data) {
        swap(&newNode->data, &newNode->parent->data);
        newNode = newNode->parent;
    }

    return root;
}

void heapify(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* largest = root;

    if (root->left && root->left->data > largest->data)
        largest = root->left;

    if (root->right && root->right->data > largest->data)
        largest = root->right;

    if (largest != root) {
        swap(&largest->data, &root->data);
        heapify(largest);
    }
}

struct Node* deleteMax(struct Node* root) {
    if (root == NULL) {
        printf("Heap is empty.\n");
        return NULL;
    }

    struct Node* lastNode = root;
    struct Node* parent = NULL;
    while (lastNode->left != NULL || lastNode->right != NULL) {
        parent = lastNode;
        lastNode = (lastNode->right != NULL) ? lastNode->right : lastNode->left;
    }

    if (parent->left == lastNode)
        parent->left = NULL;
    else
        parent->right = NULL;

    root->data = lastNode->data;
    free(lastNode);

    heapify(root);

    return root;
}
void displayHeap(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    displayHeap(root->left);
    displayHeap(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        root = insert(root, element); // Insert each element into the heap
    }

    printf("Heap after insertion: ");
    displayHeap(root);
    printf("\n");

    printf("Inserting value 50 into the heap.\n");
    root = insert(root, 50);
    printf("Heap after insertion: ");
    displayHeap(root);
    printf("\n");

    printf("Deleting the maximum value from the heap...\n");
    root = deleteMax(root);
    printf("Heap after deletion: ");
    displayHeap(root);
    printf("\n");

    return 0;
}
