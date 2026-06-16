"""
PROBLEM: Longest Substring Without Repeating Characters
Difficulty: Medium
Pattern: Sliding Window, Hash Map

DESCRIPTION:
Given a string s, find the length of the longest substring without repeating characters.

EXPLANATION:
We use a sliding window approach with a hash map to store the last seen index of each character.
As we iterate through the string, if we find a repeating character, we move the left pointer
to the position after the last occurrence of that character.

Time Complexity: O(n)
Space Complexity: O(min(m, n)) where m is the charset size

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with length of 3.
"""

from typing import Dict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp: Dict[str, int] = {}
        l = 0
        r = 0
        maxlen = 0
        
        while r < len(s):
            if s[r] in mp:
                l = mp[s[r]] + 1
            
            newlen = r - l + 1
            maxlen = max(maxlen, newlen)
            mp[s[r]] = r
            r += 1
        
        return maxlen


if __name__ == "__main__":
    solution = Solution()
    
    # Test Case 1
    s1 = "abcabcbb"
    result1 = solution.lengthOfLongestSubstring(s1)
    print(f"Test 1: {result1}")
    
    # Test Case 2
    s2 = "bbbbb"
    result2 = solution.lengthOfLongestSubstring(s2)
    print(f"Test 2: {result2}")
    
    # Test Case 3
    s3 = "pwwkew"
    result3 = solution.lengthOfLongestSubstring(s3)
    print(f"Test 3: {result3}")
