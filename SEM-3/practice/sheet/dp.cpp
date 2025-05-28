// 0/1 Knapsack Problem	Given a set of items, each with a weight and a value, determine the maximum value that can be obtained by selecting items such that their total weight is less than or equal to a given limit.
// Unbounded Knapsack Problem	Similar to the 0/1 knapsack, but each item can be selected multiple times.
// Longest Common Subsequence (LCS)	Find the longest subsequence that is common between two strings.
// Longest Increasing Subsequence (LIS)	Find the longest subsequence of a sequence of numbers such that all elements of the subsequence are sorted in increasing order.
// Longest decreasing Subsequence (LIS)	Find the longest subsequence of a sequence of numbers such that all elements of the subsequence are sorted in increasing order.
// Matrix Chain Multiplication	Given a sequence of matrices, find the most efficient way to multiply them together.
// Coin Change Problem	Given a set of coins and a total, find the minimum number of coins needed to make the total.
// Edit Distance	Given two strings, find the minimum number of operations (insertions, deletions, substitutions) required to convert one string into another.
// Subset Sum Problem	Given a set of numbers, determine if there is a subset whose sum equals a given number.
// Partition Problem	Given a set of integers, determine if it can be partitioned into two subsets such that the sums of the subsets are equal.
// Rod Cutting Problem	Given a rod of length n and a list of prices for rods of different lengths, determine the maximum value obtainable by cutting the rod into pieces.
// Fibonacci Sequence	A classic problem where you calculate the nth Fibonacci number using DP.
// Shortest Path in a Grid	Find the shortest path from the top-left corner to the bottom-right corner of a grid, where you can move in any direction.
// Count of Subsets with Sum K	Find the number of subsets of a given set that sum up to a given number.
// 0-1 Knapsack with DP Table	A variation of the 0/1 knapsack problem where a DP table is used to store intermediate results.
// N-th Catalan Number	The N-th number in the Catalan series, which is used to count the number of ways to arrange balanced parentheses or triangulate a polygon.
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

///////////////////////////////////////////////////////////////
// 1. 0/1 Knapsack Problem
///////////////////////////////////////////////////////////////

int knapsack01(vector<int>& weights, vector<int>& values, int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

///////////////////////////////////////////////////////////////
// 2. Unbounded Knapsack Problem
///////////////////////////////////////////////////////////////

int unboundedKnapsack(vector<int>& weights, vector<int>& values, int W, int n) {
    vector<int> dp(W+1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = weights[i]; w <= W; w++) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W];
}

///////////////////////////////////////////////////////////////
// 3. Longest Common Subsequence (LCS)
///////////////////////////////////////////////////////////////

int longestCommonSubsequence(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

///////////////////////////////////////////////////////////////
// 4. Longest Increasing Subsequence (LIS)
///////////////////////////////////////////////////////////////

int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

///////////////////////////////////////////////////////////////
// 5. Longest Decreasing Subsequence (LDS)
///////////////////////////////////////////////////////////////

int longestDecreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] < nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

///////////////////////////////////////////////////////////////
// 6. Matrix Chain Multiplication
///////////////////////////////////////////////////////////////

int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j]);
            }
        }
    }

    return dp[1][n-1];
}

///////////////////////////////////////////////////////////////
// 7. Coin Change Problem
///////////////////////////////////////////////////////////////

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

///////////////////////////////////////////////////////////////
// 8. Edit Distance
///////////////////////////////////////////////////////////////

int editDistance(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }

    return dp[m][n];
}

///////////////////////////////////////////////////////////////
// 9. Subset Sum Problem
///////////////////////////////////////////////////////////////

bool subsetSum(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (nums[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

///////////////////////////////////////////////////////////////
// 10. Partition Problem
///////////////////////////////////////////////////////////////

bool partitionProblem(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    return subsetSum(nums, sum / 2);
}

///////////////////////////////////////////////////////////////
// 11. Rod Cutting Problem
///////////////////////////////////////////////////////////////

int rodCutting(vector<int>& prices, int length) {
    vector<int> dp(length + 1, 0);

    for (int i = 1; i <= length; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], prices[j] + dp[i-j-1]);
        }
    }

    return dp[length];
}

///////////////////////////////////////////////////////////////
// 12. Fibonacci Sequence
///////////////////////////////////////////////////////////////

