"""
PROBLEM: Generate All Subsets (Power Set)
===========================================
Given a set of distinct integers, return all possible subsets (power set).

APPROACH:
- Use bit manipulation to generate all subsets
- For n elements, there are 2^n subsets
- Each subset corresponds to a binary number from 0 to 2^n-1
- If ith bit is set, include ith element in subset

PATTERN: Subset Generation using Binary Representation

INPUT/OUTPUT:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Explanation: All possible subsets

Input: nums = [0]
Output: [[],[0]]

TIME COMPLEXITY: O(n * 2^n) - n for each subset creation
SPACE COMPLEXITY: O(n * 2^n) - for output
"""

from typing import List, Optional

class Solution:
    def for(self, mask++):
        public:
        vector<vector<int>> subsets(vector<int>& nums):
        vector<vector<int>> result
        n = len(nums)
        totalSubsets = 1 << n; # 2^n subsets
        # Generate all subsets from 0 to 2^n-1
        for mask in range(totalSubsets):
        subset
        # Check each bit
        for i in range(n):
        # If ith bit is set, include nums[i]
        if (mask & (1 << i)):
        subset.append(nums[i])
        result.append(subset)
        return result


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 2, 3]
    print(f"Input: [1,2,3]")
    print("Output: ")
    vector<vector<int>> result1 = sol.subsets(nums1)
    printSubsets(result1)
    print(f"Total subsets: {len(result1)}")
    nums2 = [0]
    print(f"Input: [0]")
    print("Output: ")
    vector<vector<int>> result2 = sol.subsets(nums2)
    printSubsets(result2)
    print(f"Total subsets: {len(result2)}")
