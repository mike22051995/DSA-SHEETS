/*
PROBLEM: Detect Cycle in Undirected Graph
Difficulty: Easy-Medium
Pattern: DFS with Parent Tracking

DESCRIPTION:
Given an undirected graph, detect if it contains any cycle.

GRAPH DIAGRAM:
  Example with Cycle:         Example without Cycle (Tree):
      0---1                       0---1
          |\                          |
          | \                         2
          2  4                        |
          | /                          3
          |/
          3

  Cycle: 1-2-3-4-1              No cycle: Just a linear path
  (An edge back to visited     (Tree structure with no back edges)
   non-parent node)

APPROACH:
1. Use DFS traversal
2. Keep track of parent node to avoid false cycle detection
3. If we visit an already visited node that is not the parent, cycle exists

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for visited array and recursion stack
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfsCheckCycle(int node, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCheckCycle(neighbor, node, adj, visited)) {
                    return true;
                }
            }
            // If visited and not parent, cycle found
            else if (neighbor != parent) {
                return true;
            }
        }
        
        return false;

    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        // Check for all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCheckCycle(i, -1, adj, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main() {
    // Example 1: Graph with cycle
    int V1 = 5;
    vector<int> adj1[V1];
    adj1[0].push_back(1);
    adj1[1].push_back(0);
    adj1[1].push_back(2);
    adj1[2].push_back(1);
    adj1[2].push_back(3);
    adj1[3].push_back(2);
    adj1[3].push_back(4);
    adj1[4].push_back(3);
    adj1[4].push_back(1); // Creates cycle
    adj1[1].push_back(4);
    
    Solution sol;
    cout << "Graph 1 has cycle: " << (sol.isCycle(V1, adj1) ? "Yes" : "No") << endl;
    
    // Example 2: Graph without cycle (tree)
    int V2 = 4;
    vector<int> adj2[V2];
    adj2[0].push_back(1);
    adj2[1].push_back(0);
    adj2[1].push_back(2);
    adj2[2].push_back(1);
    adj2[2].push_back(3);
    adj2[3].push_back(2);
    
    cout << "Graph 2 has cycle: " << (sol.isCycle(V2, adj2) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
INPUT 1:
Vertices: 5
Edges: (0,1), (1,2), (2,3), (3,4), (4,1)

OUTPUT:
Graph 1 has cycle: Yes

EXPLANATION:
The cycle exists: 1 -> 2 -> 3 -> 4 -> 1

INPUT 2:
Vertices: 4
Edges: (0,1), (1,2), (2,3)

OUTPUT:
Graph 2 has cycle: No

EXPLANATION:
This is a tree structure with no cycles.
*/
