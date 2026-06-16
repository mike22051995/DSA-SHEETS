"""
PROBLEM: Minimum Window Substring
---------------------------------------------------------------------------
Given two strings s and t, return the minimum window substring of s such 
that every character in t (including duplicates) is included in the window. 
If no such substring exists, return the empty string "".

PATTERN: Sliding Window (Variable Size with HashMap)
TIME COMPLEXITY: O(m + n) where m = s.length, n = t.length
SPACE COMPLEXITY: O(n)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: Minimum window substring "BANC" includes 'A', 'B', 'C' from t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: Entire string s is the minimum window.
"""

from typing import List, Optional

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""
        
        tCount = {}
        for c in t:
            tCount[c] = tCount.get(c, 0) + 1
        
        required = len(tCount)
        formed = 0
        windowCount = {}
        left = 0
        minLen = float('inf')
        minLeft = 0
        
        for right in range(len(s)):
            c = s[right]
            windowCount[c] = windowCount.get(c, 0) + 1
            if c in tCount and windowCount[c] == tCount[c]:
                formed += 1
            
            # Try to shrink window
            while left <= right and formed == required:
                # Update result
                if right - left + 1 < minLen:
                    minLen = right - left + 1
                    minLeft = left
                
                leftChar = s[left]
                windowCount[leftChar] -= 1
                if leftChar in tCount and windowCount[leftChar] < tCount[leftChar]:
                    formed -= 1
                left += 1
        
        return "" if minLen == float('inf') else s[minLeft:minLeft + minLen]


if __name__ == "__main__":
    sol = Solution()
    s1 = "ADOBECODEBANC"
    t1 = "ABC"
    print(f"Test 1: {sol.minWindow(s1, t1)}")
    s2 = "a"
    t2 = "a"
    print(f"Test 2: {sol.minWindow(s2, t2)}")
