#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int robLinear(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    
    return dp[n-1];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    
    vector<int> nums1(nums.begin(), nums.end() - 1);
    vector<int> nums2(nums.begin() + 1, nums.end());
    
    return max(robLinear(nums1), robLinear(nums2));
}

int main() {
    vector<int> nums1 = {2, 3, 2};
    vector<int> nums2 = {1, 2, 3, 1};
    vector<int> nums3 = {1, 2, 3};
    
    cout << "Max money for [2, 3, 2]: " << rob(nums1) << endl;  // Output: 3
    cout << "Max money for [1, 2, 3, 1]: " << rob(nums2) << endl;  // Output: 4
    cout << "Max money for [1, 2, 3]: " << rob(nums3) << endl;  // Output: 3
    
    return 0;
}
