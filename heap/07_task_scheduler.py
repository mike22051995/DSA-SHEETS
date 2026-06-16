"""
PROBLEM: Task Scheduler (LeetCode 621)
DIFFICULTY: Medium
PATTERN: Heap - Max-Heap with cooldown queue

DESCRIPTION:
Given tasks (letters) and cooldown n, find minimum intervals to complete all tasks.
Same task must be separated by at least n intervals.

EXAMPLE:
Input: tasks=[A,A,A,B,B,B], n=2 -> Output: 8
Input: tasks=[A,A,A,B,B,B], n=0 -> Output: 6
Input: tasks=[A,A,A,A,B,C,D,E], n=2 -> Output: 10

TIME COMPLEXITY: O(T log T) where T = number of tasks
SPACE COMPLEXITY: O(1) (at most 26 distinct tasks)
"""

import heapq
from collections import Counter, deque
from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = Counter(tasks)
        max_heap = [-cnt for cnt in freq.values()]
        heapq.heapify(max_heap)

        time = 0
        # Queue of (remaining_count, available_at_time)
        cooldown: deque = deque()

        while max_heap or cooldown:
            time += 1
            if max_heap:
                cnt = 1 + heapq.heappop(max_heap)  # reduce count (negated)
                if cnt < 0:
                    cooldown.append((cnt, time + n))
            if cooldown and cooldown[0][1] == time:
                heapq.heappush(max_heap, cooldown.popleft()[0])

        return time

    def leastIntervalMath(self, tasks: List[str], n: int) -> int:
        freq = Counter(tasks)
        max_freq = max(freq.values())
        tasks_with_max = sum(1 for v in freq.values() if v == max_freq)
        return max(len(tasks), (max_freq - 1) * (n + 1) + tasks_with_max)


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        (["A", "A", "A", "B", "B", "B"], 2),
        (["A", "A", "A", "B", "B", "B"], 0),
        (["A", "A", "A", "A", "B", "C", "D", "E"], 2),
    ]
    for tasks, n in test_cases:
        print(f"tasks={tasks}, n={n} -> {sol.leastInterval(tasks, n)}")
