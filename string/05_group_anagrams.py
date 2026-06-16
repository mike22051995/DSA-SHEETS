"""
    Group Anagrams - LeetCode #49
    
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.
    
    Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    
    Example 2:
    Input: strs = [""]
    Output: [[""]]
    
    Example 3:
    Input: strs = ["a"]
    Output: [["a"]]
    
    Constraints:
    - 1 <= strs.length <= 10^4
    - 0 <= strs[i].length <= 100
    - strs[i] consists of lowercase English letters
    
    Time Complexity: O(n * k log k) where k is max length of string
    Space Complexity: O(n * k)
"""

from collections import defaultdict
from typing import List

class Solution:
    # Approach 1: Sorting as Key
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        
        for s in strs:
            key = ''.join(sorted(s))
            groups[key].append(s)
        
        return list(groups.values())
    
    # Approach 2: Character Count as Key
    def groupAnagramsCount(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            
            # Convert count to tuple (immutable, can be dict key)
            key = tuple(count)
            groups[key].append(s)
        
        return list(groups.values())

if __name__ == "__main__":
    sol = Solution()
    
    test1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
    result1 = sol.groupAnagrams(test1)
    print(f"Test 1: {result1}")
    
    test2 = [""]
    result2 = sol.groupAnagrams(test2)
    print(f"Test 2: {result2}")
    
    test3 = ["a"]
    result3 = sol.groupAnagrams(test3)
    print(f"Test 3: {result3}")
