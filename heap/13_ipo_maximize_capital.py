"""
PROBLEM: IPO - Maximize Capital (LeetCode 502)
DIFFICULTY: Hard
PATTERN: Heap - Min-Heap for capital, Max-Heap for profit

DESCRIPTION:
Complete at most k projects. Project i needs capital[i] and gives profit[i].
Start with initial capital w. Maximize final capital.

EXAMPLE:
Input: k=2, w=0, profits=[1,2,3], capital=[0,1,1] -> 4
Input: k=3, w=0, profits=[1,2,3], capital=[0,1,2] -> 6
Input: k=1, w=2, profits=[5,6], capital=[1,3] -> 7

TIME COMPLEXITY: O(n log n + k log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        # Sort projects by required capital
        projects = sorted(zip(capital, profits))
        max_profit_heap: List[int] = []
        idx = 0
        n = len(projects)

        for _ in range(k):
            # Add all affordable projects to max-heap
            while idx < n and projects[idx][0] <= w:
                heapq.heappush(max_profit_heap, -projects[idx][1])
                idx += 1
            if not max_profit_heap:
                break
            w += -heapq.heappop(max_profit_heap)

        return w


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        (2, 0, [1, 2, 3], [0, 1, 1]),
        (3, 0, [1, 2, 3], [0, 1, 2]),
        (1, 2, [5, 6], [1, 3]),
    ]
    for k, w, profits, capital in test_cases:
        print(f"k={k}, w={w} -> {sol.findMaximizedCapital(k, w, profits, capital)}")
