"""
PROBLEM: Sort Colors (Dutch National Flag)
---------------------------------------------------------------------------
Given an array nums with n objects colored red, white, or blue (represented 
by integers 0, 1, and 2), sort them in-place so that objects of the same 
color are adjacent, with colors in order red, white, and blue.

PATTERN: Three Pointers (Dutch National Flag)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
"""

from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        low = 0       # Boundary for 0s
        mid = 0       # Current element
        high = len(nums) - 1  # Boundary for 2s
        while mid <= high:
            if nums[mid] == 0:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:  # nums[mid] == 2
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1


if __name__ == "__main__":
    sol = Solution()
    nums1 = [2, 0, 2, 1, 1, 0]
    sol.sortColors(nums1)
    print(f"Test 1: {nums1}")
    nums2 = [2, 0, 1]
    sol.sortColors(nums2)
    print(f"Test 2: {nums2}")
