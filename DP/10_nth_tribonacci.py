"""
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
"""

from typing import List, Optional

class Solution:
    def tribonacci(self, n):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 1
        for i in range(3, n + 1):
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
        return dp[n]

    def tribonacciOptimized(self, n):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        a, b, c = 0, 1, 1
        for _ in range(3, n + 1):
            a, b, c = b, c, a + b + c
        return c


if __name__ == "__main__":
    sol = Solution()
    n1 = 4
    print(f"Input: n = {n1}")
    print(f"Output: {sol.tribonacci(n1)}")
    print(f"Output (Optimized): {sol.tribonacciOptimized(n1)}")
    n2 = 25
    print(f"Input: n = {n2}")
    print(f"Output: {sol.tribonacci(n2)}")
    print(f"Output (Optimized): {sol.tribonacciOptimized(n2)}")
    print("\nFirst 10 Tribonacci numbers: ")
    for i in range(10):
        print(sol.tribonacci(i), end=" ")
    print()
