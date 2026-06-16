"""
PROBLEM: Connect Sticks (LeetCode 1167)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap greedy

DESCRIPTION:
Connecting two sticks of length x and y costs x+y.
Return minimum total cost to connect all sticks into one.

EXAMPLE:
Input: [2,4,3] -> Output: 14
Input: [1,8,3,5] -> Output: 30
Input: [5] -> Output: 0

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        if len(sticks) <= 1:
            return 0

        heapq.heapify(sticks)
        total = 0

        while len(sticks) > 1:
            a = heapq.heappop(sticks)
            b = heapq.heappop(sticks)
            cost = a + b
            total += cost
            heapq.heappush(sticks, cost)

        return total


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        [2, 4, 3],
        [1, 8, 3, 5],
        [5],
    ]
    for sticks in test_cases:
        print(f"sticks={sticks} -> {sol.connectSticks(sticks[:])}")
