/*
PROBLEM: Course Schedule II (LeetCode 210)
Difficulty: Medium
Pattern: Topological Sort

DESCRIPTION:
Return the ordering of courses you should take to finish all courses.
If impossible, return empty array.

GRAPH DIAGRAM:
  Example: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
  
      0 → 1 → 3
      ↓     ↑
      2 → →↑
  
  Dependencies:
  - Course 1 needs Course 0
  - Course 2 needs Course 0  
  - Course 3 needs Courses 1 and 2
  
  Valid Order: [0, 1, 2, 3] or [0, 2, 1, 3]
  (Take 0 first, then 1 and 2, finally 3)

APPROACH:
1. Build adjacency list from prerequisites
2. Use topological sort (Kahn's algorithm)
3. Store the order of processed courses
4. If cycle exists, return empty array

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V + E)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        
        vector<int> order;
        
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            
            for (int nextCourse : adj[course]) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // If not all courses processed, cycle exists
        if (order.size() != numCourses) {
            return {};
        }
        
        return order;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> result1 = sol.findOrder(numCourses1, prerequisites1);
    
    cout << "Course order: ";
    for (int course : result1) {
        cout << course << " ";
    }
    cout << endl;
    
    // Example 2: Cycle
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1,0},{0,1}};
    vector<int> result2 = sol.findOrder(numCourses2, prerequisites2);
    
    cout << "Course order (with cycle): ";
    if (result2.empty()) {
        cout << "[]" << endl;
    }
    
    return 0;
}

/*
INPUT:
numCourses = 4
prerequisites = [[1,0],[2,0],[3,1],[3,2]]

OUTPUT:
Course order: 0 1 2 3 (or 0 2 1 3)

EXPLANATION:
- Take course 0 first (no prerequisites)
- Then take courses 1 and 2 (both need 0)
- Finally take course 3 (needs both 1 and 2)
*/
