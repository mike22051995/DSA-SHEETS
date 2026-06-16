"""
PROBLEM: Image Overlap (LeetCode 835)
Difficulty: Medium
Company: Google, Meta
Pattern: Matrix Sliding / HashMap

DESCRIPTION:
Given two binary n x n matrices img1 and img2, find the largest possible overlap
after translating one image. Overlap = count of 1's at same position after shift.

APPROACH:
For each pair of 1-positions from img1 and img2, compute translation vector.
Count frequency of each translation vector using a HashMap.
Maximum frequency = maximum overlap.

TIME COMPLEXITY: O(N^4) worst case, O(N^2 * M^2) where M = count of 1's
SPACE COMPLEXITY: O(N^2) or O(M^2)
"""

from typing import List
from collections import defaultdict


class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)

        ones1 = [(i, j) for i in range(n) for j in range(n) if img1[i][j] == 1]
        ones2 = [(i, j) for i in range(n) for j in range(n) if img2[i][j] == 1]

        count = defaultdict(int)
        max_overlap = 0

        for i1, j1 in ones1:
            for i2, j2 in ones2:
                key = (i2 - i1, j2 - j1)
                count[key] += 1
                max_overlap = max(max_overlap, count[key])

        return max_overlap

    # Brute force: try all translations
    def largestOverlapBruteForce(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        max_overlap = 0

        for di in range(-(n - 1), n):
            for dj in range(-(n - 1), n):
                overlap = 0
                for i in range(n):
                    for j in range(n):
                        ni, nj = i + di, j + dj
                        if 0 <= ni < n and 0 <= nj < n:
                            overlap += img1[i][j] & img2[ni][nj]
                max_overlap = max(max_overlap, overlap)

        return max_overlap


if __name__ == "__main__":
    sol = Solution()

    img1 = [[1, 1, 0], [0, 1, 0], [0, 1, 0]]
    img2 = [[0, 0, 0], [0, 1, 1], [0, 0, 1]]
    print("Largest overlap:", sol.largestOverlap(img1, img2))  # 3
