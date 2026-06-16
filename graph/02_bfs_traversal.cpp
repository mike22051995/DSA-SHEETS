/*
PROBLEM: BFS Traversal of Graph
Difficulty: Easy
Pattern: Breadth First Search (BFS)

DESCRIPTION:
Given a connected undirected graph, perform Breadth First Search traversal starting from vertex 0.
Print all vertices in the order they are visited level by level.

GRAPH DIAGRAM:
        0          (Level 0)
       / \
      1   2       (Level 1)
      |   |
      3   4       (Level 2)

Edges: 0-1, 0-2, 1-3, 2-4
BFS Traversal Order: 0 -> 1 -> 2 -> 3 -> 4
(Visits level by level: all nodes at distance d before distance d+1)

APPROACH:
1. Use a queue to traverse the graph level by level
2. Mark vertices as visited to avoid cycles
3. Process all vertices at current level before moving to next level

TIME COMPLEXITY: O(V + E) where V = vertices, E = edges
SPACE COMPLEXITY: O(V) for visited array and queue
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfsTraversal(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> result;
        queue<int> q;
        
        // Start from vertex 0
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            // Visit all adjacent vertices
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
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
    vector<int> result = sol.bfsTraversal(V, adj);
    
    cout << "BFS Traversal: ";
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
BFS Traversal: 0 1 2 3 4

EXPLANATION:
Starting from vertex 0:
Level 0: Visit 0
Level 1: Visit 1, 2 (adjacent to 0)
Level 2: Visit 3 (adjacent to 1), 4 (adjacent to 2)
*/
