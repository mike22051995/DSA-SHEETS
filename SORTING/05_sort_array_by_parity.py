"""
PROBLEM: Sort Array By Parity (LeetCode 905)
===============================================
DESCRIPTION:
Given an array of integers, move all the even integers to the beginning of the 
array followed by all the odd integers. Return any array that satisfies this condition.

PATTERN: Two Pointer / Partition
DIFFICULTY: Easy
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT:
Array of integers

OUTPUT:
Array with all even numbers before odd numbers

EXAMPLE:
Input: [3,1,2,4]
Output: [2,4,3,1] (or any valid arrangement)
"""

from typing import List, Optional

class Solution:
    # Approach 1: Two Pointer with inner while loops
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        left = 0
        right = len(nums) - 1
        
        while left < right:
            # Skip even numbers from left
            while left < right and nums[left] % 2 == 0:
                left += 1
            # Skip odd numbers from right
            while left < right and nums[right] % 2 != 0:
                right -= 1
            # Swap odd from left with even from right
            if left < right:
                nums[left], nums[right] = nums[right], nums[left]
        
        return nums
    
    # Approach 2: Partition approach (similar to quicksort partition)
    def sortArrayByParityV2(self, nums: List[int]) -> List[int]:
        j = 0  # Position for next even number
        
        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
        
        return nums


if __name__ == "__main__":
    sol = Solution()
    nums1 = [3, 1, 2, 4]
    nums2 = [3, 1, 2, 4]
    
    print("Original array: ")
    for num in nums1:
        print(num, end=" ")
    print()
    
    sol.sortArrayByParity(nums1)
    print("Approach 1 (Two Pointer): ")
    for num in nums1:
        print(num, end=" ")
    print()
    
    sol.sortArrayByParityV2(nums2)
    print("Approach 2 (Partition): ")
    for num in nums2:
        print(num, end=" ")
    print()
