"""
    Regular Expression Matching - LeetCode #10
    
    Given an input string s and a pattern p, implement regular expression matching with
    support for '.' and '*' where:
    - '.' Matches any single character.
    - '*' Matches zero or more of the preceding element.
    
    The matching should cover the entire input string (not partial).
    
    Example 1:
    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    
    Example 2:
    Input: s = "aa", p = "a*"
    Output: true
    Explanation: '*' means zero or more of the preceding element, 'a'.
    
    Example 3:
    Input: s = "ab", p = ".*"
    Output: true
    Explanation: ".*" means "zero or more (*) of any character (.)".
    
    Constraints:
    - 1 <= s.length <= 20
    - 1 <= p.length <= 30
    - s contains only lowercase English letters
    - p contains only lowercase English letters, '.', and '*'
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
"""

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True
        
        # Handle patterns like a*, a*b*, a*b*c*
        for j in range(2, n + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    # Two cases:
                    # 1. Zero occurrence of character before *
                    dp[i][j] = dp[i][j - 2]
                    
                    # 2. One or more occurrence
                    if p[j - 2] == s[i - 1] or p[j - 2] == '.':
                        dp[i][j] = dp[i][j] or dp[i - 1][j]
                else:
                    # Current characters match
                    if p[j - 1] == s[i - 1] or p[j - 1] == '.':
                        dp[i][j] = dp[i - 1][j - 1]
        
        return dp[m][n]

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.isMatch('aa', 'a')}")                      # False
    print(f"Test 2: {sol.isMatch('aa', 'a*')}")                     # True
    print(f"Test 3: {sol.isMatch('ab', '.*')}")                     # True
    print(f"Test 4: {sol.isMatch('aab', 'c*a*b')}")                 # True
    print(f"Test 5: {sol.isMatch('mississippi', 'mis*is*p*.')}")    # False
