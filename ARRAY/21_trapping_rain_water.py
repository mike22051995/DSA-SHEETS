"""
PROBLEM: Trapping Rain Water
Difficulty: Hard
Pattern: Two Pointers, Dynamic Programming

DESCRIPTION:
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

EXPLANATION:
Two Pointer Approach:
- Water trapped at any position = min(maxLeft, maxRight) - height[i]
- Use two pointers from both ends
- Move the pointer with smaller height inward
- Track max heights from both sides

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: Water trapped in valleys between bars

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
Explanation: Multiple valleys trap water

Example 3:
Input: height = [4,2,3]
Output: 1
Explanation: Small valley traps 1 unit
"""

from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        left, right = 0, len(height) - 1
        leftMax, rightMax = 0, 0
        water = 0
        while left < right:
            if height[left] < height[right]:
                if height[left] >= leftMax:
                    leftMax = height[left]
                else:
                    water += leftMax - height[left]
                left += 1
            else:
                if height[right] >= rightMax:
                    rightMax = height[right]
                else:
                    water += rightMax - height[right]
                right -= 1
        return water


if __name__ == "__main__":
    solution = Solution()
    height1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(f"Test 1: {solution.trap(height1)}")
    height2 = [4, 2, 0, 3, 2, 5]
    print(f"Test 2: {solution.trap(height2)}")
    height3 = [4, 2, 3]
    print(f"Test 3: {solution.trap(height3)}")
