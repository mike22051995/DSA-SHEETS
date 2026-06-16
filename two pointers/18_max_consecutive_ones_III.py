"""
PROBLEM: Max Consecutive Ones III
---------------------------------------------------------------------------
Given a binary array nums and an integer k, return the maximum number of 
consecutive 1's in the array if you can flip at most k 0's.

PATTERN: Sliding Window (Variable Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: Flip the two 0's at indices 4,5. Result: [1,1,1,0,0,1,1,1,1,1,1]

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: Flip 0's at indices 4,5,9. Max consecutive 1's = 10.
"""

from typing import List


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = 0
        zeros = 0
        maxLen = 0
        for right in range(len(nums)):
            if nums[right] == 0:
                zeros += 1
            # Shrink window if we have more than k zeros
            while zeros > k:
                if nums[left] == 0:
                    zeros -= 1
                left += 1
            maxLen = max(maxLen, right - left + 1)
        return maxLen


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0]
    k1 = 2
    print(f"Test 1: {sol.longestOnes(nums1, k1)}")
    nums2 = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1]
    k2 = 3
    print(f"Test 2: {sol.longestOnes(nums2, k2)}")
