"""
PROBLEM: 3Sum (LeetCode 15)
===============================================
DESCRIPTION:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

PATTERN: Sorting + Two Pointer
DIFFICULTY: Medium
TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(1) excluding output

INPUT:
Array of integers

OUTPUT:
List of triplets that sum to zero

EXAMPLE:
Input: [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: [0,1,1]
Output: []
"""

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)
        
        for i in range(n - 2):
            # Skip duplicates for first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            # Early termination: if smallest element > 0, no solution
            if nums[i] > 0:
                break
            
            left = i + 1
            right = n - 1
            target = -nums[i]  # We need two numbers that sum to target
            
            while left < right:
                sum_val = nums[left] + nums[right]
                if sum_val == target:
                    result.append([nums[i], nums[left], nums[right]])
                    # Skip duplicates for left pointer
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    # Skip duplicates for right pointer
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif sum_val < target:
                    left += 1
                else:
                    right -= 1
        
        return result


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [-1, 0, 1, 2, -1, -4]
    print("Input: ")
    for num in nums1:
        print(num, end=" ")
    print()
    result1 = sol.threeSum(nums1)
    print(f"Output:")
    for triplet in result1:
        print(triplet)
    
    nums2 = [0, 0, 0]
    print("\nInput: ")
    for num in nums2:
        print(num, end=" ")
    print()
    result2 = sol.threeSum(nums2)
    print(f"Output:")
    for triplet in result2:
        print(triplet)
