"""
PROBLEM: 4Sum (LeetCode 18)
===============================================
DESCRIPTION:
Given an array nums of n integers, return all unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct
- nums[a] + nums[b] + nums[c] + nums[d] == target

PATTERN: Sorting + Two Pointer (Extended 3Sum)
DIFFICULTY: Medium
TIME COMPLEXITY: O(n³)
SPACE COMPLEXITY: O(1) excluding output

INPUT:
Array of integers and target sum

OUTPUT:
List of quadruplets that sum to target

EXAMPLE:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
"""

from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)
        
        for i in range(n - 3):
            # Skip duplicates for first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            for j in range(i + 1, n - 2):
                # Skip duplicates for second element
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                
                left = j + 1
                right = n - 1
                twoSum = target - nums[i] - nums[j]
                
                while left < right:
                    sum_val = nums[left] + nums[right]
                    if sum_val == twoSum:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        # Skip duplicates for left
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        # Skip duplicates for right
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
                    elif sum_val < twoSum:
                        left += 1
                    else:
                        right -= 1
        
        return result


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [1, 0, -1, 0, -2, 2]
    target1 = 0
    print("Input: ")
    for num in nums1:
        print(num, end=" ")
    print(f"\nTarget: {target1}")
    result1 = sol.fourSum(nums1, target1)
    print(f"Output:")
    for quad in result1:
        print(quad)
    
    nums2 = [2, 2, 2, 2, 2]
    target2 = 8
    print("\nInput: ")
    for num in nums2:
        print(num, end=" ")
    print(f"\nTarget: {target2}")
    result2 = sol.fourSum(nums2, target2)
    print(f"Output:")
    for quad in result2:
        print(quad)
