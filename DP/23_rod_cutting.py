"""
PROBLEM: Rod Cutting Problem (LeetCode similar concepts)
DIFFICULTY: Medium
PATTERN: Unbounded Knapsack Variant

DESCRIPTION:
Given a rod of length n and an array of prices where prices[i] denotes the value of 
a piece of length i+1. Determine the maximum value obtainable by cutting up the rod 
and selling the pieces.

EXAMPLE:
Input:
length = 8
prices = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: Cut into pieces of length 2 and 6 (5 + 17 = 22) OR
pieces of length 2, 2, 2, 2 (5+5+5+5=20) 
Best: length 2 and length 6: prices[1] + prices[5] = 5 + 17 = 22

Input:
length = 4
prices = [2, 5, 7, 8]
Output: 10
Explanation: Cut into 2 pieces of length 2 each (5 + 5 = 10)

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n)
"""

from typing import List, Optional

class Solution:
    def cutRod(self, prices, n):
        dp = [0] * (n + 1)
        for length in range(1, n + 1):
            for cut in range(1, length + 1):
                dp[length] = max(dp[length], prices[cut-1] + dp[length - cut])
        return dp[n]

    def cutRodMemo(self, prices, n):
        from functools import lru_cache
        @lru_cache(maxsize=None)
        def helper(rem):
            if rem == 0:
                return 0
            best = 0
            for i in range(1, rem + 1):
                best = max(best, prices[i-1] + helper(rem - i))
            return best
        return helper(n)

    def cutRodUnbounded(self, prices, n):
        # Same as unbounded knapsack
        lengths = list(range(1, len(prices) + 1))
        dp = [0] * (n + 1)
        for w in range(1, n + 1):
            for i in range(len(prices)):
                if lengths[i] <= w:
                    dp[w] = max(dp[w], prices[i] + dp[w - lengths[i]])
        return dp[n]

    def printCuts(self, prices, n):
        dp = [0] * (n + 1)
        cut_at = [0] * (n + 1)
        for length in range(1, n + 1):
            for cut in range(1, length + 1):
                if prices[cut-1] + dp[length - cut] > dp[length]:
                    dp[length] = prices[cut-1] + dp[length - cut]
                    cut_at[length] = cut
        cuts = []
        rem = n
        while rem > 0:
            cuts.append(cut_at[rem])
            rem -= cut_at[rem]
        print(f"Cuts: {cuts}")


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    prices1 = [1, 5, 8, 9, 10, 17, 17, 20]
    length1 = 8
    print(f"Rod length: {length1}")
    print(f"Prices: {prices1}")
    print(f"Maximum value (Bottom-up): {sol.cutRod(prices1, length1)}")
    print(f"Maximum value (Memoization): {sol.cutRodMemo(prices1, length1)}")
    print(f"Maximum value (Unbounded): {sol.cutRodUnbounded(prices1, length1)}")
    sol.printCuts(prices1, length1)
    print(f"\nTest Case 2:")
    prices2 = [2, 5, 7, 8]
    length2 = 4
    print(f"Rod length: {length2}")
    print(f"Prices: {prices2}")
    print(f"Maximum value: {sol.cutRod(prices2, length2)}")
    sol.printCuts(prices2, length2)
    print(f"\nTest Case 3:")
    prices3 = [3, 5, 8, 9, 10, 17, 17, 20]
    length3 = 8
    print(f"Rod length: {length3}")
    print(f"Maximum value: {sol.cutRod(prices3, length3)}")
