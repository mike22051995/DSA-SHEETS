"""
PROBLEM: Find Median from Data Stream (LeetCode 295)
DIFFICULTY: Hard
PATTERN: Heap - Two Heaps (max-heap for lower half, min-heap for upper half)

DESCRIPTION:
Design a data structure that supports adding numbers and finding median at any time.

EXAMPLE:
add(1), add(2) -> median = 1.5
add(3) -> median = 2.0
add(4), add(5) -> median = 3.0

TIME COMPLEXITY: O(log n) add, O(1) findMedian
SPACE COMPLEXITY: O(n)
"""

import heapq


class MedianFinder:
    def __init__(self) -> None:
        # max_heap: lower half (negate to simulate max-heap)
        self.max_heap: list = []
        # min_heap: upper half
        self.min_heap: list = []

    def addNum(self, num: int) -> None:
        # Push to max_heap first
        heapq.heappush(self.max_heap, -num)
        # Balance: ensure max_heap top <= min_heap top
        if self.min_heap and (-self.max_heap[0]) > self.min_heap[0]:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        # Balance sizes: max_heap can have at most 1 extra
        if len(self.max_heap) > len(self.min_heap) + 1:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        elif len(self.min_heap) > len(self.max_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))

    def findMedian(self) -> float:
        if len(self.max_heap) > len(self.min_heap):
            return float(-self.max_heap[0])
        return (-self.max_heap[0] + self.min_heap[0]) / 2.0


if __name__ == "__main__":
    mf = MedianFinder()
    ops = [1, 2, 3, 4, 5]
    for num in ops:
        mf.addNum(num)
        print(f"After adding {num}: median = {mf.findMedian()}")

    mf2 = MedianFinder()
    mf2.addNum(1)
    mf2.addNum(2)
    print(f"Median after [1,2]: {mf2.findMedian()}")
    mf2.addNum(3)
    print(f"Median after [1,2,3]: {mf2.findMedian()}")
