"""
PROBLEM: Vertical Lines to Trap Rain Water (LeetCode 42 - Advanced Greedy)
DIFFICULTY: Hard
PATTERN: Two Pointer Greedy Optimization

DESCRIPTION:
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

INPUT:
- height: array of non-negative integers

OUTPUT:
- Total water trapped

APPROACH:
1. Use two pointers from both ends
2. Track leftMax and rightMax
3. Move pointer with smaller max
4. Water at current position = min(leftMax, rightMax) - height[i]
5. Greedy: process from smaller side

WHY GREEDY WORKS:
Water level at position depends on minimum of max heights on both sides.
By processing from smaller side, we ensure we know the limiting height.
"""

from typing import List, Optional

class Solution:
    def trap(self, height):
        public:
        int trap(vector<int>& height):
        if (not height) return 0
        left = 0, right = len(height) - 1
        leftMax = 0, rightMax = 0
        water = 0
        while left < right:
        if height[left] < height[right]:
        # Process left side
        if height[left] >= leftMax:
        leftMax = height[left]
        } else 
        water += leftMax - height[left]
        left += 1
        } else 
        # Process right side
        if height[right] >= rightMax:
        rightMax = height[right]
        } else 
        water += rightMax - height[right]
        right -= 1
        return water
        # Alternative: Using extra space (easier to understand)
        int trapWithExtraSpace(vector<int>& height):
        n = len(height)
        if (n == 0) return 0
        leftMax(n), rightMax(n)
        # Fill leftMax
        leftMax[0] = height[0]
        for i in range(1, n):
        leftMax[i] = max(leftMax[i-1], height[i])
        # Fill rightMax
        rightMax[n-1] = height[n-1]
        for i in range(n-2, 0 - 1, -1):
        rightMax[i] = max(rightMax[i+1], height[i])
        # Calculate water
        water = 0
        for i in range(n):
        water += min(leftMax[i], rightMax[i]) - height[i]
        return water


if __name__ == "__main__":
    sol = Solution()
    height1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(f"Test 1 - Height: [0,1,0,2,1,0,1,3,2,1,2,1]")
    print(f"Output: {sol.trap(height1)}")
    print(f"Expected: 6")
    height2 = [4, 2, 0, 3, 2, 5]
    print(f"Test 2 - Height: [4,2,0,3,2,5]")
    print(f"Output: {sol.trap(height2)}")
    print(f"Expected: 9")
    height3 = [4, 2, 3]
    print(f"Test 3 - Height: [4,2,3]")
    print(f"Output: {sol.trap(height3)}")
    print(f"Expected: 1")
    height4 = [5, 4, 1, 2]
    print(f"Test 4 - Height: [5,4,1,2]")
    print(f"Output: {sol.trap(height4)}")
    print(f"Expected: 1")
