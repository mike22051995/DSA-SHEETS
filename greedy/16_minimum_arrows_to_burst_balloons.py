"""
PROBLEM: Minimum Number of Arrows to Burst Balloons (LeetCode 452)
DIFFICULTY: Medium
PATTERN: Interval Overlap Detection / Greedy Shooting

DESCRIPTION:
There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] 
denotes a balloon whose horizontal diameter stretches between xstart and xend.
An arrow can be shot up exactly vertically from any point along the x-axis. A balloon with 
xstart and xend is burst by an arrow shot at x if xstart ≤ x ≤ xend. Return the minimum 
number of arrows that must be shot to burst all balloons.

INPUT:
- points: array of [xstart, xend] representing balloons

OUTPUT:
- Minimum number of arrows needed

APPROACH:
1. Sort balloons by end position
2. Shoot arrow at first balloon's end
3. This arrow bursts all overlapping balloons
4. When we find non-overlapping balloon, shoot new arrow

WHY GREEDY WORKS:
Shooting at the end of earliest-ending balloon maximizes the number of balloons 
burst by that arrow.
"""

from typing import List, Optional

class Solution:
    def findMinArrowShots(self, points):
        if (not points) return 0
        # Sort by end position
        sort(points.begin(), points.end(),
        [](const vector<int>& a, const vector<int>& b):
        return a[1] < b[1]
        })
        arrows = 1
        arrowPos = points[0][1];  # Shoot at first balloon's end
        for i in range(1, len(points)):
        # If current balloon starts after arrow position, need new arrow
        if points[i][0] > arrowPos:
        arrows += 1
        arrowPos = points[i][1];  # Shoot at new balloon's end
        # Otherwise, current arrow bursts this balloon too
        return arrows


if __name__ == "__main__":
    sol = Solution()
    vector<vector<int>> points1 = [{10, 16], [2, 8], [1, 6], [7, 12]}
    print(f"Test 1 - Balloons: [[10,16],[2,8],[1,6],[7,12]]")
    print(f"Output: {sol.findMinArrowShots(points1)}")
    print(f"Expected: 2 (arrows at x=6 and x=11)")
    vector<vector<int>> points2 = [{1, 2], [3, 4], [5, 6], [7, 8]}
    print(f"Test 2 - Balloons: [[1,2],[3,4],[5,6],[7,8]]")
    print(f"Output: {sol.findMinArrowShots(points2)}")
    print(f"Expected: 4 (no overlaps)")
    vector<vector<int>> points3 = [{1, 2], [2, 3], [3, 4], [4, 5]}
    print(f"Test 3 - Balloons: [[1,2],[2,3],[3,4],[4,5]]")
    print(f"Output: {sol.findMinArrowShots(points3)}")
    print(f"Expected: 2")
