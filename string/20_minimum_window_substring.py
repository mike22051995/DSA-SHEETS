"""
    Minimum Window Substring - LeetCode #76
    
    Given two strings s and t, return the minimum window substring of s such that
    every character in t (including duplicates) is included in the window. If there
    is no such substring, return the empty string "".
    
    Example 1:
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
    
    Example 2:
    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.
    
    Example 3:
    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    
    Constraints:
    - 1 <= s.length, t.length <= 10^5
    - s and t consist of uppercase and lowercase English letters
    
    Time Complexity: O(n + m)
    Space Complexity: O(1) - fixed size of 52 or 128 for ASCII
"""

from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t):
            return ""
        
        t_count = Counter(t)
        required = len(t_count)
        formed = 0
        window_count = {}
        
        left = 0
        right = 0
        min_len = float('inf')
        min_left = 0
        
        while right < len(s):
            # Add character from right
            char = s[right]
            window_count[char] = window_count.get(char, 0) + 1
            
            if char in t_count and window_count[char] == t_count[char]:
                formed += 1
            
            # Try to contract window
            while left <= right and formed == required:
                # Update result
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    min_left = left
                
                # Remove from left
                left_char = s[left]
                window_count[left_char] -= 1
                
                if left_char in t_count and window_count[left_char] < t_count[left_char]:
                    formed -= 1
                
                left += 1
            
            right += 1
        
        return "" if min_len == float('inf') else s[min_left:min_left + min_len]

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: \"{sol.minWindow('ADOBECODEBANC', 'ABC')}\"")  # "BANC"
    print(f"Test 2: \"{sol.minWindow('a', 'a')}\"")                # "a"
    print(f"Test 3: \"{sol.minWindow('a', 'aa')}\"")               # ""
