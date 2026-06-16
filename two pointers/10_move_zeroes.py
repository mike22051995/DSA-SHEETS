"""
PROBLEM: Move Zeroes
---------------------------------------------------------------------------
Given an integer array nums, move all 0's to the end of it while maintaining 
the relative order of the non-zero elements. Must do this in-place without 
making a copy of the array.

PATTERN: Fast-Slow Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0,0,1]
Output: [1,0,0]
"""

from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        slow = 0  # Position to place next non-zero element
        # Move all non-zero elements to the front
        for fast in range(len(nums)):
            if nums[fast] != 0:
                nums[slow] = nums[fast]
                slow += 1
        # Fill remaining positions with zeros
        for i in range(slow, len(nums)):
            nums[i] = 0


if __name__ == "__main__":
    sol = Solution()
    nums1 = [0, 1, 0, 3, 12]
    sol.moveZeroes(nums1)
    print(f"Test 1: {nums1}")
    nums2 = [0, 0, 1]
    sol.moveZeroes(nums2)
    print(f"Test 2: {nums2}")
