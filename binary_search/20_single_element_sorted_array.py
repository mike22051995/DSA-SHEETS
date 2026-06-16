"""
PROBLEM: Single Element in a Sorted Array
Difficulty: Medium
Pattern: Binary Search

DESCRIPTION:
You are given a sorted array consisting of only integers where every element appears exactly 
twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

EXPLANATION:
Binary search with parity checking:
- In a valid section, pairs start at even indices
- If single element is on right, pairs start at odd indices before mid
- Check mid and its neighbor, adjust search based on index parity

Time Complexity: O(log n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

Example 3:
Input: nums = [1]
Output: 1
"""

from typing import List, Optional

class Solution:
    def singleNonDuplicate(self, nums):
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            # Make mid even
            if mid % 2 == 1:
                mid -= 1
            # Check if pair is intact
            if nums[mid] == nums[mid + 1]:
                # Single element is on right
                left = mid + 2
            else:
                # Single element is on left
                right = mid
        return nums[left]


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 1, 2, 3, 3, 4, 4, 8, 8]
    print(f"Test 1: {solution.singleNonDuplicate(nums1)}")
    nums2 = [3, 3, 7, 7, 10, 11, 11]
    print(f"Test 2: {solution.singleNonDuplicate(nums2)}")
    nums3 = [1]
    print(f"Test 3: {solution.singleNonDuplicate(nums3)}")
