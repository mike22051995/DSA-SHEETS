"""
PROBLEM: Minimize Max Distance to Gas Station
Difficulty: Hard
Pattern: Binary Search on Answer (with Precision)

DESCRIPTION:
You are given an integer array stations that represents the positions of gas stations on the 
x-axis. You are also given an integer k.
You should add k new gas stations. You can add the stations anywhere on the x-axis, and you 
do not need to add them on integer coordinates.
Return the minimum possible value of the maximum distance between adjacent gas stations after 
adding the k new stations.

EXPLANATION:
Binary search on the maximum distance:
- Min distance = 0, Max distance = max gap in original stations
- For each distance, calculate stations needed to achieve it
- Find minimum distance that requires <= k stations

Time Complexity: O(n * log(max_gap / precision))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: stations = [1,2,3,4,5,6,7,8,9,10], k = 9
Output: 0.50000
Explanation: Add 1 station between each pair

Example 2:
Input: stations = [23,24,36,39,46,56,57,65,84,98], k = 1
Output: 14.00000
Explanation: Add station between 24 and 36

Example 3:
Input: stations = [1,5,10], k = 1
Output: 4.00000
"""

from typing import List, Optional


def can_achieve(stations, k, max_dist):
    stations_needed = 0
    for i in range(1, len(stations)):
        gap = stations[i] - stations[i - 1]
        stations_needed += int(gap / max_dist)
    return stations_needed <= k


class Solution:
    def minmaxGasDist(self, stations, k):
        left = 0.0
        right = 0.0
        for i in range(1, len(stations)):
            right = max(right, float(stations[i] - stations[i - 1]))
        epsilon = 1e-6
        while right - left > epsilon:
            mid = left + (right - left) / 2.0
            if can_achieve(stations, k, mid):
                right = mid
            else:
                left = mid
        return left


if __name__ == "__main__":
    solution = Solution()
    stations1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    print(f"Test 1: {solution.minmaxGasDist(stations1, 9):.5f}")
    stations2 = [23, 24, 36, 39, 46, 56, 57, 65, 84, 98]
    print(f"Test 2: {solution.minmaxGasDist(stations2, 1):.5f}")
    stations3 = [1, 5, 10]
    print(f"Test 3: {solution.minmaxGasDist(stations3, 1):.5f}")
