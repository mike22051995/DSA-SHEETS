"""
PROBLEM: Gray Code
===================
Generate n-bit Gray code sequence. Gray code is a binary sequence where 
two successive values differ in only one bit.

APPROACH:
- Gray code formula: gray(i) = i ^ (i >> 1)
- For n bits, generate numbers from 0 to 2^n-1
- Apply Gray code formula to each number

PATTERN: Gray Code Generation - XOR with Right Shift

INPUT/OUTPUT:
Input: n = 2
Output: [0,1,3,2]
Explanation: 
00 (0)
01 (1)
11 (3)
10 (2)

Input: n = 3
Output: [0,1,3,2,6,7,5,4]

TIME COMPLEXITY: O(2^n)
SPACE COMPLEXITY: O(2^n) for output
"""

from typing import List, Optional

class Solution:
    def for(self, i++):
        public:
        grayCode(int n):
        result
        size = 1 << n; # 2^n
        for i in range(size):
        # Gray code formula: i XOR (i >> 1)
        gray = i ^ (i >> 1)
        result.append(gray)
        return result
        # Alternative: Reflective method
        grayCodeReflective(int n):
        result = {0}
        for i in range(n):
        size = len(result)
        # Add reflected sequence with MSB set
        for j in range(size - 1, 0 - 1, -1):
        result.append(result[j] | (1 << i))
        return result


if __name__ == "__main__":
    sol = Solution()
    n1 = 2
    print(f"Input: {n1}")
    result1 = sol.grayCode(n1)
    print("Output: [")
    for (i = 0; i < len(result1); i++) 
    print(result1[i], end="")
    print(",")
    print(f"]")
    print(f"Binary representation:")
    for val in result1:
    printBinary(val, n1)
    print(f" ({val}")
    print()
    n2 = 3
    print(f"Input: {n2}")
    result2 = sol.grayCode(n2)
    print("Output: [")
    for (i = 0; i < len(result2); i++) 
    print(result2[i], end="")
    print(",")
    print(f"]")
    print(f"Binary representation:")
    for val in result2:
    printBinary(val, n2)
    print(f" ({val}")
