// #include<stdio.h>

// void printArray(int* A, int n){
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", A[i]);
//     }
//     printf("\n");
// }

// // for j ← 2 to n
// // do key ← A[ j ]
// // Insert A[ j ] into the sorted sequence A[1 . . j -1]
// // i ← j - 1
// // while (i > 0 and A[i] > key)
// // do A[i + 1] ← A[i]
// // i ← i – 1
// // A[i + 1] ← key
// void insertionSort(int *A, int n){
//     int key, j;
//     // Loop for passes
//     for (int i = 1; i <= n-1; i++)
//     {
//         key = A[i];
//         j = i-1;
//         // Loop for each pass
//         while(j>=0 && A[j] > key){
//             A[j+1] = A[j];
//             j--;
//         }
//         A[j+1] = key;
//     }
// }

// int main(){
//    // -1   0    1   2   3   4   5
//    //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
//    //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

//    //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
//    //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

//    //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
//    //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
//    //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
//    //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
//    //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

//    // Fast forwarding and 4th and 5th pass will give:
//    //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
//    //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

//    //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
//    //      07, 09, 12, 23, 54, 65| --> After the 5th pass 
    
//     int A[] = {12, 54, 65, 7, 23, 9};
//     int n = 6;
//     printArray(A, n);
//     insertionSort(A, n);
//     printArray(A, n);
//     return 0;
// }


// #include <stdio.h>

// void selectionSort(int A[], int n) {
//     int j, i, smallest, temp;

//     // Outer loop: Move the boundary of the unsorted part of the array
//     for (j = 0; j < n - 1; j++) {
//         // Assume the first element of the unsorted part is the smallest
//         smallest = j;

//         // Inner loop: Find the smallest element in the unsorted part
//         for (i = j + 1; i < n; i++) {
//             if (A[i] < A[smallest]) {
//                 smallest = i;
//             }
//         }

//         // Exchange A[j] ↔ A[smallest] if needed
//         if (smallest != j) {
//             temp = A[j];
//             A[j] = A[smallest];
//             A[smallest] = temp;
//         }
//     }
// }

// // Function to print the array
// void printArray(int A[], int n) {
//     for (int i = 0; i < n; i++) {
//         printf("%d ", A[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int A[] = {64, 25, 12, 22, 11};
//     int n = sizeof(A) / sizeof(A[0]);

//     printf("Original array: \n");
//     printArray(A, n);

//     selectionSort(A, n);

//     printf("Sorted array: \n");
//     printArray(A, n);

//     return 0;
// }




#include <stdio.h>

// Function to merge two subarrays of A[]
// First subarray is A[l..mid]
// Second subarray is A[mid+1..r]
void merge(int A[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    
    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + 1 + i];
    }

    // Merge the temporary arrays back into A[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort on array A[]
void mergeSort(int A[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;  // Find the middle point

        // Recursively sort first and second halves
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);

        // Merge the sorted halves
        merge(A, l, mid, r);
    }
}

// Function to print the array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int A[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(A) / sizeof(A[0]);

    printf("Given array is \n");
    printArray(A, arr_size);

    mergeSort(A, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(A, arr_size);
    return 0;
}


// #include <stdio.h>
// #include <limits.h> // For INT_MAX

// // Merge function to merge two sorted subarrays A[p..q] and A[q+1..r]
// void merge(int A[], int p, int q, int r) {
//     int n1 = q - p + 1;  // Size of left subarray
//     int n2 = r - q;      // Size of right subarray

//     // Create temporary arrays L[] and R[]
//     int L[n1 + 1], R[n2 + 1];

//     // Copy data into L[] and R[]
//     for (int i = 0; i < n1; i++) {
//         L[i] = A[p + i];
//     }
//     for (int j = 0; j < n2; j++) {
//         R[j] = A[q + 1 + j];
//     }

//     // Add sentinel values (∞) at the end of L[] and R[] arrays
//     L[n1] = INT_MAX;
//     R[n2] = INT_MAX;

//     int i = 0, j = 0;

//     // Merge the temporary arrays back into A[p..r]
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j]) {
//             A[k] = L[i];
//             i++;
//         } else {
//             A[k] = R[j];
//             j++;
//         }
//     }
// }

// // MergeSort function to recursively divide and sort the array A[p..r]
// void mergeSort(int A[], int p, int r) {
//     if (p < r) {
//         int q = (p + r) / 2;  // Find the middle point

//         // Recursively sort first and second halves
//         mergeSort(A, p, q);
//         mergeSort(A, q + 1, r);

//         // Merge the sorted halves
//         merge(A, p, q, r);
//     }
// }

// // Function to print the array
// void printArray(int A[], int size) {
//     for (int i = 0; i < size; i++) {
//         printf("%d ", A[i]);
//     }
//     printf("\n");
// }

// // Driver code
// int main() {
//     int A[] = {12, 11, 13, 5, 6, 7};
//     int arr_size = sizeof(A) / sizeof(A[0]);

//     printf("Given array is \n");
//     printArray(A, arr_size);

//     mergeSort(A, 0, arr_size - 1);

//     printf("\nSorted array is \n");
//     printArray(A, arr_size);
    
//     return 0;
// }#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that returns the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = (low - 1);  // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap the pivot element with the element at i+1 (correct position for pivot)
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}




