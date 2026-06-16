"""
PROBLEM: Maximum Product After K Increments (LeetCode 2233)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap greedy (always increment smallest)

DESCRIPTION:
Given nums and k operations, in each operation increment one element by 1.
Return maximum possible product modulo 10^9 + 7.

EXAMPLE:
Input: nums=[0,4], k=5 -> 20
Input: nums=[6,3,3,2], k=2 -> 216
Input: nums=[1,1,1], k=3 -> 8

TIME COMPLEXITY: O((n + k) log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        MOD = 10 ** 9 + 7
        heapq.heapify(nums)

        for _ in range(k):
            smallest = heapq.heappop(nums)
            heapq.heappush(nums, smallest + 1)

        result = 1
        for x in nums:
            result = (result * x) % MOD
        return result


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([0, 4], 5),
        ([6, 3, 3, 2], 2),
        ([1, 1, 1], 3),
    ]
    for nums, k in test_cases:
        print(f"nums={nums}, k={k} -> {sol.maximumProduct(nums[:], k)}")
