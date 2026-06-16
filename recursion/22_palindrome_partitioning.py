"""
PROBLEM: Palindrome Partitioning
---------------------------------------------------------------------------
Given a string s, partition s such that every substring of the partition 
is a palindrome. Return all possible palindrome partitioning of s.

DIFFICULTY: Medium
PATTERN: Backtracking (String Partitioning)
TIME COMPLEXITY: O(n * 2^n)
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
"""

from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result = []
        self._backtrack(s, 0, [], result)
        return result

    def _backtrack(self, s: str, start: int, current: List[str],
                   result: List[List[str]]) -> None:
        if start >= len(s):
            result.append(current[:])
            return
        for end in range(start, len(s)):
            if self._is_palindrome(s, start, end):
                current.append(s[start:end + 1])
                self._backtrack(s, end + 1, current, result)
                current.pop()

    def _is_palindrome(self, s: str, left: int, right: int) -> bool:
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True


if __name__ == "__main__":
    sol = Solution()
    s1 = "aab"
    result1 = sol.partition(s1)
    print(f"Test 1: {result1}")
    s2 = "a"
    result2 = sol.partition(s2)
    print(f"Test 2: Total partitions = {len(result2)}")
