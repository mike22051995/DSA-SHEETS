"""
PROBLEM: Permutation in String
---------------------------------------------------------------------------
Given two strings s1 and s2, return True if s2 contains a permutation of s1, 
or False otherwise. In other words, return True if one of s1's permutations 
is a substring of s2.

PATTERN: Sliding Window (Fixed Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(26) = O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: False
Explanation: s2 does not contain any permutation of s1.
"""

from typing import List, Optional

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        s1Count = [0] * 26
        s2Count = [0] * 26
        
        # Count characters in s1
        for c in s1:
            s1Count[ord(c) - ord('a')] += 1
        
        # Sliding window
        for i in range(len(s2)):
            s2Count[ord(s2[i]) - ord('a')] += 1
            # Remove leftmost character if window exceeds s1 size
            if i >= len(s1):
                s2Count[ord(s2[i - len(s1)]) - ord('a')] -= 1
            # Check if current window matches
            if s1Count == s2Count:
                return True
        return False


if __name__ == "__main__":
    sol = Solution()
    s1_1 = "ab"
    s2_1 = "eidbaooo"
    print(f"Test 1: {sol.checkInclusion(s1_1, s2_1)}")
    s1_2 = "ab"
    s2_2 = "eidboaoo"
    print(f"Test 2: {sol.checkInclusion(s1_2, s2_2)}")
