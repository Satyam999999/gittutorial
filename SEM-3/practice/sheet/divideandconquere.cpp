// Maximum Subarray (Kadane’s via Divide & Conquer)	Find the contiguous subarray with the maximum sum.
// Closest Pair of Points	Find the smallest distance between two points in a 2D plane.
// Majority Element (Boyer-Moore, or D&C)	Find the element that appears more than n/2 times.
// Count Inversions in Array	Count how far the array is from being sorted.
// Find k-th smallest/largest element	QuickSelect (variant of QuickSort).
// Strassen’s Matrix Multiplication	Faster matrix multiplication using D&C.
// Exponentiation by Squaring	Efficient power calculation using D&C.
// Median of Two Sorted Arrays	Complex but elegant problem solvable with D&C.
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

///////////////////////////////////////////////////////////////
// 1. Maximum Subarray (Divide & Conquer)
///////////////////////////////////////////////////////////////
// Problem: Find the contiguous subarray with the maximum sum using D&C.

int maxCrossingSum(vector<int>& arr, int l, int m, int r) {
    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }
    return leftSum + rightSum;
}

int maxSubArrayDivide(vector<int>& arr, int l, int r) {
    if (l == r) return arr[l];
    int m = (l + r) / 2;
    return max({
        maxSubArrayDivide(arr, l, m),
        maxSubArrayDivide(arr, m + 1, r),
        maxCrossingSum(arr, l, m, r)
    });
}

///////////////////////////////////////////////////////////////
// 2. Count Inversions in Array
///////////////////////////////////////////////////////////////
// Problem: Count pairs (i, j) such that i < j and arr[i] > arr[j]

long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
    int i = l, j = m + 1;
    vector<int> temp;
    long long inv = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else {
            temp.push_back(arr[j++]);
            inv += (m - i + 1);
        }
    }
    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) arr[k] = temp[k - l];
    return inv;
}

long long countInversions(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    return countInversions(arr, l, m) +
           countInversions(arr, m + 1, r) +
           mergeAndCount(arr, l, m, r);
}

///////////////////////////////////////////////////////////////
// 3. Majority Element using Divide and Conquer
///////////////////////////////////////////////////////////////
// Problem: Find the element that appears more than n/2 times in an array.

int majorityHelper(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];
    int m = (l + r) / 2;
    int left = majorityHelper(nums, l, m);
    int right = majorityHelper(nums, m + 1, r);
    if (left == right) return left;

    int lcount = 0, rcount = 0;
    for (int i = l; i <= r; i++) {
        if (nums[i] == left) lcount++;
        else if (nums[i] == right) rcount++;
    }
    return lcount > rcount ? left : right;
}

int findMajority(vector<int>& nums) {
    return majorityHelper(nums, 0, nums.size() - 1);
}

///////////////////////////////////////////////////////////////
// 4. Closest Pair of Points in 2D
///////////////////////////////////////////////////////////////
// Problem: Find the smallest distance between two points in a 2D plane.

struct Point {
    int x, y;
};

bool compareX(Point a, Point b) { return a.x < b.x; }
bool compareY(Point a, Point b) { return a.y < b.y; }

double dist(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double closestInStrip(vector<Point>& strip, double d) {
    double minDist = d;
    sort(strip.begin(), strip.end(), compareY);
    for (int i = 0; i < strip.size(); i++)
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; j++)
            minDist = min(minDist, dist(strip[i], strip[j]));
    return minDist;
}

double closestPairUtil(vector<Point>& Px, vector<Point>& Py, int n) {
    if (n <= 3) {
        double minDist = 1e9;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                minDist = min(minDist, dist(Px[i], Px[j]));
        return minDist;
    }

    int mid = n / 2;
    Point midPoint = Px[mid];

    vector<Point> Pyl, Pyr;
    for (int i = 0; i < n; i++) {
        if (Py[i].x <= midPoint.x) Pyl.push_back(Py[i]);
        else Pyr.push_back(Py[i]);
    }

    double dl = closestPairUtil(Px, Pyl, mid);
    double dr = closestPairUtil(vector<Point>(Px.begin() + mid, Px.end()), Pyr, n - mid);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip.push_back(Py[i]);

    return min(d, closestInStrip(strip, d));
}

double closestPair(vector<Point>& points) {
    vector<Point> Px = points, Py = points;
    sort(Px.begin(), Px.end(), compareX);
    sort(Py.begin(), Py.end(), compareY);
    return closestPairUtil(Px, Py, points.size());
}

///////////////////////////////////////////////////////////////
// 5. Exponentiation by Squaring
///////////////////////////////////////////////////////////////
// Problem: Compute a^b in O(log b) time using divide and conquer.

long long power(long long a, long long b) {
    if (b == 0) return 1;
    long long half = power(a, b / 2);
    return (b % 2 == 0) ? half * half : half * half * a;
}

///////////////////////////////////////////////////////////////
// 6. Median of Two Sorted Arrays (Equal Size)
///////////////////////////////////////////////////////////////
// Problem: Find median of two sorted arrays of the same size using D&C.

double getMedianSingle(vector<int>& arr, int n) {
    return n % 2 == 0 ? (arr[n/2] + arr[n/2 - 1]) / 2.0 : arr[n/2];
}

double findMedianSortedArraysEqual(vector<int>& A, vector<int>& B, int n) {
    if (n == 0) return -1;
    if (n == 1) return (A[0] + B[0]) / 2.0;
    if (n == 2) return (max(A[0], B[0]) + min(A[1], B[1])) / 2.0;

    double m1 = getMedianSingle(A, n);
    double m2 = getMedianSingle(B, n);

    if (m1 == m2) return m1;
    if (m1 < m2) return findMedianSortedArraysEqual(vector<int>(A.begin() + n/2, A.end()),
                                                    vector<int>(B.begin(), B.begin() + n - n/2), n - n/2);
    return findMedianSortedArraysEqual(vector<int>(A.begin(), A.begin() + n - n/2),
                                       vector<int>(B.begin() + n/2, B.end()), n - n/2);
}

///////////////////////////////////////////////////////////////
// MAIN FUNCTION
///////////////////////////////////////////////////////////////

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArrayDivide(arr, 0, arr.size() - 1) << endl;

    vector<int> invArr = {2, 4, 1, 3, 5};
    cout << "Inversion Count: " << countInversions(invArr, 0, invArr.size() - 1) << endl;

    vector<int> majorityArr = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << findMajority(majorityArr) << endl;

    vector<Point> points = {{0, 0}, {1, 1}, {4, 5}, {13, 6}, {7, 8}, {9, 9}};
    cout << "Closest Pair Distance: " << closestPair(points) << endl;

    cout << "Power(2, 10): " << power(2, 10) << endl;

    vector<int> A = {1, 2, 3};
    vector<int> B = {4, 5, 6};
    cout << "Median of Two Arrays: " << findMedianSortedArraysEqual(A, B, A.size()) << endl;

    return 0;
}
