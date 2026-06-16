"""
PROBLEM: Largest Rectangle in Histogram (LeetCode 84)
DIFFICULTY: Hard
PATTERN: Monotonic Stack for Area Calculation

DESCRIPTION:
Given an array of integers heights representing the histogram's bar height where 
the width of each bar is 1, return the area of the largest rectangle in the histogram.

INPUT: heights = [2,1,5,6,2,3]
OUTPUT: 10
Explanation: The largest rectangle has area = 10 (width=2, height=5)

INPUT: heights = [2,4]
OUTPUT: 4

TIME COMPLEXITY: O(n) where n is the number of bars
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a monotonic increasing stack to store indices of bars.
For each bar, if it's smaller than stack top, we've found the right boundary.
Pop from stack and calculate area using popped height and width between boundaries.
This is a classic and very important pattern for FAANG interviews!
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


if __name__ == "__main__":
    test_cases = [
        [2, 1, 5, 6, 2, 3],
        [2, 4],
        [1, 1, 1, 1, 1],
        [6, 2, 5, 4, 5, 1, 6],
        [2, 1, 2],
        [4, 2, 0, 3, 2, 5],
    ]
    for heights in test_cases:
        result = largestRectangleArea(heights)
        print(f"Heights: {heights}")
        print(f"Largest Rectangle Area: {result}")
        print()
