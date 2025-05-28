#include<iostream>
using namespace std;

int main() {
    int size;
    cin >> size;
    int arr[size];
    int arr1[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        arr1[i]=arr[i];
    }
    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max+1];
     for (int i = 0; i < size; i++) {
        count[i]=0;
    }

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    int counter = 0;
    int ans[size];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != arr1[i]) {
            ans[j++] = i;
            counter++;
        }
    }

    cout << "number of mismatches: " << counter << endl;
    cout << "mismatched indices: ";
    for (int i = 0; i < j; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}