/*
PROBLEM: Unbounded Knapsack
DIFFICULTY: Medium
PATTERN: Unbounded Knapsack (Can use unlimited items)

DESCRIPTION:
Given weights and values of n items, put these items in a knapsack of capacity W.
Unlike 0/1 knapsack, you can use unlimited quantity of each item.
Find the maximum value that can be obtained.

EXAMPLE:
Input:
W = 100
weights = [10, 20, 30]
values = [60, 100, 120]
Output: 300
Explanation: Take 10 items of weight 10 (value = 60 * 10 = 600) 
Wait, that's > 100. Take 5 items of weight 20 (value = 100 * 5 = 500) NO
Actually take weight 30 three times and weight 10 once: 30+30+30+10=100, value=120*3+60=420
Better: weight 20 five times: 20*5=100, value=100*5=500
Best: Check all combinations

Input:
W = 8
weights = [1, 3, 4, 5]
values = [10, 40, 50, 70]
Output: 110
Explanation: Take item with weight 1 eight times OR take weight 4 twice (50*2=100) OR 
Take weight 3 once and weight 5 once (40+70=110) - this is best!

TIME COMPLEXITY: O(n * W)
SPACE COMPLEXITY: O(n * W), can be optimized to O(W)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Bottom-up DP
    int unboundedKnapsack(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                // Don't include current item
                dp[i][w] = dp[i-1][w];
                
                // Include current item (can use multiple times)
                if (weights[i-1] <= w) {
                    // Notice: dp[i][w-weight] not dp[i-1][w-weight]
                    // Because we can use same item again!
                    dp[i][w] = max(dp[i][w], 
                                   values[i-1] + dp[i][w - weights[i-1]]);
                }
            }
        }
        
        return dp[n][W];
    }
    
    // Approach 2: Space Optimized O(W)
    int unboundedKnapsackOptimized(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<int> dp(W+1, 0);
        
        // For each capacity
        for (int w = 1; w <= W; w++) {
            // Try each item
            for (int i = 0; i < n; i++) {
                if (weights[i] <= w) {
                    dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
                }
            }
        }
        
        return dp[W];
    }
    
    // Approach 3: Another way - iterate items first
    int unboundedKnapsack2(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<int> dp(W+1, 0);
        
        for (int i = 0; i < n; i++) {
            // Unlike 0/1 knapsack, go LEFT TO RIGHT
            // Because we can use same item multiple times
            for (int w = weights[i]; w <= W; w++) {
                dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
            }
        }
        
        return dp[W];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    int W1 = 8;
    vector<int> weights1 = {1, 3, 4, 5};
    vector<int> values1 = {10, 40, 50, 70};
    
    cout << "Capacity: " << W1 << endl;
    cout << "Weights: "; for(int w : weights1) cout << w << " "; cout << endl;
    cout << "Values: "; for(int v : values1) cout << v << " "; cout << endl;
    cout << "Maximum value (2D DP): " << sol.unboundedKnapsack(W1, weights1, values1) << endl;
    cout << "Maximum value (1D DP method 1): " << sol.unboundedKnapsackOptimized(W1, weights1, values1) << endl;
    cout << "Maximum value (1D DP method 2): " << sol.unboundedKnapsack2(W1, weights1, values1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    int W2 = 10;
    vector<int> weights2 = {2, 3, 5, 7};
    vector<int> values2 = {1, 5, 2, 4};
    
    cout << "Capacity: " << W2 << endl;
    cout << "Maximum value: " << sol.unboundedKnapsack(W2, weights2, values2) << endl;
    
    return 0;
}

/*
EXPLANATION:

UNBOUNDED KNAPSACK - Can use items UNLIMITED times!

KEY DIFFERENCE from 0/1 Knapsack:
dp[i][w] = max(
    dp[i-1][w],                          // don't use item i
    values[i-1] + dp[i][w - weights[i-1]]   // use item i (NOTE: dp[i] not dp[i-1]!)
)

In 0/1: dp[i-1][w-weight] (previous row - can't reuse)
In Unbounded: dp[i][w-weight] (same row - can reuse!)

SPACE OPTIMIZATION:
In 0/1 knapsack: traverse RIGHT to LEFT (to avoid using updated values)
In Unbounded: traverse LEFT to RIGHT (we WANT to use updated values!)

VARIATIONS OF UNBOUNDED KNAPSACK:
1. Rod Cutting
2. Coin Change (minimum coins)
3. Coin Change II (count ways)
4. Minimum Cost for Tickets

THOUGHT PROCESS:
- Can I use items multiple times? → Unbounded
- Each item used once? → 0/1 Knapsack
- Order matters? → Permutation (different problem)

EXAMPLE WALKTHROUGH:
W = 8, weights = [1, 3, 4, 5], values = [10, 40, 50, 70]

For W=8:
- Use weight 5 once + weight 3 once: 70 + 40 = 110 ✓ BEST
- Use weight 4 twice: 50 + 50 = 100
- Use weight 1 eight times: 10 * 8 = 80
- Use weight 3 twice + weight 1 twice: 40*2 + 10*2 = 100

INTERVIEW TIP:
Always ask: "Can I use items multiple times?" 
This determines if it's 0/1 or Unbounded!

OUTPUT:
Test Case 1:
Capacity: 8
Weights: 1 3 4 5
Values: 10 40 50 70
Maximum value (2D DP): 110
Maximum value (1D DP method 1): 110
Maximum value (1D DP method 2): 110

Test Case 2:
Capacity: 10
Maximum value: 16
*/
