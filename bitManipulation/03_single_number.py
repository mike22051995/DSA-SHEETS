"""
PROBLEM: Single Number (Find the Unique Element)
==================================================
Given a non-empty array where every element appears twice except one, 
find that single element.

APPROACH:
- XOR of two same numbers is 0
- XOR of a number with 0 is the number itself
- XOR all elements: duplicates cancel out, single element remains

PATTERN: XOR Properties - Finding Unique Element

INPUT/OUTPUT:
Input: nums = [2,2,1]
Output: 1

Input: nums = [4,1,2,1,2]
Output: 4

Input: nums = [1]
Output: 1

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def singleNumber(self, nums):
        result = 0
        # XOR all elements
        # a ^ a = 0, a ^ 0 = a
        for num in nums:
        result ^= num
        return result


if __name__ == "__main__":
    sol = Solution()
    nums1 = [2, 2, 1]
    print(f"Input: [2,2,1]")
    print(f"Output: {sol.singleNumber(nums1)}")
    print(f"Explanation: 2 appears twice, 1 is unique")
    nums2 = [4, 1, 2, 1, 2]
    print(f"Input: [4,1,2,1,2]")
    print(f"Output: {sol.singleNumber(nums2)}")
    print(f"Explanation: 1 and 2 appear twice, 4 is unique")
    nums3 = [1]
    print(f"Input: [1]")
    print(f"Output: {sol.singleNumber(nums3)}")
    print(f"Explanation: Only one element")
