/*
PROBLEM: N-th Tribonacci Number
Difficulty: Easy
Pattern: 1D DP, Fibonacci Variant

DESCRIPTION:
The Tribonacci sequence Tn is defined as follows:
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.

INPUT:
n = 4

OUTPUT:
4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for dp array, O(1) optimized
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: DP with Tabulation
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        return dp[n];
    }
    
    // Method 2: Space Optimized
    int tribonacciOptimized(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        int prev3 = 0, prev2 = 1, prev1 = 1;
        
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2 + prev3;
            prev3 = prev2;
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
    cout << "Output: " << sol.tribonacci(n1) << endl;
    cout << "Output (Optimized): " << sol.tribonacciOptimized(n1) << endl << endl;
    
    // Test Case 2
    int n2 = 25;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << sol.tribonacci(n2) << endl;
    cout << "Output (Optimized): " << sol.tribonacciOptimized(n2) << endl;
    
    // Print first 10 tribonacci numbers
    cout << "\nFirst 10 Tribonacci numbers: ";
    for (int i = 0; i < 10; i++) {
        cout << sol.tribonacci(i) << " ";
    }
    cout << endl;
    
    return 0;
}

/*
EXPLANATION:
1. Extension of Fibonacci sequence
2. Each number is sum of previous THREE numbers
3. Base cases: T(0) = 0, T(1) = 1, T(2) = 1
4. Recurrence: T(n) = T(n-1) + T(n-2) + T(n-3)
5. Space can be optimized to O(1) by keeping only last 3 values

Sequence: 0, 1, 1, 2, 4, 7, 13, 24, 44, 81...

KEY LEARNING:
- Generalization of Fibonacci pattern
- Same DP principles apply
- Space optimization requires tracking more previous values
- Pattern appears in various counting problems
*/
