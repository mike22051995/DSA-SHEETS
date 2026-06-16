"""
PROBLEM: Kth Largest Element in an Array (LeetCode 215)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap of size k

DESCRIPTION:
Given an integer array nums and an integer k, return the k-th largest element.

EXAMPLE:
Input: nums = [3,2,1,5,6,4], k = 2 -> Output: 5
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4 -> Output: 4

TIME COMPLEXITY: O(n log k)
SPACE COMPLEXITY: O(k)
"""

import heapq
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # Maintain min-heap of size k; top is k-th largest
        min_heap: List[int] = []
        for num in nums:
            heapq.heappush(min_heap, num)
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        return min_heap[0]

    def findKthLargestQuickSelect(self, nums: List[int], k: int) -> int:
        # QuickSelect O(n) average
        target = len(nums) - k

        def partition(lo: int, hi: int) -> int:
            pivot = nums[hi]
            i = lo
            for j in range(lo, hi):
                if nums[j] <= pivot:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
            nums[i], nums[hi] = nums[hi], nums[i]
            return i

        lo, hi = 0, len(nums) - 1
        while lo < hi:
            pi = partition(lo, hi)
            if pi == target:
                break
            elif pi < target:
                lo = pi + 1
            else:
                hi = pi - 1
        return nums[target]


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([3, 2, 1, 5, 6, 4], 2),
        ([3, 2, 3, 1, 2, 4, 5, 5, 6], 4),
        ([7], 1),
    ]
    for nums, k in test_cases:
        print(f"nums={nums}, k={k} -> {sol.findKthLargest(nums[:], k)}")
