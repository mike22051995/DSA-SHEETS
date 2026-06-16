"""
    Valid Anagram - LeetCode #242
    
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
    typically using all the original letters exactly once.
    
    Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true
    
    Example 2:
    Input: s = "rat", t = "car"
    Output: false
    
    Constraints:
    - 1 <= s.length, t.length <= 5 * 10^4
    - s and t consist of lowercase English letters
    
    Time Complexity: O(n)
    Space Complexity: O(1) - fixed size array
"""

from collections import Counter

class Solution:
    # Approach 1: Using Counter
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
    
    # Approach 2: Using Dictionary
    def isAnagramDict(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        count = {}
        
        for char in s:
            count[char] = count.get(char, 0) + 1
        
        for char in t:
            if char not in count:
                return False
            count[char] -= 1
            if count[char] < 0:
                return False
        
        return True
    
    # Approach 3: Using Sorting
    def isAnagramSort(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.isAnagram('anagram', 'nagaram')}")  # True
    print(f"Test 2: {sol.isAnagram('rat', 'car')}")  # False
    print(f"Test 3: {sol.isAnagram('listen', 'silent')}")  # True
