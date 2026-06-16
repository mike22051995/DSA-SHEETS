/*
PROBLEM: Dijkstra's Shortest Path Algorithm
Difficulty: Medium-Hard
Pattern: Shortest Path - Single Source

DESCRIPTION:
Find the shortest path from a source vertex to all other vertices in a weighted graph
with non-negative edge weights.

WEIGHTED GRAPH DIAGRAM:
       2        1
    0 --- 1 ------- 3
    |     |         |
   4|     |7       1|
    |     |         |
    2 --- 4 ------- (complete)
       3

  Edges with weights:
  0-1(2), 0-2(4), 1-2(1), 1-3(7), 2-4(3), 3-4(1)
  
  From source 0:
  dist[0]=0, dist[1]=2, dist[2]=3, dist[3]=9, dist[4]=6
  Path to 4: 0 → 1(2) → 2(1) → 4(3) = 6

APPROACH:
1. Use a min-heap (priority queue) to always process the nearest unvisited vertex
2. Maintain a distance array initialized to infinity
3. Update distances of neighbors if a shorter path is found
4. Repeat until all vertices are processed

TIME COMPLEXITY: O((V + E) * log V) with binary heap
SPACE COMPLEXITY: O(V + E)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
        // Min-heap: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            // Skip if we've already found a shorter path
            if (d > dist[u]) continue;
            
            // Update distances to neighbors
            for (auto& [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    
    // Adding edges: {neighbor, weight}
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});
    adj[4].push_back({3, 2});
    
    Solution sol;
    vector<int> distances = sol.dijkstra(V, adj, 0);
    
    cout << "Shortest distances from vertex 0:" << endl;
    for (int i = 0; i < V; i++) {
        if (distances[i] == INT_MAX) {
            cout << "Vertex " << i << ": INF" << endl;
        } else {
            cout << "Vertex " << i << ": " << distances[i] << endl;
        }
    }
    
    return 0;
}

/*
INPUT:
Vertices: 5
Weighted Edges: (0,1,2), (0,2,4), (1,2,1), (1,3,7), (2,4,3), (3,4,1), (4,3,2)
Source: 0

OUTPUT:
Shortest distances from vertex 0:
Vertex 0: 0
Vertex 1: 2
Vertex 2: 3
Vertex 3: 8
Vertex 4: 6

EXPLANATION:
Path to vertex 1: 0->1 (cost 2)
Path to vertex 2: 0->1->2 (cost 3)
Path to vertex 3: 0->1->2->4->3 (cost 8)
Path to vertex 4: 0->1->2->4 (cost 6)
*/
