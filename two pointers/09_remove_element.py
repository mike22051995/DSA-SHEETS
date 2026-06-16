"""
PROBLEM: Remove Element
---------------------------------------------------------------------------
Given an integer array nums and an integer val, remove all occurrences of 
val in nums in-place. Return the number of elements in nums which are not 
equal to val.

PATTERN: Fast-Slow Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Function returns 2, with first two elements being 2.

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,3,0,4,_,_,_]
Explanation: Function returns 5, with first five elements 0,1,3,0,4.
"""

from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slow = 0  # Position to place next non-val element
        for fast in range(len(nums)):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
        return slow


if __name__ == "__main__":
    sol = Solution()
    nums1 = [3, 2, 2, 3]
    val1 = 3
    len1 = sol.removeElement(nums1, val1)
    print(f"Test 1: Length = {len1}, nums = {nums1[:len1]}")
    nums2 = [0, 1, 2, 2, 3, 0, 4, 2]
    val2 = 2
    len2 = sol.removeElement(nums2, val2)
    print(f"Test 2: Length = {len2}, nums = {nums2[:len2]}")
