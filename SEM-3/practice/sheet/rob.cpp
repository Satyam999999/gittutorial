#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper to solve normal linear house robber
int robLinear(vector<int>& nums, int start, int end) {
    int prev1 = 0, prev2 = 0;
    for (int i = start; i <= end; ++i) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Case 1: Exclude last house
    int max1 = robLinear(nums, 0, n - 2);
    // Case 2: Exclude first house
    int max2 = robLinear(nums, 1, n - 1);

    return max(max1, max2);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << "Maximum money that can be robbed: " << rob(nums) << endl;
    return 0;
}
