"""
PROBLEM: Trapping Rain Water
---------------------------------------------------------------------------
Given n non-negative integers representing an elevation map where the width 
of each bar is 1, compute how much water it can trap after raining.

PATTERN: Opposite Direction Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The elevation map traps 6 units of rain water.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
Explanation: Water trapped = 1 + 2 + 3 + 2 + 1 = 9
"""

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        left = 0
        right = len(height) - 1
        leftMax = 0
        rightMax = 0
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
    sol = Solution()
    height1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(f"Test 1: {sol.trap(height1)}")
    height2 = [4, 2, 0, 3, 2, 5]
    print(f"Test 2: {sol.trap(height2)}")
