"""
PROBLEM: Minimum Window Substring
Difficulty: Hard
Pattern: Sliding Window, Hash Map

DESCRIPTION:
Given two strings s and t of lengths m and n respectively, return the minimum window substring 
of s such that every character in t (including duplicates) is included in the window. If there 
is no such substring, return the empty string "".

EXPLANATION:
Sliding Window with two pointers:
1. Expand window by moving right pointer until all characters of t are included
2. Contract window by moving left pointer while maintaining all characters
3. Track minimum window that contains all characters
4. Use hash map to track character frequencies

Time Complexity: O(m + n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: Minimum window containing A, B, and C

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: Entire string is the minimum window

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Not enough 'a's in s
"""

from typing import List
from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""
        need = Counter(t)
        window = {}
        left = 0
        valid = 0  # Count of characters matched
        start = 0
        minLen = float('inf')
        for right in range(len(s)):
            c = s[right]
            # Update window
            if c in need:
                window[c] = window.get(c, 0) + 1
                if window[c] == need[c]:
                    valid += 1
            # Contract window
            while valid == len(need):
                # Update minimum window
                if right - left + 1 < minLen:
                    start = left
                    minLen = right - left + 1
                d = s[left]
                left += 1
                if d in need:
                    if window[d] == need[d]:
                        valid -= 1
                    window[d] -= 1
        return "" if minLen == float('inf') else s[start:start + minLen]


if __name__ == "__main__":
    solution = Solution()
    print(f"Test 1: {solution.minWindow('ADOBECODEBANC', 'ABC')}")
    print(f"Test 2: {solution.minWindow('a', 'a')}")
    print(f"Test 3: {solution.minWindow('a', 'aa')}")
