"""
PROBLEM: Painter's Partition Problem
Difficulty: Hard
Pattern: Binary Search on Answer

DESCRIPTION:
Given an array of N boards, where the ith board has length boards[i]. Some K painters are 
available to paint these boards. Each painter takes 1 unit time to paint 1 unit of the board.
The task is to find the minimum time to paint all boards under the constraints that any painter 
will only paint contiguous sections of boards, and all painters work simultaneously.

EXPLANATION:
Binary search on maximum time:
- Min time = max(boards) (one painter must paint longest board)
- Max time = sum(boards) (one painter paints all)
- For each time, check if K painters can finish
- Find minimum time that works

Time Complexity: O(n * log(sum))
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: boards = [10,20,30,40], painters = 2
Output: 60
Explanation: Painter 1: [10,20,30], Painter 2: [40]

Example 2:
Input: boards = [10,10,10,10], painters = 2
Output: 20
Explanation: Each painter paints 2 boards

Example 3:
Input: boards = [5,10,30,20,15], painters = 3
Output: 35
"""

from typing import List, Optional


def can_paint(boards, painters, max_time):
    count = 1
    current = 0
    for b in boards:
        if current + b > max_time:
            count += 1
            current = 0
        current += b
    return count <= painters


class Solution:
    def paintersPartition(self, boards, painters):
        left = max(boards)
        right = sum(boards)
        while left < right:
            mid = left + (right - left) // 2
            if can_paint(boards, painters, mid):
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == "__main__":
    solution = Solution()
    boards1 = [10, 20, 30, 40]
    print(f"Test 1: {solution.paintersPartition(boards1, 2)}")
    boards2 = [10, 10, 10, 10]
    print(f"Test 2: {solution.paintersPartition(boards2, 2)}")
    boards3 = [5, 10, 30, 20, 15]
    print(f"Test 3: {solution.paintersPartition(boards3, 3)}")
