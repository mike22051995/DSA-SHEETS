"""
    Longest Substring Without Repeating Characters - LeetCode #3
    
    Given a string s, find the length of the longest substring without repeating characters.
    
    Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    
    Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    
    Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    
    Constraints:
    - 0 <= s.length <= 5 * 10^4
    - s consists of English letters, digits, symbols and spaces
    
    Time Complexity: O(n)
    Space Complexity: O(min(n, m)) where m is the charset size
"""

class Solution:
    # Approach 1: Sliding Window with Dictionary (Optimized)
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_index = {}
        max_len = 0
        left = 0
        
        for right, char in enumerate(s):
            # If character exists in current window
            if char in char_index and char_index[char] >= left:
                left = char_index[char] + 1
            
            char_index[char] = right
            max_len = max(max_len, right - left + 1)
        
        return max_len
    
    # Approach 2: Sliding Window with Set
    def lengthOfLongestSubstringSet(self, s: str) -> int:
        chars = set()
        max_len = 0
        left = 0
        
        for right in range(len(s)):
            while s[right] in chars:
                chars.remove(s[left])
                left += 1
            
            chars.add(s[right])
            max_len = max(max_len, right - left + 1)
        
        return max_len

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.lengthOfLongestSubstring('abcabcbb')}")  # 3
    print(f"Test 2: {sol.lengthOfLongestSubstring('bbbbb')}")     # 1
    print(f"Test 3: {sol.lengthOfLongestSubstring('pwwkew')}")    # 3
    print(f"Test 4: {sol.lengthOfLongestSubstring('')}")          # 0
    print(f"Test 5: {sol.lengthOfLongestSubstring('dvdf')}")      # 3
