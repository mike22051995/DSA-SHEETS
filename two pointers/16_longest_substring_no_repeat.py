"""
PROBLEM: Longest Substring Without Repeating Characters
---------------------------------------------------------------------------
Given a string s, find the length of the longest substring without repeating 
characters.

PATTERN: Sliding Window (Variable Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(min(n, m)) where m is character set size

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with length 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with length 1.
"""

from typing import List


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        left = 0
        maxLen = 0
        for right in range(len(s)):
            # Shrink window until no duplicate
            while s[right] in charSet:
                charSet.remove(s[left])
                left += 1
            charSet.add(s[right])
            maxLen = max(maxLen, right - left + 1)
        return maxLen

    # METHOD 2: dict storing last seen index — jump left directly (no inner loop)
    def lengthOfLongestSubstringMap(self, s: str) -> int:
        last_index = {}  # char -> last seen index
        left = 0
        max_len = 0
        for right in range(len(s)):
            # If char is inside current window, jump left past the previous occurrence
            if s[right] in last_index and last_index[s[right]] >= left:
                left = last_index[s[right]] + 1
            last_index[s[right]] = right
            max_len = max(max_len, right - left + 1)
        return max_len


if __name__ == "__main__":
    sol = Solution()
    s1 = "abcabcbb"
    print(f"Test 1 (set): {sol.lengthOfLongestSubstring(s1)}")
    print(f"Test 1 (map): {sol.lengthOfLongestSubstringMap(s1)}")
    s2 = "bbbbb"
    print(f"Test 2 (set): {sol.lengthOfLongestSubstring(s2)}")
    print(f"Test 2 (map): {sol.lengthOfLongestSubstringMap(s2)}")
    # Edge case: duplicate outside window
    s3 = "abba"
    print(f"Test 3 (set): {sol.lengthOfLongestSubstring(s3)}")
    print(f"Test 3 (map): {sol.lengthOfLongestSubstringMap(s3)}")
