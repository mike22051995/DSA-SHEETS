"""
PROBLEM: Minimum Number of Refueling Stops (LeetCode 871)
DIFFICULTY: Hard
PATTERN: Heap - Max-Heap greedy (refuel retroactively from best passed station)

DESCRIPTION:
Travel to target distance with startFuel and stations at given positions.
Return minimum refueling stops, or -1 if impossible.

EXAMPLE:
Input: target=100, startFuel=10, stations=[[10,60],[20,30],[30,30],[60,40]] -> 2
Input: target=100, startFuel=1, stations=[[10,100]] -> -1
Input: target=100, startFuel=100, stations=[] -> 0

TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(n)
"""

import heapq
from typing import List


class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        max_heap: List[int] = []  # available fuels from passed stations (negated)
        fuel = startFuel
        idx = 0
        stops = 0
        n = len(stations)

        while fuel < target:
            # Add all reachable stations to heap
            while idx < n and stations[idx][0] <= fuel:
                heapq.heappush(max_heap, -stations[idx][1])
                idx += 1
            if not max_heap:
                return -1
            # Greedily take the largest available fuel
            fuel += -heapq.heappop(max_heap)
            stops += 1

        return stops


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        (100, 10, [[10, 60], [20, 30], [30, 30], [60, 40]]),
        (100, 1, [[10, 100]]),
        (100, 100, []),
    ]
    for target, start_fuel, stations in test_cases:
        print(f"target={target}, startFuel={start_fuel} -> "
              f"{sol.minRefuelStops(target, start_fuel, stations)}")
