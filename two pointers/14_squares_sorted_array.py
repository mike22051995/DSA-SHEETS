"""
PROBLEM: Squares of a Sorted Array
---------------------------------------------------------------------------
Given an integer array nums sorted in non-decreasing order, return an array 
of the squares of each number sorted in non-decreasing order.

PATTERN: Opposite Direction Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: Squares are [16,1,0,9,100]. After sorting: [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
"""

from typing import List


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        left = 0
        right = n - 1
        pos = n - 1  # Fill from the end
        while left <= right:
            leftSquare = nums[left] * nums[left]
            rightSquare = nums[right] * nums[right]
            if leftSquare > rightSquare:
                result[pos] = leftSquare
                left += 1
            else:
                result[pos] = rightSquare
                right -= 1
            pos -= 1
        return result


if __name__ == "__main__":
    sol = Solution()
    nums1 = [-4, -1, 0, 3, 10]
    result1 = sol.sortedSquares(nums1)
    print(f"Test 1: {result1}")
    nums2 = [-7, -3, 2, 3, 11]
    result2 = sol.sortedSquares(nums2)
    print(f"Test 2: {result2}")
