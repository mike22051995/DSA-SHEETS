"""
PROBLEM: Kth Smallest Element in a Sorted Matrix (LeetCode 378)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap multi-row traversal

DESCRIPTION:
Given an n x n matrix where rows and columns are sorted, return k-th smallest element.

EXAMPLE:
Input: [[1,5,9],[10,11,13],[12,13,15]], k=8 -> Output: 13
Input: [[-5]], k=1 -> Output: -5
Input: [[1,2],[1,3]], k=2 -> Output: 1

TIME COMPLEXITY: O(k log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        # Push first element from each row
        min_heap = [(matrix[r][0], r, 0) for r in range(n)]
        heapq.heapify(min_heap)

        for _ in range(k - 1):
            val, r, c = heapq.heappop(min_heap)
            if c + 1 < n:
                heapq.heappush(min_heap, (matrix[r][c + 1], r, c + 1))

        return min_heap[0][0]


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([[1, 5, 9], [10, 11, 13], [12, 13, 15]], 8),
        ([[-5]], 1),
        ([[1, 2], [1, 3]], 2),
    ]
    for matrix, k in test_cases:
        print(f"k={k} -> {sol.kthSmallest(matrix, k)}")
