/*
PROBLEM: Is Graph Bipartite? (LeetCode 785)
Difficulty: Medium
Pattern: BFS/DFS with Coloring

DESCRIPTION:
A graph is bipartite if we can divide its vertices into two independent sets such that
every edge connects a vertex from one set to the other.
Check if the given graph is bipartite.

GRAPH DIAGRAM:
  Bipartite Graph:             Not Bipartite (Triangle):
      0 ---- 1                     0
      |      |                    / \
      |      |                   /   \
      3 ---- 2                  1-----2

  Set A: {0, 2}                Can't 2-color a triangle!
  Set B: {1, 3}                All 3 nodes are connected
  All edges go between sets    (Odd cycle = not bipartite)

  Use 2-coloring: Color 0/1
  Adjacent nodes must have different colors

APPROACH:
1. Try to color the graph using 2 colors (0 and 1)
2. Use BFS/DFS to traverse and color nodes
3. If any adjacent nodes have the same color, it's not bipartite
4. Check all components for disconnected graphs

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for color array and queue
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool bfsCheck(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                // If not colored, color with opposite color
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                }
                // If same color as current node, not bipartite
                else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 means not colored
        
        // Check all components
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!bfsCheck(i, graph, color)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    // Example 1: Bipartite graph
    vector<vector<int>> graph1 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << "Graph 1 is bipartite: " << (sol.isBipartite(graph1) ? "Yes" : "No") << endl;
    
    // Example 2: Not bipartite (triangle)
    vector<vector<int>> graph2 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << "Graph 2 is bipartite: " << (sol.isBipartite(graph2) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
INPUT 1:
graph = [[1,3],[0,2],[1,3],[0,2]]

OUTPUT:
Graph 1 is bipartite: Yes

EXPLANATION:
We can divide vertices into two sets: {0, 2} and {1, 3}
0--1, 0--3, 2--1, 2--3 (all edges go between sets)

INPUT 2:
graph = [[1,2,3],[0,2],[0,1,3],[0,2]]

OUTPUT:
Graph 2 is bipartite: No

EXPLANATION:
Contains a triangle (0-1-2), which cannot be colored with 2 colors.
*/
