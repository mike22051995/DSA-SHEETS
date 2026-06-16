"""
PROBLEM: Subarray Sum Equals K
Difficulty: Medium
Pattern: Prefix Sum, Hash Map

DESCRIPTION:
Given an array of integers nums and an integer k, return the total number of subarrays 
whose sum equals to k. A subarray is a contiguous non-empty sequence of elements within 
an array.

EXPLANATION:
Use prefix sum with hash map:
- Store cumulative sums and their frequencies
- For each position, check if (currentSum - k) exists in map
- If yes, it means there's a subarray ending at current position with sum = k

Time Complexity: O(n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Explanation: Subarrays [1,1] at positions (0,1) and (1,2)

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
Explanation: Subarrays [1,2] and [3]

Example 3:
Input: nums = [1,-1,0], k = 0
Output: 3
Explanation: Subarrays [-1,1], [0], and [1,-1,0]
"""

from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSumCount = {}
        prefixSumCount[0] = 1  # Empty subarray has sum 0
        currentSum = 0
        count = 0
        for num in nums:
            currentSum += num
            # Check if (currentSum - k) exists
            # If yes, there's a subarray with sum = k
            if currentSum - k in prefixSumCount:
                count += prefixSumCount[currentSum - k]
            # Add current sum to map
            if currentSum in prefixSumCount:
                prefixSumCount[currentSum] += 1
            else:
                prefixSumCount[currentSum] = 1
        return count


if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 1, 1]
    print(f"Test 1: {solution.subarraySum(nums1, 2)}")
    nums2 = [1, 2, 3]
    print(f"Test 2: {solution.subarraySum(nums2, 3)}")
    nums3 = [1, -1, 0]
    print(f"Test 3: {solution.subarraySum(nums3, 0)}")
