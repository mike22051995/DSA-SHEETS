/*
PROBLEM: Min Cost Climbing Stairs
Difficulty: Easy
Pattern: 1D DP, Cost Minimization

DESCRIPTION:
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

INPUT:
cost = [10, 15, 20]

OUTPUT:
15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for dp array, O(1) optimized
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Method 1: DP Tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        
        dp[0] = 0; // No cost to start at position 0
        dp[1] = 0; // No cost to start at position 1
        
        for (int i = 2; i <= n; i++) {
            // Min cost to reach step i = min of:
            // - Coming from step (i-1) and paying cost[i-1]
            // - Coming from step (i-2) and paying cost[i-2]
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        return dp[n];
    }
    
    // Method 2: Space Optimized
    int minCostClimbingStairsOptimized(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0, prev1 = 0;
        
        for (int i = 2; i <= n; i++) {
            int curr = min(prev1 + cost[i-1], prev2 + cost[i-2]);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> cost1 = {10, 15, 20};
    cout << "Input: cost = [10, 15, 20]" << endl;
    cout << "Output: " << sol.minCostClimbingStairs(cost1) << endl;
    cout << "Output (Optimized): " << sol.minCostClimbingStairsOptimized(cost1) << endl << endl;
    
    // Test Case 2
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]" << endl;
    cout << "Output: " << sol.minCostClimbingStairs(cost2) << endl;
    cout << "Output (Optimized): " << sol.minCostClimbingStairsOptimized(cost2) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. dp[i] represents minimum cost to reach step i
2. At each step, choose the minimum between:
   - Coming from previous step (i-1) and paying its cost
   - Coming from two steps back (i-2) and paying its cost
3. Start positions (0 and 1) have no initial cost
4. Final answer is dp[n] (top of stairs, beyond last step)

KEY LEARNING:
- Cost minimization variant of climbing stairs
- Make optimal decision at each step
- Can start from index 0 or 1 (both free)
*/
