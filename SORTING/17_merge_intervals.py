"""
PROBLEM: Merge Intervals (LeetCode 56)
===============================================
DESCRIPTION:
Given an array of intervals where intervals[i] = [starti, endi], merge all 
overlapping intervals, and return an array of the non-overlapping intervals.

PATTERN: Sorting + Merge
DIFFICULTY: Medium
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)

INPUT:
Array of intervals

OUTPUT:
Array of merged intervals

EXAMPLE:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Input: [[1,4],[4,5]]
Output: [[1,5]]
"""

from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        # Sort intervals by start time
        intervals.sort(key=lambda x: x[0])
        
        merged = [intervals[0]]
        
        for current in intervals[1:]:
            last = merged[-1]
            # If current interval overlaps with last merged interval
            if current[0] <= last[1]:
                # Merge by updating end time
                last[1] = max(last[1], current[1])
            else:
                # No overlap, add current interval
                merged.append(current)
        
        return merged


if __name__ == "__main__":
    sol = Solution()
    
    intervals1 = [[1, 3], [2, 6], [8, 10], [15, 18]]
    print("Intervals 1: ")
    for interval in intervals1:
        print(f"[{interval[0]}, {interval[1]}]", end=" ")
    print()
    result1 = sol.merge(intervals1)
    print("Merged: ")
    for interval in result1:
        print(f"[{interval[0]}, {interval[1]}]", end=" ")
    print()
    
    intervals2 = [[1, 4], [4, 5]]
    print("\nIntervals 2: ")
    for interval in intervals2:
        print(f"[{interval[0]}, {interval[1]}]", end=" ")
    print()
    result2 = sol.merge(intervals2)
    print("Merged: ")
    for interval in result2:
        print(f"[{interval[0]}, {interval[1]}]", end=" ")
    print()
