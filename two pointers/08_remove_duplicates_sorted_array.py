"""
PROBLEM: Remove Duplicates from Sorted Array
---------------------------------------------------------------------------
Given an integer array nums sorted in non-decreasing order, remove the 
duplicates in-place such that each unique element appears only once. 
Return the number of unique elements in nums.

PATTERN: Fast-Slow Two Pointers (Same Direction)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Function returns 2, with first two elements being 1 and 2.

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Function returns 5, with first five elements being 0,1,2,3,4
"""

from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        slow = 0  # Position to place next unique element
        for fast in range(1, len(nums)):
            if nums[fast] != nums[slow]:
                slow += 1
                nums[slow] = nums[fast]
        return slow + 1


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 1, 2]
    len1 = sol.removeDuplicates(nums1)
    print(f"Test 1: Length = {len1}, nums = {nums1[:len1]}")
    nums2 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    len2 = sol.removeDuplicates(nums2)
    print(f"Test 2: Length = {len2}, nums = {nums2[:len2]}")
