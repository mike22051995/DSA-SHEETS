"""
PROBLEM: Can Place Flowers (LeetCode 605)
DIFFICULTY: Easy
PATTERN: Greedy Placement with Local Constraints

DESCRIPTION:
You have a long flowerbed in which some plots are planted and some are not. However, 
flowers cannot be planted in adjacent plots. Given an integer array flowerbed containing 
0's and 1's (0 means empty, 1 means planted) and an integer n, return True if n new flowers 
can be planted without violating the no-adjacent-flowers rule.

INPUT:
- flowerbed: array of 0s and 1s
- n: number of flowers to plant

OUTPUT:
- True if n flowers can be planted, False otherwise

APPROACH:
1. Iterate through the flowerbed
2. At each position, check if we can plant (current empty, left empty, right empty)
3. Greedily plant as soon as we find a valid spot
4. Check if we planted at least n flowers

WHY GREEDY WORKS:
Planting a flower at the earliest valid position never makes it worse for future placements.
It either has no effect or creates more opportunities.
"""

from typing import List, Optional

class Solution:
    def canPlaceFlowers(self, flowerbed, n):
        count = 0
        size = len(flowerbed)
        for i in range(size):
        # Check if current position is empty
        if flowerbed[i] == 0:
        # Check left neighbor (empty or out of bounds)
        leftEmpty = (i == 0) or (flowerbed[i-1] == 0)
        # Check right neighbor (empty or out of bounds)
        rightEmpty = (i == size-1) or (flowerbed[i+1] == 0)
        # If both neighbors are empty (or don't exist), plant here
        if leftEmpty and rightEmpty:
        flowerbed[i] = 1;  # Plant the flower
        count += 1
        # Early exit optimization
        if count >= n:
        return True
        return count >= n


if __name__ == "__main__":
    sol = Solution()
    flowerbed1 = [1, 0, 0, 0, 1]
    print(f"Test 1 - Flowerbed: [1,0,0,0,1], n=1")
    print(f"Output: {(sol.canPlaceFlowers(flowerbed1,}")
    print(f"Expected: True")
    flowerbed2 = [1, 0, 0, 0, 1]
    print(f"Test 2 - Flowerbed: [1,0,0,0,1], n=2")
    print(f"Output: {(sol.canPlaceFlowers(flowerbed2,}")
    print(f"Expected: False")
    flowerbed3 = [0, 0, 1, 0, 0]
    print(f"Test 3 - Flowerbed: [0,0,1,0,0], n=1")
    print(f"Output: {(sol.canPlaceFlowers(flowerbed3,}")
    print(f"Expected: True")
    flowerbed4 = [0, 0, 0, 0, 0]
    print(f"Test 4 - Flowerbed: [0,0,0,0,0], n=3")
    print(f"Output: {(sol.canPlaceFlowers(flowerbed4,}")
    print(f"Expected: True")
