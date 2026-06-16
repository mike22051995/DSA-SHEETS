"""
PROBLEM: Valid Palindrome
---------------------------------------------------------------------------
A phrase is a palindrome if, after converting all uppercase letters into 
lowercase letters and removing all non-alphanumeric characters, it reads 
the same forward and backward. Return True if it is a palindrome, False otherwise.

PATTERN: Opposite Direction Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: True
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: False
Explanation: "raceacar" is not a palindrome.
"""

from typing import List


class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1
        while left < right:
            # Skip non-alphanumeric characters from left
            while left < right and not s[left].isalnum():
                left += 1
            # Skip non-alphanumeric characters from right
            while left < right and not s[right].isalnum():
                right -= 1
            # Compare characters (case-insensitive)
            if s[left].lower() != s[right].lower():
                return False
            left += 1
            right -= 1
        return True


if __name__ == "__main__":
    sol = Solution()
    s1 = "A man, a plan, a canal: Panama"
    print(f"Test 1: {sol.isPalindrome(s1)}")
    s2 = "race a car"
    print(f"Test 2: {sol.isPalindrome(s2)}")
