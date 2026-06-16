"""
PROBLEM: Bitwise AND of Numbers Range
=======================================
Given two integers left and right representing a range [left, right],
return the bitwise AND of all numbers in this range.

APPROACH:
- Find the common prefix of left and right in binary
- All bits after the common prefix will be 0 in the result
- Keep right shifting both numbers until they're equal
- Then left shift back to get the result

PATTERN: Range Bitwise Operations - Common Prefix

INPUT/OUTPUT:
Input: left = 5, right = 7
Output: 4
Explanation: 5 (101) & 6 (110) & 7 (111) = 4 (100)

Input: left = 1, right = 2147483647
Output: 0
Explanation: Range includes 0 somewhere, result is 0

TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def rangeBitwiseAnd(self, left, right):
        shift = 0
        # Find common prefix by right shifting until equal
        while left < right:
        left >>= 1
        right >>= 1
        shift += 1
        # Left shift back to get the result
        return left << shift


if __name__ == "__main__":
    sol = Solution()
    left1 = 5, right1 = 7
    print(f"Input: left = {left1}")
    print(f"Output: {sol.rangeBitwiseAnd(left1,}")
    print(f"Explanation: 5(101) & 6(110) & 7(111) = 4(100)")
    left2 = 0, right2 = 0
    print(f"Input: left = {left2}")
    print(f"Output: {sol.rangeBitwiseAnd(left2,}")
    print(f"Explanation: Single number")
    left3 = 1, right3 = 2147483647
    print(f"Input: left = {left3}")
    print(f"Output: {sol.rangeBitwiseAnd(left3,}")
    print(f"Explanation: Large range, no common prefix")
