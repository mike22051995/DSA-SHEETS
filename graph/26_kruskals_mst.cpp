/*
PROBLEM: Minimum Spanning Tree - Kruskal's Algorithm
Difficulty: Medium-Hard
Pattern: MST using Union-Find

DESCRIPTION:
Find the Minimum Spanning Tree using Kruskal's algorithm.
Sort edges by weight and use Union-Find to avoid cycles.

MST DIAGRAM (Kruskal's Algorithm):
  Original Graph:           Edge Selection Order:
       2    3                1. (0,1): weight=2 ✓
    0---1---2                2. (1,2): weight=3 ✓
    |\  |   |                3. (1,4): weight=5 ✓
   6| \8|5  |7               4. (0,3): weight=6 ✓
    |  \|   |                5. (2,5): weight=7 ✓
    3---4---5                6. (0,4): weight=8 ✗ (creates cycle)
       9                     7. (4,5): weight=9 ✗ (creates cycle)
  
  Sort all edges, pick smallest without creating cycle
  Use Union-Find to detect cycles
  MST Weight: 2+3+5+6+7 = 23

APPROACH:
1. Sort all edges by weight
2. Use Union-Find to track connected components
3. For each edge, if it connects different components, add to MST
4. Stop when we have V-1 edges

TIME COMPLEXITY: O(E * log E) for sorting
SPACE COMPLEXITY: O(V)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
};

class Solution {
public:
    int kruskalMST(int V, vector<vector<int>>& edges) {
        // edges[i] = {u, v, weight}
        
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        
        UnionFind uf(V);
        int mstWeight = 0;
        int edgesAdded = 0;
        vector<pair<int, int>> mstEdges;
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            
            // If adding edge doesn't create cycle
            if (uf.unite(u, v)) {
                mstWeight += weight;
                mstEdges.push_back({u, v});
                edgesAdded++;
                
                // MST complete
                if (edgesAdded == V - 1) {
                    break;
                }
            }
        }
        
        cout << "MST Edges:" << endl;
        for (auto& [u, v] : mstEdges) {
            cout << u << " -- " << v << endl;
        }
        
        return mstWeight;
    }
};

int main() {
    int V = 5;
    
    // edges[i] = {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}
    };
    
    Solution sol;
    int mstWeight = sol.kruskalMST(V, edges);
    
    cout << "\nMST Weight: " << mstWeight << endl;
    
    return 0;
}

/*
INPUT:
Vertices: 5
Edges: {0,1,2}, {0,3,6}, {1,2,3}, {1,3,8}, {1,4,5}, {2,4,7}

OUTPUT:
MST Edges:
0 -- 1
1 -- 2
1 -- 4
0 -- 3

MST Weight: 16

EXPLANATION:
Kruskal's algorithm sorts edges by weight:
1. Add (0,1,2) - weight 2
2. Add (1,2,3) - weight 3
3. Add (1,4,5) - weight 5
4. Add (0,3,6) - weight 6
5. Skip (2,4,7) - creates cycle
6. Skip (1,3,8) - creates cycle
Total: 2 + 3 + 5 + 6 = 16
*/