int fibonacci(int n) {
    if (n <= 1) return n;
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

///////////////////////////////////////////////////////////////
// 13. Shortest Path in a Grid
///////////////////////////////////////////////////////////////

int shortestPathInGrid(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    if (n == 0) return 0;

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = grid[0][0];

    // Initialize first row and column
    for (int i = 1; i < m; i++) {
        if (dp[i-1][0] != INT_MAX)
            dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; j++) {
        if (dp[0][j-1] != INT_MAX)
            dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // Fill DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int min_prev = INT_MAX;
            // Check up
            if (i > 0 && dp[i-1][j] != INT_MAX)
                min_prev = min(min_prev, dp[i-1][j]);
            // Check left
            if (j > 0 && dp[i][j-1] != INT_MAX)
                min_prev = min(min_prev, dp[i][j-1]);
            // Check down (if within bounds)
            if (i < m-1 && dp[i+1][j] != INT_MAX)
                min_prev = min(min_prev, dp[i+1][j]);
            // Check right (if within bounds)
            if (j < n-1 && dp[i][j+1] != INT_MAX)
                min_prev = min(min_prev, dp[i][j+1]);
            if (min_prev != INT_MAX)
                dp[i][j] = min_prev + grid[i][j];
        }
    }

    return dp[m-1][n-1] == INT_MAX ? -1 : dp[m-1][n-1];
}

///////////////////////////////////////////////////////////////
// 14. Count of Subsets with Sum K
///////////////////////////////////////////////////////////////

int countSubsetsWithSumK(vector<int>& nums, int K) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(K+1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) {
            if (nums[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][K];
}

///////////////////////////////////////////////////////////////
// 15. N-th Catalan Number
///////////////////////////////////////////////////////////////

long long catalanNumber(int n) {
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i-1-j];
        }
    }

    return dp[n];
}

///////////////////////////////////////////////////////////////
// MAIN FUNCTION
///////////////////////////////////////////////////////////////

int main() {
    // 1. 0/1 Knapsack Problem
    vector<int> weights = {1, 2, 3};
    vector<int> values = {10, 20, 30};
    int W = 5;
    cout << "0/1 Knapsack Max Value: " << knapsack01(weights, values, W, 3) << endl;

    // 2. Unbounded Knapsack Problem
    cout << "Unbounded Knapsack Max Value: " << unboundedKnapsack(weights, values, W, 3) << endl;

    // 3. Longest Common Subsequence
    cout << "Longest Common Subsequence: " << longestCommonSubsequence("abcde", "ace") << endl;

    // 4. Longest Increasing Subsequence
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "Longest Increasing Subsequence: " << longestIncreasingSubsequence(nums) << endl;

    // 5. Longest Decreasing Subsequence
    cout << "Longest Decreasing Subsequence: " << longestDecreasingSubsequence(nums) << endl;

    // 6. Matrix Chain Multiplication
    vector<int> dims = {1, 2, 3, 4};
    cout << "Matrix Chain Multiplication Cost: " << matrixChainMultiplication(dims) << endl;

    // 7. Coin Change Problem
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum Coins Needed: " << coinChange(coins, amount) << endl;

    // 8. Edit Distance
    cout << "Edit Distance: " << editDistance("sitting", "kitten") << endl;

    // 9. Subset Sum Problem
    cout << "Subset Sum (10): " << (subsetSum(nums, 10) ? "Yes" : "No") << endl;

    // 10. Partition Problem
    cout << "Can Partition (Equal Subset): " << (partitionProblem(nums) ? "Yes" : "No") << endl;

    // 11. Rod Cutting Problem
    vector<int> prices = {1, 5, 8, 9, 10};
    int length = 5;
    cout << "Max Profit (Rod Cutting): " << rodCutting(prices, length) << endl;

    // 12. Fibonacci Sequence
    cout << "Fibonacci(10): " << fibonacci(10) << endl;

    // 13. Shortest Path in a Grid
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Shortest Path in Grid: " << shortestPathInGrid(grid) << endl;

    // 14. Count of Subsets with Sum K
    vector<int> subset_nums = {1, 2, 3, 4};
    int K = 7;
    cout << "Count of Subsets with Sum " << K << ": " << countSubsetsWithSumK(subset_nums, K) << endl;

    // 15. N-th Catalan Number
    int catalan_n = 5;
    cout << "Catalan Number(" << catalan_n << "): " << catalanNumber(catalan_n) << endl;

    return 0;
}