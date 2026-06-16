"""
PROBLEM: Range Sum Query - Immutable
Difficulty: Easy
Pattern: Prefix Sum DP

DESCRIPTION:
Given an integer array nums, handle multiple queries of the following type:
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

INPUT:
nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> -2 + 0 + 3 = 1
sumRange(2, 5) -> 3 + (-5) + 2 + (-1) = -1
sumRange(0, 5) -> -2 + 0 + 3 + (-5) + 2 + (-1) = -3

OUTPUT:
[1, -1, -3]

TIME COMPLEXITY: O(1) per query, O(n) for preprocessing
SPACE COMPLEXITY: O(n) for prefix sum array
"""

class NumArray:
    def __init__(self, nums):
        n = len(nums)
        self.prefix = [0] * (n + 1)
        for i in range(n):
            self.prefix[i + 1] = self.prefix[i] + nums[i]

    def sumRange(self, left, right):
        return self.prefix[right + 1] - self.prefix[left]


if __name__ == "__main__":
    nums = [-2, 0, 3, -5, 2, -1]
    print(f"Input: nums = [-2, 0, 3, -5, 2, -1]")
    numArray = NumArray(nums)
    print(f"sumRange(0, 2) = {numArray.sumRange(0, 2)}")
    print(f"sumRange(2, 5) = {numArray.sumRange(2, 5)}")
    print(f"sumRange(0, 5) = {numArray.sumRange(0, 5)}")
