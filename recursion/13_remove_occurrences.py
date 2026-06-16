"""
PROBLEM: Remove All Occurrences of a Character
---------------------------------------------------------------------------
Given a string and a character, remove all occurrences of that character 
from the string using recursion.

DIFFICULTY: Easy-Medium
PATTERN: Linear Recursion (String Building)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack + new string

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "hello", ch = 'l'
Output: "heo"
Explanation: Both 'l' characters are removed

Example 2:
Input: s = "aabbcc", ch = 'b'
Output: "aacc"
Explanation: Both 'b' characters are removed
"""

from typing import List, Optional

class Solution:
    def removeOccurrences(self, s: str, ch: str) -> str:
        """Remove all occurrences of character ch from string s"""
        if not s:
            return ""
        if s[0] == ch:
            return self.removeOccurrences(s[1:], ch)
        return s[0] + self.removeOccurrences(s[1:], ch)
    
    def removeOccurrencesAlt(self, s: str, ch: str) -> str:
        """Alternative approach using index-based recursion"""
        def removeHelper(s: str, ch: str, index: int) -> str:
            if index >= len(s):
                return ""
            if s[index] == ch:
                return removeHelper(s, ch, index + 1)
            return s[index] + removeHelper(s, ch, index + 1)
        
        return removeHelper(s, ch, 0)


if __name__ == "__main__":
    sol = Solution()
    s1 = "hello"
    ch1 = 'l'
    print(f"Test 1: Remove '{ch1}' from '{s1}': '{sol.removeOccurrences(s1, ch1)}'")
    
    s2 = "aabbcc"
    ch2 = 'b'
    print(f"Test 2: Remove '{ch2}' from '{s2}': '{sol.removeOccurrencesAlt(s2, ch2)}'")
