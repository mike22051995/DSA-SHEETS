/*
PROBLEM: Fibonacci Number
Difficulty: Easy
Pattern: 1D DP, Basic Recursion with Memoization

DESCRIPTION:
The Fibonacci numbers form a sequence where each number is the sum of the two preceding ones.
F(0) = 0, F(1) = 1
F(n) = F(n-1) + F(n-2), for n > 1
Given n, calculate F(n).

INPUT:
n = 4

OUTPUT:
3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for dp array, O(1) optimized
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: DP with Tabulation
    int fib(int n) {
        if (n <= 1) return n;
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
    
    // Method 2: Space Optimized
    int fibOptimized(int n) {
        if (n <= 1) return n;
        
        int prev2 = 0, prev1 = 1;
        
        for (int i = 2; i <= n; i++) {
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
    int n1 = 4;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << sol.fib(n1) << endl;
    cout << "Output (Optimized): " << sol.fibOptimized(n1) << endl << endl;
    
    // Test Case 2
    int n2 = 10;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << sol.fib(n2) << endl;
    cout << "Output (Optimized): " << sol.fibOptimized(n2) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. Base cases: F(0) = 0, F(1) = 1
2. For each number from 2 to n, calculate sum of previous two numbers
3. Store results to avoid recalculation (memoization)
4. Optimized version uses only two variables instead of array

KEY LEARNING:
- Basic DP pattern: Build solution from smaller subproblems
- Can optimize space from O(n) to O(1) when only need previous values
*/
