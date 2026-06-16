"""
PROBLEM: Course Schedule II (LeetCode 210)
Difficulty: Medium
Pattern: Topological Sort

DESCRIPTION:
Return the ordering of courses you should take to finish all courses.
If impossible, return empty array.

APPROACH:
1. Build adjacency list from prerequisites
2. Use topological sort (Kahn's algorithm)
3. Store the order of processed courses
4. If cycle exists, return empty array

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V + E)
"""

from typing import List
from collections import deque


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for course, prereq in prerequisites:
            adj[prereq].append(course)
            indegree[course] += 1
        q = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
        order = []
        while q:
            course = q.popleft()
            order.append(course)
            for next_course in adj[course]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    q.append(next_course)
        return order if len(order) == numCourses else []


if __name__ == "__main__":
    sol = Solution()
    result1 = sol.findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]])
    print("Course order:", " ".join(map(str, result1)))
    result2 = sol.findOrder(2, [[1, 0], [0, 1]])
    print("Course order (with cycle):", result2)
