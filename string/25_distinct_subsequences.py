"""
    Distinct Subsequences - LeetCode #115
    
    Given two strings s and t, return the number of distinct subsequences of s which equals t.
    
    Example 1:
    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation:
    There are 3 ways you can generate "rabbit" from s.
    rabb(b)it
    ra(b)bbit
    rab(b)bit
    
    Example 2:
    Input: s = "babgbag", t = "bag"
    Output: 5
    Explanation:
    There are 5 distinct subsequences of "bag" in "babgbag":
    (b)a(b)g(bag)
    (b)a(bgba)g
    (ba)b(g)bag
    ba(b)g(bag)
    babg(bag)
    
    Constraints:
    - 1 <= s.length, t.length <= 1000
    - s and t consist of English letters
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
"""

class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        # Empty string is a subsequence of any string
        for i in range(m + 1):
            dp[i][0] = 1
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # If characters don't match, we can only use dp[i-1][j]
                dp[i][j] = dp[i - 1][j]
                
                # If characters match, add dp[i-1][j-1]
                if s[i - 1] == t[j - 1]:
                    dp[i][j] += dp[i - 1][j - 1]
        
        return dp[m][n]
    
    # Space optimized version
    def numDistinctOptimized(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        
        dp = [0] * (n + 1)
        dp[0] = 1
        
        for i in range(1, m + 1):
            for j in range(n, 0, -1):
                if s[i - 1] == t[j - 1]:
                    dp[j] += dp[j - 1]
        
        return dp[n]

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.numDistinct('rabbbit', 'rabbit')}")  # 3
    print(f"Test 2: {sol.numDistinct('babgbag', 'bag')}")     # 5
    print(f"Test 3: {sol.numDistinct('', 'a')}")              # 0
