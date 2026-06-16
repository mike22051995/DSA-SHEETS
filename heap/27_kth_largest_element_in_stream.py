"""
PROBLEM: Kth Largest Element in a Stream (LeetCode 703)
DIFFICULTY: Easy
PATTERN: Heap - Min-Heap of size k

DESCRIPTION:
Design a class that initializes with k and a list of numbers, and returns
the k-th largest element after each new number is added.

EXAMPLE:
init k=3, nums=[4,5,8,2], add(3) -> 4
add(5) -> 5
add(10) -> 5

TIME COMPLEXITY: O(log k) per add
SPACE COMPLEXITY: O(k)
"""

import heapq
from typing import List


class KthLargest:
    def __init__(self, k: int, nums: List[int]) -> None:
        self.k = k
        self.min_heap: List[int] = []
        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        heapq.heappush(self.min_heap, val)
        if len(self.min_heap) > self.k:
            heapq.heappop(self.min_heap)
        return self.min_heap[0]


if __name__ == "__main__":
    kl = KthLargest(3, [4, 5, 8, 2])
    for val in [3, 5, 10, 9, 4]:
        print(f"add({val}) -> {kl.add(val)}")
