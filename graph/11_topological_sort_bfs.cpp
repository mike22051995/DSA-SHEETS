/*
PROBLEM: Topological Sort (Kahn's Algorithm - BFS)
Difficulty: Medium
Pattern: Topological Sort using BFS

DESCRIPTION:
Given a Directed Acyclic Graph (DAG), perform topological sort.
Topological sort is a linear ordering of vertices such that for every directed edge u->v,
u comes before v in the ordering.

GRAPH DIAGRAM (DAG):
      0 → 1 → 3
      ↓     ↓
      2 → → 4

  Edges: 0→1, 0→2, 1→3, 1→4, 2→4
  
  In-degrees: [0:0, 1:1, 2:1, 3:1, 4:2]
  Topological Order: 0 → 1 → 2 → 3 → 4 (or 0 → 2 → 1 → 3 → 4)
  
  Process nodes with in-degree 0 first (Kahn's Algorithm)

APPROACH:
1. Calculate in-degree for all vertices
2. Add all vertices with in-degree 0 to queue
3. Process vertices from queue, decrement in-degree of neighbors
4. Add vertices with in-degree 0 to queue
5. Repeat until queue is empty

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for in-degree array and queue
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        
        // Calculate in-degree for all vertices
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }
        
        queue<int> q;
        // Add all vertices with in-degree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topoOrder;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            
            // Reduce in-degree of neighbors
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return topoOrder;
    }
};

int main() {
    // Example: DAG with 6 vertices
    int V = 6;
    vector<int> adj[V];
    
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    Solution sol;
    vector<int> result = sol.topoSort(V, adj);
    
    cout << "Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

/*
INPUT:
Vertices: 6
Edges: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1

OUTPUT:
Topological Sort: 4 5 0 2 3 1 (or 5 4 2 0 3 1)

EXPLANATION:
Valid topological orderings where all edges point from left to right.
Multiple valid answers may exist.
*/
