"""
PROBLEM: Remove Duplicates from Sorted Array
Difficulty: Easy
Pattern: Two Pointers

DESCRIPTION:
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place 
such that each unique element appears only once. The relative order of the elements should 
be kept the same. Return the number of unique elements in nums.

EXPLANATION:
Use two pointers: one for the position of unique elements and one to scan the array.
Since the array is sorted, duplicates are adjacent. We only copy elements that are 
different from the previous one.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: First 2 elements should be [1,2]

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: First 5 elements should be [0,1,2,3,4]

Example 3:
Input: nums = [1,2,3]
Output: 3, nums = [1,2,3]
Explanation: All elements are unique
"""

from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        uniquePos = 1  # Position for next unique element
        for i in range(1, len(nums)):
            # If current element is different from previous
            if nums[i] != nums[i - 1]:
                nums[uniquePos] = nums[i]
                uniquePos += 1
        return uniquePos


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 1, 2]
    len1 = solution.removeDuplicates(nums1)
    print(f"Test 1: Length = {len1}, nums = {nums1[:len1]}")
    nums2 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    len2 = solution.removeDuplicates(nums2)
    print(f"Test 2: Length = {len2}, nums = {nums2[:len2]}")
    nums3 = [1, 2, 3]
    len3 = solution.removeDuplicates(nums3)
    print(f"Test 3: Length = {len3}, nums = {nums3[:len3]}")
