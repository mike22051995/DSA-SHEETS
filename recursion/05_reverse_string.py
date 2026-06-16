"""
PROBLEM: Reverse String
---------------------------------------------------------------------------
Write a recursive function that reverses a string.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "hello"
Output: "olleh"

Example 2:
Input: s = "recursion"
Output: "noisrucer"
"""

from typing import List


class Solution:
    def reverseString(self, s: str) -> str:
        def helper(chars: list, left: int, right: int) -> None:
            if left >= right:
                return
            chars[left], chars[right] = chars[right], chars[left]
            helper(chars, left + 1, right - 1)

        chars = list(s)
        helper(chars, 0, len(chars) - 1)
        return "".join(chars)


if __name__ == "__main__":
    sol = Solution()
    s1 = "hello"
    print(f"Test 1: Reverse of '{s1}' = '{sol.reverseString(s1)}'")
    s2 = "recursion"
    print(f"Test 2: Reverse of '{s2}' = '{sol.reverseString(s2)}'")
