/*
PROBLEM: Graph Valid Tree (LeetCode 261)
Difficulty: Medium
Pattern: Union-Find / DFS Cycle Detection

DESCRIPTION:
Given n nodes and a list of undirected edges, check if these edges make up a valid tree.
A valid tree must:
1. Be connected (all nodes reachable)
2. Have no cycles
3. Have exactly n-1 edges

GRAPH DIAGRAM:
  Valid Tree (n=4):           Not a Tree (has cycle):
      0                           0---1
     / \                          |   |
    1   2                         3---2
    |                         
    3                         
  Edges: 3 (n-1)              Edges: 4 (cycle: 0-1-2-3-0)
  Connected: Yes              
  No cycles: Yes              Not a Tree (disconnected):
                                  0---1    2---3
                              Edges: 2 (not connected)

APPROACH:
1. A tree with n nodes has exactly n-1 edges
2. Use Union-Find to detect cycles
3. If we can add all edges without forming a cycle, it's a tree

TIME COMPLEXITY: O(E * α(N))
SPACE COMPLEXITY: O(N)
*/

#include <iostream>
#include <vector>
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
        
        if (rootX == rootY) {
            return false; // Cycle detected
        }
        
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
    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree must have exactly n-1 edges
        if (edges.size() != n - 1) {
            return false;
        }
        
        UnionFind uf(n);
        
        // Try to add all edges
        for (auto& edge : edges) {
            if (!uf.unite(edge[0], edge[1])) {
                return false; // Cycle detected
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    // Example 1: Valid tree
    int n1 = 5;
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{1,4}};
    cout << "Is valid tree: " << (sol.validTree(n1, edges1) ? "Yes" : "No") << endl;
    
    // Example 2: Has cycle
    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    cout << "Is valid tree: " << (sol.validTree(n2, edges2) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
INPUT 1:
n = 5
edges = [[0,1],[0,2],[0,3],[1,4]]

OUTPUT:
Is valid tree: Yes

EXPLANATION:
    0
   /|\\
  1 2 3
  |
  4
Connected, no cycles, 4 edges for 5 nodes.

INPUT 2:
n = 5
edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]

OUTPUT:
Is valid tree: No

EXPLANATION:
Contains a cycle: 1-2-3-1
*/
