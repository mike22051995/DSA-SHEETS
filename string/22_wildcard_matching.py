"""
    Wildcard Matching - LeetCode #44
    
    Given an input string (s) and a pattern (p), implement wildcard pattern matching
    with support for '?' and '*' where:
    - '?' Matches any single character.
    - '*' Matches any sequence of characters (including the empty sequence).
    
    The matching should cover the entire input string (not partial).
    
    Example 1:
    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    
    Example 2:
    Input: s = "aa", p = "*"
    Output: true
    Explanation: '*' matches any sequence.
    
    Example 3:
    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'b', which does not match 'a'.
    
    Constraints:
    - 0 <= s.length, p.length <= 2000
    - s contains only lowercase English letters
    - p contains only lowercase English letters, '?' or '*'
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
"""

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True
        
        # Handle patterns starting with *
        for j in range(1, n + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 1]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    # '*' can match empty string or any sequence
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
                elif p[j - 1] == '?' or p[j - 1] == s[i - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
        
        return dp[m][n]
    
    # Space optimized two-pointer approach
    def isMatchOptimized(self, s: str, p: str) -> bool:
        i = j = 0
        star_idx = match = -1
        
        while i < len(s):
            # Current characters match or pattern has '?'
            if j < len(p) and (p[j] == s[i] or p[j] == '?'):
                i += 1
                j += 1
            # Pattern has '*'
            elif j < len(p) and p[j] == '*':
                star_idx = j
                match = i
                j += 1
            # No match, but there was a '*' before
            elif star_idx != -1:
                j = star_idx + 1
                match += 1
                i = match
            # No match and no '*' before
            else:
                return False
        
        # Check remaining characters in pattern
        while j < len(p) and p[j] == '*':
            j += 1
        
        return j == len(p)

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.isMatch('aa', 'a')}")          # False
    print(f"Test 2: {sol.isMatch('aa', '*')}")          # True
    print(f"Test 3: {sol.isMatch('cb', '?a')}")         # False
    print(f"Test 4: {sol.isMatch('adceb', '*a*b')}")    # True
    print(f"Test 5: {sol.isMatch('acdcb', 'a*c?b')}")   # False
