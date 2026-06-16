/*
================================================================================
PROBLEM: Number of Connected Components in Undirected Graph (LeetCode #323)
DIFFICULTY: Medium
PATTERN: Union Find / DFS / BFS
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        count = n;
        
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
        
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }
    
    int getCount() {
        return count;
    }
};

class Solution {
public:
    // Union Find approach
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        
        for (auto& edge : edges) {
            uf.unite(edge[0], edge[1]);
        }
        
        return uf.getCount();
    }
    
    // DFS approach
    int countComponentsDFS(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int components = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                components++;
            }
        }
        
        return components;
    }
    
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    
    cout << "Number of components: " << sol.countComponents(n, edges) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of Provinces (LeetCode #547)
2. Graph Valid Tree (LeetCode #261)
3. Number of Islands (LeetCode #200)
4. Number of Islands II (LeetCode #305)
5. Redundant Connection (LeetCode #684)
6. Redundant Connection II (LeetCode #685)
7. Accounts Merge (LeetCode #721)
8. Sentence Similarity II (LeetCode #737)
9. Satisfiability of Equality Equations (LeetCode #990)
10. Smallest String With Swaps (LeetCode #1202)
*/
