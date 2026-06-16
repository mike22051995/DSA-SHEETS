"""
PROBLEM: Magnetic Force Between Two Balls
Difficulty: Medium
Pattern: Binary Search on Answer

DESCRIPTION:
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls 
if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at 
position[i], Morty has m balls and needs to distribute the balls into the baskets such that 
the minimum magnetic force between any two balls is maximum.
Return the largest minimum magnetic force.

EXPLANATION:
Binary search on minimum distance:
- Sort positions first
- Min distance = 1, Max distance = (max - min) / (m - 1)
- For each distance, check if we can place m balls
- Find maximum distance that works

Time Complexity: O(n log n + n * log(max - min))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Place balls at positions 1, 4, and 7

Example 2:
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: Place balls at positions 1 and 1000000000

Example 3:
Input: position = [1,2,8,4,9], m = 3
Output: 3
"""

from typing import List, Optional


def can_place_balls(position, m, min_dist):
    count = 1
    last = position[0]
    for i in range(1, len(position)):
        if position[i] - last >= min_dist:
            count += 1
            last = position[i]
            if count == m:
                return True
    return False


class Solution:
    def maxDistance(self, position, m):
        position.sort()
        left = 1
        right = position[-1] - position[0]
        result = 0
        while left <= right:
            mid = left + (right - left) // 2
            if can_place_balls(position, m, mid):
                result = mid
                left = mid + 1
            else:
                right = mid - 1
        return result


if __name__ == "__main__":
    solution = Solution()
    position1 = [1, 2, 3, 4, 7]
    print(f"Test 1: {solution.maxDistance(position1, 3)}")
    position2 = [5, 4, 3, 2, 1, 1000000000]
    print(f"Test 2: {solution.maxDistance(position2, 2)}")
    position3 = [1, 2, 8, 4, 9]
    print(f"Test 3: {solution.maxDistance(position3, 3)}")
