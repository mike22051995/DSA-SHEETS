"""
PROBLEM: Furthest Building You Can Reach (LeetCode 1642)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap to greedily assign bricks vs ladders

DESCRIPTION:
Given building heights, bricks, and ladders, find furthest building index reachable.
For each upward jump, use a ladder or bricks.

EXAMPLE:
Input: heights=[4,2,7,6,9,14,12], bricks=5, ladders=1 -> 4
Input: heights=[4,12,2,7,3,18,20,3,19], bricks=10, ladders=2 -> 7
Input: heights=[14,3,19,3], bricks=17, ladders=0 -> 3

TIME COMPLEXITY: O(n log L) where L = ladders
SPACE COMPLEXITY: O(L)
"""

import heapq
from typing import List


class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        # Min-heap stores climbs where we used ladders
        min_heap: List[int] = []

        for i in range(len(heights) - 1):
            climb = heights[i + 1] - heights[i]
            if climb <= 0:
                continue
            # Assign ladder to this climb
            heapq.heappush(min_heap, climb)
            if len(min_heap) > ladders:
                # Convert smallest ladder-climb to bricks
                bricks -= heapq.heappop(min_heap)
                if bricks < 0:
                    return i

        return len(heights) - 1


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([4, 2, 7, 6, 9, 14, 12], 5, 1),
        ([4, 12, 2, 7, 3, 18, 20, 3, 19], 10, 2),
        ([14, 3, 19, 3], 17, 0),
    ]
    for heights, bricks, ladders in test_cases:
        print(f"heights={heights}, bricks={bricks}, ladders={ladders} -> "
              f"{sol.furthestBuilding(heights, bricks, ladders)}")
