// // #include <stdio.h>

// // #define MAX 100

// // int heap[MAX];
// // int size = 0;

// // // Function to swap two elements
// // void swap(int *a, int *b) {
// //     int temp = *a;
// //     *a = *b;
// //     *b = temp;
// // }

// // // Function to insert a new element into the heap
// // void insert(int value) {
// //     // Insert at the end of the heap
// //     size++;
// //     heap[size] = value;

// //     // Fix the max heap property if it's violated
// //     int i = size;
// //     while (i > 1 && heap[i] > heap[i / 2]) {
// //         // Swap the new node with its parent until the heap property is restored
// //         swap(&heap[i], &heap[i / 2]);
// //         i = i / 2;
// //     }
// // }

// // // Function to display the heap
// // void displayHeap() {
// //     for (int i = 1; i <= size; i++) {
// //         printf("%d ", heap[i]);
// //     }
// //     printf("\n");
// // }
// // void heapSort() {
// //     // Build the max heap (rearrange array)
// //     for (int i = size / 2 ; i >= 0; i--) {
// //         heapify(i);
// //     }

// //     // One by one, extract elements from the heap
// //     for (int i = size - 1; i > 0; i--) {
// //         // Move current root to the end
// //         swap(&heap[1], &heap[i]);

// //         // Call heapify on the reduced heap
// //         heapify(1);
// //     }
// // }
// // int main() {
// //     insert(10);
// //     insert(20);
// //     insert(15);
// //     insert(30);
// //     insert(40);

// //     printf("Max Heap: ");
// //     displayHeap();
// // heapSort();
// //     displayHeap();

// // }




// // // #include <stdio.h>

// // // void swap(int *a, int *b) {
// // //     int temp = *a;
// // //     *a = *b;
// // //     *b = temp;
// // // }

// // // // Function to heapify a subtree rooted at index i
// // // void heapify(int arr[], int n, int i) {
// // //     int largest = i;  // Initialize largest as root
// // //     int left = 2 * i;  // Left child
// // //     int right = 2 * i + 1; // Right child

// // //     // If left child is larger than root
// // //     if (left < n && arr[left] > arr[largest])
// // //         largest = left;

// // //     // If right child is larger than the largest so far
// // //     if (right < n && arr[right] > arr[largest])
// // //         largest = right;

// // //     // If largest is not root
// // //     if (largest != i) {
// // //         swap(&arr[i], &arr[largest]);
// // //         // Recursively heapify the affected subtree
// // //         heapify(arr, n, largest);
// // //     }
// // // }

// // // // Main function to sort an array using heap sort
// // // void heapSort(int arr[], int n) {
// // //     // Build the max heap (rearrange array)
// // //     for (int i = n / 2 ; i >= 0; i--) {
// // //         heapify(arr, n, i);
// // //     }

// // //     // One by one, extract elements from the heap
// // //     for (int i = n - 1; i > 0; i--) {
// // //         // Move current root to the end
// // //         swap(&arr[0], &arr[i]);

// // //         // Call heapify on the reduced heap
// // //         heapify(arr, i, 0);
// // //     }
// // // }

// // // // Utility function to print the array
// // // void printArray(int arr[], int n) {
// // //     for (int i = 0; i < n; i++)
// // //         printf("%d ", arr[i]);
// // //     printf("\n");
// // // }

// // // int main() {
// // //     int arr[5];
// // //     int n=5;
// // //     for(int i=0;i<n;i++){
// // // scanf("%d",&arr[i]);
// // //     }
    

// // //     printf("Original array: ");
// // //     printArray(arr, n);

// // //     heapSort(arr, n);

// // //     printf("Sorted array: ");
// // //     printArray(arr, n);

// // //     return 0;
// // // }




// // // #include <stdio.h>

// // // #define MAX 100

// // // int heap[MAX];
// // // int size = 0;

// // // // Function to swap two elements
// // // void swap(int *a, int *b) {
// // //     int temp = *a;
// // //     *a = *b;
// // //     *b = temp;
// // // }

// // // // Function to insert a new element into the heap
// // // void insert(int value) {
// // //     // Insert at the end of the heap
// // //     size++;
// // //     heap[size] = value;

// // //     // Fix the max heap property if it's violated
// // //     int i = size;
// // //     while (i > 1 && heap[i] > heap[i / 2]) {
// // //         // Swap the new node with its parent until the heap property is restored
// // //         swap(&heap[i], &heap[i / 2]);
// // //         i = i / 2;
// // //     }
// // // }

// // // // Function to heapify (bubble down) after deletion
// // // void heapify(int i) {
// // //     int largest = i;
// // //     int left = 2 * i;
// // //     int right = 2 * i + 1;

