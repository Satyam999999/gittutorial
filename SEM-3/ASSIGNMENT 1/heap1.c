#include <stdio.h>

#define MAX 100

int heap[MAX];  // Array to store the heap
int size = 0;   // Current size of the heap

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify (bubble down) from a given index
void heapify(int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i;      // Left child index
    int right = 2 * i + 1; // Right child index

    // If left child is larger than root
    if (left <= size && heap[left] > heap[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right <= size && heap[right] > heap[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&heap[i], &heap[largest]); // Swap root with largest
        heapify(largest);                 // Recursively heapify the affected sub-tree
    }
}

// Function to insert a new element into the heap
void insert(int value) {
    // Insert the new value at the end of the heap
    size++;
    heap[size] = value;

    // Fix the max heap property if it's violated
    int i = size;
    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]); // Swap with parent
        i = i / 2;                     // Move up to parent index
    }
}

// Function to delete the maximum element (root) from the heap
int deleteMax() {
    if (size < 1) {
        printf("Heap is empty. Cannot delete.\n");
        return -1; // Indicate that deletion failed
    }
    int max = heap[1]; // Get the maximum element (root)
    heap[1] = heap[size]; // Replace root with last element
    size--;               // Reduce the heap size
    heapify(1);          // Heapify from root
    return max;          // Return the deleted max value
}

// Function to delete a specific value from the heap
void deleteValue(int value) {
    int i;

    // Find the index of the value to delete
    for (i = 1; i <= size; i++) {
        if (heap[i] == value) {
            break;
        }
    }

    if (i > size) {
        printf("Value %d not found in the heap.\n", value);
        return;
    }

    // Replace the element with the last element in the heap
    heap[i] = heap[size];
    size--; // Reduce the heap size
    heapify(i); // Fix the heap property by heapifying

    // In case the replaced element is larger, we may need to bubble it up
    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

// Function to build a max heap from the input array
void buildMaxHeap() {
    for (int i = size / 2; i >= 1; i--) {
        heapify(i);
    }
}

// Heapsort function
void heapsort() {
    buildMaxHeap(); // Build max heap

    // One by one extract elements from the heap
    for (int i = size; i >= 2; i--) {
        swap(&heap[1], &heap[i]); // Move current root to the end
        size--;                   // Reduce the heap size
        heapify(1);               // Heapify the root
    }
}

// Function to display the heap
void displayHeap() {
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input elements into the heap using the insert function
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        insert(element); // Insert each element into the heap
    }

    printf("Heap after insertion: ");
    displayHeap();

 //  heapsort(); // Perform heapsort

   //printf("Sorted array: ");
    //displayHeap(); // Display sorted array

    // Example of inserting a value
    printf("Inserting value 50 into the heap.\n");
    insert(50);
    printf("Heap after insertion: ");
    displayHeap();

    // Example of deleting the maximum value
    printf("Deleting the maximum value from the heap...\n");
    int deletedValue = deleteMax();
    printf("Deleted maximum value: %d\n", deletedValue);
    printf("Heap after deletion: ");
    displayHeap();

    // Example of deleting a specific value
    printf("Enter a value to delete from the heap: ");
    scanf("%d", &value);
    deleteValue(value);
    printf("Heap after deleting value %d: ", value);
    displayHeap();

    return 0;
}


