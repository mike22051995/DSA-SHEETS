"""
PROBLEM: Permutations
---------------------------------------------------------------------------
Given an array nums of distinct integers, return all possible permutations.

DIFFICULTY: Medium
PATTERN: Backtracking (Swap-based)
TIME COMPLEXITY: O(n * n!)
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
"""

from typing import List, Optional

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        """Generate all permutations using backtracking"""
        result = []
        self.backtrack(nums[:], 0, result)
        return result
    
    def backtrack(self, nums: List[int], start: int, result: List[List[int]]) -> None:
        """Helper function to generate permutations"""
        # Base case: reached end
        if start >= len(nums):
            result.append(nums[:])  # Append a copy
            return
        
        # Try each element at current position
        for i in range(start, len(nums)):
            # Swap to choose
            nums[start], nums[i] = nums[i], nums[start]
            # Explore
            self.backtrack(nums, start + 1, result)
            # Swap back to backtrack
            nums[start], nums[i] = nums[i], nums[start]


if __name__ == "__main__":
    sol = Solution()
    
    # Test 1
    nums1 = [1, 2, 3]
    result1 = sol.permute(nums1)
    print(f"Test 1: Total permutations = {len(result1)}")
    print("Permutations:", result1)
    
    # Test 2
    nums2 = [0, 1]
    result2 = sol.permute(nums2)
    print(f"Test 2: Total permutations = {len(result2)}")
    print("Permutations:", result2)
