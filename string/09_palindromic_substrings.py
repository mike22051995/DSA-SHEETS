"""
    Palindromic Substrings - LeetCode #647
    
    Given a string s, return the number of palindromic substrings in it.
    A string is a palindrome when it reads the same backward as forward.
    A substring is a contiguous sequence of characters within the string.
    
    Example 1:
    Input: s = "abc"
    Output: 3
    Explanation: Three palindromic strings: "a", "b", "c".
    
    Example 2:
    Input: s = "aaa"
    Output: 6
    Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
    
    Constraints:
    - 1 <= s.length <= 1000
    - s consists of lowercase English letters
    
    Time Complexity: O(n^2)
    Space Complexity: O(1)
"""

class Solution:
    # Approach: Expand Around Center
    def countSubstrings(self, s: str) -> int:
        count = 0
        
        for i in range(len(s)):
            # Count odd length palindromes
            count += self.expand_around_center(s, i, i)
            # Count even length palindromes
            count += self.expand_around_center(s, i, i + 1)
        
        return count
    
    def expand_around_center(self, s: str, left: int, right: int) -> int:
        count = 0
        while left >= 0 and right < len(s) and s[left] == s[right]:
            count += 1
            left -= 1
            right += 1
        return count

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Test 1: {sol.countSubstrings('abc')}")     # 3
    print(f"Test 2: {sol.countSubstrings('aaa')}")     # 6
    print(f"Test 3: {sol.countSubstrings('racecar')}") # 10
