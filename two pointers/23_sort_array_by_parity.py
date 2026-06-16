"""
PROBLEM: Sort Array By Parity
---------------------------------------------------------------------------
Given an integer array nums, move all the even integers to the beginning 
of the array followed by all the odd integers. Return any array that 
satisfies this condition.

PATTERN: Two Pointers (Partition)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1] (or any array with evens first, then odds)
Explanation: [4,2,3,1], [2,4,1,3], and [4,2,1,3] are also valid.

Example 2:
Input: nums = [0]
Output: [0]
"""

from typing import List, Optional

class Solution:
    def sortArrayByParity(self, nums):
        left = 0
        right = len(nums) - 1
        while left < right:
            # Find odd number from left
            while left < right and nums[left] % 2 == 0:
                left += 1
            # Find even number from right
            while left < right and nums[right] % 2 == 1:
                right -= 1
            # Swap
            if left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        return nums


if __name__ == "__main__":
    sol = Solution()
    nums1 = [3, 1, 2, 4]
    result1 = sol.sortArrayByParity(nums1)
    print("Test 1: [", end="")
    for i in range(len(result1)):
        print(result1[i], end="," if i < len(result1) - 1 else "")
    print("]")
    nums2 = [0]
    result2 = sol.sortArrayByParity(nums2)
    print("Test 2: [", end="")
    for i in range(len(result2)):
        print(result2[i], end="," if i < len(result2) - 1 else "")
    print("]")
