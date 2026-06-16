"""
    Longest Palindromic Substring - LeetCode #5
    
    Given a string s, return the longest palindromic substring in s.
    
    Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
    
    Example 2:
    Input: s = "cbbd"
    Output: "bb"
    
    Constraints:
    - 1 <= s.length <= 1000
    - s consist of only digits and English letters
    
    Time Complexity: O(n^2)
    Space Complexity: O(1)
"""

class Solution:
    # Approach 1: Expand Around Center
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        
        start = 0
        max_len = 1
        
        for i in range(len(s)):
            # Check for odd length palindromes
            len1 = self.expand_around_center(s, i, i)
            # Check for even length palindromes
            len2 = self.expand_around_center(s, i, i + 1)
            
            length = max(len1, len2)
            if length > max_len:
                max_len = length
                start = i - (length - 1) // 2
        
        return s[start:start + max_len]
    
    def expand_around_center(self, s: str, left: int, right: int) -> int:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1
    
    # Approach 2: Dynamic Programming
    def longestPalindromeDP(self, s: str) -> str:
        n = len(s)
        if n == 0:
            return ""
        
        dp = [[False] * n for _ in range(n)]
        start = 0
        max_len = 1
        
        # All single characters are palindromes
        for i in range(n):
            dp[i][i] = True
        
        # Check for two character palindromes
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                start = i
                max_len = 2
        
        # Check for lengths greater than 2
        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    start = i
                    max_len = length
        
        return s[start:start + max_len]

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.longestPalindrome('babad')}")      # "bab" or "aba"
    print(f"Test 2: {sol.longestPalindrome('cbbd')}")       # "bb"
    print(f"Test 3: {sol.longestPalindrome('racecar')}")    # "racecar"
    print(f"Test 4: {sol.longestPalindrome('a')}")          # "a"
    print(f"Test 5: {sol.longestPalindrome('ac')}")         # "a" or "c"
