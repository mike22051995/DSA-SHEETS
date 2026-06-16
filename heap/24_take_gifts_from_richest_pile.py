"""
PROBLEM: Take Gifts From the Richest Pile (LeetCode 2558)
DIFFICULTY: Easy
PATTERN: Heap - Max-Heap greedy

DESCRIPTION:
Given gift piles, perform k operations: choose largest pile and replace with floor(sqrt(pile)).
Return total gifts remaining.

EXAMPLE:
Input: gifts=[25,64,9,4,100], k=4 -> 29
Input: gifts=[1,1,1,1], k=4 -> 4
Input: gifts=[16], k=2 -> 2

TIME COMPLEXITY: O(n + k log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
import math
from typing import List


class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        # Max-heap (negate values)
        max_heap = [-g for g in gifts]
        heapq.heapify(max_heap)

        for _ in range(k):
            top = -heapq.heappop(max_heap)
            heapq.heappush(max_heap, -int(math.isqrt(top)))

        return -sum(max_heap)


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([25, 64, 9, 4, 100], 4),
        ([1, 1, 1, 1], 4),
        ([16], 2),
    ]
    for gifts, k in test_cases:
        print(f"gifts={gifts}, k={k} -> {sol.pickGifts(gifts[:], k)}")
