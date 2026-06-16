"""
PROBLEM: Largest Rectangle in Histogram
Difficulty: Hard
Pattern: Stack, Monotonic Stack

DESCRIPTION:
Given an array of integers heights representing the histogram's bar height where the width 
of each bar is 1, return the area of the largest rectangle in the histogram.

EXPLANATION:
Use a monotonic stack to track indices of bars:
1. For each bar, pop bars from stack that are taller (can't extend further)
2. Calculate area for each popped bar
3. Stack maintains increasing heights
4. Process remaining bars in stack at the end

Time Complexity: O(n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: Rectangle of height 5, width 2 (between indices 2 and 3)

Example 2:
Input: heights = [2,4]
Output: 4
Explanation: Rectangle of height 2, width 2

Example 3:
Input: heights = [1,1]
Output: 2
Explanation: Rectangle of height 1, width 2
"""

from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []  # Stores indices
        maxArea = 0
        n = len(heights)
        for i in range(n):
            # Pop bars taller than current
            while stack and heights[stack[-1]] > heights[i]:
                height = heights[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                maxArea = max(maxArea, height * width)
            stack.append(i)
        # Process remaining bars in stack
        while stack:
            height = heights[stack.pop()]
            width = n if not stack else n - stack[-1] - 1
            maxArea = max(maxArea, height * width)
        return maxArea


if __name__ == "__main__":
    solution = Solution()
    heights1 = [2, 1, 5, 6, 2, 3]
    print(f"Test 1: {solution.largestRectangleArea(heights1)}")
    heights2 = [2, 4]
    print(f"Test 2: {solution.largestRectangleArea(heights2)}")
    heights3 = [1, 1]
    print(f"Test 3: {solution.largestRectangleArea(heights3)}")
