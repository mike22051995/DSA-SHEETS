"""
PROBLEM: Maximal Rectangle (LeetCode 85)
Difficulty: Hard
Company: Google, Meta, Amazon, Microsoft
Pattern: Histogram + Stack

DESCRIPTION:
Given a 2D binary matrix filled with '0's and '1's, find the largest rectangle
containing only '1's and return its area.

APPROACH:
Convert to Largest Rectangle in Histogram problem:
1. Build cumulative height array for each row
2. For each row, solve largest rectangle in histogram using stack
3. Track maximum area across all rows

TIME COMPLEXITY: O(M * N)
SPACE COMPLEXITY: O(N) for height array
"""

from typing import List


class Solution:
    def largestRectangleHistogram(self, heights: List[int]) -> int:
        stack = []
        max_area = 0
        n = len(heights)

        for i in range(n + 1):
            h = 0 if i == n else heights[i]

            while stack and h < heights[stack[-1]]:
                height = heights[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)

            stack.append(i)

        return max_area

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        m, n = len(matrix), len(matrix[0])
        heights = [0] * n
        max_area = 0

        for i in range(m):
            for j in range(n):
                heights[j] = heights[j] + 1 if matrix[i][j] == '1' else 0

            max_area = max(max_area, self.largestRectangleHistogram(heights))

        return max_area


if __name__ == "__main__":
    sol = Solution()

    matrix = [
        ["1", "0", "1", "0", "0"],
        ["1", "0", "1", "1", "1"],
        ["1", "1", "1", "1", "1"],
        ["1", "0", "0", "1", "0"]
    ]
    print("Maximal rectangle:", sol.maximalRectangle(matrix))  # 6
