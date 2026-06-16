"""
PROBLEM: Minimum Size Subarray Sum
---------------------------------------------------------------------------
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal 
to target. If there is no such subarray, return 0.

PATTERN: Sliding Window (Variable Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: Subarray [4,3] has minimal length with sum >= 7.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1
Explanation: Subarray [4] has minimal length with sum >= 4.
"""

from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        total = 0
        minLen = float('inf')
        for right in range(len(nums)):
            total += nums[right]
            # Shrink window while sum >= target
            while total >= target:
                minLen = min(minLen, right - left + 1)
                total -= nums[left]
                left += 1
        return 0 if minLen == float('inf') else minLen


if __name__ == "__main__":
    sol = Solution()
    nums1 = [2, 3, 1, 2, 4, 3]
    target1 = 7
    print(f"Test 1: {sol.minSubArrayLen(target1, nums1)}")
    nums2 = [1, 4, 4]
    target2 = 4
    print(f"Test 2: {sol.minSubArrayLen(target2, nums2)}")
