#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

    for (int i = 0; i <= n; ++i) dp[i][0] = true;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= sum; ++j)
            if (nums[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            else
                dp[i][j] = dp[i-1][j];

    return dp[n][sum];
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << (isSubsetSum(nums, sum) ? "Subset found." : "No subset found.") << endl;
    return 0;
}