// // //     // If left child is larger than root
// // //     if (left <= size && heap[left] > heap[largest])
// // //         largest = left;

// // //     // If right child is larger than largest so far
// // //     if (right <= size && heap[right] > heap[largest])
// // //         largest = right;

// // //     // If largest is not root
// // //     if (largest != i) {
// // //         swap(&heap[i], &heap[largest]);
// // //         heapify(largest);
// // //     }
// // // }

// // // // Function to delete a specific value from the heap
// // // void deleteValue(int value) {
// // //     int i;

// // //     // Find the index of the value to delete
// // //     for (i = 1; i <= size; i++) {
// // //         if (heap[i] == value) {
// // //             break;
// // //         }
// // //     }

// // //     if (i > size) {
// // //         printf("Value not found in the heap.\n");
// // //         return;
// // //     }

// // //     // Replace the element with the last element in the heap
// // //     heap[i] = heap[size];
// // //     size--;

// // //     // Fix the heap property by heapifying
// // //     heapify(i);
// // //     // In case the replaced element is smaller, we may need to bubble it up
// // //     while (i > 1 && heap[i] > heap[i / 2]) {
// // //         swap(&heap[i], &heap[i / 2]);
// // //         i = i / 2;
// // //     }
// // // }

// // // // Function to display the heap
// // // void displayHeap() {
// // //     for (int i = 1; i <= size; i++) {
// // //         printf("%d ", heap[i]);
// // //     }
// // //     printf("\n");
// // // }

// // // int main() {
// // //     int n, value;

// // //     // Insert values into the heap
// // //     insert(40);
// // //     insert(30);
// // //     insert(15);
// // //     insert(20);
// // //     insert(10);

// // //     printf("Max Heap before deletion: ");
// // //     displayHeap();

// // //     // Delete the value 30
// // //     printf("Deleting 30 from the heap...\n");
// // //     deleteValue(30);

// // //     printf("Max Heap after deletion: ");
// // //     displayHeap();

// // //     return 0;
// // // }



// // // #include <stdio.h>

// // // #define MAX 100

// // // int heap[MAX];
// // // int size = 0;

// // // // Function to swap two elements
// // // void swap(int *a, int *b) {
// // //     int temp = *a;
// // //     *a = *b;
// // //     *b = temp;
// // // }

// // // // Function to heapify (bubble down) from a given index
// // // void heapify(int i) {
// // //     int largest = i;
// // //     int left = 2 * i;    // Left child index
// // //     int right = 2 * i + 1; // Right child index

// // //     // If left child is larger than root
// // //     if (left <= size && heap[left] > heap[largest])
// // //         largest = left;

// // //     // If right child is larger than largest so far
// // //     if (right <= size && heap[right] > heap[largest])
// // //         largest = right;

// // //     // If largest is not root
// // //     if (largest != i) {
// // //         swap(&heap[i], &heap[largest]);
// // //         heapify(largest); // Recursively heapify the affected sub-tree
// // //     }
// // // }

// // // // Function to build a max heap from the input array
// // // void buildMaxHeap() {
// // //     // Start from the last non-leaf node and heapify each node
// // //     for (int i = size / 2-1; i >= 1; i--) {
// // //         heapify(i);
// // //     }
// // // }

// // // // Heapsort function
// // // void heapsort() {
// // //     buildMaxHeap(); // Build a max heap

// // //     // One by one extract elements from the heap
// // //     for (int i = size; i >= 2; i--) {
// // //         // Move current root to the end
// // //         swap(&heap[1], &heap[i]);
// // //         size--; // Reduce the heap size
// // //         heapify(1); // Heapify the root
// // //     }
// // // }

// // // // Function to display the array
// // // void displayArray() {
// // //     for (int i = 1; i <= size; i++) {
// // //         printf("%d ", heap[i]);
// // //     }
// // //     printf("\n");
// // // }

// // // int main() {
// // //     // Sample input array (1-based index)
// // //     int n;

// // //     printf("Enter the number of elements: ");
// // //     scanf("%d", &n);
    
// // //     // Input elements into the heap starting from index 1
// // //     printf("Enter %d elements:\n", n);
// // //     size = n; // Set the size
// // //     for (int i = 1; i <= size; i++) {
// // //         scanf("%d", &heap[i]);
// // //     }

// // //     printf("Array before sorting: ");
// // //     displayArray();

// // //     heapsort(); // Perform heapsort

// // //     printf("Sorted array: ");
// // //     displayArray(); // Display sorted array

// // //     return 0;
// // // }


// #include <stdio.h>

// #define MAX 100

// int heap[MAX];  // Array to store the heap
// int size = 0;   // Current size of the heap

