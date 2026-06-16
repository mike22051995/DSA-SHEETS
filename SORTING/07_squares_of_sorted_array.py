"""
PROBLEM: Squares of a Sorted Array (LeetCode 977)
===============================================
DESCRIPTION:
Given an integer array sorted in non-decreasing order, return an array of the 
squares of each number sorted in non-decreasing order.

PATTERN: Two Pointer + Merge
DIFFICULTY: Easy
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for output array

INPUT:
Sorted array (can contain negative numbers)

OUTPUT:
Sorted array of squares

EXAMPLE:
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
"""

from typing import List, Optional

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        left = 0
        right = n - 1
        
        # Fill result array from right to left (largest squares first)
        for pos in range(n - 1, -1, -1):
            leftSquare = nums[left] * nums[left]
            rightSquare = nums[right] * nums[right]
            
            if leftSquare > rightSquare:
                result[pos] = leftSquare
                left += 1
            else:
                result[pos] = rightSquare
                right -= 1
        
        return result


if __name__ == "__main__":
    sol = Solution()
    nums1 = [-4, -1, 0, 3, 10]
    nums2 = [-7, -3, 2, 3, 11]
    
    print("Test Case 1:")
    print("Input: ", nums1)
    result1 = sol.sortedSquares(nums1)
    print("Output: ", result1)
    
    print("\nTest Case 2:")
    print("Input: ", nums2)
    result2 = sol.sortedSquares(nums2)
    print("Output: ", result2)
