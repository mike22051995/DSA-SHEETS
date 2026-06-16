/*
PROBLEM: Climbing Stairs
Difficulty: Easy
Pattern: 1D DP, Fibonacci Variant

DESCRIPTION:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

INPUT:
n = 3

OUTPUT:
3
Explanation: Three ways to climb to the top:
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for dp array, O(1) optimized
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: DP Tabulation
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        vector<int> dp(n + 1);
        dp[1] = 1; // 1 way to reach step 1
        dp[2] = 2; // 2 ways to reach step 2
        
        for (int i = 3; i <= n; i++) {
            // Ways to reach step i = ways to reach (i-1) + ways to reach (i-2)
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
    
    // Method 2: Space Optimized
    int climbStairsOptimized(int n) {
        if (n <= 2) return n;
        
        int prev2 = 1, prev1 = 2;
        
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 3;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << sol.climbStairs(n1) << endl;
    cout << "Output (Optimized): " << sol.climbStairsOptimized(n1) << endl << endl;
    
    // Test Case 2
    int n2 = 5;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << sol.climbStairs(n2) << endl;
    cout << "Output (Optimized): " << sol.climbStairsOptimized(n2) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. To reach step i, you can come from step (i-1) or step (i-2)
2. Total ways to reach step i = ways(i-1) + ways(i-2)
3. This is essentially Fibonacci sequence starting from different base values
4. dp[i] stores the number of ways to reach step i

KEY LEARNING:
- Classic 1D DP problem
- Identify recurrence relation: dp[i] = dp[i-1] + dp[i-2]
- Space optimization using previous two values only
*/
