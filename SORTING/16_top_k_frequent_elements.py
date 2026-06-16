"""
PROBLEM: Top K Frequent Elements (LeetCode 347)
===============================================
DESCRIPTION:
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.

PATTERN: Heap / QuickSelect / Bucket Sort
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log k) using heap, O(n) using bucket sort
SPACE COMPLEXITY: O(n)

INPUT:
nums = [1,1,1,2,2,3], k = 2

OUTPUT:
[1,2]

EXAMPLE:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]
"""

import heapq
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Count frequency of each number
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        # Use min heap of size k
        heap = []
        for num, count in freq.items():
            heapq.heappush(heap, (count, num))
            if len(heap) > k:
                heapq.heappop(heap)
        
        # Extract elements from heap
        result = []
        while heap:
            result.append(heapq.heappop(heap)[1])
        
        return result[::-1]
    
    def topKFrequentBucket(self, nums: List[int], k: int) -> List[int]:
        # Count frequency
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        # Bucket sort by frequency
        buckets = [[] for _ in range(len(nums) + 1)]
        for num, count in freq.items():
            buckets[count].append(num)
        
        # Collect k most frequent
        result = []
        for i in range(len(buckets) - 1, -1, -1):
            for num in buckets[i]:
                result.append(num)
                if len(result) == k:
                    return result
        
        return result


if __name__ == "__main__":
    sol = Solution()
    nums1 = [1, 1, 1, 2, 2, 3]
    k1 = 2
    print("Array: ")
    for num in nums1:
        print(num, end=" ")
    print(f"\nK = {k1}")
    result1 = sol.topKFrequent(nums1, k1)
    print(f"Top {k1} frequent: {result1}")
    
    result1_bucket = sol.topKFrequentBucket(nums1, k1)
    print(f"Top {k1} frequent (Bucket): {result1_bucket}")
