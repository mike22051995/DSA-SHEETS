/*
================================================================================
PROBLEM: Minimum Height Trees (LeetCode #310)
DIFFICULTY: Medium
PATTERN: Topological Sort / BFS
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        
        vector<unordered_set<int>> graph(n);
        
        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        // Find all leaf nodes
        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                leaves.push(i);
            }
        }
        
        // Remove leaves layer by layer
        int remaining = n;
        
        while (remaining > 2) {
            int leafCount = leaves.size();
            remaining -= leafCount;
            
            for (int i = 0; i < leafCount; i++) {
                int leaf = leaves.front();
                leaves.pop();
                
                int neighbor = *graph[leaf].begin();
                graph[neighbor].erase(leaf);
                
                if (graph[neighbor].size() == 1) {
                    leaves.push(neighbor);
                }
            }
        }
        
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    
    vector<int> result = sol.findMinHeightTrees(n, edges);
    
    cout << "MHT roots: ";
    for (int root : result) {
        cout << root << " ";
    }
    cout << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Course Schedule (LeetCode #207)
2. Course Schedule II (LeetCode #210)
3. Tree Diameter (LeetCode #1245)
4. Diameter of Binary Tree (LeetCode #543)
5. Height of Binary Tree After Subtree Removal (LeetCode #2458)
6. Longest Path With Different Adjacent Characters (LeetCode #2246)
7. Count Subtrees With Max Distance (LeetCode #1617)
8. Maximum Depth of N-ary Tree (LeetCode #559)
9. Frog Position After T Seconds (LeetCode #1377)
10. All Paths From Source Lead to Destination (LeetCode #1059)
*/
