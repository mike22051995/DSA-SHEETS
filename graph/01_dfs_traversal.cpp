/*
PROBLEM: DFS Traversal of Graph
Difficulty: Easy
Pattern: Depth First Search (DFS)

DESCRIPTION:
Given a connected undirected graph, perform Depth First Search traversal starting from vertex 0.
Print all vertices in the order they are visited.

GRAPH DIAGRAM:
        0
       / \
      1   2
      |   |
      3   4

Edges: 0-1, 0-2, 1-3, 2-4
DFS Traversal Order: 0 -> 1 -> 3 -> 2 -> 4
(Visits depth-first: goes as deep as possible before backtracking)

APPROACH:
1. Use recursion or stack to traverse the graph
2. Mark vertices as visited to avoid cycles
3. Visit all adjacent unvisited vertices recursively

TIME COMPLEXITY: O(V + E) where V = vertices, E = edges
SPACE COMPLEXITY: O(V) for visited array and recursion stack
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfsHelper(int node, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
        // Base condition: skip already visited nodes
        if (visited[node]) return;

        visited[node] = true;
        result.push_back(node);
        
        // Visit all adjacent vertices
        for (int neighbor : adj[node]) {   
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }
    
    vector<int> dfsTraversal(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> result;
        
        // Loop over all vertices to handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsHelper(i, adj, visited, result);
            }
        }
        
        return result;
    }
};

int main() {
    // Example: Graph with 5 vertices
    int V = 5;
    vector<int> adj[V];
    
    // Adding edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);
    
    Solution sol;
    vector<int> result = sol.dfsTraversal(V, adj);
    
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

/*
INPUT:
Vertices: 5
Edges: (0,1), (0,2), (1,3), (2,4)

OUTPUT:
DFS Traversal: 0 1 3 2 4

EXPLANATION:
Starting from vertex 0:
- Visit 0, mark as visited
- Visit adjacent vertex 1, mark as visited
- Visit adjacent vertex 3 from 1, mark as visited
- Backtrack to 0, visit adjacent vertex 2
- Visit adjacent vertex 4 from 2
*/
