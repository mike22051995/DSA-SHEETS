"""
PROBLEM: Divide Two Integers (Without / or *)
===============================================
Divide two integers without using multiplication, division, or mod operator.
Return the quotient after dividing dividend by divisor.

APPROACH:
- Use bit manipulation with left shift to simulate division
- Keep subtracting (divisor << i) from dividend
- Add (1 << i) to quotient
- Handle edge cases for integer overflow

PATTERN: Division Using Bit Shifts - Arithmetic Operations

INPUT/OUTPUT:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33, truncated to 3

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33, truncated to -2

TIME COMPLEXITY: O(log n)^2
SPACE COMPLEXITY: O(1)
"""

from typing import List, Optional

class Solution:
    def divide(self, dividend, divisor):
        public:
        int divide(int dividend, int divisor):
        # Handle overflow case
        if dividend == INT_MIN and divisor == -1:
        return float('inf')
        # Determine sign of result
        negative = (dividend < 0) ^ (divisor < 0)
        # Work with positive numbers
        long long dvd = abs((long long)dividend)
        long long dvs = abs((long long)divisor)
        long long quotient = 0
        # Keep subtracting divisor from dividend
        while dvd >= dvs:
        long long temp = dvs
        long long multiple = 1
        # Find largest multiple of divisor that fits
        while (dvd >= (temp << 1)):
        temp <<= 1
        multiple <<= 1
        dvd -= temp
        quotient += multiple
        return negative ? -quotient : quotient


if __name__ == "__main__":
    sol = Solution()
    dividend1 = 10, divisor1 = 3
    print(f"Input: dividend = {dividend1}")
    print(f"Output: {sol.divide(dividend1,}")
    print(f"Explanation: 10/3 = 3.33, truncated to 3")
    dividend2 = 7, divisor2 = -3
    print(f"Input: dividend = {dividend2}")
    print(f"Output: {sol.divide(dividend2,}")
    print(f"Explanation: 7/-3 = -2.33, truncated to -2")
    dividend3 = -2147483648, divisor3 = -1
    print(f"Input: dividend = {dividend3}")
    print(f"Output: {sol.divide(dividend3,}")
    print(f"Explanation: Overflow case handled")
