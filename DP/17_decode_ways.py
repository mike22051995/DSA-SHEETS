"""
PROBLEM: Decode Ways
Difficulty: Medium
Pattern: 1D DP, String Decoding

DESCRIPTION:
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1", 'B' -> "2", ..., 'Z' -> "26"
Given a string s containing only digits, return the number of ways to decode it.

INPUT:
s = "226"

OUTPUT:
3
Explanation: "226" could be decoded as:
- "BZ" (2 26)
- "VF" (22 6)
- "BBF" (2 2 6)

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n), can be optimized to O(1)
"""

from typing import List, Optional

class Solution:
    def numDecodings(self, s):
        n = len(s)
        if n == 0 or s[0] == '0':
            return 0
        # dp[i] = number of ways to decode s[0...i-1]
        dp = [0] * (n + 1)
        dp[0] = 1  # Empty string has 1 way
        dp[1] = 1  # First character (if not '0')
        for i in range(2, n + 1):
            # Single digit decode
            one_digit = int(s[i-1:i])
            if 1 <= one_digit <= 9:
                dp[i] += dp[i-1]
            # Two digit decode
            two_digits = int(s[i-2:i])
            if 10 <= two_digits <= 26:
                dp[i] += dp[i-2]
        return dp[n]

    def numDecodingsOptimized(self, s):
        n = len(s)
        if n == 0 or s[0] == '0':
            return 0
        prev2, prev1 = 1, 1
        for i in range(2, n + 1):
            curr = 0
            if 1 <= int(s[i-1:i]) <= 9:
                curr += prev1
            if 10 <= int(s[i-2:i]) <= 26:
                curr += prev2
            prev2, prev1 = prev1, curr
        return prev1


if __name__ == "__main__":
    sol = Solution()
    s1 = "226"
    print(f"Input: s = {s1}")
    print(f"Output: {sol.numDecodings(s1)}")
    print(f"Output (Optimized): {sol.numDecodingsOptimized(s1)}")
    s2 = "12"
    print(f"Input: s = {s2}")
    print(f"Output: {sol.numDecodings(s2)}")
    print(f"Output (Optimized): {sol.numDecodingsOptimized(s2)}")
    s3 = "06"
    print(f"Input: s = {s3}")
    print(f"Output: {sol.numDecodings(s3)}")
    print(f"Output (Optimized): {sol.numDecodingsOptimized(s3)}")
