"""
PROBLEM: Minimum Cost to Move Chips to The Same Position (LeetCode 1217)
DIFFICULTY: Easy
PATTERN: Parity-Based Greedy

DESCRIPTION:
We have n chips, where the position of the ith chip is position[i]. We need to move all 
the chips to the same position. In one step, we can:
- Move a chip at position[i] to position[i+2] or position[i-2] with cost = 0
- Move a chip at position[i] to position[i+1] or position[i-1] with cost = 1

Return the minimum cost to move all the chips to the same position.

INPUT:
- position: array of chip positions

OUTPUT:
- Minimum cost to gather all chips

APPROACH:
Key insight: Moving by 2 is free, moving by 1 costs 1
- All chips at even positions can be gathered at position 0 with 0 cost
- All chips at odd positions can be gathered at position 1 with 0 cost
- Moving from 0 to 1 (or vice versa) costs 1 per chip
- Greedy: Move the smaller group to the larger group

WHY GREEDY WORKS:
Since we can move even→even and odd→odd for free, we only need to count parity.
Moving the minority to majority minimizes cost.
"""

from typing import List, Optional

class Solution:
    def minCostToMoveChips(self, position):
        evenCount = 0
        oddCount = 0
        # Count chips at even and odd positions
        for pos in position:
        if pos % 2 == 0:
        evenCount += 1
        } else 
        oddCount += 1
        # Move the smaller group to the larger group
        return min(evenCount, oddCount)


if __name__ == "__main__":
    sol = Solution()
    position1 = [1, 2, 3]
    print(f"Test 1 - Positions: [1,2,3]")
    print(f"Output: {sol.minCostToMoveChips(position1)}")
    print(f"Expected: 1 (Move chip at position 1 to 2, cost 1)")
    position2 = [2, 2, 2, 3, 3]
    print(f"Test 2 - Positions: [2,2,2,3,3]")
    print(f"Output: {sol.minCostToMoveChips(position2)}")
    print(f"Expected: 2 (Move 2 chips from odd positions)")
    position3 = [1, 1000000000]
    print(f"Test 3 - Positions: [1,1000000000]")
    print(f"Output: {sol.minCostToMoveChips(position3)}")
    print(f"Expected: 1")
