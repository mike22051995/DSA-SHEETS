"""
PROBLEM: 0/1 Knapsack Problem
DIFFICULTY: Medium
PATTERN: 0/1 Knapsack (FUNDAMENTAL DP PATTERN)

DESCRIPTION:
Given weights and values of n items, put these items in a knapsack of capacity W 
to get the maximum total value in the knapsack.
Note: You cannot break an item (0/1 choice - take it or leave it).

EXAMPLE:
Input: 
W = 50 (capacity)
weights = [10, 20, 30]
values = [60, 100, 120]
Output: 220
Explanation: Take items with weight 20 and 30 (value = 100 + 120 = 220)

Input:
W = 10
weights = [5, 4, 6, 3]
values = [10, 40, 30, 50]
Output: 90
Explanation: Take items with weight 4 and 3 (value = 40 + 50 = 90)

TIME COMPLEXITY: O(n * W)
SPACE COMPLEXITY: O(n * W), optimized to O(W)
"""

from typing import List, Optional

class Solution:
    def knapsack(self, W, weights, values):
        n = len(weights)
        dp = [[0] * (W + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for w in range(1, W + 1):
                # Don't include item i
                dp[i][w] = dp[i-1][w]
                # Include item i if it fits
                if weights[i-1] <= w:
                    dp[i][w] = max(dp[i][w], values[i-1] + dp[i-1][w - weights[i-1]])
        return dp[n][W]

    def knapsackMemo(self, W, weights, values):
        from functools import lru_cache
        n = len(weights)
        @lru_cache(maxsize=None)
        def helper(idx, cap):
            if idx == 0 or cap == 0:
                return 0
            if weights[idx-1] > cap:
                return helper(idx-1, cap)
            return max(helper(idx-1, cap),
                       values[idx-1] + helper(idx-1, cap - weights[idx-1]))
        return helper(n, W)

    def knapsackOptimized(self, W, weights, values):
        n = len(weights)
        dp = [0] * (W + 1)
        for i in range(n):
            for w in range(W, weights[i] - 1, -1):
                dp[w] = max(dp[w], values[i] + dp[w - weights[i]])
        return dp[W]

    def printItems(self, W, weights, values):
        n = len(weights)
        dp = [[0] * (W + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for w in range(1, W + 1):
                dp[i][w] = dp[i-1][w]
                if weights[i-1] <= w:
                    dp[i][w] = max(dp[i][w], values[i-1] + dp[i-1][w - weights[i-1]])
        # Backtrack
        w = W
        items = []
        for i in range(n, 0, -1):
            if dp[i][w] != dp[i-1][w]:
                items.append(i-1)
                w -= weights[i-1]
        print(f"Selected items: {items}")


if __name__ == "__main__":
    sol = Solution()
    W1 = 50
    weights1 = [10, 20, 30]
    values1 = [60, 100, 120]
    print(f"Test Case 1:")
    print(f"Capacity: {W1}")
    print(f"Weights: {weights1}")
    print(f"Values: {values1}")
    print(f"Maximum value (Bottom-up): {sol.knapsack(W1, weights1, values1)}")
    print(f"Maximum value (Memoization): {sol.knapsackMemo(W1, weights1, values1)}")
    print(f"Maximum value (Optimized): {sol.knapsackOptimized(W1, weights1, values1)}")
    sol.printItems(W1, weights1, values1)
    print(f"\nTest Case 2:")
    W2 = 10
    weights2 = [5, 4, 6, 3]
    values2 = [10, 40, 30, 50]
    print(f"Capacity: {W2}")
    print(f"Maximum value: {sol.knapsack(W2, weights2, values2)}")
    sol.printItems(W2, weights2, values2)
