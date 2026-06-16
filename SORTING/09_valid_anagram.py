"""
PROBLEM: Valid Anagram (LeetCode 242)
===============================================
DESCRIPTION:
Given two strings s and t, return True if t is an anagram of s, and False otherwise.
An anagram is a word formed by rearranging the letters of a different word, using 
all the original letters exactly once.

PATTERN: Sorting for Comparison
DIFFICULTY: Easy
TIME COMPLEXITY: O(n log n) for sorting approach
SPACE COMPLEXITY: O(1) ignoring space used for sorting

INPUT:
Two strings

OUTPUT:
Boolean (True if anagram, False otherwise)

EXAMPLE:
Input: s = "anagram", t = "nagaram"
Output: True

Input: s = "rat", t = "car"
Output: False
"""

from typing import List, Optional

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Different lengths can't be anagrams
        if len(s) != len(t):
            return False
        # Sort both strings and compare
        return sorted(s) == sorted(t)
    
    def isAnagramV2(self, s: str, t: str) -> bool:
        # Using character frequency (HashMap approach)
        if len(s) != len(t):
            return False
        char_count = {}
        for c in s:
            char_count[c] = char_count.get(c, 0) + 1
        for c in t:
            if c not in char_count:
                return False
            char_count[c] -= 1
            if char_count[c] < 0:
                return False
        return True


if __name__ == "__main__":
    sol = Solution()
    s1 = "anagram"
    t1 = "nagaram"
    print(f"s = {s1}, t = {t1}")
    print(f"Is anagram (Sorting): {sol.isAnagram(s1, t1)}")
    print(f"Is anagram (HashMap): {sol.isAnagramV2(s1, t1)}")
    
    s2 = "rat"
    t2 = "car"
    print(f"\ns = {s2}, t = {t2}")
    print(f"Is anagram (Sorting): {sol.isAnagram(s2, t2)}")
    print(f"Is anagram (HashMap): {sol.isAnagramV2(s2, t2)}")
