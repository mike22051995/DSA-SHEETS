"""
PROBLEM: Counting Bits
Difficulty: Easy
Pattern: 1D DP, Bit Manipulation

DESCRIPTION:
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.

INPUT:
n = 5

OUTPUT:
[0, 1, 1, 2, 1, 2]
Explanation:
0 --> 0 (0 ones)
1 --> 1 (1 one)
2 --> 10 (1 one)
3 --> 11 (2 ones)
4 --> 100 (1 one)
5 --> 101 (2 ones)

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for result array
"""

class Solution:
    def countBits(self, n):
        # dp[i] = number of 1's in binary representation of i
        result = [0] * (n + 1)
        for i in range(1, n + 1):
            # If i is even: same number of bits as i/2
            # If i is odd: one more bit than i-1
            result[i] = result[i >> 1] + (i & 1)
        return result

    def countBitsAlternate(self, n):
        result = [0] * (n + 1)
        for i in range(1, n + 1):
            result[i] = result[i & (i - 1)] + 1
        return result


if __name__ == "__main__":
    sol = Solution()
    n1 = 5
    print(f"Input: n = {n1}")
    result1 = sol.countBits(n1)
    print(f"Output: {result1}")
    n2 = 8
    print(f"Input: n = {n2}")
    result2 = sol.countBitsAlternate(n2)
    print(f"Output: {result2}")
