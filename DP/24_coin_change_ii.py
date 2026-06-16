"""
PROBLEM: Coin Change II - Number of Ways (LeetCode 518)
DIFFICULTY: Medium
PATTERN: Unbounded Knapsack - Count Ways

DESCRIPTION:
You are given an integer array coins representing coins of different denominations 
and an integer amount. Return the number of combinations that make up that amount.
You may assume you have infinite number of each coin.

EXAMPLE:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: 
1+1+1+1+1
1+1+1+2
1+2+2
5

Input: amount = 3, coins = [2]
Output: 0

Input: amount = 10, coins = [10]
Output: 1

TIME COMPLEXITY: O(n * amount)
SPACE COMPLEXITY: O(n * amount), can be optimized to O(amount)
"""

from typing import List, Optional

class Solution:
    def change2D(self, amount, coins):
        n = len(coins)
        dp = [[0] * (amount + 1) for _ in range(n + 1)]
        # Base case: 1 way to make amount 0 (use no coins)
        for i in range(n + 1):
            dp[i][0] = 1
        for i in range(1, n + 1):
            for amt in range(1, amount + 1):
                # Don't use current coin
                dp[i][amt] = dp[i-1][amt]
                # Use current coin (if possible)
                if coins[i-1] <= amt:
                    # Add ways using current coin
                    # Note: dp[i][amt - coins[i-1]] not dp[i-1]
                    # Because we can use same coin multiple times
                    dp[i][amt] += dp[i][amt - coins[i-1]]
        return dp[n][amount]

    def change(self, amount, coins):
        dp = [0] * (amount + 1)
        dp[0] = 1
        for coin in coins:
            for amt in range(coin, amount + 1):
                dp[amt] += dp[amt - coin]
        return dp[amount]

    def changeWrong(self, amount, coins):
        # This counts permutations (wrong for combinations)
        dp = [0] * (amount + 1)
        dp[0] = 1
        for amt in range(1, amount + 1):
            for coin in coins:
                if coin <= amt:
                    dp[amt] += dp[amt - coin]
        return dp[amount]


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    amount1 = 5
    coins1 = [1, 2, 5]
    print(f"Amount: {amount1}")
    print(f"Coins: {coins1}")
    print(f"Number of ways (2D DP): {sol.change2D(amount1, coins1)}")
    print(f"Number of ways (1D DP): {sol.change(amount1, coins1)}")
    print(f"Wrong approach (permutations): {sol.changeWrong(amount1, coins1)}")
    print(f"\nTest Case 2:")
    amount2 = 3
    coins2 = [2]
    print(f"Amount: {amount2}")
    print(f"Coins: {coins2}")
    print(f"Number of ways: {sol.change(amount2, coins2)}")
    print(f"\nTest Case 3:")
    amount3 = 10
    coins3 = [10]
    print(f"Amount: {amount3}")
    print(f"Number of ways: {sol.change(amount3, coins3)}")
