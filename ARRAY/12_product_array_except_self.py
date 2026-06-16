"""
PROBLEM: Product of Array Except Self
Difficulty: Medium
Pattern: Prefix and Suffix Product

DESCRIPTION:
Given an integer array nums, return an array answer such that answer[i] is equal to the 
product of all the elements of nums except nums[i]. You must write an algorithm that runs 
in O(n) time and without using the division operation.

EXPLANATION:
Two-pass approach:
1. Calculate prefix products (product of all elements before i)
2. Calculate suffix products (product of all elements after i)
3. Result[i] = prefix[i] * suffix[i]
We can optimize space by calculating suffix on the fly.

Time Complexity: O(n)
Space Complexity: O(1) excluding output array

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Explanation: 24 = 2*3*4, 12 = 1*3*4, 8 = 1*2*4, 6 = 1*2*3

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
Explanation: Products involving 0

Example 3:
Input: nums = [2,3,4,5]
Output: [60,40,30,24]
"""
from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1] * n
        # Calculate prefix products
        prefix = 1
        for i in range(n):
            result[i] = prefix
            prefix *= nums[i]
        # Multiply with suffix products
        suffix = 1
        for i in range(n - 1, -1, -1):
            result[i] *= suffix
            suffix *= nums[i]
        return result


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 2, 3, 4]
    print(f"Test 1: {solution.productExceptSelf(nums1)}")
    nums2 = [-1, 1, 0, -3, 3]
    print(f"Test 2: {solution.productExceptSelf(nums2)}")
    nums3 = [2, 3, 4, 5]
    print(f"Test 3: {solution.productExceptSelf(nums3)}")
