/*
PROBLEM: Number of Connected Components (LeetCode 323)
Difficulty: Medium
Pattern: Union-Find / DFS

DESCRIPTION:
Given n nodes labeled from 0 to n-1 and a list of undirected edges,
find the number of connected components in the graph.

GRAPH DIAGRAM:
  Example: n=5, edges=[[0,1],[1,2],[3,4]]
  
      0---1---2        3---4
  
  Component 1: {0, 1, 2}
  Component 2: {3, 4}
  Number of Components: 2
  
  Use Union-Find: Start with 5 components, reduce to 2 after unions

APPROACH (Using Union-Find):
1. Initialize Union-Find with n components
2. For each edge, union the two nodes
3. Return the number of remaining components

TIME COMPLEXITY: O(E * α(N)) where α is inverse Ackermann function
SPACE COMPLEXITY: O(N)
*/

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int components;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        components = n;
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
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        components--;
    }
    
    int getComponents() {
        return components;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        
        for (auto& edge : edges) {
            uf.unite(edge[0], edge[1]);
        }
        
        return uf.getComponents();
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 5;
    vector<vector<int>> edges1 = {{0,1},{1,2},{3,4}};
    cout << "Number of components: " << sol.countComponents(n1, edges1) << endl;
    
    // Example 2
    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{3,4}};
    cout << "Number of components: " << sol.countComponents(n2, edges2) << endl;
    
    return 0;
}

/*
INPUT 1:
n = 5
edges = [[0,1],[1,2],[3,4]]

OUTPUT:
Number of components: 2

EXPLANATION:
Component 1: {0, 1, 2}
Component 2: {3, 4}

INPUT 2:
n = 5
edges = [[0,1],[1,2],[2,3],[3,4]]

OUTPUT:
Number of components: 1

EXPLANATION:
All nodes are connected in one component: {0, 1, 2, 3, 4}
*/
