"""

"""

from typing import List, Optional

class Solution:
    def maxProfit(self, prices):
        buy =prices[0]
        profit =0
        for price in prices:
        if price>buy:
        profit=max(price-buy,profit)
        buy=min(buy,price)
        return profit
