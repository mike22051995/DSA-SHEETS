"""
PROBLEM: Contains Duplicate
Difficulty: Easy
Pattern: Hash Set

DESCRIPTION:
Given an integer array nums, return True if any value appears at least twice in the array, 
and return False if every element is distinct.

EXPLANATION:
We use a hash set to track numbers we've seen. If we encounter a number that's already 
in the set, we found a duplicate. Otherwise, we add it to the set.

Time Complexity: O(n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,2,3,1]
Output: True
Explanation: 1 appears twice

Example 2:
Input: nums = [1,2,3,4]
Output: False
Explanation: All elements are distinct

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: True
Explanation: Multiple duplicates exist
"""

from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        
        for num in nums:
            # If number already exists in set, we found a duplicate
            if num in seen:
                return True
            seen.add(num)
        
        return False

if __name__ == "__main__":
    solution = Solution()
    
    # Test Case 1
    nums1 = [1, 2, 3, 1]
    print(f"Test 1: {solution.containsDuplicate(nums1)}")
    
    # Test Case 2
    nums2 = [1, 2, 3, 4]
    print(f"Test 2: {solution.containsDuplicate(nums2)}")
    
    # Test Case 3
    nums3 = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
    print(f"Test 3: {solution.containsDuplicate(nums3)}")
