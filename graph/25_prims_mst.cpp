/*
PROBLEM: Minimum Spanning Tree - Prim's Algorithm
Difficulty: Medium-Hard
Pattern: Minimum Spanning Tree (MST)

DESCRIPTION:
Find the Minimum Spanning Tree of a weighted undirected graph.
MST connects all vertices with minimum total edge weight and no cycles.

MST DIAGRAM (Prim's Algorithm):
  Original Graph:           Minimum Spanning Tree:
       2    3                     2    3
    0---1---2                  0---1---2
    |\  |   |                  |       |
   6| \8|5  |7                6|       |7
    |  \|   |                  |       |
    3---4---5                  3       5
       9
  
  Edges in MST: (0,1,2), (1,2,3), (1,4,5), (2,5,7), (0,3,6)
  Total Weight: 2+3+5+7+6 = 23
  
  Greedy: Always pick minimum weight edge that connects to MST

APPROACH:
1. Start from any vertex
2. Use min-heap to always pick minimum weight edge
3. Add vertex to MST if not already included
4. Add all edges from new vertex to heap
5. Repeat until all vertices are in MST

TIME COMPLEXITY: O(E * log V)
SPACE COMPLEXITY: O(V + E)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int primMST(int V, vector<vector<pair<int, int>>>& adj) {
        // Min-heap: {weight, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<bool> inMST(V, false);
        int mstWeight = 0;
        int edgesCount = 0;
        
        // Start from vertex 0
        pq.push({0, 0});
        
        while (!pq.empty() && edgesCount < V) {
            auto [weight, u] = pq.top();
            pq.pop();
            
            // Skip if already in MST
            if (inMST[u]) continue;
            
            // Add to MST
            inMST[u] = true;
            mstWeight += weight;
            edgesCount++;
            
            // Add all edges from u to heap
            for (auto& [v, w] : adj[u]) {
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }
        
        return mstWeight;
    }
    
    // Get MST edges (optional)
    vector<pair<int, int>> getMSTEdges(int V, vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        vector<bool> inMST(V, false);
        vector<pair<int, int>> mstEdges;
        
        // Start from vertex 0
        pq.push({0, {0, -1}}); // {weight, {vertex, parent}}
        
        while (!pq.empty()) {
            auto [weight, vertexPair] = pq.top();
            auto [u, parent] = vertexPair;
            pq.pop();
            
            if (inMST[u]) continue;
            
            inMST[u] = true;
            if (parent != -1) {
                mstEdges.push_back({parent, u});
            }
            
            for (auto& [v, w] : adj[u]) {
                if (!inMST[v]) {
                    pq.push({w, {v, u}});
                }
            }
        }
        
        return mstEdges;
    }
};

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    
    // Adding undirected edges: {neighbor, weight}
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    
    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});
    
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});
    
    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});
    
    Solution sol;
    int mstWeight = sol.primMST(V, adj);
    
    cout << "MST Weight: " << mstWeight << endl;
    
    vector<pair<int, int>> mstEdges = sol.getMSTEdges(V, adj);
    cout << "MST Edges:" << endl;
    for (auto& [u, v] : mstEdges) {
        cout << u << " -- " << v << endl;
    }
    
    return 0;
}

/*
INPUT:
Vertices: 5
Weighted Edges: (0,1,2), (0,3,6), (1,2,3), (1,3,8), (1,4,5), (2,4,7)

OUTPUT:
MST Weight: 16
MST Edges:
0 -- 1
1 -- 2
0 -- 3
1 -- 4

EXPLANATION:
Prim's algorithm builds MST by greedily selecting minimum weight edges.
Total weight: 2 + 3 + 6 + 5 = 16
*/
