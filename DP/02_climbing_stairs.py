"""
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
"""

from typing import List, Optional

class Solution:
    def climbStairs(self, n):
        if n <= 2:
            return n
        dp = [0] * (n + 1)
        dp[1] = 1  # 1 way to reach step 1
        dp[2] = 2  # 2 ways to reach step 2
        for i in range(3, n + 1):
            # Ways to reach step i = ways to reach (i-1) + ways to reach (i-2)
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]

    def climbStairsOptimized(self, n):
        if n <= 2:
            return n
        prev2, prev1 = 1, 2
        for i in range(3, n + 1):
            curr = prev1 + prev2
            prev2 = prev1
            prev1 = curr
        return prev1


if __name__ == "__main__":
    sol = Solution()
    n1 = 3
    print(f"Input: n = {n1}")
    print(f"Output: {sol.climbStairs(n1)}")
    print(f"Output (Optimized): {sol.climbStairsOptimized(n1)}")
    n2 = 5
    print(f"Input: n = {n2}")
    print(f"Output: {sol.climbStairs(n2)}")
    print(f"Output (Optimized): {sol.climbStairsOptimized(n2)}")
