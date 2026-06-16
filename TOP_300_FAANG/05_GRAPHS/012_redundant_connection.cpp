/*
================================================================================
PROBLEM: Redundant Connection (LeetCode #684)
DIFFICULTY: Medium
PATTERN: Union Find / DFS
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
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
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        
        for (int i = 0; i <= n; i++) {
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
            return false; // Already connected
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        
        for (auto& edge : edges) {
            if (!uf.unite(edge[0], edge[1])) {
                return edge;
            }
        }
        
        return {};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    
    vector<int> result = sol.findRedundantConnection(edges);
    
    cout << "Redundant connection: [" << result[0] << "," << result[1] << "]" << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Redundant Connection II (LeetCode #685)
2. Number of Connected Components (LeetCode #323)
3. Graph Valid Tree (LeetCode #261)
4. Find Critical and Pseudo-Critical Edges (LeetCode #1489)
5. Minimize Malware Spread (LeetCode #924)
6. Minimize Malware Spread II (LeetCode #928)
7. Accounts Merge (LeetCode #721)
8. Sentence Similarity II (LeetCode #737)
9. Evaluate Division (LeetCode #399)
10. Satisfiability of Equality Equations (LeetCode #990)
*/
