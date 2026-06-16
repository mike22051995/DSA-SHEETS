"""
PROBLEM: Word Break
Difficulty: Medium
Pattern: 1D DP, String Segmentation

DESCRIPTION:
Given a string s and a dictionary of strings wordDict, return True if s can be segmented into 
a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

INPUT:
s = "leetcode", wordDict = ["leet", "code"]

OUTPUT:
True
Explanation: Return True because "leetcode" can be segmented as "leet code".

TIME COMPLEXITY: O(n^2 * m) where n = length of s, m = average word length
SPACE COMPLEXITY: O(n)
"""

from typing import List, Optional

class Solution:
    def wordBreak(self, s, wordDict):
        n = len(s)
        wordSet = set(wordDict)
        # dp[i] = True if s[0...i-1] can be segmented
        dp = [False] * (n + 1)
        dp[0] = True  # Empty string
        for i in range(1, n + 1):
            for j in range(i):
                # If s[0...j-1] can be segmented AND s[j...i-1] is in dictionary
                if dp[j] and s[j:i] in wordSet:
                    dp[i] = True
                    break  # Found one valid segmentation
        return dp[n]

    def wordBreakAlternate(self, s, wordDict):
        from functools import lru_cache
        wordSet = set(wordDict)
        @lru_cache(maxsize=None)
        def dp(start):
            if start == len(s):
                return True
            for end in range(start + 1, len(s) + 1):
                if s[start:end] in wordSet and dp(end):
                    return True
            return False
        return dp(0)


if __name__ == "__main__":
    sol = Solution()
    s1 = "leetcode"
    wordDict1 = ["leet", "code"]
    print(f"Input: s = {s1}")
    print(f"Output: {sol.wordBreak(s1, wordDict1)}")
    print(f"Output (Alternate): {sol.wordBreakAlternate(s1, wordDict1)}")
    s2 = "applepenapple"
    wordDict2 = ["apple", "pen"]
    print(f"Input: s = {s2}")
    print(f"Output: {sol.wordBreak(s2, wordDict2)}")
    print(f"Output (Alternate): {sol.wordBreakAlternate(s2, wordDict2)}")
    s3 = "catsandog"
    wordDict3 = ["cats", "dog", "sand", "and", "cat"]
    print(f"Input: s = {s3}")
    print(f"Output: {sol.wordBreak(s3, wordDict3)}")
    print(f"Output (Alternate): {sol.wordBreakAlternate(s3, wordDict3)}")
