"""
PROBLEM: Kth Smallest Element in Sorted Matrix (LeetCode 378)
Difficulty: Medium
Company: Google, Meta, Amazon, Microsoft
Pattern: Binary Search / Min Heap

DESCRIPTION:
Given an n x n matrix where each row and column is sorted in ascending order,
find the kth smallest element in the matrix.

APPROACH:
Method 1: Min Heap - push first element of each row, pop k times
Method 2: Binary Search on Value Range - count elements <= mid

TIME COMPLEXITY: O(k * log n) or O(n * log(max-min))
SPACE COMPLEXITY: O(n) or O(1)
"""

from typing import List
import heapq


class Solution:
    # Method 1: Min Heap
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        min_heap = []

        # Push first element of each row
        for r in range(min(n, k)):
            heapq.heappush(min_heap, (matrix[r][0], r, 0))

        result = 0
        for _ in range(k):
            val, r, c = heapq.heappop(min_heap)
            result = val
            if c + 1 < n:
                heapq.heappush(min_heap, (matrix[r][c + 1], r, c + 1))

        return result

    # Method 2: Binary Search on Value
    def kthSmallestBinarySearch(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)

        def count_less_equal(target: int) -> int:
            count = 0
            row, col = n - 1, 0
            while row >= 0 and col < n:
                if matrix[row][col] <= target:
                    count += row + 1
                    col += 1
                else:
                    row -= 1
            return count

        lo, hi = matrix[0][0], matrix[n-1][n-1]
        while lo < hi:
            mid = (lo + hi) // 2
            if count_less_equal(mid) < k:
                lo = mid + 1
            else:
                hi = mid

        return lo


if __name__ == "__main__":
    sol = Solution()

    matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]]
    print("3rd smallest:", sol.kthSmallest(matrix, 8))  # 13
