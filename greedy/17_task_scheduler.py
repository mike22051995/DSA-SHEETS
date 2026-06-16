"""
PROBLEM: Task Scheduler (LeetCode 621)
DIFFICULTY: Medium
PATTERN: Greedy Scheduling with Cooling Period

DESCRIPTION:
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter 
represents a different task. Tasks could be done in any order. Each task is done in one unit 
of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two 
same tasks (the same letter), meaning there must be at least n units of time between any two 
same tasks. Return the least number of units of time that the CPU will take to finish all tasks.

INPUT:
- tasks: array of characters representing tasks
- n: cooling period between same tasks

OUTPUT:
- Minimum time units to complete all tasks

APPROACH:
1. Count frequency of each task
2. Most frequent task determines minimum time
3. Formula: (maxFreq - 1) * (n + 1) + numberOfTasksWithMaxFreq
4. But answer can't be less than total tasks

WHY GREEDY WORKS:
Schedule most frequent task first with maximum spacing. Other tasks fill the gaps.
If gaps aren't enough, we can append tasks at the end.
"""

from typing import List, Optional

class Solution:
    def leastInterval(self, tasks, n):
        # Count frequency of each task
        freq
        maxFreq = 0
        for task in tasks:
        freq[task]++
        maxFreq = max(maxFreq, freq[task])
        # Count how many tasks have maximum frequency
        maxFreqCount = 0
        for (auto& p : freq):
        if p.second == maxFreq:
        maxFreqCount += 1
        # Calculate minimum time
        # (maxFreq - 1) chunks, each of size (n + 1), plus final tasks
        minTime = (maxFreq - 1) * (n + 1) + maxFreqCount
        # If we have enough variety of tasks, we don't need idle time
        return max(minTime, (int)len(tasks))


if __name__ == "__main__":
    sol = Solution()
    tasks1 = ['A', 'A', 'A', 'B', 'B', 'B']
    print(f"Test 1 - Tasks: ['A','A','A','B','B','B'], n=2")
    print(f"Output: {sol.leastInterval(tasks1,}")
    print(f"Expected: 8 (A.B.idle.A.B.idle.A.B)")
    tasks2 = ['A', 'A', 'A', 'B', 'B', 'B']
    print(f"Test 2 - Tasks: ['A','A','A','B','B','B'], n=0")
    print(f"Output: {sol.leastInterval(tasks2,}")
    print(f"Expected: 6 (no cooling needed)")
    tasks3 = ['A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G']
    print(f"Test 3 - Tasks: ['A'*6,'B','C','D','E','F','G'], n=2")
    print(f"Output: {sol.leastInterval(tasks3,}")
    print(f"Expected: 16")
