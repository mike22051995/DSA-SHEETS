"""
PROBLEM: Catalan Numbers
DIFFICULTY: Medium
PATTERN: Combinatorial DP / Partition DP

DESCRIPTION:
Catalan numbers form a sequence of natural numbers that occur in many counting problems.
The nth Catalan number counts:
1. Number of valid parentheses expressions with n pairs
2. Number of binary search trees with n nodes
3. Number of ways to triangulate a polygon with n+2 sides
4. Number of paths in grid that don't cross diagonal
5. And many more...

Formula: C(n) = (2n)! / ((n+1)! * n!)
Or: C(n) = Σ C(i) * C(n-1-i) for i from 0 to n-1

EXAMPLE:
C(0) = 1
C(1) = 1
C(2) = 2  ((), ()())
C(3) = 5  ((())) (()()), (())(), ()(()), ()()())
C(4) = 14
C(5) = 42

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n)
"""

from typing import List, Optional

class Solution:
    def catalanFormula(self, n):
        if n <= 1:
            return 1
        from math import comb
        # C(n) = C(2n, n) / (n+1)
        return comb(2 * n, n) // (n + 1)

    def catalanDP(self, n):
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i-1-j]
        return dp[n]

    def catalanMemoWrapper(self, n):
        from functools import lru_cache
        @lru_cache(maxsize=None)
        def catalan(k):
            if k <= 1:
                return 1
            return sum(catalan(j) * catalan(k-1-j) for j in range(k))
        return catalan(n)

    def generateParentheses(self, n):
        result = []
        def backtrack(s, open_count, close_count):
            if len(s) == 2 * n:
                result.append(s)
                return
            if open_count < n:
                backtrack(s + '(', open_count + 1, close_count)
            if close_count < open_count:
                backtrack(s + ')', open_count, close_count + 1)
        backtrack('', 0, 0)
        return result

    def numTriangulations(self, sides):
        # Number of triangulations of a polygon with n sides = C(n-2)
        return self.catalanFormula(sides - 2)


if __name__ == "__main__":
    sol = Solution()
    print(f"=== CATALAN NUMBERS ===")
    print(f"First 10 Catalan Numbers:")
    for i in range(11):
        print(f"C({i}) = {sol.catalanFormula(i)}")
    print(f"\n=== VERIFICATION ===")
    n = 5
    print(f"C({n}) values:")
    print(f"Formula: {sol.catalanFormula(n)}")
    print(f"DP: {sol.catalanDP(n)}")
    print(f"Memoization: {sol.catalanMemoWrapper(n)}")
    print(f"\n=== APPLICATION: Valid Parentheses ===")
    pairs = 3
    print(f"Valid parentheses with {pairs} pairs:")
    parens = sol.generateParentheses(pairs)
    for p in parens:
        print(p)
    print(f"Count: {len(parens)}")
    print(f"\n=== APPLICATION: Number of BSTs ===")
    nodes = 4
    print(f"Number of BSTs with {nodes} nodes: {sol.catalanFormula(nodes)}")
    print(f"\n=== APPLICATION: Polygon Triangulation ===")
    sides = 5
    print(f"Ways to triangulate polygon with {sides} sides: {sol.numTriangulations(sides)}")
