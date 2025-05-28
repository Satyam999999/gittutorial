#include <stdio.h>

#define MAX 100

int heap[MAX];  
int size = 0;   

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i) {
    int largest = i;        
    int left = 2 * i;      
    int right = 2 * i + 1; 

    if (left <= size && heap[left] > heap[largest])
        largest = left;

    if (right <= size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]); 
        heapify(largest);                 
    }
}

void insert(int value) {
    size++;
    heap[size] = value;

    int i = size;
    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]); 
        i = i / 2;                     
    }
}

int deleteMax() {
    if (size < 1) {
        printf("Heap is empty. Cannot delete.\n");
        return -1; 
    }
    int max = heap[1]; 
    heap[1] = heap[size]; 
    size--;               
    heapify(1);         
    return max;        
}

void deleteValue(int value) {
    int i;

    for (i = 1; i <= size; i++) {
        if (heap[i] == value) {
            break;
        }
    }

    if (i > size) {
        printf("Value %d not found in the heap.\n", value);
        return;
    }

    heap[i] = heap[size];
    size--; 
    heapify(i); 

    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}

void buildMaxHeap() {
    for (int i = size / 2; i >= 1; i--) {
        heapify(i);
    }
}

void heapsort() {
    buildMaxHeap(); 
    for (int i = size; i >= 2; i--) {
        swap(&heap[1], &heap[i]); 
        size--;                 
        heapify(1);              
    }
}

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
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        insert(element); 
    }

    printf("Heap after insertion: ");
    displayHeap();

 //  heapsort(); // Perform heapsort

   //printf("Sorted array: ");
    //displayHeap(); // Display sorted array

    printf("Inserting value 50 into the heap.\n");
    insert(50);
    printf("Heap after insertion: ");
    displayHeap();

    printf("Deleting the maximum value from the heap...\n");
    int deletedValue = deleteMax();
    printf("Deleted maximum value: %d\n", deletedValue);
    printf("Heap after deletion: ");
    displayHeap();

    printf("Enter a value to delete from the heap: ");
    scanf("%d", &value);
    deleteValue(value);
    printf("Heap after deleting value %d: ", value);
    displayHeap();

    return 0;
}


 