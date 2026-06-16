"""
PROBLEM: Wildcard Matching (LeetCode 44)
DIFFICULTY: Hard
PATTERN: Greedy Backtracking with Two Pointers

DESCRIPTION:
Given an input string (s) and a pattern (p), implement wildcard pattern matching with 
support for '?' and '*' where:
- '?' Matches any single character.
- '*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

INPUT:
- s: input string
- p: pattern with wildcards

OUTPUT:
- True if pattern matches string

APPROACH:
1. Use two pointers for string and pattern
2. When '*' found, remember position (greedy backtrack point)
3. Try matching '*' with empty sequence first
4. If mismatch later, backtrack and match '*' with more characters
5. Greedy: try minimal match first, expand if needed

WHY GREEDY WORKS:
Try to match '*' with minimum characters first. If doesn't work, backtrack 
and expand the match. This ensures we find a valid match if it exists.
"""

from typing import List, Optional

class Solution:
    def isMatch(self, s, p):
        sLen = len(s), pLen = len(p)
        sIdx = 0, pIdx = 0
        starIdx = -1, matchIdx = 0
        while sIdx < sLen:
        # If characters match or pattern has '?'
        if (pIdx < pLen and (s[sIdx] == p[pIdx] or p[pIdx] == '?')):
        sIdx += 1
        pIdx += 1
        # If pattern has '*', remember position
        else if pIdx < pLen and p[pIdx] == '*':
        starIdx = pIdx
        matchIdx = sIdx
        pIdx++;  # Try matching '*' with empty sequence first
        # Mismatch: if we saw '*' before, backtrack
        else if starIdx != -1:
        pIdx = starIdx + 1
        matchIdx += 1
        sIdx = matchIdx;  # Try matching '*' with one more character
        # No match possible
        else 
        return False
        # Check remaining pattern characters (should all be '*')
        while pIdx < pLen and p[pIdx] == '*':
        pIdx += 1
        return pIdx == pLen


if __name__ == "__main__":
    sol = Solution()
    print(f"Test 1 - s=\")
    print(f"Output: {(sol.isMatch("aa",}")
    print(f"Expected: False")
    print(f"Test 2 - s=\")
    print(f"Output: {(sol.isMatch("aa",}")
    print(f"Expected: True")
    print(f"Test 3 - s=\")
    print(f"Output: {(sol.isMatch("cb",}")
    print(f"Expected: False")
    print(f"Test 4 - s=\")
    print(f"Output: {(sol.isMatch("adceb",}")
    print(f"Expected: True")
    print(f"Test 5 - s=\")
    print(f"Output: {(sol.isMatch("acdcb",}")
    print(f"Expected: False")
