"""
PROBLEM: Longest Repeating Character Replacement
---------------------------------------------------------------------------
You are given a string s and an integer k. You can choose any character of 
the string and change it to any other uppercase English character. You can 
perform this operation at most k times. Return the length of the longest 
substring containing the same letter you can get after performing the operations.

PATTERN: Sliding Window (With Character Frequency)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(26) = O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace two 'A's with 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace one 'A' in the middle with 'B': "AABBBBA". Substring "BBBB" = 4.
"""

from typing import List, Optional

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        left = 0
        maxCount = 0
        maxLen = 0
        
        for right in range(len(s)):
            count[s[right]] = count.get(s[right], 0) + 1
            maxCount = max(maxCount, count[s[right]])
            # Window size - most frequent char count > k means invalid
            while right - left + 1 - maxCount > k:
                count[s[left]] -= 1
                left += 1
            maxLen = max(maxLen, right - left + 1)
        return maxLen


if __name__ == "__main__":
    sol = Solution()
    s1 = "ABAB"
    k1 = 2
    print(f"Test 1: {sol.characterReplacement(s1, k1)}")
    s2 = "AABABBA"
    k2 = 1
    print(f"Test 2: {sol.characterReplacement(s2, k2)}")
