"""
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
"""

from typing import List

class Solution:
    # Method 1: DP with Tabulation
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        
        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 1
        
        for i in range(2, n + 1):
            dp[i] = dp[i-1] + dp[i-2]
        
        return dp[n]
    
    # Method 2: Space Optimized
    def fibOptimized(self, n: int) -> int:
        if n <= 1:
            return n
        
        prev2 = 0
        prev1 = 1
        
        for i in range(2, n + 1):
            curr = prev1 + prev2
            prev2 = prev1
            prev1 = curr
        
        return prev1


if __name__ == "__main__":
    sol = Solution()
    
    # Test Case 1
    n1 = 4
    print(f"Input: n = {n1}")
    print(f"Output: {sol.fib(n1)}")
    print(f"Output (Optimized): {sol.fibOptimized(n1)}\n")
    
    # Test Case 2
    n2 = 10
    print(f"Input: n = {n2}")
    print(f"Output: {sol.fib(n2)}")
    print(f"Output (Optimized): {sol.fibOptimized(n2)}")
