/*
================================================================================
PROBLEM: Course Schedule (LeetCode #207)
DIFFICULTY: Medium
PATTERN: Topological Sort / DFS / Cycle Detection
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
There are a total of numCourses courses you have to take, labeled from 0 to 
numCourses - 1. You are given an array prerequisites where prerequisites[i] = 
[ai, bi] indicates that you must take course bi first if you want to take course ai.

Return true if you can finish all courses. Otherwise, return false.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Dependency graph problems
2. Detect cycles in directed graph
3. Topological sort needed
4. Course prerequisites, task scheduling

Key Indicators:
- "Prerequisites" or "dependencies"
- "Can finish all" or "valid order"
- Directed acyclic graph (DAG)
- Cycle detection required

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: Take course 0, then course 1

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: Cycle exists

Example 3:
Input: numCourses = 3, prerequisites = [[1,0],[2,1]]
Output: true

================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // DFS Cycle Detection
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        // Build adjacency list
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        
        vector<int> visited(numCourses, 0); // 0: unvisited, 1: visiting, 2: visited
        
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(graph, visited, i)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool hasCycle(vector<vector<int>>& graph, vector<int>& visited, int course) {
        if (visited[course] == 1) return true;  // Cycle detected
        if (visited[course] == 2) return false; // Already processed
        
        visited[course] = 1; // Mark as visiting
        
        for (int next : graph[course]) {
            if (hasCycle(graph, visited, next)) {
                return true;
            }
        }
        
        visited[course] = 2; // Mark as visited
        return false;
    }
    
    // BFS Kahn's Algorithm
    bool canFinishBFS(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            
            for (int next : graph[course]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return count == numCourses;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> prereq1 = {{1,0}};
    cout << "Can finish (test 1): " << (sol.canFinish(2, prereq1) ? "true" : "false") << endl;
    
    vector<vector<int>> prereq2 = {{1,0},{0,1}};
    cout << "Can finish (test 2): " << (sol.canFinish(2, prereq2) ? "true" : "false") << endl;
    
    return 0;
}

/*
================================================================================
SIMILAR PROBLEMS:
1. Course Schedule II (LeetCode #210) - Return the order
2. Course Schedule III (LeetCode #630) - Maximum courses
3. Course Schedule IV (LeetCode #1462) - Queries on prerequisites
4. Parallel Courses (LeetCode #1136)
5. Sequence Reconstruction (LeetCode #444)
6. Alien Dictionary (LeetCode #269)
7. Minimum Height Trees (LeetCode #310)
8. Find Eventual Safe States (LeetCode #802)
9. All Ancestors of a Node (LeetCode #2192)
10. Sort Items by Groups (LeetCode #1203)
================================================================================
*/
