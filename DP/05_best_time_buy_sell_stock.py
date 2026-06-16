"""
PROBLEM: Best Time to Buy and Sell Stock
Difficulty: Easy
Pattern: 1D DP, Max Profit with Single Transaction

DESCRIPTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any 
profit, return 0.

INPUT:
prices = [7, 1, 5, 3, 6, 4]

OUTPUT:
5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def maxProfit(self, prices):
        minPrice = float('inf')
        maxProfit = 0
        for i in range(len(prices)):
            # Update minimum price seen so far
            minPrice = min(minPrice, prices[i])
            # Calculate profit if we sell at current price
            profit = prices[i] - minPrice
            # Update maximum profit
            maxProfit = max(maxProfit, profit)
        return maxProfit

    def maxProfitDP(self, prices):
        n = len(prices)
        if n == 0:
            return 0
        dp = [0] * n
        minPrice = prices[0]
        for i in range(1, n):
            minPrice = min(minPrice, prices[i])
            dp[i] = max(dp[i-1], prices[i] - minPrice)
        return dp[n-1]


if __name__ == "__main__":
    sol = Solution()
    prices1 = [7, 1, 5, 3, 6, 4]
    print(f"Input: prices = [7, 1, 5, 3, 6, 4]")
    print(f"Output: {sol.maxProfit(prices1)}")
    print(f"Output (DP): {sol.maxProfitDP(prices1)}")
    prices2 = [7, 6, 4, 3, 1]
    print(f"Input: prices = [7, 6, 4, 3, 1]")
    print(f"Output: {sol.maxProfit(prices2)}")
    print(f"Output (DP): {sol.maxProfitDP(prices2)}")
