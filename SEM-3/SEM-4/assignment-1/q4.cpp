#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> relativeSort(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> count;

    // Step 1: Count frequency of each number in arr1
    for (int num : arr1) {
        count[num]++;
    }

    vector<int> result;

    // Step 2: Add elements in arr2 order
    for (int num : arr2) {
        while (count[num] > 0) {
            result.push_back(num);
            count[num]--;
        }
    }

    // Step 3: Collect remaining elements
    vector<int> remaining;
    for (auto& it : count) {
        while (it.second > 0) {
            remaining.push_back(it.first);
            it.second--;
        }
    }

    // Step 4: Sort remaining and add to result
    sort(remaining.begin(), remaining.end());
    for (int num : remaining) {
        result.push_back(num);
    }

    return result;
}
