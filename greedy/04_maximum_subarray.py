"""
PROBLEM: Maximum Subarray (Kadane's Algorithm) (LeetCode 53)
DIFFICULTY: Easy
PATTERN: Running Sum with Reset Strategy

DESCRIPTION:
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

INPUT:
- nums: array of integers

OUTPUT:
- Maximum sum of contiguous subarray

APPROACH (Kadane's Algorithm):
1. Keep track of current sum and maximum sum
2. At each element, decide: extend current subarray or start fresh from current element
3. Greedy choice: if current sum becomes negative, reset it (start new subarray)

WHY GREEDY WORKS:
If sum of elements up to index i is negative, including them can only decrease 
the sum of any subarray starting after i. So we greedily discard them.
"""

from typing import List, Optional

class Solution:
    def maxSubArray(self, nums):
        currentSum = 0
        maxSum = INT_MIN
        for num in nums:
        currentSum += num
        maxSum = max(maxSum, currentSum)
        # Greedy reset: if sum becomes negative, start fresh
        if currentSum < 0:
        currentSum = 0
        return maxSum


if __name__ == "__main__":
    sol = Solution()
    nums1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(f"Test 1 - Array: [-2,1,-3,4,-1,2,1,-5,4]")
    print(f"Output: {sol.maxSubArray(nums1)}")
    print(f"Expected: 6 (subarray [4,-1,2,1])")
    nums2 = [1]
    print(f"Test 2 - Array: [1]")
    print(f"Output: {sol.maxSubArray(nums2)}")
    print(f"Expected: 1")
    nums3 = [5, 4, -1, 7, 8]
    print(f"Test 3 - Array: [5,4,-1,7,8]")
    print(f"Output: {sol.maxSubArray(nums3)}")
    print(f"Expected: 23 (entire array)")
    nums4 = [-1, -2, -3, -4]
    print(f"Test 4 - Array: [-1,-2,-3,-4]")
    print(f"Output: {sol.maxSubArray(nums4)}")
    print(f"Expected: -1")
