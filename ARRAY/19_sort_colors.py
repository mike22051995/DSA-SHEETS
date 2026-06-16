"""
PROBLEM: Sort Colors (Dutch National Flag)
Difficulty: Medium
Pattern: Three Pointers, Partitioning

DESCRIPTION:
Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

EXPLANATION:
Dutch National Flag Algorithm (Three-way partitioning):
- Use three pointers: low, mid, high
- low tracks the boundary of 0s, high tracks boundary of 2s
- mid scans the array
- Swap elements to maintain: [0s][1s][2s]

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Explanation: All 0s, then 1s, then 2s

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
Explanation: One of each color

Example 3:
Input: nums = [1,2,0]
Output: [0,1,2]
"""

from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        low = 0            # Boundary for 0s
        mid = 0            # Current element
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
                # Don't increment mid, need to check swapped element


if __name__ == "__main__":
    solution = Solution()
    nums1 = [2, 0, 2, 1, 1, 0]
    solution.sortColors(nums1)
    print(f"Test 1: {nums1}")
    nums2 = [2, 0, 1]
    solution.sortColors(nums2)
    print(f"Test 2: {nums2}")
    nums3 = [1, 2, 0]
    solution.sortColors(nums3)
    print(f"Test 3: {nums3}")
