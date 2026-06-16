"""
PROBLEM: Check Palindrome String
---------------------------------------------------------------------------
Given a string, check if it is a palindrome using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion (Two Pointers)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "racecar"
Output: True
Explanation: "racecar" reads the same forward and backward

Example 2:
Input: s = "hello"
Output: False
Explanation: "hello" is not a palindrome
"""

from typing import List


class Solution:
    def isPalindrome(self, s: str) -> bool:
        def check(left: int, right: int) -> bool:
            if left >= right:
                return True
            if s[left] != s[right]:
                return False
            return check(left + 1, right - 1)

        return check(0, len(s) - 1)


if __name__ == "__main__":
    sol = Solution()
    s1 = "racecar"
    print(f"Test 1: Is '{s1}' a palindrome? {sol.isPalindrome(s1)}")
    s2 = "hello"
    print(f"Test 2: Is '{s2}' a palindrome? {sol.isPalindrome(s2)}")
