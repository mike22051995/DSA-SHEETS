"""
PROBLEM: Sort Colors / Dutch National Flag Problem (LeetCode 75)
===============================================
DESCRIPTION:
Given an array with n objects colored red, white, or blue, sort them in-place so 
that objects of the same color are adjacent, with colors in order red, white, blue.
Use integers 0, 1, and 2 to represent red, white, and blue respectively.

PATTERN: Three Pointer / Dutch National Flag
DIFFICULTY: Easy-Medium
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers (0, 1, 2)

OUTPUT:
Sorted array with all 0s, then 1s, then 2s

EXAMPLE:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
"""

from typing import List, Optional

class Solution:
    def sortColors(self, nums):
        low = 0;              # Boundary for 0s
        mid = 0;              # Current element
        high = len(nums) - 1; # Boundary for 2s
        while mid <= high:
            if nums[mid] == 0:
                # Found 0, swap with low boundary and move both forward
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                # Found 1, it's in correct region, just move mid
                mid += 1
            else:
                # Found 2, swap with high boundary and move high backward
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1
                # Don't increment mid as we need to check swapped element
        return nums


if __name__ == "__main__":
    sol = Solution()
    nums = [2, 0, 2, 1, 1, 0]
    print("Original array: ")
    for num in nums:
        print(num, end=" ")
    print()
    sol.sortColors(nums)
    print("Sorted array: ")
    for num in nums:
        print(num, end=" ")
    print()
