"""
PROBLEM: Capacity To Ship Packages Within D Days
Difficulty: Medium
Pattern: Binary Search on Answer

DESCRIPTION:
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship 
with packages on the conveyor belt (in the order given by weights). We may not load more weight 
than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the 
conveyor belt being shipped within days days.

EXPLANATION:
Binary search on ship capacity:
- Min capacity = max(weights) (must carry heaviest package)
- Max capacity = sum(weights) (carry all in one day)
- For each mid capacity, check if can ship in D days
- Find minimum capacity that works

Time Complexity: O(n * log(sum - max))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: Ship with capacity 15: [1,2,3,4,5],[6,7],[8],[9],[10]

Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: Ship with capacity 6: [3,2],[2,4],[1,4]

Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3
"""

from typing import List, Optional


def can_ship(weights, days, capacity):
    current_load = 0
    days_needed = 1
    for w in weights:
        if current_load + w > capacity:
            days_needed += 1
            current_load = 0
        current_load += w
    return days_needed <= days


class Solution:
    def shipWithinDays(self, weights, days):
        left = max(weights)
        right = sum(weights)
        while left < right:
            mid = left + (right - left) // 2
            if can_ship(weights, days, mid):
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == "__main__":
    solution = Solution()
    weights1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    print(f"Test 1: {solution.shipWithinDays(weights1, 5)}")
    weights2 = [3, 2, 2, 4, 1, 4]
    print(f"Test 2: {solution.shipWithinDays(weights2, 3)}")
    weights3 = [1, 2, 3, 1, 1]
    print(f"Test 3: {solution.shipWithinDays(weights3, 4)}")
