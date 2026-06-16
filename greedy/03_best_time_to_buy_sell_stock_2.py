"""
PROBLEM: Best Time to Buy and Sell Stock II (LeetCode 122)
DIFFICULTY: Easy
PATTERN: Peak Valley Approach / Sum of All Positive Differences

DESCRIPTION:
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share 
of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

INPUT:
- prices: array of integers representing stock prices on each day

OUTPUT:
- Maximum profit achievable

APPROACH:
Greedy insight: Capture every upward movement!
If price increases from day i to i+1, we can capture that profit by buying at i and selling at i+1.
Simply sum all positive differences between consecutive days.

WHY GREEDY WORKS:
Any profit between two days can be decomposed into sum of daily profits.
Example: profit from day 1 to day 4 = (p[2]-p[1]) + (p[3]-p[2]) + (p[4]-p[3])
"""

from typing import List, Optional

class Solution:
    def maxProfit(self, prices):
        maxProfit = 0
        # Add all positive differences
        for i in range(1, len(prices)):
        if prices[i] > prices[i-1]:
        maxProfit += prices[i] - prices[i-1]
        return maxProfit


if __name__ == "__main__":
    sol = Solution()
    prices1 = [7, 1, 5, 3, 6, 4]
    print(f"Test 1 - Prices: [7,1,5,3,6,4]")
    print(f"Output: {sol.maxProfit(prices1)}")
    print(f"Expected: 7 (Buy at 1, sell at 5: +4, Buy at 3, sell at 6: +3)")
    prices2 = [1, 2, 3, 4, 5]
    print(f"Test 2 - Prices: [1,2,3,4,5]")
    print(f"Output: {sol.maxProfit(prices2)}")
    print(f"Expected: 4 (Buy at 1, sell at 5)")
    prices3 = [7, 6, 4, 3, 1]
    print(f"Test 3 - Prices: [7,6,4,3,1]")
    print(f"Output: {sol.maxProfit(prices3)}")
    print(f"Expected: 0 (No profitable transaction)")
