"""
PROBLEM: Find K Pairs with Smallest Sums (LeetCode 373)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap with (sum, i, j) state

DESCRIPTION:
Given two sorted arrays nums1, nums2, return k pairs (u,v) with smallest sums.

EXAMPLE:
Input: nums1=[1,7,11], nums2=[2,4,6], k=3 -> [[1,2],[1,4],[1,6]]
Input: nums1=[1,1,2], nums2=[1,2,3], k=2 -> [[1,1],[1,1]]

TIME COMPLEXITY: O(k log k)
SPACE COMPLEXITY: O(k)
"""

import heapq
from typing import List


class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        if not nums1 or not nums2:
            return []

        min_heap: List = []
        # Initialize with (sum, i, j=0) for first min(k, len) indices of nums1
        for i in range(min(k, len(nums1))):
            heapq.heappush(min_heap, (nums1[i] + nums2[0], i, 0))

        result: List[List[int]] = []
        while min_heap and len(result) < k:
            _, i, j = heapq.heappop(min_heap)
            result.append([nums1[i], nums2[j]])
            if j + 1 < len(nums2):
                heapq.heappush(min_heap, (nums1[i] + nums2[j + 1], i, j + 1))

        return result


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([1, 7, 11], [2, 4, 6], 3),
        ([1, 1, 2], [1, 2, 3], 2),
        ([1, 2], [3], 3),
    ]
    for nums1, nums2, k in test_cases:
        print(f"nums1={nums1}, nums2={nums2}, k={k} -> {sol.kSmallestPairs(nums1, nums2, k)}")
