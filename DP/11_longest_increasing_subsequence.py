"""
PROBLEM: Longest Increasing Subsequence (LIS)
Difficulty: Medium
Pattern: 1D DP, Subsequence

DESCRIPTION:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

INPUT:
nums = [10, 9, 2, 5, 3, 7, 101, 18]

OUTPUT:
4
Explanation: The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.

TIME COMPLEXITY: O(n^2) for DP, O(n log n) for Binary Search approach
SPACE COMPLEXITY: O(n)
"""

from typing import List, Optional

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        
        dp = [1] * n  # dp[i] = length of LIS ending at index i
        maxLen = 1
        
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
            maxLen = max(maxLen, dp[i])
        
        return maxLen
    
    def lengthOfLISOptimal(self, nums: List[int]) -> int:
        """Binary search approach - O(n log n)"""
        if not nums:
            return 0
        
        tails = []  # tails[i] is the smallest tail of all increasing subsequences of length i+1
        
        for num in nums:
            # Binary search for the position to insert/replace
            left, right = 0, len(tails)
            while left < right:
                mid = (left + right) // 2
                if tails[mid] < num:
                    left = mid + 1
                else:
                    right = mid
            
            # If left == len(tails), we found a new largest element
            if left == len(tails):
                tails.append(num)
            else:
                tails[left] = num
        
        return len(tails)


if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [10, 9, 2, 5, 3, 7, 101, 18]
    print(f"Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]")
    print(f"Output: {sol.lengthOfLIS(nums1)}")
    print(f"Output (Optimal): {sol.lengthOfLISOptimal(nums1)}")
    print()
    
    nums2 = [0, 1, 0, 3, 2, 3]
    print(f"Input: nums = [0, 1, 0, 3, 2, 3]")
    print(f"Output: {sol.lengthOfLIS(nums2)}")
    print(f"Output (Optimal): {sol.lengthOfLISOptimal(nums2)}")
