/*
PROBLEM: Topological Sort (DFS)
Difficulty: Medium
Pattern: Topological Sort using DFS

DESCRIPTION:
Given a Directed Acyclic Graph (DAG), perform topological sort using DFS.
Use a stack to store the finishing order of vertices.

GRAPH DIAGRAM (DAG):
      0 → 1 → 3
      ↓     ↓
      2 → → 4

  Edges: 0→1, 0→2, 1→3, 1→4, 2→4
  
  DFS finishing order (pushed to stack): 3, 4, 1, 2, 0
  Topological Order (pop from stack): 0, 2, 1, 4, 3
  
  Finish DFS on a node → Push to stack → Reverse gives topo order

APPROACH:
1. Use DFS traversal
2. After visiting all neighbors of a vertex, push it to stack
3. The stack will contain vertices in reverse topological order
4. Pop all elements from stack to get topological sort

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V) for visited array and stack
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        
        // Visit all neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }
        
        // Push to stack after visiting all neighbors
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        stack<int> st;
        
        // Call DFS for all vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }
        
        // Pop all elements from stack
        vector<int> topoOrder;
        while (!st.empty()) {
            topoOrder.push_back(st.top());
            st.pop();
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
    
    cout << "Topological Sort (DFS): ";
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
Topological Sort (DFS): 5 4 2 3 1 0 (one possible ordering)

EXPLANATION:
DFS finishes vertices in reverse topological order.
Stack ensures correct ordering.
*/
