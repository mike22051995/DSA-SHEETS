"""
PROBLEM: Scramble String (LeetCode 87)
DIFFICULTY: Hard
PATTERN: Interval DP / Partition with Recursion

DESCRIPTION:
We can scramble a string s to get a string t using the following algorithm:
1. If the length of the string is 1, stop.
2. If the length of the string is > 1, do the following:
   - Split the string into two non-empty substrings at a random index
   - Randomly decide to swap the two substrings or not
   - Apply step 1 recursively on each of the two substrings

Given two strings s1 and s2 of the same length, return True if s2 is a 
scrambled string of s1, otherwise, return False.

EXAMPLE:
Input: s1 = "great", s2 = "rgeat"
Output: True
Explanation: Split "great" → "gr" + "eat"
              Split "gr" → "g" + "r", swap → "rg"
              Result: "rg" + "eat" = "rgeat"

Input: s1 = "abcde", s2 = "caebd"
Output: False

Input: s1 = "a", s2 = "a"
Output: True

TIME COMPLEXITY: O(n^4) with memoization
SPACE COMPLEXITY: O(n^3) for memoization
"""

from typing import List, Optional

class Solution:
    def isScramble(self, s1, s2):
        from functools import lru_cache

        @lru_cache(maxsize=None)
        def dp(a, b):
            # Quick checks
            if a == b:
                return True
            if len(a) != len(b):
                return False
            # Check if same characters exist
            if sorted(a) != sorted(b):
                return False
            n = len(a)
            # Try all split points
            for i in range(1, n):
                # Case 1: No swap
                if dp(a[:i], b[:i]) and dp(a[i:], b[i:]):
                    return True
                # Case 2: Swap
                if dp(a[:i], b[n-i:]) and dp(a[i:], b[:n-i]):
                    return True
            return False

        return dp(s1, s2)


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    s1_1, s2_1 = "great", "rgeat"
    print(f"s1 = {s1_1}, s2 = {s2_1}")
    print(f"Is Scramble: {sol.isScramble(s1_1, s2_1)}")
    print(f"\nTest Case 2:")
    s1_2, s2_2 = "abcde", "caebd"
    print(f"s1 = {s1_2}, s2 = {s2_2}")
    print(f"Is Scramble: {sol.isScramble(s1_2, s2_2)}")
    print(f"\nTest Case 3:")
    s1_3, s2_3 = "a", "a"
    print(f"s1 = {s1_3}, s2 = {s2_3}")
    print(f"Is Scramble: {sol.isScramble(s1_3, s2_3)}")
    print(f"\nTest Case 4:")
    s1_4, s2_4 = "abcdefghijklmnopq", "efghijklmnopqcadb"
    print(f"s1 = {s1_4}, s2 = {s2_4}")
    print(f"Is Scramble: {sol.isScramble(s1_4, s2_4)}")
