"""
PROBLEM: Maximal Rectangle (LeetCode 85)
DIFFICULTY: Hard
PATTERN: Stack + Histogram (Extension of Problem 21)

DESCRIPTION:
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle 
containing only 1's and return its area.

INPUT: matrix = [
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
OUTPUT: 6
Explanation: The maximal rectangle has area 6 (2x3 rectangle)

TIME COMPLEXITY: O(rows * cols) where rows and cols are matrix dimensions
SPACE COMPLEXITY: O(cols) for the height array and stack

EXPLANATION:
Convert the problem to "Largest Rectangle in Histogram" for each row.
Build a heights array where heights[i] = consecutive 1's ending at current row.
For each row, treat it as base of histogram and find largest rectangle.
This combines the histogram problem with dynamic height calculation.
"""



from typing import List


def largestRectangleArea(heights: List[int]) -> int:
    stack = []
    max_area = 0
    n = len(heights)
    for i in range(n + 1):
        h = 0 if i == n else heights[i]
        while stack and heights[stack[-1]] > h:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        stack.append(i)
    return max_area


def maximalRectangle(matrix: List[List[str]]) -> int:
    if not matrix or not matrix[0]:
        return 0
    cols = len(matrix[0])
    heights = [0] * cols
    max_area = 0

    for row in matrix:
        for j in range(cols):
            heights[j] = heights[j] + 1 if row[j] == '1' else 0
        max_area = max(max_area, largestRectangleArea(heights))

    return max_area


if __name__ == "__main__":
    test_cases = [
        [["1","0","1","0","0"],
         ["1","0","1","1","1"],
         ["1","1","1","1","1"],
         ["1","0","0","1","0"]],
        [["0","1"],
         ["1","0"]],
        [["1","1","1","1"],
         ["1","1","1","1"],
         ["1","1","1","1"]],
        [["0"]],
    ]
    for matrix in test_cases:
        result = maximalRectangle(matrix)
        print("Matrix:")
        for row in matrix:
            print(f"  {row}")
        print(f"Maximal Rectangle Area: {result}")
        print()
