"""
    Shortest Palindrome - LeetCode #214
    
    You are given a string s. You can convert s to a palindrome by adding characters in front of it.
    Return the shortest palindrome you can find by performing this transformation.
    
    Example 1:
    Input: s = "aacecaaa"
    Output: "aaacecaaa"
    
    Example 2:
    Input: s = "abcd"
    Output: "dcbabcd"
    
    Constraints:
    - 0 <= s.length <= 5 * 10^4
    - s consists of lowercase English letters only
    
    Time Complexity: O(n^2) brute force, O(n) with KMP
    Space Complexity: O(n)
"""

from typing import List

class Solution:
    # Approach 1: Using KMP Algorithm
    def shortestPalindrome(self, s: str) -> str:
        rev = s[::-1]
        combined = s + "#" + rev
        
        # Build LPS array
        lps = self.build_lps(combined)
        
        # Length of longest palindrome starting from beginning
        longest_palindrome_len = lps[-1]
        
        # Add reverse of remaining part to the beginning
        to_add = s[longest_palindrome_len:][::-1]
        
        return to_add + s
    
    def build_lps(self, pattern: str) -> List[int]:
        m = len(pattern)
        lps = [0] * m
        length = 0
        i = 1
        
        while i < m:
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        
        return lps
    
    # Approach 2: Brute Force
    def shortestPalindromeBruteForce(self, s: str) -> str:
        n = len(s)
        
        # Find the longest palindrome starting from index 0
        end = n - 1
        while end >= 0:
            if self.is_palindrome(s, 0, end):
                break
            end -= 1
        
        # Add reverse of remaining part to the beginning
        to_add = s[end + 1:][::-1]
        
        return to_add + s
    
    def is_palindrome(self, s: str, left: int, right: int) -> bool:
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.shortestPalindrome('aacecaaa')}")  # "aaacecaaa"
    print(f"Test 2: {sol.shortestPalindrome('abcd')}")      # "dcbabcd"
    print(f"Test 3: {sol.shortestPalindrome('')}")          # ""
    print(f"Test 4: {sol.shortestPalindrome('a')}")         # "a"
