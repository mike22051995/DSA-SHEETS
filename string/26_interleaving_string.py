"""
    Interleaving String - LeetCode #97
    
    Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
    An interleaving of two strings s and t is a configuration where s and t are divided into
    n and m substrings respectively, such that: s = s1 + s2 + ... + sn, t = t1 + t2 + ... + tm,
    and s3 = s1 + t1 + s2 + t2 + ... or t1 + s1 + t2 + s2 + ...
    
    Example 1:
    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    Output: true
    Explanation: One way to obtain s3 is:
    Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
    Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
    
    Example 2:
    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
    Output: false
    
    Example 3:
    Input: s1 = "", s2 = "", s3 = ""
    Output: true
    
    Constraints:
    - 0 <= s1.length, s2.length <= 100
    - 0 <= s3.length <= 200
    - s1, s2, and s3 consist of lowercase English letters
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
"""

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        
        if m + n != len(s3):
            return False
        
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True
        
        # Fill first column (only using s1)
        for i in range(1, m + 1):
            dp[i][0] = dp[i - 1][0] and s1[i - 1] == s3[i - 1]
        
        # Fill first row (only using s2)
        for j in range(1, n + 1):
            dp[0][j] = dp[0][j - 1] and s2[j - 1] == s3[j - 1]
        
        # Fill rest of the table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                k = i + j - 1
                
                # Try taking from s1
                if s1[i - 1] == s3[k]:
                    dp[i][j] = dp[i][j] or dp[i - 1][j]
                
                # Try taking from s2
                if s2[j - 1] == s3[k]:
                    dp[i][j] = dp[i][j] or dp[i][j - 1]
        
        return dp[m][n]
    
    # Space optimized version
    def isInterleaveOptimized(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        
        if m + n != len(s3):
            return False
        
        dp = [False] * (n + 1)
        dp[0] = True
        
        for j in range(1, n + 1):
            dp[j] = dp[j - 1] and s2[j - 1] == s3[j - 1]
        
        for i in range(1, m + 1):
            dp[0] = dp[0] and s1[i - 1] == s3[i - 1]
            
            for j in range(1, n + 1):
                k = i + j - 1
                take_s1 = dp[j] and s1[i - 1] == s3[k]
                take_s2 = dp[j - 1] and s2[j - 1] == s3[k]
                dp[j] = take_s1 or take_s2
        
        return dp[n]

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.isInterleave('aabcc', 'dbbca', 'aadbbcbcac')}")   # True
    print(f"Test 2: {sol.isInterleave('aabcc', 'dbbca', 'aadbbbaccc')}")   # False
    print(f"Test 3: {sol.isInterleave('', '', '')}")                       # True
