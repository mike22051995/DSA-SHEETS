"""
PROBLEM: Fruit Into Baskets
---------------------------------------------------------------------------
You are visiting a farm with a single row of fruit trees. Each tree has a 
type denoted by an integer. You have two baskets, and each basket can hold 
any quantity of fruit, but you want each basket to only hold one type of fruit.
Find the maximum number of fruits you can collect.

PATTERN: Sliding Window (At Most K Distinct)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can collect all 3 fruits using 2 baskets for types 1 and 2.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2]. Types 1 and 2 in two baskets.
"""

from typing import List
from collections import defaultdict


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        basket = defaultdict(int)  # fruit type -> count
        left = 0
        maxFruits = 0
        for right in range(len(fruits)):
            basket[fruits[right]] += 1
            # Shrink window if more than 2 types
            while len(basket) > 2:
                basket[fruits[left]] -= 1
                if basket[fruits[left]] == 0:
                    del basket[fruits[left]]
                left += 1
            maxFruits = max(maxFruits, right - left + 1)
        return maxFruits


if __name__ == "__main__":
    sol = Solution()
    fruits1 = [1, 2, 1]
    print(f"Test 1: {sol.totalFruit(fruits1)}")
    fruits2 = [0, 1, 2, 2]
    print(f"Test 2: {sol.totalFruit(fruits2)}")
