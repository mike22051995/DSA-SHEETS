"""
PROBLEM: Top K Frequent Elements (LeetCode 347)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap of size k by frequency

DESCRIPTION:
Given an integer array nums and an integer k, return the k most frequent elements.

EXAMPLE:
Input: nums = [1,1,1,2,2,3], k = 2 -> Output: [1, 2]
Input: nums = [1], k = 1 -> Output: [1]

TIME COMPLEXITY: O(n log k)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List
from collections import Counter


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        # min-heap of (frequency, element); keep size k
        min_heap: List = []
        for num, cnt in freq.items():
            heapq.heappush(min_heap, (cnt, num))
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        return [num for _, num in min_heap]

    def topKFrequentBucket(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        buckets: List[List[int]] = [[] for _ in range(len(nums) + 1)]
        for num, cnt in freq.items():
            buckets[cnt].append(num)
        result: List[int] = []
        for i in range(len(buckets) - 1, -1, -1):
            result.extend(buckets[i])
            if len(result) >= k:
                return result[:k]
        return result[:k]


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([1, 1, 1, 2, 2, 3], 2),
        ([1], 1),
        ([4, 4, 4, 6, 6, 7], 2),
    ]
    for nums, k in test_cases:
        print(f"nums={nums}, k={k} -> {sol.topKFrequent(nums, k)}")
