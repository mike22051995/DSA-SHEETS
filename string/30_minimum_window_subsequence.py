"""
    Minimum Window Subsequence - LeetCode #727 (Premium)
    
    Given strings s and t, find the minimum (contiguous) substring of s, such that t is a
    subsequence of this substring. If there is no such substring, return the empty string "".
    
    Example 1:
    Input: s = "abcdebdde", t = "bde"
    Output: "bcde"
    Explanation: "bcde" is the shortest substring that contains the subsequence "bde".
    "deb" is also a valid answer, but we choose "bcde" since it comes first.
    
    Example 2:
    Input: s = "jmeqksfrsdcmsiwvaovztaqenprpvnbstl", t = "u"
    Output: ""
    
    Constraints:
    - 1 <= s.length <= 2 * 10^4
    - 1 <= t.length <= 100
    - s and t consist of lowercase English letters
    
    Note: A subsequence of a string is a new string that is formed from the original string
    by deleting some (can be none) of the characters without disturbing the relative positions
    of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
    
    Time Complexity: O(m*n) where m = len(s), n = len(t)
    Space Complexity: O(m*n)
"""

class Solution:
    # Approach 1: Dynamic Programming
    def minWindow(self, s: str, t: str) -> str:
        m, n = len(s), len(t)
        
        # dp[i][j] = start index of minimum window ending at s[i] that contains t[0...j]
        dp = [[-1] * (n + 1) for _ in range(m + 1)]
        
        # Empty t is valid for all positions
        for i in range(m + 1):
            dp[i][0] = i
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i - 1][j]
        
        min_len = float('inf')
        start = 0
        
        # Find minimum window
        for i in range(1, m + 1):
            if dp[i][n] != -1:
                length = i - dp[i][n]
                if length < min_len:
                    min_len = length
                    start = dp[i][n]
        
        return "" if min_len == float('inf') else s[start:start + min_len]
    
    # Approach 2: Two Pointers (Optimized)
    def minWindowTwoPointers(self, s: str, t: str) -> str:
        m, n = len(s), len(t)
        min_len = float('inf')
        result = ""
        
        i = 0
        while i < m:
            j = 0
            
            # Find the first occurrence of t[0] in s starting from i
            while i < m and s[i] != t[j]:
                i += 1
            
            if i == m:
                break
            
            start = i
            
            # Try to match all characters of t
            while i < m and j < n:
                if s[i] == t[j]:
                    j += 1
                i += 1
            
            # If we matched all characters of t
            if j == n:
                # Move back to minimize window
                i -= 1
                j -= 1
                
                while j >= 0:
                    if s[i] == t[j]:
                        j -= 1
                    i -= 1
                
                i += 1
                
                # Update result if this window is smaller
                if start - i + 1 < min_len:
                    min_len = start - i + 1
                    result = s[i:start + 1]
                
                i += 1
        
        return result

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: \"{sol.minWindow('abcdebdde', 'bde')}\"")                        # "bcde"
    print(f"Test 2: \"{sol.minWindow('jmeqksfrsdcmsiwvaovztaqenprpvnbstl', 'u')}\"") # ""
    print(f"Test 3: \"{sol.minWindow('cnhczmccqouqauvlmgkztudygjkz', 'mm')}\"")      # "mccqouqauvlm"
