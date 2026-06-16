"""
PROBLEM: Minimum Deviation in Array (LeetCode 1675)
DIFFICULTY: Hard
PATTERN: Heap - Max-Heap with current minimum tracking

DESCRIPTION:
You can divide even numbers by 2 and multiply odd numbers by 2.
Return minimum possible deviation (max - min) after any operations.

EXAMPLE:
Input: [1,2,3,4] -> 1
Input: [4,1,5,20,3] -> 3
Input: [2,10,8] -> 3

TIME COMPLEXITY: O(n log n * log(max_val))
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        max_heap: List[int] = []
        current_min = float('inf')

        # Convert all to even (multiply odds by 2)
        for x in nums:
            if x % 2 == 1:
                x *= 2
            heapq.heappush(max_heap, -x)
            current_min = min(current_min, x)

        min_deviation = -max_heap[0] - current_min

        while max_heap[0] % 2 == 0:  # top is even (negated → even check)
            top = -heapq.heappop(max_heap)
            current_min = min(current_min, top)
            min_deviation = min(min_deviation, top - current_min)
            top //= 2
            heapq.heappush(max_heap, -top)
            min_deviation = min(min_deviation, -max_heap[0] - current_min)

        return min_deviation


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        [1, 2, 3, 4],
        [4, 1, 5, 20, 3],
        [2, 10, 8],
    ]
    for nums in test_cases:
        print(f"nums={nums} -> {sol.minimumDeviation(nums)}")
