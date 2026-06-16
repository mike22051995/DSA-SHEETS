"""
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
"""

from typing import List, Optional

class Solution:
    def unboundedKnapsack(self, W, weights, values):
        n = len(weights)
        dp = [[0] * (W + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for w in range(1, W + 1):
                # Don't include current item
                dp[i][w] = dp[i-1][w]
                # Include current item (can use multiple times)
                if weights[i-1] <= w:
                    # Notice: dp[i][w-weight] not dp[i-1][w-weight]
                    # Because we can use same item again!
                    dp[i][w] = max(dp[i][w],
                                   values[i-1] + dp[i][w - weights[i-1]])
        return dp[n][W]

    def unboundedKnapsackOptimized(self, W, weights, values):
        dp = [0] * (W + 1)
        for w in range(1, W + 1):
            for i in range(len(weights)):
                if weights[i] <= w:
                    dp[w] = max(dp[w], values[i] + dp[w - weights[i]])
        return dp[W]

    def unboundedKnapsack2(self, W, weights, values):
        n = len(weights)
        dp = [0] * (W + 1)
        for w in range(W + 1):
            for i in range(n):
                if weights[i] <= w:
                    dp[w] = max(dp[w], values[i] + dp[w - weights[i]])
        return dp[W]


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    W1 = 8
    weights1 = [1, 3, 4, 5]
    values1 = [10, 40, 50, 70]
    print(f"Capacity: {W1}")
    print(f"Weights: {weights1}")
    print(f"Values: {values1}")
    print(f"Maximum value (2D DP): {sol.unboundedKnapsack(W1, weights1, values1)}")
    print(f"Maximum value (1D DP method 1): {sol.unboundedKnapsackOptimized(W1, weights1, values1)}")
    print(f"Maximum value (1D DP method 2): {sol.unboundedKnapsack2(W1, weights1, values1)}")
    print(f"\nTest Case 2:")
    W2 = 10
    weights2 = [2, 3, 5, 7]
    values2 = [1, 5, 2, 4]
    print(f"Capacity: {W2}")
    print(f"Maximum value: {sol.unboundedKnapsack(W2, weights2, values2)}")
