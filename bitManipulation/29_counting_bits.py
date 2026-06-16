"""
PROBLEM: Counting Bits (DP Approach)
======================================
Given an integer n, return an array ans of length n+1 where ans[i] is 
the number of 1's in binary representation of i.

APPROACH:
- Use DP with bit manipulation
- Observation: bits[i] = bits[i >> 1] + (i & 1)
- Right shift removes last bit, then add back if it was 1

PATTERN: Dynamic Programming with Bit Manipulation

INPUT/OUTPUT:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 -> 0 (0 bits)
1 -> 1 (1 bit)
2 -> 10 (1 bit)
3 -> 11 (2 bits)
4 -> 100 (1 bit)
5 -> 101 (2 bits)

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for output array
"""



if __name__ == "__main__":
    sol = Solution()
    n1 = 5
    print(f"Input: {n1}")
    result1 = sol.countBits(n1)
    print("Output: [")
    for (i = 0; i < len(result1); i++) 
    print(result1[i], end="")
    print(",")
    print(f"]")
    print(f"Explanation:")
    for (i = 0; i <= n1; i++) 
    print(i, end=" -> ")
    printBinary(i, 4)
    print(f" ({result1[i]}")
    print()
    n2 = 8
    print(f"Input: {n2}")
    result2 = sol.countBits(n2)
    print("Output: [")
    for (i = 0; i < len(result2); i++) 
    print(result2[i], end="")
    print(",")
    print(f"]")
