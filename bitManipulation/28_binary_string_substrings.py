"""
PROBLEM: Binary String with Substrings Representing 1 to N
============================================================
Given a binary string s and a positive integer n, return True if every 
integer from 1 to n has a binary representation as a substring of s.

APPROACH:
- Generate binary representation of each number from 1 to n
- Check if it exists as substring in s
- Optimization: Start from n and go backwards (larger numbers less likely)

PATTERN: Binary Representation Matching

INPUT/OUTPUT:
Input: s = "0110", n = 3
Output: True
Explanation: "1"(1), "10"(2), "11"(3) all exist in "0110"

Input: s = "0110", n = 4
Output: False
Explanation: "100"(4) doesn't exist in "0110"

TIME COMPLEXITY: O(n * log n) - converting to binary and searching
SPACE COMPLEXITY: O(log n) - for binary string
"""

from typing import List, Optional

class Solution:
    def queryString(self, s, n):
        # Check from n down to 1 (optimization)
        for i in range(n, 1 - 1, -1):
        binary = toBinary(i)
        if (s.find(binary) == string::npos):
        return False
        return True


if __name__ == "__main__":
    sol = Solution()
    s1 = "0110"
    n1 = 3
    print(f"Input: s = \{s1}")
    print(f"Output: {(sol.queryString(s1,}")
    print(f"Explanation: 1(1), 10(2), 11(3) all exist")
    print(f"Checking:")
    for (i = 1; i <= n1; i++) 
    bin = ""
    temp = i
    while (temp) [ bin = (char)('0' + (temp & 1)) + bin; temp >>= 1; ]
    print(f"  {i}")
    print()
    s2 = "0110"
    n2 = 4
    print(f"Input: s = \{s2}")
    print(f"Output: {(sol.queryString(s2,}")
    print(f"Explanation: 100(4) doesn't exist")
    s3 = "1111100000"
    n3 = 5
    print(f"Input: s = \{s3}")
    print(f"Output: {(sol.queryString(s3,}")
    print(f"Explanation: All binary from 1 to 5 exist")
