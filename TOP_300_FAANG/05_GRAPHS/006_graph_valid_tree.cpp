/*
================================================================================
PROBLEM: Graph Valid Tree (LeetCode #261)
DIFFICULTY: Medium
PATTERN: Union Find / DFS
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DFS Approach
    bool validTree(int n, vector<vector<int>>& edges) {
        // Tree must have exactly n-1 edges
        if (edges.size() != n - 1) return false;
        
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        
        // Check if connected (all nodes reachable from node 0)
        dfs(graph, visited, 0);
        
        for (bool v : visited) {
            if (!v) return false;
        }
        
        return true;
    }
    
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }
    
    // Union Find Approach
    bool validTreeUF(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        for (auto& edge : edges) {
            int p1 = find(parent, edge[0]);
            int p2 = find(parent, edge[1]);
            
            if (p1 == p2) return false; // Cycle detected
            
            parent[p1] = p2;
        }
        
        return true;
    }
    
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{1,4}};
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    
    cout << "Valid tree (test 1): " << (sol.validTree(5, edges1) ? "true" : "false") << endl;
    cout << "Valid tree (test 2): " << (sol.validTree(5, edges2) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of Connected Components (LeetCode #323)
2. Clone Graph (LeetCode #133)
3. Course Schedule (LeetCode #207)
4. Course Schedule II (LeetCode #210)
5. Redundant Connection (LeetCode #684)
6. Redundant Connection II (LeetCode #685)
7. Number of Islands (LeetCode #200)
8. Accounts Merge (LeetCode #721)
9. Most Stones Removed (LeetCode #947)
10. Find if Path Exists in Graph (LeetCode #1971)
*/
