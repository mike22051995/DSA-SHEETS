"""
PROBLEM: Find Minimum in Rotated Sorted Array
Difficulty: Easy
Pattern: Modified Binary Search

DESCRIPTION:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.

EXPLANATION:
Binary search approach:
- If nums[mid] > nums[right], minimum is in right half
- Otherwise, minimum is in left half (including mid)
- The inflection point is the minimum element

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: Original array was [1,2,3,4,5] rotated 3 times

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: Original array was [0,1,2,4,5,6,7] rotated 4 times

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: Array is not rotated
"""

from typing import List, Optional

class Solution:
    def findMin(self, nums):
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[right]:
                # Minimum is in right half
                left = mid + 1
            else:
                # Minimum is in left half (including mid)
                right = mid
        return nums[left]


if __name__ == "__main__":
    solution = Solution()
    nums1 = [3, 4, 5, 1, 2]
    print(f"Test 1: {solution.findMin(nums1)}")
    nums2 = [4, 5, 6, 7, 0, 1, 2]
    print(f"Test 2: {solution.findMin(nums2)}")
    nums3 = [11, 13, 15, 17]
    print(f"Test 3: {solution.findMin(nums3)}")
