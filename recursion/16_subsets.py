"""
PROBLEM: Subsets (Power Set)
---------------------------------------------------------------------------
Given an integer array nums of unique elements, return all possible subsets.
The solution set must not contain duplicate subsets.

DIFFICULTY: Medium
PATTERN: Backtracking (Include/Exclude)
TIME COMPLEXITY: O(2^n)
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
"""

from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        current = []
        self._backtrack(nums, 0, current, result)
        return result

    def _backtrack(self, nums: List[int], index: int, current: List[int],
                   result: List[List[int]]) -> None:
        # Base case: add current subset
        if index >= len(nums):
            result.append(current[:])
            return
        # Exclude current element
        self._backtrack(nums, index + 1, current, result)
        # Include current element
        current.append(nums[index])
        self._backtrack(nums, index + 1, current, result)
        current.pop()


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 2, 3]
    result1 = sol.subsets(nums1)
    print(f"Test 1: {result1}")
    nums2 = [0]
    result2 = sol.subsets(nums2)
    print(f"Test 2: Total subsets = {len(result2)}")
