"""
    Longest Common Prefix - LeetCode #14
    
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
    
    Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"
    
    Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
    
    Constraints:
    - 1 <= strs.length <= 200
    - 0 <= strs[i].length <= 200
    - strs[i] consists of only lowercase English letters
    
    Time Complexity: O(S) where S is sum of all characters
    Space Complexity: O(1)
"""

from typing import List

class Solution:
    # Approach 1: Vertical Scanning
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        for i in range(len(strs[0])):
            char = strs[0][i]
            for j in range(1, len(strs)):
                if i >= len(strs[j]) or strs[j][i] != char:
                    return strs[0][:i]
        
        return strs[0]
    
    # Approach 2: Horizontal Scanning
    def longestCommonPrefixHorizontal(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        prefix = strs[0]
        for i in range(1, len(strs)):
            while not strs[i].startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""
        
        return prefix
    
    # Approach 3: Using Sorting
    def longestCommonPrefixSort(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        strs.sort()
        first = strs[0]
        last = strs[-1]
        
        i = 0
        while i < len(first) and i < len(last) and first[i] == last[i]:
            i += 1
        
        return first[:i]

if __name__ == "__main__":
    sol = Solution()
    
    test1 = ["flower", "flow", "flight"]
    print(f"Test 1: {sol.longestCommonPrefix(test1)}")  # "fl"
    
    test2 = ["dog", "racecar", "car"]
    print(f"Test 2: {sol.longestCommonPrefix(test2)}")  # ""
    
    test3 = ["interspecies", "interstellar", "interstate"]
    print(f"Test 3: {sol.longestCommonPrefix(test3)}")  # "inters"
