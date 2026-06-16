"""
PROBLEM: Meeting Rooms II (LeetCode 253)
DIFFICULTY: Medium
PATTERN: Heap - Min-Heap for end times of active meetings

DESCRIPTION:
Given meeting time intervals, find minimum number of conference rooms required.

EXAMPLE:
Input: [[0,30],[5,10],[15,20]] -> Output: 2
Input: [[7,10],[2,4]] -> Output: 1
Input: [[1,5],[2,6],[4,8],[9,10]] -> Output: 3

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key=lambda x: x[0])
        # min-heap of end times of currently active meetings
        end_times: List[int] = []

        for start, end in intervals:
            if end_times and end_times[0] <= start:
                heapq.heapreplace(end_times, end)
            else:
                heapq.heappush(end_times, end)

        return len(end_times)


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        [[0, 30], [5, 10], [15, 20]],
        [[7, 10], [2, 4]],
        [[1, 5], [2, 6], [4, 8], [9, 10]],
    ]
    for intervals in test_cases:
        print(f"intervals={intervals} -> {sol.minMeetingRooms([i[:] for i in intervals])}")
