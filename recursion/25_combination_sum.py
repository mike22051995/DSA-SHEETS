"""
PROBLEM: Combination Sum
---------------------------------------------------------------------------
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations where the chosen numbers sum to 
target. The same number may be chosen from candidates an unlimited number 
of times.

DIFFICULTY: Medium
PATTERN: Backtracking (Unbounded Knapsack)
TIME COMPLEXITY: O(n^(target/min))
SPACE COMPLEXITY: O(target/min) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
"""

from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        self._backtrack(candidates, target, 0, [], result)
        return result

    def _backtrack(self, candidates: List[int], target: int, start: int,
                   current: List[int], result: List[List[int]]) -> None:
        if target == 0:
            result.append(current[:])
            return
        if target < 0:
            return
        for i in range(start, len(candidates)):
            current.append(candidates[i])
            self._backtrack(candidates, target - candidates[i], i, current, result)
            current.pop()


if __name__ == "__main__":
    sol = Solution()
    candidates1 = [2, 3, 6, 7]
    target1 = 7
    result1 = sol.combinationSum(candidates1, target1)
    print(f"Test 1: {result1}")
    candidates2 = [2, 3, 5]
    target2 = 8
    result2 = sol.combinationSum(candidates2, target2)
    print(f"Test 2: Total combinations = {len(result2)}")
