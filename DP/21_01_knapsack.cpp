/*
PROBLEM: 0/1 Knapsack Problem
DIFFICULTY: Medium
PATTERN: 0/1 Knapsack (FUNDAMENTAL DP PATTERN)

DESCRIPTION:
Given weights and values of n items, put these items in a knapsack of capacity W 
to get the maximum total value in the knapsack.
Note: You cannot break an item (0/1 choice - take it or leave it).

EXAMPLE:
Input: 
W = 50 (capacity)
weights = [10, 20, 30]
values = [60, 100, 120]
Output: 220
Explanation: Take items with weight 20 and 30 (value = 100 + 120 = 220)

Input:
W = 10
weights = [5, 4, 6, 3]
values = [10, 40, 30, 50]
Output: 90
Explanation: Take items with weight 4 and 3 (value = 40 + 50 = 90)

TIME COMPLEXITY: O(n * W)
SPACE COMPLEXITY: O(n * W), optimized to O(W)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive (with memoization)
    int knapsackHelper(int W, vector<int>& weights, vector<int>& values, int n, 
                       vector<vector<int>>& dp) {
        // Base case: no items left or capacity is 0
        if (n == 0 || W == 0) return 0;
        
        // If already computed
        if (dp[n][W] != -1) return dp[n][W];
        
        // If weight of nth item is more than capacity, can't include it
        if (weights[n-1] > W) {
            return dp[n][W] = knapsackHelper(W, weights, values, n-1, dp);
        }
        
        // Return max of two cases:
        // 1. nth item included
        // 2. nth item not included
        int include = values[n-1] + knapsackHelper(W - weights[n-1], weights, values, n-1, dp);
        int exclude = knapsackHelper(W, weights, values, n-1, dp);
        
        return dp[n][W] = max(include, exclude);
    }
    
    int knapsackMemo(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return knapsackHelper(W, weights, values, n, dp);
    }
    
    // Approach 2: Bottom-up DP (MOST IMPORTANT FOR INTERVIEWS)
    int knapsack(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        // Build table dp[][] in bottom-up manner
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                // If current item can be included
                if (weights[i-1] <= w) {
                    // Max of including or excluding current item
                    dp[i][w] = max(
                        values[i-1] + dp[i-1][w - weights[i-1]],  // include
                        dp[i-1][w]                                 // exclude
                    );
                } else {
                    // Can't include, take value without this item
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        
        return dp[n][W];
    }
    
    // Approach 3: Space Optimized O(W)
    int knapsackOptimized(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<int> dp(W+1, 0);
        
        for (int i = 0; i < n; i++) {
            // Traverse from right to left to avoid using updated values
            for (int w = W; w >= weights[i]; w--) {
                dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
            }
        }
        
        return dp[W];
    }
    
    // Print which items are selected
    void printItems(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        // Build DP table
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (weights[i-1] <= w) {
                    dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], 
                                   dp[i-1][w]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        
        // Backtrack to find items
        cout << "Selected items: ";
        int w = W;
        for (int i = n; i > 0 && w > 0; i--) {
            // If value comes from including current item
            if (dp[i][w] != dp[i-1][w]) {
                cout << i << " ";
                w -= weights[i-1];
            }
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int W1 = 50;
    vector<int> weights1 = {10, 20, 30};
    vector<int> values1 = {60, 100, 120};
    
    cout << "Test Case 1:" << endl;
    cout << "Capacity: " << W1 << endl;
    cout << "Weights: "; for(int w : weights1) cout << w << " "; cout << endl;
    cout << "Values: "; for(int v : values1) cout << v << " "; cout << endl;
    cout << "Maximum value (Bottom-up): " << sol.knapsack(W1, weights1, values1) << endl;
    cout << "Maximum value (Memoization): " << sol.knapsackMemo(W1, weights1, values1) << endl;
    cout << "Maximum value (Optimized): " << sol.knapsackOptimized(W1, weights1, values1) << endl;
    sol.printItems(W1, weights1, values1);
    
    cout << "\nTest Case 2:" << endl;
    int W2 = 10;
    vector<int> weights2 = {5, 4, 6, 3};
    vector<int> values2 = {10, 40, 30, 50};
    
    cout << "Capacity: " << W2 << endl;
    cout << "Maximum value: " << sol.knapsack(W2, weights2, values2) << endl;
    sol.printItems(W2, weights2, values2);
    
    return 0;
}

/*
EXPLANATION:

0/1 KNAPSACK - MOST IMPORTANT DP PATTERN!

State Definition:
dp[i][w] = maximum value achievable with first i items and capacity w

Recurrence Relation:
dp[i][w] = max(
    dp[i-1][w],                           // don't include item i
    values[i-1] + dp[i-1][w - weights[i-1]]  // include item i
)

Base Case:
dp[0][w] = 0 (no items)
dp[i][0] = 0 (no capacity)

DECISION TREE:
For each item, we have 2 choices:
1. Include it (if weight allows) → get its value + solve for remaining capacity
2. Exclude it → solve without this item

WHY THIS PATTERN IS CRITICAL:
Many problems can be reduced to 0/1 knapsack:
- Subset sum
- Partition equal subset sum
- Target sum
- Count of subset sum
- Minimum subset sum difference

SPACE OPTIMIZATION:
We only need previous row, so can use 1D array.
IMPORTANT: Traverse from right to left to avoid overwriting needed values.

TIPS FOR INTERVIEW:
1. Always clarify: 0/1 (can't repeat) or unbounded (can repeat)?
2. Draw the DP table for small example
3. Explain the choice: include or exclude
4. Mention space optimization if time permits

OUTPUT:
Test Case 1:
Capacity: 50
Weights: 10 20 30
Values: 60 100 120
Maximum value (Bottom-up): 220
Maximum value (Memoization): 220
Maximum value (Optimized): 220
Selected items: 3 2

Test Case 2:
Capacity: 10
Maximum value: 90
Selected items: 4 2
*/
