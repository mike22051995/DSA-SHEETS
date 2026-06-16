"""
PROBLEM: Boats to Save People
---------------------------------------------------------------------------
You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight 
of limit. Each boat carries at most two people at the same time, provided 
the sum of their weights is at most limit. Return the minimum number of 
boats to carry every given person.

PATTERN: Sorting + Opposite Direction Two Pointers (Greedy)
TIME COMPLEXITY: O(n log n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat carries both people (1 + 2).

Example 2:
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats: (1,2), (2), (3)
"""

from typing import List


class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        left = 0
        right = len(people) - 1
        boats = 0
        while left <= right:
            # Try to pair heaviest with lightest
            if people[left] + people[right] <= limit:
                left += 1  # Both can fit in one boat
            right -= 1     # Heaviest person takes a boat
            boats += 1
        return boats


if __name__ == "__main__":
    sol = Solution()
    people1 = [1, 2]
    limit1 = 3
    print(f"Test 1: {sol.numRescueBoats(people1, limit1)}")
    people2 = [3, 2, 2, 1]
    limit2 = 3
    print(f"Test 2: {sol.numRescueBoats(people2, limit2)}")
