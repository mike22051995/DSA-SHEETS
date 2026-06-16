/*
================================================================================
PROBLEM: Course Schedule II (LeetCode #210)
DIFFICULTY: Medium
PATTERN: Topological Sort / DFS / BFS
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Kahn's Algorithm (BFS)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }
        
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
            
            for (int next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return order.size() == numCourses ? order : vector<int>();
    }
    
    // DFS approach
    vector<int> findOrderDFS(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        for (auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
        }
        
        vector<int> visited(numCourses, 0);  // 0: unvisited, 1: visiting, 2: visited
        vector<int> order;
        
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, graph, visited, order)) {
                return {};
            }
        }
        
        reverse(order.begin(), order.end());
        return order;
    }
    
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited, vector<int>& order) {
        if (visited[course] == 1) return true;   // Cycle detected
        if (visited[course] == 2) return false;  // Already processed
        
        visited[course] = 1;
        
        for (int next : graph[course]) {
            if (dfs(next, graph, visited, order)) {
                return true;
            }
        }
        
        visited[course] = 2;
        order.push_back(course);
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> prereqs = {{1,0},{2,0},{3,1},{3,2}};
    
    vector<int> order = sol.findOrder(4, prereqs);
    
    cout << "Course order: ";
    for (int course : order) {
        cout << course << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Course Schedule (LeetCode #207)
2. Course Schedule III (LeetCode #630)
3. Course Schedule IV (LeetCode #1462)
4. Parallel Courses (LeetCode #1136)
5. Parallel Courses II (LeetCode #1494)
6. Alien Dictionary (LeetCode #269)
7. Sequence Reconstruction (LeetCode #444)
8. Minimum Height Trees (LeetCode #310)
9. Sort Items by Groups (LeetCode #1203)
10. Build Array Where Value Equal to Index (LeetCode #1640)
*/
