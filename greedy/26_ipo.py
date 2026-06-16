"""
PROBLEM: IPO (LeetCode 502)
DIFFICULTY: Hard
PATTERN: Greedy with Two Heaps

DESCRIPTION:
You are given n projects where the ith project has a pure profit profits[i] and a minimum 
capital of capital[i] is needed to start it. Initially, you have w capital. When you finish 
a project, you will obtain its pure profit and the profit will be added to your total capital.
Pick a list of at most k distinct projects from given projects to maximize your final capital.

INPUT:
- k: maximum projects to complete
- w: initial capital
- profits: profit for each project
- capital: capital needed for each project

OUTPUT:
- Maximum capital after completing at most k projects

APPROACH:
1. Store all projects sorted by capital (min heap)
2. Use max heap for available projects (by profit)
3. At each step, add all affordable projects to max heap
4. Pick highest profit project
5. Repeat k times

WHY GREEDY WORKS:
Always picking the most profitable affordable project maximizes capital growth,
which enables more projects in future iterations.
"""

from typing import List, Optional

class Solution:
    def findMaximizedCapital(self, k, w, profits, capital):
        n = len(profits)
        # Min heap of projects by capital requirement
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapital
        for i in range(n):
        minCapital.push({capital[i], profits[i]})
        # Max heap of profits for affordable projects
        priority_queue<int> maxProfit
        for i in range(k):
        # Add all projects we can now afford to max heap
        while (!not minCapital and minCapital.top().first <= w):
        maxProfit.push(minCapital.top().second)
        minCapital.pop()
        # If no affordable projects, break
        if not maxProfit:
        break
        # Pick most profitable project
        w += maxProfit.top()
        maxProfit.pop()
        return w


if __name__ == "__main__":
    sol = Solution()
    profits1 = [1, 2, 3]
    capital1 = [0, 1, 1]
    print(f"Test 1 - k=2, w=0, profits=[1,2,3], capital=[0,1,1]")
    print(f"Output: {sol.findMaximizedCapital(2,}")
    print(f"Expected: 4 (do project 0: w=1, then project 2: w=4)")
    profits2 = [1, 2, 3]
    capital2 = [0, 1, 2]
    print(f"Test 2 - k=3, w=0, profits=[1,2,3], capital=[0,1,2]")
    print(f"Output: {sol.findMaximizedCapital(3,}")
    print(f"Expected: 6")
    profits3 = [1, 2, 3]
    capital3 = [1, 1, 2]
    print(f"Test 3 - k=1, w=0, profits=[1,2,3], capital=[1,1,2]")
    print(f"Output: {sol.findMaximizedCapital(1,}")
    print(f"Expected: 0 (can't afford any project)")
