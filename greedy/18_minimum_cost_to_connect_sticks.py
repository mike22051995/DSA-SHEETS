"""
PROBLEM: Minimum Cost to Connect Sticks (LeetCode 1167)
DIFFICULTY: Medium
PATTERN: Greedy Huffman Coding / Merge Smallest First

DESCRIPTION:
You have some sticks with positive integer lengths. You can connect any two sticks of 
lengths X and Y into one stick by paying a cost of X + Y. Perform this until one stick 
remains. Return the minimum cost of connecting all sticks.

INPUT:
- sticks: array of positive integers

OUTPUT:
- Minimum cost to connect all sticks

APPROACH:
1. Use a min heap (priority queue)
2. Always connect two smallest sticks
3. Add the combined stick back to heap
4. Continue until one stick remains

WHY GREEDY WORKS:
Smaller sticks should be combined first because they'll be counted multiple times.
This is similar to Huffman encoding - minimize weighted path length.
"""

from typing import List, Optional

class Solution:
    def connectSticks(self, sticks):
        # Min heap to always get two smallest sticks
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end())
        totalCost = 0
        # Keep combining until one stick remains
        while (len(minHeap) > 1):
        # Take two smallest sticks
        first = minHeap.top()
        minHeap.pop()
        second = minHeap.top()
        minHeap.pop()
        # Cost to combine them
        cost = first + second
        totalCost += cost
        # Put combined stick back
        minHeap.push(cost)
        return totalCost


if __name__ == "__main__":
    sol = Solution()
    sticks1 = [2, 4, 3]
    print(f"Test 1 - Sticks: [2,4,3]")
    print(f"Output: {sol.connectSticks(sticks1)}")
    print(f"Expected: 14 (connect 2+3=5 cost 5, then 5+4=9 cost 9, total 14)")
    sticks2 = [1, 8, 3, 5]
    print(f"Test 2 - Sticks: [1,8,3,5]")
    print(f"Output: {sol.connectSticks(sticks2)}")
    print(f"Expected: 30")
    sticks3 = [5]
    print(f"Test 3 - Sticks: [5]")
    print(f"Output: {sol.connectSticks(sticks3)}")
    print(f"Expected: 0 (only one stick)")
