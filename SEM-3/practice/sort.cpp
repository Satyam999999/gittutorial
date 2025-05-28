#include <bits/stdc++.h>
using namespace std;

// Bubble Sort - O(N²)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection Sort - O(N²)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort - O(N²)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort - O(N logN)
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) 
        arr[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort - O(N logN)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort - O(N logN)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Counting Sort - O(N + K)
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0), output(arr.size());

    for (int num : arr) count[num]++;
    for (int i = 1; i <= maxVal; i++) count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    arr = output;
}

// Radix Sort - O(d * (N + K))
void countingSortRadix(vector<int>& arr, int exp) {
    vector<int> output(arr.size()), count(10, 0);
    for (int num : arr) count[(num / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortRadix(arr, exp);
}

// Function to print an array
void printArray(vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// Main function
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Choose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n6. Heap Sort\n7. Counting Sort\n8. Radix Sort\n";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: bubbleSort(arr); break;
        case 2: selectionSort(arr); break;
        case 3: insertionSort(arr); break;
        case 4: mergeSort(arr, 0, arr.size() - 1); break;
        case 5: quickSort(arr, 0, arr.size() - 1); break;
        case 6: heapSort(arr); break;
        case 7: countingSort(arr); break;
        case 8: radixSort(arr); break;
        default: cout << "Invalid choice!\n"; return 0;
    }

    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
