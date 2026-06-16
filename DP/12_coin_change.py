"""
PROBLEM: Coin Change
Difficulty: Medium
Pattern: Unbounded Knapsack, Minimum Coins

DESCRIPTION:
You are given an integer array coins representing coins of different denominations and an integer 
amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money 
cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

INPUT:
coins = [1, 2, 5], amount = 11

OUTPUT:
3
Explanation: 11 = 5 + 5 + 1

TIME COMPLEXITY: O(amount * n) where n = number of coins
SPACE COMPLEXITY: O(amount)
"""

from typing import List, Optional

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp[i] = minimum coins needed to make amount i
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0  # 0 coins needed for amount 0
        
        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i and dp[i - coin] != float('inf'):
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        
        return -1 if dp[amount] == float('inf') else dp[amount]


if __name__ == "__main__":
    sol = Solution()
    
    coins1 = [1, 2, 5]
    amount1 = 11
    print(f"Input: coins = [1, 2, 5], amount = {amount1}")
    print(f"Output: {sol.coinChange(coins1, amount1)}")
    print()
    
    coins2 = [2]
    amount2 = 3
    print(f"Input: coins = [2], amount = {amount2}")
    print(f"Output: {sol.coinChange(coins2, amount2)}")
    print()
    
    coins3 = [1]
    amount3 = 0
    print(f"Input: coins = [1], amount = {amount3}")
    print(f"Output: {sol.coinChange(coins3, amount3)}")
