"""
PROBLEM: Find All Anagrams in a String
---------------------------------------------------------------------------
Given two strings s and p, return an array of all the start indices of p's 
anagrams in s. An Anagram is a word formed by rearranging the letters of 
a different word.

PATTERN: Sliding Window (Fixed Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(26) = O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation: The anagrams "cba" at index 0 and "bac" at index 6.

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation: Anagrams "ab" at 0, "ba" at 1, "ab" at 2.
"""

from typing import List, Optional

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        result = []
        if len(s) < len(p):
            return result
        
        pCount = [0] * 26
        sCount = [0] * 26
        
        # Count characters in p
        for c in p:
            pCount[ord(c) - ord('a')] += 1
        
        # Sliding window
        for i in range(len(s)):
            sCount[ord(s[i]) - ord('a')] += 1
            # Remove leftmost character if window exceeds p size
            if i >= len(p):
                sCount[ord(s[i - len(p)]) - ord('a')] -= 1
            # Check if current window is an anagram
            if pCount == sCount:
                result.append(i - len(p) + 1)
        return result


if __name__ == "__main__":
    sol = Solution()
    s1 = "cbaebabacd"
    p1 = "abc"
    result1 = sol.findAnagrams(s1, p1)
    print("Test 1: [", end="")
    for i in range(len(result1)):
        print(result1[i], end="," if i < len(result1) - 1 else "")
    print("]")
    s2 = "abab"
    p2 = "ab"
    result2 = sol.findAnagrams(s2, p2)
    print("Test 2: [", end="")
    for i in range(len(result2)):
        print(result2[i], end="," if i < len(result2) - 1 else "")
    print("]")
