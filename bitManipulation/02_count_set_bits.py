"""
PROBLEM: Count Set Bits (Hamming Weight)
==========================================
Given an integer n, count the number of 1's in its binary representation.

APPROACH:
- Method 1: Use Brian Kernighan's Algorithm
- n & (n-1) clears the rightmost set bit
- Keep doing this until n becomes 0
- Count the number of operations

PATTERN: Brian Kernighan's Algorithm - Count Set Bits

INPUT/OUTPUT:
Input: n = 11
Output: 3
Explanation: 11 in binary is 1011, which has 3 set bits

Input: n = 128
Output: 1
Explanation: 128 in binary is 10000000, which has 1 set bit

TIME COMPLEXITY: O(log n) or O(number of set bits)
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def countSetBits(self, n):
        count = 0
        # Brian Kernighan's Algorithm
        while n > 0:
        n = n & (n - 1);  # Remove rightmost set bit
        count += 1
        return count


if __name__ == "__main__":
    sol = Solution()
    n1 = 11
    print(f"Input: {n1}")
    print(f"Output: {sol.countSetBits(n1)}")
    print(f"Explanation: 11 in binary is 1011 (3 set bits)")
    n2 = 128
    print(f"Input: {n2}")
    print(f"Output: {sol.countSetBits(n2)}")
    print(f"Explanation: 128 in binary is 10000000 (1 set bit)")
    n3 = 15
    print(f"Input: {n3}")
    print(f"Output: {sol.countSetBits(n3)}")
    print(f"Explanation: 15 in binary is 1111 (4 set bits)")
