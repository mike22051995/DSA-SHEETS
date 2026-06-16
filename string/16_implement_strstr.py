"""
    Implement strStr() / Find the Index of the First Occurrence - LeetCode #28
    
    Given two strings needle and haystack, return the index of the first occurrence
    of needle in haystack, or -1 if needle is not part of haystack.
    
    Example 1:
    Input: haystack = "sadbutsad", needle = "sad"
    Output: 0
    Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0.
    
    Example 2:
    Input: haystack = "leetcode", needle = "leeto"
    Output: -1
    Explanation: "leeto" did not occur in "leetcode".
    
    Constraints:
    - 1 <= haystack.length, needle.length <= 10^4
    - haystack and needle consist of only lowercase English characters
    
    Time Complexity: O(n*m) naive, O(n+m) with KMP
    Space Complexity: O(1) naive, O(m) with KMP
"""

from typing import List

class Solution:
    # Approach 1: Naive / Built-in
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        
        return haystack.find(needle)
    
    # Approach 2: Manual sliding window
    def strStrManual(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        
        n = len(haystack)
        m = len(needle)
        
        for i in range(n - m + 1):
            if haystack[i:i + m] == needle:
                return i
        
        return -1
    
    # Approach 3: KMP Algorithm
    def strStrKMP(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        
        n = len(haystack)
        m = len(needle)
        
        # Build LPS array
        lps = self.build_lps(needle)
        
        i = 0  # index for haystack
        j = 0  # index for needle
        
        while i < n:
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            
            if j == m:
                return i - j
            elif i < n and haystack[i] != needle[j]:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        
        return -1
    
    def build_lps(self, pattern: str) -> List[int]:
        m = len(pattern)
        lps = [0] * m
        length = 0
        i = 1
        
        while i < m:
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        
        return lps

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.strStr('sadbutsad', 'sad')}")      # 0
    print(f"Test 2: {sol.strStr('leetcode', 'leeto')}")     # -1
    print(f"Test 3: {sol.strStr('hello', 'll')}")           # 2
    print(f"Test 4: {sol.strStr('aaaaa', 'bba')}")          # -1
