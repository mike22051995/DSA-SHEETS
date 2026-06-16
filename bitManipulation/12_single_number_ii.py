"""
PROBLEM: Single Number II (Element Appearing Once, Others Thrice)
===================================================================
Given an array where every element appears three times except one 
which appears once, find that single element.

APPROACH:
- Count bits at each position for all numbers
- If a bit count is divisible by 3, the single number has 0 at that position
- Otherwise, it has 1 at that position
- Reconstruct the number from bit counts

PATTERN: Bit Counting - Advanced XOR Variation

INPUT/OUTPUT:
Input: nums = [2,2,3,2]
Output: 3
Explanation: 2 appears 3 times, 3 appears once

Input: nums = [0,1,0,1,0,1,99]
Output: 99

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def singleNumber(self, nums):
        result = 0
        # Check each bit position (32 bits for int)
        for i in range(32):
        bitCount = 0
        # Count how many numbers have bit set at position i
        for num in nums:
        if ((num >> i) & 1):
        bitCount += 1
        # If count is not divisible by 3, set this bit in result
        if bitCount % 3 != 0:
        result |= (1 << i)
        return result


if __name__ == "__main__":
    sol = Solution()
    nums1 = [2, 2, 3, 2]
    print(f"Input: [2,2,3,2]")
    print(f"Output: {sol.singleNumber(nums1)}")
    print(f"Explanation: 2 appears 3 times, 3 once")
    nums2 = [0, 1, 0, 1, 0, 1, 99]
    print(f"Input: [0,1,0,1,0,1,99]")
    print(f"Output: {sol.singleNumber(nums2)}")
    print(f"Explanation: 0 and 1 appear 3 times, 99 once")
    nums3 = [-2, -2, 1, 1, 4, 1, 4, 4, -2]
    print(f"Input: [-2,-2,1,1,4,1,4,4,-2]")
    print(f"Output: {sol.singleNumber(nums3)}")
    print(f"Explanation: Works with negative numbers too")
