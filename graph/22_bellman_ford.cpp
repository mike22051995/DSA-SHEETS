/*
PROBLEM: Bellman-Ford Algorithm
Difficulty: Medium-Hard
Pattern: Shortest Path with Negative Weights

DESCRIPTION:
Find shortest paths from source to all vertices, even with negative edge weights.
Can detect negative weight cycles.

WEIGHTED GRAPH DIAGRAM (with negative weights):
       -1        2
    0 → 1 → 3
    |     |
   4|     |3
    ↓     ↓
    2 → 4
      -2

  Directed edges with weights:
  0→1(-1), 0→2(4), 1→2(3), 1→3(2), 2→4(-2)
  
  Negative Cycle Example:
  1 → 2 → 3 → 1 (if sum of weights < 0)
  
  Relax all edges V-1 times, then check for more improvements

APPROACH:
1. Initialize distances to infinity except source (0)
2. Relax all edges V-1 times
3. Check for negative weight cycles in Vth iteration
4. If any distance can still be reduced, negative cycle exists

TIME COMPLEXITY: O(V * E)
SPACE COMPLEXITY: O(V)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // edges[i] = {u, v, weight}
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        
        // Check for negative weight cycles
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle!" << endl;
                return {};
            }
        }
        
        return dist;
    }
};

int main() {
    Solution sol;
    
    // Example without negative cycle
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    
    vector<int> distances = sol.bellmanFord(V, edges, 0);
    
    if (!distances.empty()) {
        cout << "Shortest distances from vertex 0:" << endl;
        for (int i = 0; i < V; i++) {
            if (distances[i] == INT_MAX) {
                cout << "Vertex " << i << ": INF" << endl;
            } else {
                cout << "Vertex " << i << ": " << distances[i] << endl;
            }
        }
    }
    
    return 0;
}

/*
INPUT:
Vertices: 5
Edges with weights: 
(0,1,-1), (0,2,4), (1,2,3), (1,3,2), (1,4,2), (3,2,5), (3,1,1), (4,3,-3)
Source: 0

OUTPUT:
Shortest distances from vertex 0:
Vertex 0: 0
Vertex 1: -1
Vertex 2: 2
Vertex 3: -2
Vertex 4: 1

EXPLANATION:
Bellman-Ford can handle negative weights.
Path to vertex 3: 0->1->4->3 (cost -2)
Negative weights allowed but no negative cycles.
*/
