"""
PROBLEM: Subarray Product Less Than K
---------------------------------------------------------------------------
Given an array of integers nums and an integer k, return the number of 
contiguous subarrays where the product of all the elements in the subarray 
is strictly less than k.

PATTERN: Sliding Window (Variable Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: [10],[5],[2],[6],[10,5],[5,2],[2,6],[5,2,6]

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
Explanation: No subarray has product < 0.
"""

from typing import List


class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        left = 0
        product = 1
        count = 0
        for right in range(len(nums)):
            product *= nums[right]
            # Shrink window while product >= k
            while product >= k:
                product //= nums[left]
                left += 1
            # All subarrays ending at right with valid products
            count += right - left + 1
        return count


if __name__ == "__main__":
    sol = Solution()
    nums1 = [10, 5, 2, 6]
    k1 = 100
    print(f"Test 1: {sol.numSubarrayProductLessThanK(nums1, k1)}")
    nums2 = [1, 2, 3]
    k2 = 0
    print(f"Test 2: {sol.numSubarrayProductLessThanK(nums2, k2)}")
