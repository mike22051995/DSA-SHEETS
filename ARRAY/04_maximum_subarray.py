"""
PROBLEM: Maximum Subarray (Kadane's Algorithm)
Difficulty: Easy
Pattern: Dynamic Programming, Kadane's Algorithm

DESCRIPTION:
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

EXPLANATION:
Kadane's Algorithm: We maintain a running sum of the current subarray.
If the running sum becomes negative, we reset it to 0 (start a new subarray).
We keep track of the maximum sum seen so far.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6

Example 2:
Input: nums = [1]
Output: 1
Explanation: Single element array

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: [5,4,-1,7,8] has the largest sum = 23
"""

from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = nums[0]
        current_sum = nums[0]
        
        for i in range(1, len(nums)):
            # Either extend the existing subarray or start a new one
            current_sum = max(nums[i], current_sum + nums[i])
            
            # Update maximum sum
            max_sum = max(max_sum, current_sum)
        
        return max_sum

if __name__ == "__main__":
    solution = Solution()
    
    # Test Case 1
    nums1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(f"Test 1: {solution.maxSubArray(nums1)}")
    
    # Test Case 2
    nums2 = [1]
    print(f"Test 2: {solution.maxSubArray(nums2)}")
    
    # Test Case 3
    nums3 = [5, 4, -1, 7, 8]
    print(f"Test 3: {solution.maxSubArray(nums3)}")
