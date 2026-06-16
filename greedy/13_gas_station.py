"""
PROBLEM: Gas Station (LeetCode 134)
DIFFICULTY: Medium
PATTERN: Circular Array Greedy with Running Sum

DESCRIPTION:
There are n gas stations along a circular route. You have a car with unlimited gas tank capacity.
It costs cost[i] to travel from station i to next station (i+1). You begin with an empty tank at 
one of the stations. Given gas and cost arrays, return the starting station's index if you can 
travel around the circuit once, otherwise return -1. Solution is guaranteed to be unique.

INPUT:
- gas: array where gas[i] is gas available at station i
- cost: array where cost[i] is gas needed to reach next station

OUTPUT:
- Starting station index, or -1 if impossible

APPROACH:
1. If total gas < total cost, impossible
2. Track running tank: at each station, tank += gas[i] - cost[i]
3. If tank goes negative, all stations from start to current can't be starting point
4. Reset start to next station and reset tank

WHY GREEDY WORKS:
If we can't reach station j from station i, then any station between i and j 
also can't reach j. So we can safely skip all of them.
"""

from typing import List, Optional

class Solution:
    def canCompleteCircuit(self, gas, cost):
        totalGas = 0
        totalCost = 0
        tank = 0
        start = 0
        for i in range(len(gas)):
        totalGas += gas[i]
        totalCost += cost[i]
        tank += gas[i] - cost[i]
        # If tank is negative, can't start from any station up to i
        if tank < 0:
        start = i + 1;  # Try starting from next station
        tank = 0;       # Reset tank
        # If total gas < total cost, impossible to complete circuit
        return (totalGas >= totalCost) ? start : -1


if __name__ == "__main__":
    sol = Solution()
    gas1 = [1, 2, 3, 4, 5]
    cost1 = [3, 4, 5, 1, 2]
    print(f"Test 1 - Gas: [1,2,3,4,5], Cost: [3,4,5,1,2]")
    print(f"Output: {sol.canCompleteCircuit(gas1,}")
    print(f"Expected: 3")
    gas2 = [2, 3, 4]
    cost2 = [3, 4, 3]
    print(f"Test 2 - Gas: [2,3,4], Cost: [3,4,3]")
    print(f"Output: {sol.canCompleteCircuit(gas2,}")
    print(f"Expected: -1")
    gas3 = [5, 1, 2, 3, 4]
    cost3 = [4, 4, 1, 5, 1]
    print(f"Test 3 - Gas: [5,1,2,3,4], Cost: [4,4,1,5,1]")
    print(f"Output: {sol.canCompleteCircuit(gas3,}")
    print(f"Expected: 4")
