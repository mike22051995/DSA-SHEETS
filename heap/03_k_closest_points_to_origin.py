"""
PROBLEM: K Closest Points to Origin (LeetCode 973)
DIFFICULTY: Medium
PATTERN: Heap - Max-Heap of size k by distance

DESCRIPTION:
Given points on a 2D plane and integer k, return the k closest points to origin.

EXAMPLE:
Input: points = [[1,3],[-2,2]], k = 1 -> Output: [[-2,2]]
Input: points = [[3,3],[5,-1],[-2,4]], k = 2 -> Output: [[3,3],[-2,4]]

TIME COMPLEXITY: O(n log k)
SPACE COMPLEXITY: O(k)
"""

import heapq
from typing import List


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # Max-heap (negate distance) of size k
        max_heap: List = []
        for x, y in points:
            dist = -(x * x + y * y)
            heapq.heappush(max_heap, (dist, x, y))
            if len(max_heap) > k:
                heapq.heappop(max_heap)
        return [[x, y] for _, x, y in max_heap]

    def kClosestSort(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=lambda p: p[0] * p[0] + p[1] * p[1])
        return points[:k]


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([[1, 3], [-2, 2]], 1),
        ([[3, 3], [5, -1], [-2, 4]], 2),
        ([[0, 1], [1, 0]], 2),
    ]
    for points, k in test_cases:
        print(f"points={points}, k={k} -> {sol.kClosest([p[:] for p in points], k)}")
