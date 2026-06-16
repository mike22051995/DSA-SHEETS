"""
PROBLEM: Combinations
---------------------------------------------------------------------------
Given two integers n and k, return all possible combinations of k numbers 
chosen from the range [1, n].

DIFFICULTY: Medium
PATTERN: Backtracking (Choose K from N)
TIME COMPLEXITY: O(C(n,k) * k) where C(n,k) is binomial coefficient
SPACE COMPLEXITY: O(k) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

Example 2:
Input: n = 1, k = 1
Output: [[1]]
"""

from typing import List, Optional

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        """Generate all combinations of k numbers from range [1, n]"""
        result = []
        current = []
        self.backtrack(n, k, 1, current, result)
        return result
    
    def backtrack(self, n: int, k: int, start: int, current: List[int], result: List[List[int]]) -> None:
        """Helper function for backtracking"""
        # Base case: found k numbers
        if len(current) == k:
            result.append(current[:])
            return
        
        # Try each number from start to n
        for i in range(start, n + 1):
            current.append(i)  # Choose
            self.backtrack(n, k, i + 1, current, result)  # Explore
            current.pop()  # Unchoose (backtrack)


if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    n1, k1 = 4, 2
    result1 = sol.combine(n1, k1)
    print(f"Test 1: n={n1}, k={k1}")
    print(f"Combinations: {result1}")
    
    # Test 2
    n2, k2 = 1, 1
    result2 = sol.combine(n2, k2)
    print(f"Test 2: n={n2}, k={k2}")
    print(f"Combinations: {result2}")
