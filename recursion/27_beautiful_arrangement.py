"""
PROBLEM: Beautiful Arrangement
---------------------------------------------------------------------------
Suppose you have n integers labeled 1 through n. A permutation of those n 
integers is considered beautiful if for every i (1 <= i <= n), either:
- perm[i] is divisible by i, or
- i is divisible by perm[i]
Given an integer n, return the number of beautiful arrangements.

DIFFICULTY: Medium
PATTERN: Backtracking (Constraint-based Permutation)
TIME COMPLEXITY: O(k) where k is number of valid permutations (< n!)
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 2
Output: 2
Explanation: [1,2] and [2,1] are both beautiful

Example 2:
Input: n = 3
Output: 3
Explanation: [1,2,3], [2,1,3], [3,2,1] are beautiful
"""

from typing import List


class Solution:
    def countArrangement(self, n: int) -> int:
        visited = [False] * (n + 1)
        return self._backtrack(n, 1, visited)

    def _backtrack(self, n: int, pos: int, visited: List[bool]) -> int:
        if pos > n:
            return 1
        count = 0
        for num in range(1, n + 1):
            if not visited[num] and (num % pos == 0 or pos % num == 0):
                visited[num] = True
                count += self._backtrack(n, pos + 1, visited)
                visited[num] = False
        return count


if __name__ == "__main__":
    sol = Solution()
    n1 = 2
    print(f"Test 1: Beautiful arrangements for n={n1} = {sol.countArrangement(n1)}")
    n2 = 3
    print(f"Test 2: Beautiful arrangements for n={n2} = {sol.countArrangement(n2)}")
