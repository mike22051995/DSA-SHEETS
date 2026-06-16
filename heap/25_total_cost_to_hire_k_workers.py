"""
PROBLEM: Total Cost to Hire K Workers (LeetCode 2462)
DIFFICULTY: Medium
PATTERN: Heap - Two Min-Heaps (left and right candidate windows)

DESCRIPTION:
Given hiring costs and candidates count, hire exactly k workers.
Each session: choose minimum cost from first 'candidates' or last 'candidates' workers.
Return total minimum cost.

EXAMPLE:
Input: costs=[17,12,10,2,7,2,11,20,8], k=3, candidates=4 -> 11
Input: costs=[1,2,4,1], k=3, candidates=3 -> 4
Input: costs=[5,3,8,2], k=2, candidates=1 -> 7

TIME COMPLEXITY: O((k + candidates) log candidates)
SPACE COMPLEXITY: O(candidates)
"""

import heapq
from typing import List


class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n = len(costs)
        left_heap: List = []
        right_heap: List = []

        lo, hi = 0, n - 1

        # Initialize left window
        for _ in range(candidates):
            if lo <= hi:
                heapq.heappush(left_heap, (costs[lo], lo))
                lo += 1

        # Initialize right window
        for _ in range(candidates):
            if lo <= hi:
                heapq.heappush(right_heap, (costs[hi], hi))
                hi -= 1

        total = 0
        for _ in range(k):
            lv = left_heap[0] if left_heap else (float('inf'), -1)
            rv = right_heap[0] if right_heap else (float('inf'), -1)

            if lv[0] <= rv[0]:
                cost, idx = heapq.heappop(left_heap)
                total += cost
                if lo <= hi:
                    heapq.heappush(left_heap, (costs[lo], lo))
                    lo += 1
            else:
                cost, idx = heapq.heappop(right_heap)
                total += cost
                if lo <= hi:
                    heapq.heappush(right_heap, (costs[hi], hi))
                    hi -= 1

        return total


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([17, 12, 10, 2, 7, 2, 11, 20, 8], 3, 4),
        ([1, 2, 4, 1], 3, 3),
        ([5, 3, 8, 2], 2, 1),
    ]
    for costs, k, candidates in test_cases:
        print(f"costs={costs}, k={k}, candidates={candidates} -> "
              f"{sol.totalCost(costs, k, candidates)}")
