"""
    Longest Common Subsequence - LeetCode #1143
    
    Given two strings text1 and text2, return the length of their longest common subsequence.
    If there is no common subsequence, return 0.
    
    A subsequence is a sequence that can be derived from another sequence by deleting some
    or no elements without changing the order of the remaining elements.
    
    Example 1:
    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation: The longest common subsequence is "ace" and its length is 3.
    
    Example 2:
    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.
    
    Example 3:
    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
"""

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        
        return dp[m][n]
    
    # Space optimized version
    def longestCommonSubsequenceOptimized(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        
        prev = [0] * (n + 1)
        curr = [0] * (n + 1)
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    curr[j] = prev[j - 1] + 1
                else:
                    curr[j] = max(prev[j], curr[j - 1])
            
            prev, curr = curr, prev
        
        return prev[n]

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.longestCommonSubsequence('abcde', 'ace')}")     # 3
    print(f"Test 2: {sol.longestCommonSubsequence('abc', 'abc')}")       # 3
    print(f"Test 3: {sol.longestCommonSubsequence('abc', 'def')}")       # 0
