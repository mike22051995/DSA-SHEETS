/*
================================================================================
PROBLEM: All Paths From Source to Target (LeetCode #797)
DIFFICULTY: Medium
PATTERN: DFS / Backtracking
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path = {0};
        
        dfs(graph, 0, path, result);
        
        return result;
    }
    
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
        if (node == graph.size() - 1) {
            result.push_back(path);
            return;
        }
        
        for (int neighbor : graph[node]) {
            path.push_back(neighbor);
            dfs(graph, neighbor, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    
    vector<vector<int>> paths = sol.allPathsSourceTarget(graph);
    
    cout << "All paths from 0 to " << graph.size() - 1 << ":" << endl;
    for (auto& path : paths) {
        cout << "[";
        for (int node : path) {
            cout << node << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Number of Ways to Arrive (LeetCode #1976)
2. Find All Possible Recipes (LeetCode #2115)
3. Minimum Cost to Reach Destination (LeetCode #1928)
4. Count Paths (LeetCode #2242)
5. Binary Tree Paths (LeetCode #257)
6. Path Sum II (LeetCode #113)
7. Combination Sum (LeetCode #39)
8. Word Ladder II (LeetCode #126)
9. Restore IP Addresses (LeetCode #93)
10. Letter Combinations (LeetCode #17)
*/
