"""
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
"""

from typing import List, Optional

class Solution:
    def minCostClimbingStairs(self, cost):
        n = len(cost)
        dp = [0] * (n + 1)
        dp[0] = 0  # No cost to start at position 0
        dp[1] = 0  # No cost to start at position 1
        for i in range(2, n + 1):
            # Min cost to reach step i = min of:
            # - Coming from step (i-1) and paying cost[i-1]
            # - Coming from step (i-2) and paying cost[i-2]
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
        return dp[n]

    def minCostClimbingStairsOptimized(self, cost):
        n = len(cost)
        prev2, prev1 = 0, 0
        for i in range(2, n + 1):
            curr = min(prev1 + cost[i-1], prev2 + cost[i-2])
            prev2 = prev1
            prev1 = curr
        return prev1


if __name__ == "__main__":
    sol = Solution()
    cost1 = [10, 15, 20]
    print(f"Input: cost = [10, 15, 20]")
    print(f"Output: {sol.minCostClimbingStairs(cost1)}")
    print(f"Output (Optimized): {sol.minCostClimbingStairsOptimized(cost1)}")
    cost2 = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    print(f"Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]")
    print(f"Output: {sol.minCostClimbingStairs(cost2)}")
    print(f"Output (Optimized): {sol.minCostClimbingStairsOptimized(cost2)}")
