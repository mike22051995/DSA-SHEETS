"""
PROBLEM: Merge K Sorted Arrays
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap for multi-way merge

DESCRIPTION:
Given k sorted arrays, merge them into one sorted array.

EXAMPLE:
Input: [[1,4,7],[2,5,8],[3,6,9]] -> [1,2,3,4,5,6,7,8,9]
Input: [[1,3,5],[2,4,6]] -> [1,2,3,4,5,6]

TIME COMPLEXITY: O(N log k) where N = total elements
SPACE COMPLEXITY: O(k)
"""

import heapq
from typing import List


class Solution:
    def mergeKSortedArrays(self, arrays: List[List[int]]) -> List[int]:
        min_heap: List = []
        # Push first element from each array: (value, row, col)
        for row, arr in enumerate(arrays):
            if arr:
                heapq.heappush(min_heap, (arr[0], row, 0))

        result: List[int] = []
        while min_heap:
            val, row, col = heapq.heappop(min_heap)
            result.append(val)
            next_col = col + 1
            if next_col < len(arrays[row]):
                heapq.heappush(min_heap, (arrays[row][next_col], row, next_col))

        return result


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        [[1, 4, 7], [2, 5, 8], [3, 6, 9]],
        [[1, 3, 5], [2, 4, 6]],
        [[10], [1, 2, 3], [4, 5]],
    ]
    for arrays in test_cases:
        print(f"arrays={arrays} -> {sol.mergeKSortedArrays(arrays)}")
