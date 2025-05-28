#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
int maxi(vector<int>& arr, int prevIndex, int currIndex) {
    
    if (currIndex == arr.size()) {
        return 0;
    }

    int exclude = maxi(arr, prevIndex, currIndex + 1);

    int include = 0;
    if (prevIndex == -1 || arr[currIndex] > arr[prevIndex]) {
        include = 1 + maxi(arr, currIndex, currIndex + 1);
    }

    return max(exclude, include);
}

int func(vector<int>& arr) {
    return maxi(arr, -1, 0); 
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int lisLength = func(arr);

        cout << (N - lisLength) << endl;
    }

    return 0;
}