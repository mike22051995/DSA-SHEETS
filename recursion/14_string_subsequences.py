"""
PROBLEM: Print All Subsequences of a String
---------------------------------------------------------------------------
Given a string, print all possible subsequences (subsets) using recursion.
A subsequence is a sequence derived by deleting some or no characters 
without changing the order of remaining characters.

DIFFICULTY: Medium
PATTERN: Recursion Tree (Include/Exclude)
TIME COMPLEXITY: O(2^n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "abc"
Output: "", "a", "b", "c", "ab", "ac", "bc", "abc"
Explanation: All 2^3 = 8 subsequences

Example 2:
Input: s = "ab"
Output: "", "a", "b", "ab"
Explanation: All 2^2 = 4 subsequences
"""

from typing import List


class Solution:
    def printSubsequences(self, s: str) -> None:
        def helper(index: int, current: str) -> None:
            if index >= len(s):
                print(repr(current))
                return
            # Include s[index]
            helper(index + 1, current + s[index])
            # Exclude s[index]
            helper(index + 1, current)

        helper(0, "")

    def getAllSubsequences(self, s: str) -> List[str]:
        result = []

        def helper(index: int, current: str) -> None:
            if index >= len(s):
                result.append(current)
                return
            helper(index + 1, current + s[index])
            helper(index + 1, current)

        helper(0, "")
        return result


if __name__ == "__main__":
    sol = Solution()
    s1 = "abc"
    print(f"Test 1: Subsequences of '{s1}':")
    sol.printSubsequences(s1)
    print()
    s2 = "ab"
    result = sol.getAllSubsequences(s2)
    print(f"Test 2: Subsequences of '{s2}':")
    for sub in result:
        print(f"  '{sub}'")
    print()
