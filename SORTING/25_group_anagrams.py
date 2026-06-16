"""
PROBLEM: Group Anagrams (LeetCode 49)
===============================================
DESCRIPTION:
Given an array of strings strs, group the anagrams together. You can return the 
answer in any order. An anagram is a word formed by rearranging the letters of 
a different word.

PATTERN: Sorting for Grouping / HashMap
DIFFICULTY: Medium
TIME COMPLEXITY: O(n * k log k) where n = number of strings, k = max string length
SPACE COMPLEXITY: O(n * k)

INPUT:
Array of strings

OUTPUT:
List of grouped anagrams

EXAMPLE:
Input: ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Input: [""]
Output: [[""]]
"""

from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Use sorted string as key
        anagram_map = {}
        
        for s in strs:
            # Sort characters to get canonical form
            key = "".join(sorted(s))
            if key not in anagram_map:
                anagram_map[key] = []
            anagram_map[key].append(s)
        
        return list(anagram_map.values())
    
    def groupAnagramsCount(self, strs: List[str]) -> List[List[str]]:
        # Use character count as key
        anagram_map = {}
        
        for s in strs:
            # Count characters
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            key = tuple(count)
            
            if key not in anagram_map:
                anagram_map[key] = []
            anagram_map[key].append(s)
        
        return list(anagram_map.values())


if __name__ == "__main__":
    sol = Solution()
    
    strs1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print("Input: ")
    print(strs1)
    print()
    result1 = sol.groupAnagrams(strs1)
    print(f"Output (Sorting):")
    for group in result1:
        print(group)
    
    result1_count = sol.groupAnagramsCount(strs1)
    print(f"\nUsing character count approach:")
    for group in result1_count:
        print(group)
