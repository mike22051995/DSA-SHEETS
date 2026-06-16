"""
PROBLEM: Power(x, n)
---------------------------------------------------------------------------
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

DIFFICULTY: Easy-Medium
PATTERN: Divide and Conquer Recursion
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(log n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000
Explanation: 2^10 = 1024

Example 2:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/(2^2) = 1/4 = 0.25
"""

from typing import List, Optional

class Solution:
    def myPow(self, x: float, n: int) -> float:
        def fastPow(x: float, n: int) -> float:
            if n == 0:
                return 1.0
            
            half = fastPow(x, n // 2)
            
            if n % 2 == 0:
                return half * half
            else:
                return half * half * x
        
        N = n
        if N < 0:
            x = 1 / x
            N = -N
        
        return fastPow(x, N)


if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    x1 = 2.0
    n1 = 10
    result1 = sol.myPow(x1, n1)
    print(f"Test 1: {x1}^{n1} = {result1}")
    
    # Test 2
    x2 = 2.0
    n2 = -2
    result2 = sol.myPow(x2, n2)
    print(f"Test 2: {x2}^{n2} = {result2}")
