"""
PROBLEM: Maximum Product Subarray
Difficulty: Medium
Pattern: 1D DP, Product Optimization

DESCRIPTION:
Given an integer array nums, find a contiguous non-empty subarray within the array that has 
the largest product, and return the product.

INPUT:
nums = [2, 3, -2, 4]

OUTPUT:
6
Explanation: [2, 3] has the largest product 6.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def maxProduct(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        # Track both max and min product ending at current position
        # (min can become max when multiplied by negative number)
        maxProd = nums[0]
        minProd = nums[0]
        result = nums[0]
        for i in range(1, n):
            # If current number is negative, swap max and min
            if nums[i] < 0:
                maxProd, minProd = minProd, maxProd
            # Calculate max and min product ending at current position
            maxProd = max(nums[i], maxProd * nums[i])
            minProd = min(nums[i], minProd * nums[i])
            # Update overall result
            result = max(result, maxProd)
        return result

    def maxProductAlternate(self, nums):
        max_p = min_p = res = nums[0]
        for num in nums[1:]:
            candidates = (num, max_p * num, min_p * num)
            max_p = max(candidates)
            min_p = min(candidates)
            res = max(res, max_p)
        return res


if __name__ == "__main__":
    sol = Solution()
    nums1 = [2, 3, -2, 4]
    print(f"Input: nums = [2, 3, -2, 4]")
    print(f"Output: {sol.maxProduct(nums1)}")
    print(f"Output (Alternate): {sol.maxProductAlternate(nums1)}")
    nums2 = [-2, 0, -1]
    print(f"Input: nums = [-2, 0, -1]")
    print(f"Output: {sol.maxProduct(nums2)}")
    print(f"Output (Alternate): {sol.maxProductAlternate(nums2)}")
    nums3 = [-2, 3, -4]
    print(f"Input: nums = [-2, 3, -4]")
    print(f"Output: {sol.maxProduct(nums3)}")
    print(f"Output (Alternate): {sol.maxProductAlternate(nums3)}")
