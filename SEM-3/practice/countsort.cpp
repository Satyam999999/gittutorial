
// void countingSort(vector<int>& arr) {
//     int maxVal = *max_element(arr.begin(), arr.end()); 
//     vector<int> count(maxVal + 1, 0);

//     for (int num : arr) count[num]++; 
//     for (int i = 1; i <= maxVal; i++) count[i] += count[i - 1];

//     vector<int> output(arr.size());
//     for (int i = arr.size() - 1; i >= 0; i--) { 
//         output[count[arr[i]] - 1] = arr[i];
//         count[arr[i]]--;
//     }

//     arr = output; 
// }


// void bucketSort(vector<float>& arr) {
//     int n = arr.size();
//     vector<vector<float>> buckets(n); // Create 'n' empty buckets

//     // Step 1: Place elements into buckets
//     for (float num : arr) {
//         int bucketIndex = num * n; // Scale value into a bucket
//         buckets[bucketIndex].push_back(num);
//     }

//     // Step 2: Sort individual buckets (Using Insertion Sort)
//     for (int i = 0; i < n; i++) {
//         sort(buckets[i].begin(), buckets[i].end()); // Sorting inside each bucket
//     }

//     // Step 3: Merge sorted buckets into the original array
//     int index = 0;
//     for (int i = 0; i < n; i++) {
//         for (float num : buckets[i]) {
//             arr[index++] = num;
//         }
//     }
// }


// 1.
// vector<pair<int, int>> sortEmployeesByLeave(vector<pair<int, int>>& employees) {
//     vector<vector<int>> count(61); // Bucket for each leave count (0 to 60)

//     for (auto& emp : employees) {
//         count[emp.second].push_back(emp.first);
//     }

//     vector<pair<int, int>> result;
//     for (int i = 60; i >= 0; --i) {
//         for (int emp : count[i]) {
//             result.push_back({emp, i});
//         }
//     }
//     return result;
// }


// 2.
// int heightChecker(vector<int>& heights) {
//     vector<int> count(101, 0); // Heights range from 1 to 100

//     for (int h : heights) count[h]++; // Count occurrences

//     vector<int> expected;
//     for (int h = 1; h <= 100; h++) {
//         while (count[h]-- > 0) expected.push_back(h); // Construct sorted order
//     }

//     int mismatches = 0;
//     for (int i = 0; i < heights.size(); i++) {
//         if (heights[i] != expected[i]) mismatches++; // Compare with original
//     }

//     return mismatches;
// }

// 3.string frequencySort(string s) {
//     vector<int> count(128, 0); // ASCII character count

//     for (char c : s) count[c]++; // Count occurrences

//     vector<string> bucket(s.size() + 1, ""); // Bucket index = frequency

//     for (char c = 0; c < 128; c++) {
//         if (count[c] > 0) bucket[count[c]] += string(count[c], c);
//     }

//     string result;
//     for (int i = s.size(); i > 0; --i) {
//         if (!bucket[i].empty()) result += bucket[i];
//     }

//     return result;
// }

// #include <iostream>
// #include <vector>   // Required for vector and range-based for loop
// #include <utility>  // Required for pair
// #include <algorithm>
// using namespace std;

// vector<pair<int, int>> v;

// void countSort(int arr[][2], int n) {
//     int maxi = -1;
//     for (int i = 0; i < n; i++) {
//         if (arr[i][1] > maxi) maxi = arr[i][1];
//     }
//     vector<int> hsh(maxi + 1, 0);
//     for (int i = 0; i < n; i++) {
//         hsh[arr[i][1]]++;
//     }
//     for (int i = maxi; i >= 0; i--) {
//         while (hsh[i] > 0) {
//             for (int j = 0; j < n; j++) {
//                 if (arr[j][1] == i) {
//                     v.push_back({arr[j][0], arr[j][1]});
//                     hsh[i]--;
//                 }
//             }
//         }
//     }
// }

// int maximumUnits(int boxToys[][2], int n, int truckSize) {
//     countSort(boxToys, n);
//     int totalUnits = 0;
//     for (auto& box : v) {
//         if (truckSize <= 0) break;
//         int count = min(box.first, truckSize);
//         totalUnits += count * box.second;
//         truckSize -= count;
//     }
//     return totalUnits;
// }

// int main() {
//     int n; 
//     cin >> n;
//     int boxToys[n][2];
//     int truckSize; 
//     cin >> truckSize;
//     for (int i = 0; i < n; i++) { 
//         cin >> boxToys[i][0];
//         cin >> boxToys[i][1];
//     }
//     int result = maximumUnits(boxToys, n, truckSize);
//     cout << result << endl;
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator to sort books by pages per cost ratio in descending order
bool compare(const pair<int, int>& book1, const pair<int, int>& book2) {
    return (double)book1.second / book1.first > (double)book2.second / book2.first;
}

