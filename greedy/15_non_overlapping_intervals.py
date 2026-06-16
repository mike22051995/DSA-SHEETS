"""
PROBLEM: Non-overlapping Intervals (LeetCode 435)
DIFFICULTY: Medium
PATTERN: Interval Scheduling / Activity Selection

DESCRIPTION:
Given an array of intervals where intervals[i] = [start_i, end_i], return the minimum 
number of intervals you need to remove to make the rest of the intervals non-overlapping.

INPUT:
- intervals: array of [start, end] pairs

OUTPUT:
- Minimum number of intervals to remove

APPROACH:
1. Sort intervals by end time (earliest ending first)
2. Keep track of end time of last kept interval
3. If current interval starts before last end, it overlaps → remove it
4. Otherwise, update last end time

WHY GREEDY WORKS:
Keeping intervals that end earliest leaves more room for future intervals.
This is the classic activity selection problem.
"""

from typing import List, Optional

class Solution:
    def eraseOverlapIntervals(self, intervals):
        if (not intervals) return 0
        # Sort by end time
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b):
        return a[1] < b[1]
        })
        removals = 0
        lastEnd = intervals[0][1]
        for i in range(1, len(intervals)):
        # If current interval starts before last end, overlaps
        if intervals[i][0] < lastEnd:
        removals++;  # Remove current interval
        } else 
        lastEnd = intervals[i][1];  # Update last end
        return removals


if __name__ == "__main__":
    sol = Solution()
    vector<vector<int>> intervals1 = [{1, 2], [2, 3], [3, 4], [1, 3]}
    print(f"Test 1 - Intervals: [[1,2],[2,3],[3,4],[1,3]]")
    print(f"Output: {sol.eraseOverlapIntervals(intervals1)}")
    print(f"Expected: 1 (remove [1,3])")
    vector<vector<int>> intervals2 = [{1, 2], [1, 2], [1, 2]}
    print(f"Test 2 - Intervals: [[1,2],[1,2],[1,2]]")
    print(f"Output: {sol.eraseOverlapIntervals(intervals2)}")
    print(f"Expected: 2 (keep only one)")
    vector<vector<int>> intervals3 = [{1, 2], [2, 3]}
    print(f"Test 3 - Intervals: [[1,2],[2,3]]")
    print(f"Output: {sol.eraseOverlapIntervals(intervals3)}")
    print(f"Expected: 0 (touching but not overlapping)")
    vector<vector<int>> intervals4 = [{1, 100], [11, 22], [1, 11], [2, 12]}
    print(f"Test 4 - Intervals: [[1,100],[11,22],[1,11],[2,12]]")
    print(f"Output: {sol.eraseOverlapIntervals(intervals4)}")
    print(f"Expected: 2")
