"""
PROBLEM: Remove Duplicates from Sorted Array II
---------------------------------------------------------------------------
Given an integer array nums sorted in non-decreasing order, remove some 
duplicates in-place such that each unique element appears at most twice. 
Return the number of elements in nums after removing the extra duplicates.

PATTERN: Fast-Slow Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Function returns 5, with first five elements 1,1,2,2,3.

Example 2:
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Function returns 7, with first seven elements 0,0,1,1,2,3,3.
"""

from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return len(nums)
        slow = 2  # Position to place next valid element
        for fast in range(2, len(nums)):
            # Only add if not same as element two positions back
            if nums[fast] != nums[slow - 2]:
                nums[slow] = nums[fast]
                slow += 1
        return slow


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 1, 1, 2, 2, 3]
    len1 = sol.removeDuplicates(nums1)
    print(f"Test 1: Length = {len1}, nums = {nums1[:len1]}")
    nums2 = [0, 0, 1, 1, 1, 1, 2, 3, 3]
    len2 = sol.removeDuplicates(nums2)
    print(f"Test 2: Length = {len2}, nums = {nums2[:len2]}")
