"""
PROBLEM: Minimum Cost to Hire K Workers (LeetCode 857)
DIFFICULTY: Hard
PATTERN: Heap - Sort by wage/quality ratio, Max-Heap for selected qualities

DESCRIPTION:
Given quality and wage arrays, hire exactly k workers with minimum total cost.
Every worker in the group must be paid at least their minimum wage expectation,
and paid proportional to their quality.

EXAMPLE:
Input: quality=[10,20,5], wage=[70,50,30], k=2 -> 105.0
Input: quality=[3,1,10,10,1], wage=[4,8,2,2,7], k=3 -> 30.666...
Input: quality=[5,5,5], wage=[5,5,5], k=2 -> 10.0

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        # Sort by wage/quality ratio
        workers = sorted(zip(quality, wage), key=lambda w: w[1] / w[0])

        max_heap: List[int] = []  # negate quality for max-heap
        quality_sum = 0
        min_cost = float('inf')

        for q, w in workers:
            heapq.heappush(max_heap, -q)
            quality_sum += q
            if len(max_heap) > k:
                quality_sum += heapq.heappop(max_heap)  # add negative to subtract
            if len(max_heap) == k:
                ratio = w / q
                min_cost = min(min_cost, ratio * quality_sum)

        return min_cost


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([10, 20, 5], [70, 50, 30], 2),
        ([3, 1, 10, 10, 1], [4, 8, 2, 2, 7], 3),
        ([5, 5, 5], [5, 5, 5], 2),
    ]
    for quality, wage, k in test_cases:
        result = sol.mincostToHireWorkers(quality, wage, k)
        print(f"quality={quality}, wage={wage}, k={k} -> {result:.5f}")
