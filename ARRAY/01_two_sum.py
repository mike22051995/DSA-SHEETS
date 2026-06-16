"""
PROBLEM: Two Sum
Difficulty: Easy
Pattern: Hash Map

DESCRIPTION:
Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target. You may assume that each input would have exactly one 
solution, and you may not use the same element twice.

EXPLANATION:
We use a hash map to store the complement (target - current number) we're looking for.
As we iterate through the array, we check if the current number exists in the hash map.
If it does, we found our pair. Otherwise, we store the current number and its index.

Time Complexity: O(n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Explanation: nums[1] + nums[2] = 2 + 4 = 6

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
"""

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        
        for i in range(len(nums)):
            complement = target - nums[i]
            
            # Check if complement exists in map
            if complement in num_map:
                return [num_map[complement], i]
            
            # Store current number and its index
            num_map[nums[i]] = i
        
        return []  # No solution found

if __name__ == "__main__":
    solution = Solution()
    
    # Test Case 1
    nums1 = [2, 7, 11, 15]
    target1 = 9
    result1 = solution.twoSum(nums1, target1)
    print(f"Test 1: {result1}")
    
    # Test Case 2
    nums2 = [3, 2, 4]
    target2 = 6
    result2 = solution.twoSum(nums2, target2)
    print(f"Test 2: {result2}")
    
    # Test Case 3
    nums3 = [3, 3]
    target3 = 6
    result3 = solution.twoSum(nums3, target3)
    print(f"Test 3: {result3}")
