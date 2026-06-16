"""
PROBLEM: Find Kth Largest XOR Coordinate Value (LeetCode 1738)
DIFFICULTY: Medium
PATTERN: Heap - Prefix XOR matrix + Min-Heap of size k

DESCRIPTION:
Define prefix XOR value at (a,b) as XOR of all elements in submatrix (0,0)→(a,b).
Return k-th largest among all prefix XOR values.

EXAMPLE:
Input: matrix=[[5,2],[1,6]], k=1 -> 7
Input: matrix=[[5,2],[1,6]], k=2 -> 5
Input: matrix=[[5,2],[1,6]], k=3 -> 4

TIME COMPLEXITY: O(m*n log k)
SPACE COMPLEXITY: O(m*n)
"""

import heapq
from typing import List


class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        m = len(matrix[0])
        pref = [[0] * m for _ in range(n)]
        min_heap: List[int] = []

        for i in range(n):
            for j in range(m):
                pref[i][j] = matrix[i][j]
                if i > 0:
                    pref[i][j] ^= pref[i - 1][j]
                if j > 0:
                    pref[i][j] ^= pref[i][j - 1]
                if i > 0 and j > 0:
                    pref[i][j] ^= pref[i - 1][j - 1]

                heapq.heappush(min_heap, pref[i][j])
                if len(min_heap) > k:
                    heapq.heappop(min_heap)

        return min_heap[0]


if __name__ == "__main__":
    sol = Solution()
    matrix = [[5, 2], [1, 6]]
    for k in [1, 2, 3, 4]:
        print(f"matrix={matrix}, k={k} -> {sol.kthLargestValue(matrix, k)}")
