"""
    Group Shifted Strings - LeetCode #249 (Premium)
    
    We can shift a string by shifting each of its letters to its successive letter.
    Given an array of strings, group all strings that belong to the same shifting sequence.
    
    Example 1:
    Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
    Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
    
    Example 2:
    Input: strings = ["a"]
    Output: [["a"]]
    
    Explanation:
    "abc" can be shifted to "bcd" by shifting each letter by 1.
    "xyz" can also be shifted to "abc" (wrapping around).
    The key is to find a pattern that uniquely identifies each group.
    
    Time Complexity: O(n * m) where n is number of strings, m is avg length
    Space Complexity: O(n * m)
"""

from collections import defaultdict
from typing import List

class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        
        for s in strings:
            key = self.get_shift_pattern(s)
            groups[key].append(s)
        
        return list(groups.values())
    
    def get_shift_pattern(self, s: str) -> tuple:
        if len(s) == 1:
            return (0,)
        
        pattern = []
        for i in range(1, len(s)):
            diff = (ord(s[i]) - ord(s[i - 1]) + 26) % 26
            pattern.append(diff)
        
        return tuple(pattern)

if __name__ == "__main__":
    sol = Solution()
    
    test1 = ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]
    result1 = sol.groupStrings(test1)
    print(f"Test 1: {result1}")
    
    test2 = ["a"]
    result2 = sol.groupStrings(test2)
    print(f"Test 2: {result2}")
