/*
PROBLEM: Detect Cycle in Directed Graph
Difficulty: Medium
Pattern: DFS with Recursion Stack

DESCRIPTION:
Given a directed graph, detect if it contains any cycle.

GRAPH DIAGRAM:
  Example with Cycle:           Example without Cycle (DAG):
      0 → 1                          0 → 1
          ↓                              ↓
          2                              2
          ↓                              ↓
          3 → 1 (back edge)              3

  Cycle: 1 → 2 → 3 → 1           DAG: 0 → 1 → 2 → 3
  (Back edge to node in          (No back edges, topological
   current recursion path)        order exists)

  Key: Track recursion stack to detect back edges

APPROACH:
1. Use DFS with two arrays: visited and recursion stack
2. visited tracks all visited nodes
3. recursionStack tracks nodes in current DFS path
4. If we reach a node that's in recursion stack, cycle exists

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for visited and recursion stack arrays
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfsCheckCycle(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;
        
        for (int neighbor : adj[node]) {
            // If not visited, recurse
            if (!visited[neighbor]) {
                if (dfsCheckCycle(neighbor, adj, visited, recStack)) {
                    return true;
                }
            }
            // If in recursion stack, cycle found
            else if (recStack[neighbor]) {
                return true;
            }
        }
        
        // Remove from recursion stack before returning
        recStack[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        
        // Check all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCheckCycle(i, adj, visited, recStack)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main() {
    // Example 1: Graph with cycle
    int V1 = 4;
    vector<int> adj1[V1];
    adj1[0].push_back(1);
    adj1[1].push_back(2);
    adj1[2].push_back(3);
    adj1[3].push_back(1); // Creates cycle: 1->2->3->1
    
    Solution sol;
    cout << "Graph 1 has cycle: " << (sol.isCyclic(V1, adj1) ? "Yes" : "No") << endl;
    
    // Example 2: DAG (no cycle)
    int V2 = 4;
    vector<int> adj2[V2];
    adj2[0].push_back(1);
    adj2[1].push_back(2);
    adj2[2].push_back(3);
    
    cout << "Graph 2 has cycle: " << (sol.isCyclic(V2, adj2) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
INPUT 1:
Vertices: 4
Directed Edges: 0->1, 1->2, 2->3, 3->1

OUTPUT:
Graph 1 has cycle: Yes

EXPLANATION:
Cycle exists: 1 -> 2 -> 3 -> 1

INPUT 2:
Vertices: 4
Directed Edges: 0->1, 1->2, 2->3

OUTPUT:
Graph 2 has cycle: No

EXPLANATION:
This is a DAG (Directed Acyclic Graph) with no cycles.
*/
