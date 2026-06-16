"""
    Word Break - LeetCode #139
    
    Given a string s and a dictionary of strings wordDict, return true if s can be
    segmented into a space-separated sequence of one or more dictionary words.
    
    Note: The same word in the dictionary may be reused multiple times in the segmentation.
    
    Example 1:
    Input: s = "leetcode", wordDict = ["leet","code"]
    Output: true
    Explanation: Return true because "leetcode" can be segmented as "leet code".
    
    Example 2:
    Input: s = "applepenapple", wordDict = ["apple","pen"]
    Output: true
    Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
    
    Example 3:
    Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    Output: false
    
    Constraints:
    - 1 <= s.length <= 300
    - 1 <= wordDict.length <= 1000
    - 1 <= wordDict[i].length <= 20
    - s and wordDict[i] consist of only lowercase English letters
    - All the strings of wordDict are unique
    
    Time Complexity: O(n^2) where n is length of s
    Space Complexity: O(n)
"""

from typing import List

class Solution:
    # Approach: Dynamic Programming
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True  # Empty string
        
        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break
        
        return dp[n]

if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    dict1 = ["leet", "code"]
    print(f"Test 1: {sol.wordBreak('leetcode', dict1)}")
    
    # Test 2
    dict2 = ["apple", "pen"]
    print(f"Test 2: {sol.wordBreak('applepenapple', dict2)}")
    
    # Test 3
    dict3 = ["cats", "dog", "sand", "and", "cat"]
    print(f"Test 3: {sol.wordBreak('catsandog', dict3)}")
