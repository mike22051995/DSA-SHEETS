/*
PROBLEM: Course Schedule (LeetCode 207)
Difficulty: Medium
Pattern: Cycle Detection in Directed Graph / Topological Sort

DESCRIPTION:
There are numCourses courses labeled from 0 to numCourses-1.
Given prerequisites where prerequisites[i] = [ai, bi] indicates you must take course bi
before course ai. Return true if you can finish all courses.

GRAPH DIAGRAM:
  Valid Schedule:              Invalid (has cycle):
      1 → 0                         1 → 0
      ↓                             ↑   ↓
      2 → 3                         3 ← 2
  
  prereq: [[0,1],[2,1],[3,2]]  prereq: [[0,1],[1,2],[2,0]]
  Can finish: YES              Can finish: NO (cycle!)
  Order: 1→0, 1→2→3           Cycle: 0→1→2→0
  
  Use topological sort - if cycle exists, can't finish

APPROACH:
1. Build adjacency list from prerequisites
2. Use topological sort (Kahn's algorithm)
3. If we can process all courses, return true
4. If cycle exists (can't process all), return false

TIME COMPLEXITY: O(V + E) where V = courses, E = prerequisites
SPACE COMPLEXITY: O(V + E) for adjacency list
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build graph
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Add all courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int processedCourses = 0;
        
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            processedCourses++;
            
            for (int nextCourse : adj[course]) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // If all courses processed, no cycle
        return processedCourses == numCourses;
    }
};

int main() {
    Solution sol;
    
    // Example 1: Can finish
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Can finish courses (Example 1): " 
         << (sol.canFinish(numCourses1, prerequisites1) ? "Yes" : "No") << endl;
    
    // Example 2: Cannot finish (cycle)
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Can finish courses (Example 2): " 
         << (sol.canFinish(numCourses2, prerequisites2) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
INPUT 1:
numCourses = 2
prerequisites = [[1,0]]

OUTPUT:
Can finish courses: Yes

EXPLANATION:
To take course 1, you must first take course 0.
No cycle exists, so you can complete all courses.

INPUT 2:
numCourses = 2
prerequisites = [[1,0],[0,1]]

OUTPUT:
Can finish courses: No

EXPLANATION:
To take course 1, you need course 0.
To take course 0, you need course 1.
This creates a cycle, making it impossible.
*/