void findMaxPages(int n, int X, vector<int>& bookPrice, vector<int>& pages) {
    // Step 1: Create a vector of pairs to hold prices and pages together
    vector<pair<int, int>> books;
    for (int i = 0; i < n; i++) {
        books.push_back(make_pair(bookPrice[i], pages[i]));
    }

    // Step 2: Sort books based on pages per cost ratio
    sort(books.begin(), books.end(), compare);

    // Step 3: Greedily pick books
    int maxPages = 0, maxBooks = 0, expenditure = 0;

    for (int i = 0; i < n; i++) {
        if (expenditure + books[i].first <= X) { // If the book fits in the budget
            expenditure += books[i].first;
            maxPages += books[i].second;
            maxBooks++;
        } else {
            break; // Stop when budget is exceeded
        }
    }

    // Step 4: Output results
    cout << "Max Books = " << maxBooks << endl;
    cout << "Max cost of expenditure = " << expenditure << endl;
    cout << "Max Pages = " << maxPages << endl;
}

int main() {
    int n = 4, X = 10;
    vector<int> bookPrice = {4, 8, 5, 3};
    vector<int> pages = {5, 12, 8, 1};

    findMaxPages(n, X, bookPrice, pages);

    return 0;
}

#include <iostream>
#include <cstdlib>

using namespace std;

#define N 16 // Predefined matrix size (must be a power of 2 for Strassen's)

void initializeMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = rand() % 10;
}

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void addMatrix(int A[N][N], int B[N][N], int result[N][N], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(int A[N][N], int B[N][N], int result[N][N], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] - B[i][j];
}

void strassenMultiply(int A[N][N], int B[N][N], int C[N][N], int size) {
    if (size == 2) { 
        // Direct computation for 2x2 matrices
        int a = A[0][0], b = A[0][1], c = A[1][0], d = A[1][1];
        int e = B[0][0], f = B[0][1], g = B[1][0], h = B[1][1];

        C[0][0] = a * e + b * g;
        C[0][1] = a * f + b * h;
        C[1][0] = c * e + d * g;
        C[1][1] = c * f + d * h;
        return;
    }

    int newSize = size / 2;
    int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
    int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
    int C11[N][N], C12[N][N], C21[N][N], C22[N][N];
    int M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];
    int temp1[N][N], temp2[N][N];

    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }

    addMatrix(A11, A22, temp1, newSize);
    addMatrix(B11, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, M1, newSize); 

    addMatrix(A21, A22, temp1, newSize);
    strassenMultiply(temp1, B11, M2, newSize);

    subtractMatrix(B12, B22, temp1, newSize);
    strassenMultiply(A11, temp1, M3, newSize);

    subtractMatrix(B21, B11, temp1, newSize);
    strassenMultiply(A22, temp1, M4, newSize);

    addMatrix(A11, A12, temp1, newSize);
    strassenMultiply(temp1, B22, M5, newSize);

    subtractMatrix(A21, A11, temp1, newSize);
    addMatrix(B11, B12, temp2, newSize);
    strassenMultiply(temp1, temp2, M6, newSize);

    subtractMatrix(A12, A22, temp1, newSize);
    addMatrix(B21, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, M7, newSize);

    addMatrix(M1, M4, temp1, newSize);
    subtractMatrix(temp1, M5, temp2, newSize);
    addMatrix(temp2, M7, C11, newSize);

    addMatrix(M3, M5, C12, newSize);
    addMatrix(M2, M4, C21, newSize);

    addMatrix(M1, M3, temp1, newSize);
    subtractMatrix(temp1, M2, temp2, newSize);
    addMatrix(temp2, M6, C22, newSize);

    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
}

int main() {
    int A[N][N] = {0}, B[N][N] = {0}, C[N][N] = {0};

    initializeMatrix(A);
    initializeMatrix(B);

    cout << "Matrix A:\n";
    printMatrix(A);

    cout << "Matrix B:\n";
    printMatrix(B);

    strassenMultiply(A, B, C, N);

    cout << "Matrix Multiplication using Strassen's Algorithm:\n";
    printMatrix(C);

    return 0;
}
int paddedSize = pow(2, ceil(log2(N)));
int paddedMatrix[paddedSize][paddedSize] = {0};

// Copy original matrix into the padded one
for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
        paddedMatrix[i][j] = originalMatrix[i][j];


        