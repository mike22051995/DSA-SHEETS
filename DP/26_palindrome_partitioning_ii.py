"""
PROBLEM: Palindrome Partitioning II (LeetCode 132)
DIFFICULTY: Hard
PATTERN: Partition DP + Palindrome Check

DESCRIPTION:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

EXAMPLE:
Input: s = "aab"
Output: 1
Explanation: Cut into "aa | b" (1 cut)

Input: s = "a"
Output: 0
Explanation: Already a palindrome

Input: s = "ab"
Output: 1

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n²) for palindrome table + O(n) for cuts
"""

from typing import List, Optional

class Solution:
    def minCut(self, s):
        n = len(s)
        # Step 1: Build palindrome table
        isPalin = [[False] * n for _ in range(n)]
        # Every single character is a palindrome
        for i in range(n):
            isPalin[i][i] = True
        # Check for length 2
        for i in range(n - 1):
            if s[i] == s[i+1]:
                isPalin[i][i+1] = True
        # Check for lengths greater than 2
        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j] and isPalin[i+1][j-1]:
                    isPalin[i][j] = True
        # Step 2: Calculate minimum cuts
        cuts = [0] * n
        for i in range(n):
            # If entire substring [0...i] is palindrome, no cuts needed
            if isPalin[0][i]:
                cuts[i] = 0
            else:
                min_cuts = float('inf')
                # Try all possible cuts
                for j in range(i):
                    # If right part [j+1...i] is palindrome
                    if isPalin[j+1][i]:
                        min_cuts = min(min_cuts, cuts[j] + 1)
                cuts[i] = min_cuts
        return cuts[n-1]

    def minCutOptimized(self, s):
        n = len(s)
        cuts = list(range(-1, n))  # cuts[i+1] = min cuts for s[0..i]
        for i in range(n):
            # Odd length palindromes centered at i
            for l in range(i, -1, -1):
                r = 2 * i - l
                if r >= n or s[l] != s[r]:
                    break
                cuts[r+1] = min(cuts[r+1], cuts[l] + 1)
            # Even length palindromes centered between i and i+1
            for l in range(i, -1, -1):
                r = 2 * i - l + 1
                if r >= n or s[l] != s[r]:
                    break
                cuts[r+1] = min(cuts[r+1], cuts[l] + 1)
        return cuts[n]


if __name__ == "__main__":
    sol = Solution()
    print(f"Test Case 1:")
    s1 = "aab"
    print(f"String: {s1}")
    print(f"Minimum cuts: {sol.minCut(s1)}")
    print(f"Minimum cuts (Optimized): {sol.minCutOptimized(s1)}")
    print(f"\nTest Case 2:")
    s2 = "a"
    print(f"String: {s2}")
    print(f"Minimum cuts: {sol.minCut(s2)}")
    print(f"\nTest Case 3:")
    s3 = "ababbbabbababa"
    print(f"String: {s3}")
    print(f"Minimum cuts: {sol.minCut(s3)}")
    print(f"\nTest Case 4:")
    s4 = "racecar"
    print(f"String: {s4}")
    print(f"Minimum cuts: {sol.minCut(s4)}")
