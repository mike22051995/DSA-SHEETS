"""
PROBLEM: Last Stone Weight (LeetCode 1046)
DIFFICULTY: Easy
PATTERN: Heap - Max-Heap

DESCRIPTION:
Given stones where stones[i] is weight, repeatedly smash two heaviest stones.
If x != y, stone of weight x-y remains. Return final stone weight (0 if none).

EXAMPLE:
Input: [2,7,4,1,8,1] -> Output: 1
Input: [1] -> Output: 1
Input: [9,3,2,10] -> Output: 0

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # Negate for max-heap
        max_heap = [-s for s in stones]
        heapq.heapify(max_heap)

        while len(max_heap) > 1:
            a = -heapq.heappop(max_heap)
            b = -heapq.heappop(max_heap)
            if a != b:
                heapq.heappush(max_heap, -(a - b))

        return -max_heap[0] if max_heap else 0


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        [2, 7, 4, 1, 8, 1],
        [1],
        [9, 3, 2, 10],
    ]
    for stones in test_cases:
        print(f"stones={stones} -> {sol.lastStoneWeight(stones)}")