// // Function to swap two elements
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Function to heapify (bubble down) from a given index
// void heapify(int i) {
//     int largest = i;        // Initialize largest as root
//     int left = 2 * i;      // Left child index
//     int right = 2 * i + 1; // Right child index

//     // If left child is larger than root
//     if (left <= size && heap[left] > heap[largest])
//         largest = left;

//     // If right child is larger than largest so far
//     if (right <= size && heap[right] > heap[largest])
//         largest = right;

//     // If largest is not root
//     if (largest != i) {
//         swap(&heap[i], &heap[largest]); // Swap root with largest
//         heapify(largest);                 // Recursively heapify the affected sub-tree
//     }
// }

// // Function to insert a new element into the heap
// void insert(int value) {
//     // Insert the new value at the end of the heap
//     size++;
//     heap[size] = value;

//     // Fix the max heap property if it's violated
//     int i = size;
//     while (i > 1 && heap[i] > heap[i / 2]) {
//         swap(&heap[i], &heap[i / 2]); // Swap with parent
//         i = i / 2;                     // Move up to parent index
//     }
// }

// // Function to delete the maximum element (root) from the heap
// int deleteMax() {
//     if (size < 1) {
//         printf("Heap is empty. Cannot delete.\n");
//         return -1; // Indicate that deletion failed
//     }
//     int max = heap[1]; // Get the maximum element (root)
//     heap[1] = heap[size]; // Replace root with last element
//     size--;               // Reduce the heap size
//     heapify(1);          // Heapify from root
//     return max;          // Return the deleted max value
// }

// // Function to delete a specific value from the heap
// void deleteValue(int value) {
//     int i;

//     // Find the index of the value to delete
//     for (i = 1; i <= size; i++) {
//         if (heap[i] == value) {
//             break;
//         }
//     }

//     if (i > size) {
//         printf("Value %d not found in the heap.\n", value);
//         return;
//     }

//     // Replace the element with the last element in the heap
//     heap[i] = heap[size];
//     size--; // Reduce the heap size
//     heapify(i); // Fix the heap property by heapifying

//     // In case the replaced element is larger, we may need to bubble it up
//     while (i > 1 && heap[i] > heap[i / 2]) {
//         swap(&heap[i], &heap[i / 2]);
//         i = i / 2;
//     }
// }

// // Function to build a max heap from the input array
// void buildMaxHeap() {
//     for (int i = size / 2; i >= 1; i--) {
//         heapify(i);
//     }
// }

// // Heapsort function
// void heapsort() {
//     buildMaxHeap(); // Build max heap

//     // One by one extract elements from the heap
//     for (int i = size; i >= 2; i--) {
//         swap(&heap[1], &heap[i]); // Move current root to the end
//         size--;                   // Reduce the heap size
//         heapify(1);               // Heapify the root
//     }
// }

// // Function to display the heap
// void displayHeap() {
//     for (int i = 1; i <= size; i++) {
//         printf("%d ", heap[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int n, value;

//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
    
//     // Input elements into the heap starting from index 1
//     printf("Enter %d elements:\n", n);
//     size = n; // Set the size
//     for (int i = 1; i <= size; i++) {
//         scanf("%d", &heap[i]);
//     }

//     printf("Array before sorting: ");
//     displayHeap();

//     heapsort(); // Perform heapsort

//     printf("Sorted array: ");
//     displayHeap(); // Display sorted array

//     // Example of inserting a value
//     printf("Inserting value 50 into the heap.\n");
//     insert(50);
//     printf("Heap after insertion: ");
//     displayHeap();

//     // Example of deleting the maximum value
//     printf("Deleting the maximum value from the heap...\n");
//     int deletedValue = deleteMax();
//     printf("Deleted maximum value: %d\n", deletedValue);
//     printf("Heap after deletion: ");
//     displayHeap();

//     // Example of deleting a specific value
//     printf("Enter a value to delete from the heap: ");
//     scanf("%d", &value);
//     deleteValue(value);
//     printf("Heap after deleting value %d: ", value);
//     displayHeap();

//     return 0;
// }



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
    
    // Input elements into the heap starting from index 1
    printf("Enter %d elements:\n", n);
    size = n; // Set the size
    for (int i = 1; i <= size; i++) {
        scanf("%d", &heap[i]);
    }

    printf("Array before sorting: ");
    displayHeap();

    // Save the original size for displaying the sorted array
    int originalSize = size;

   // heapsort(); // Perform heapsort

    printf("Sorted array: ");
    for (int i = 1; i <= originalSize; i++) { // Use original size for display
        printf("%d ", heap[i]);
    }
    printf("\n");

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

