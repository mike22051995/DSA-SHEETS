"""
PROBLEM: Smallest Range Covering Elements from K Lists (LeetCode 632)
DIFFICULTY: Hard
PATTERN: Heap - Min-Heap with current max tracking

DESCRIPTION:
Given k sorted lists, find the smallest range [l,r] that includes at least
one number from each list.

EXAMPLE:
Input: [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]] -> [20,24]
Input: [[1,2,3],[1,2,3],[1,2,3]] -> [1,1]
Input: [[1],[2],[3]] -> [1,3]

TIME COMPLEXITY: O(N log k) where N = total elements
SPACE COMPLEXITY: O(k)
"""

import heapq
from typing import List


class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        # (value, list_idx, element_idx)
        min_heap: List = []
        current_max = float('-inf')

        for i, lst in enumerate(nums):
            heapq.heappush(min_heap, (lst[0], i, 0))
            current_max = max(current_max, lst[0])

        best_range = [min_heap[0][0], int(current_max)]

        while True:
            val, li, ei = heapq.heappop(min_heap)
            if ei + 1 >= len(nums[li]):
                break
            next_val = nums[li][ei + 1]
            heapq.heappush(min_heap, (next_val, li, ei + 1))
            current_max = max(current_max, next_val)
            current_min = min_heap[0][0]
            if current_max - current_min < best_range[1] - best_range[0]:
                best_range = [current_min, int(current_max)]

        return best_range


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        [[4, 10, 15, 24, 26], [0, 9, 12, 20], [5, 18, 22, 30]],
        [[1, 2, 3], [1, 2, 3], [1, 2, 3]],
        [[1], [2], [3]],
    ]
    for nums in test_cases:
        print(f"nums={nums} -> {sol.smallestRange(nums)}")
