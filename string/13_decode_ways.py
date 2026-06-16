"""
    Decode Ways - LeetCode #91
    
    A message containing letters from A-Z can be encoded into numbers using the following mapping:
    'A' -> "1", 'B' -> "2", ..., 'Z' -> "26"
    
    To decode an encoded message, all the digits must be grouped then mapped back into letters
    using the reverse of the mapping above. Given a string s containing only digits,
    return the number of ways to decode it.
    
    Example 1:
    Input: s = "12"
    Output: 2
    Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
    
    Example 2:
    Input: s = "226"
    Output: 3
    Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
    
    Example 3:
    Input: s = "06"
    Output: 0
    Explanation: "06" cannot be mapped to "F" because of the leading zero.
    
    Constraints:
    - 1 <= s.length <= 100
    - s contains only digits and may contain leading zero(s)
    
    Time Complexity: O(n)
    Space Complexity: O(n) or O(1) if optimized
"""

class Solution:
    # Approach 1: Dynamic Programming (Bottom-up)
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1  # Empty string
        dp[1] = 1  # First character (already checked not '0')
        
        for i in range(2, n + 1):
            # One digit decode
            one_digit = int(s[i - 1])
            if 1 <= one_digit <= 9:
                dp[i] += dp[i - 1]
            
            # Two digit decode
            two_digit = int(s[i - 2:i])
            if 10 <= two_digit <= 26:
                dp[i] += dp[i - 2]
        
        return dp[n]
    
    # Approach 2: Space Optimized DP
    def numDecodingsOptimized(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        
        n = len(s)
        prev2 = 1  # dp[i-2]
        prev1 = 1  # dp[i-1]
        
        for i in range(2, n + 1):
            current = 0
            
            # One digit decode
            one_digit = int(s[i - 1])
            if 1 <= one_digit <= 9:
                current += prev1
            
            # Two digit decode
            two_digit = int(s[i - 2:i])
            if 10 <= two_digit <= 26:
                current += prev2
            
            prev2 = prev1
            prev1 = current
        
        return prev1

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.numDecodings('12')}")      # 2
    print(f"Test 2: {sol.numDecodings('226')}")     # 3
    print(f"Test 3: {sol.numDecodings('06')}")      # 0
    print(f"Test 4: {sol.numDecodings('10')}")      # 1
    print(f"Test 5: {sol.numDecodings('2101')}")    # 1
