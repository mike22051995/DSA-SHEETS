"""
PROBLEM: Longest Palindromic Substring
Difficulty: Medium
Pattern: 2D DP, String Palindrome

DESCRIPTION:
Given a string s, return the longest palindromic substring in s.

INPUT:
s = "babad"

OUTPUT:
"bab"
Note: "aba" is also a valid answer.

TIME COMPLEXITY: O(n^2) for DP and expand around center, O(n) for Manacher's algorithm
SPACE COMPLEXITY: O(n^2) for DP, O(1) for expand around center
"""

from typing import List, Optional

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s
        
        start = 0
        maxLen = 1
        
        for i in range(n):
            # Check for odd length palindromes (center is a single character)
            len1 = self.expandAroundCenter(s, i, i)
            # Check for even length palindromes (center is between two characters)
            len2 = self.expandAroundCenter(s, i, i + 1)
            length = max(len1, len2)
            
            if length > maxLen:
                maxLen = length
                start = i - (length - 1) // 2
        
        return s[start:start + maxLen]
    
    def expandAroundCenter(self, s: str, left: int, right: int) -> int:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1
    
    def longestPalindromeDP(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s
        
        # dp[i][j] = True if s[i:j+1] is a palindrome
        dp = [[False] * n for _ in range(n)]
        start = 0
        maxLen = 1
        
        # Single characters are palindromes
        for i in range(n):
            dp[i][i] = True
        
        # Check for two-character palindromes
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                start = i
                maxLen = 2
        
        # Check for palindromes of length 3 or more
        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    start = i
                    maxLen = length
        
        return s[start:start + maxLen]


if __name__ == "__main__":
    sol = Solution()
    
    s1 = "babad"
    print(f"Input: s = {s1}")
    print(f"Output: {sol.longestPalindrome(s1)}")
    print(f"Output (DP): {sol.longestPalindromeDP(s1)}")
    print()
    
    s2 = "cbbd"
    print(f"Input: s = {s2}")
    print(f"Output: {sol.longestPalindrome(s2)}")
    print(f"Output (DP): {sol.longestPalindromeDP(s2)}")
    print()
    
    s3 = "racecar"
    print(f"Input: s = {s3}")
    print(f"Output: {sol.longestPalindrome(s3)}")
    print(f"Output (DP): {sol.longestPalindromeDP(s3)}")
