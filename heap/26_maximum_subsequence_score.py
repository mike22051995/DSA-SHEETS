"""
PROBLEM: Maximum Subsequence Score (LeetCode 2542)
DIFFICULTY: Medium
PATTERN: Heap - Sort by nums2 desc, Min-Heap for top-k nums1 values

DESCRIPTION:
Given nums1 and nums2, pick k indices to maximize: sum(nums1[i]) * min(nums2[i]).

EXAMPLE:
Input: nums1=[1,3,3,2], nums2=[2,1,3,4], k=3 -> 12
Input: nums1=[4,2,3,1,1], nums2=[7,5,10,9,6], k=1 -> 30
Input: nums1=[2,1,14,12], nums2=[11,7,13,6], k=3 -> 168

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        # Sort pairs by nums2 descending so current nums2 value acts as minimum
        pairs = sorted(zip(nums1, nums2), key=lambda p: -p[1])

        min_heap: List[int] = []  # store nums1 values
        nums1_sum = 0
        best = 0

        for n1, n2 in pairs:
            heapq.heappush(min_heap, n1)
            nums1_sum += n1
            if len(min_heap) > k:
                nums1_sum -= heapq.heappop(min_heap)
            if len(min_heap) == k:
                best = max(best, nums1_sum * n2)

        return best


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([1, 3, 3, 2], [2, 1, 3, 4], 3),
        ([4, 2, 3, 1, 1], [7, 5, 10, 9, 6], 1),
        ([2, 1, 14, 12], [11, 7, 13, 6], 3),
    ]
    for nums1, nums2, k in test_cases:
        print(f"nums1={nums1}, nums2={nums2}, k={k} -> {sol.maxScore(nums1, nums2, k)}")
