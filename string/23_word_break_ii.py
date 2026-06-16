"""
    Word Break II - LeetCode #140
    
    Given a string s and a dictionary of strings wordDict, add spaces in s to construct
    a sentence where each word is a valid dictionary word. Return all such possible sentences
    in any order.
    
    Example 1:
    Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
    Output: ["cats and dog","cat sand dog"]
    
    Example 2:
    Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
    Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
    Explanation: "pineapplepenapple" can be segmented as "pine apple pen apple".
    
    Example 3:
    Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    Output: []
    
    Constraints:
    - 1 <= s.length <= 20
    - 1 <= wordDict.length <= 1000
    - 1 <= wordDict[i].length <= 10
    - s and wordDict[i] consist of only lowercase English letters
    
    Time Complexity: O(n * 2^n) worst case
    Space Complexity: O(n * 2^n)
"""

from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set = set(wordDict)
        memo = {}
        
        def backtrack(start: int) -> List[str]:
            if start in memo:
                return memo[start]
            
            result = []
            
            # Base case: reached end of string
            if start == len(s):
                result.append("")
                return result
            
            # Try all possible words starting from current position
            for end in range(start + 1, len(s) + 1):
                word = s[start:end]
                
                if word in word_set:
                    sublist = backtrack(end)
                    
                    for sub in sublist:
                        if sub:
                            result.append(word + " " + sub)
                        else:
                            result.append(word)
            
            memo[start] = result
            return result
        
        return backtrack(0)

if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    dict1 = ["cat", "cats", "and", "sand", "dog"]
    result1 = sol.wordBreak("catsanddog", dict1)
    print("Test 1:")
    for s in result1:
        print(f"  \"{s}\"")
    
    # Test 2
    dict2 = ["apple", "pen", "applepen", "pine", "pineapple"]
    result2 = sol.wordBreak("pineapplepenapple", dict2)
    print("Test 2:")
    for s in result2:
        print(f"  \"{s}\"")
