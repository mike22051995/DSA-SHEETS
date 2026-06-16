"""
PROBLEM: Course Schedule (LeetCode 207)
Difficulty: Medium
Pattern: Cycle Detection in Directed Graph / Topological Sort

DESCRIPTION:
There are numCourses courses labeled from 0 to numCourses-1.
Given prerequisites where prerequisites[i] = [ai, bi] indicates you must take course bi
before course ai. Return True if you can finish all courses.

APPROACH:
1. Build adjacency list from prerequisites
2. Use topological sort (Kahn's algorithm)
3. If we can process all courses, return True
4. If cycle exists (can't process all), return False

TIME COMPLEXITY: O(V + E) where V = courses, E = prerequisites
SPACE COMPLEXITY: O(V + E) for adjacency list
"""

from typing import List
from collections import deque


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        # Build graph
        for course, prereq in prerequisites:
            adj[prereq].append(course)
            indegree[course] += 1
        # Add all courses with no prerequisites
        q = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
        processed = 0
        while q:
            course = q.popleft()
            processed += 1
            for next_course in adj[course]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    q.append(next_course)
        # If all courses processed, no cycle
        return processed == numCourses


if __name__ == "__main__":
    sol = Solution()
    print(f"Can finish courses (Example 1): {sol.canFinish(2, [[1, 0]])}")
    print(f"Can finish courses (Example 2): {sol.canFinish(2, [[1, 0], [0, 1]])}")
