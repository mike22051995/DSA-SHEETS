"""
PROBLEM: Boats to Save People (LeetCode 881)
DIFFICULTY: Medium
PATTERN: Two Pointer Greedy Pairing

DESCRIPTION:
You are given an array people where people[i] is the weight of the ith person, and an 
infinite number of boats where each boat can carry a maximum weight of limit. Each boat 
carries at most two people at the same time, provided the sum of the weight of those 
people is at most limit. Return the minimum number of boats to carry every given person.

INPUT:
- people: array of person weights
- limit: maximum weight per boat

OUTPUT:
- Minimum number of boats needed

APPROACH:
1. Sort people by weight
2. Use two pointers: lightest and heaviest
3. Try to pair lightest with heaviest
4. If they fit together, move both pointers
5. If not, heaviest goes alone

WHY GREEDY WORKS:
Pairing lightest with heaviest maximizes boat utilization. If heaviest can't 
pair with lightest, it can't pair with anyone.
"""

from typing import List, Optional

class Solution:
    def numRescueBoats(self, people, limit):
        sort(people.begin(), people.end())
        left = 0
        right = len(people) - 1
        boats = 0
        while left <= right:
        # Check if lightest and heaviest can share a boat
        if people[left] + people[right] <= limit:
        left++;   # Lightest person gets on boat
        right--;  # Heaviest person gets on boat
        } else 
        right--;  # Only heaviest person gets on boat
        boats++;  # One boat used either way
        return boats


if __name__ == "__main__":
    sol = Solution()
    people1 = [1, 2]
    print(f"Test 1 - People: [1,2], Limit: 3")
    print(f"Output: {sol.numRescueBoats(people1,}")
    print(f"Expected: 1")
    people2 = [3, 2, 2, 1]
    print(f"Test 2 - People: [3,2,2,1], Limit: 3")
    print(f"Output: {sol.numRescueBoats(people2,}")
    print(f"Expected: 3")
    people3 = [3, 5, 3, 4]
    print(f"Test 3 - People: [3,5,3,4], Limit: 5")
    print(f"Output: {sol.numRescueBoats(people3,}")
    print(f"Expected: 4")
    people4 = [5, 1, 4, 2]
    print(f"Test 4 - People: [5,1,4,2], Limit: 6")
    print(f"Output: {sol.numRescueBoats(people4,}")
    print(f"Expected: 2")
