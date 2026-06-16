"""
PROBLEM: Remove Stones to Minimize the Total (LeetCode 1962)
DIFFICULTY: Medium
PATTERN: Heap - Max-Heap greedy

DESCRIPTION:
Given piles of stones and k operations, in each operation choose a pile and
remove floor(pile/2) stones. Return minimum total stones after k operations.

EXAMPLE:
Input: piles=[5,4,9], k=2 -> 12
Input: piles=[4,3,6,7], k=3 -> 12
Input: piles=[10], k=3 -> 2

TIME COMPLEXITY: O((n + k) log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List
import math


class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        # Max-heap (negate values)
        max_heap = [-p for p in piles]
        heapq.heapify(max_heap)

        for _ in range(k):
            top = -heapq.heappop(max_heap)
            top -= top // 2  # ceil(top/2) remains
            heapq.heappush(max_heap, -top)

        return -sum(max_heap)


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([5, 4, 9], 2),
        ([4, 3, 6, 7], 3),
        ([10], 3),
    ]
    for piles, k in test_cases:
        print(f"piles={piles}, k={k} -> {sol.minStoneSum(piles[:], k)}")
