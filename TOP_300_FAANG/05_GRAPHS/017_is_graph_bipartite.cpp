/*
================================================================================
PROBLEM: Is Graph Bipartite? (LeetCode #785)
DIFFICULTY: Medium
PATTERN: BFS / DFS / Graph Coloring
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // BFS approach
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (colors[i] != -1) continue;
            
            queue<int> q;
            q.push(i);
            colors[i] = 0;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : graph[node]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[node];
                        q.push(neighbor);
                    } else if (colors[neighbor] == colors[node]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    // DFS approach
    bool isBipartiteDFS(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!dfs(graph, i, 0, colors)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, int node, int color, vector<int>& colors) {
        colors[node] = color;
        
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == -1) {
                if (!dfs(graph, neighbor, 1 - color, colors)) {
                    return false;
                }
            } else if (colors[neighbor] == color) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph1 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    vector<vector<int>> graph2 = {{1,3},{0,2},{1,3},{0,2}};
    
    cout << "Is bipartite: " << (sol.isBipartite(graph1) ? "true" : "false") << endl;
    cout << "Is bipartite: " << (sol.isBipartite(graph2) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Possible Bipartition (LeetCode #886)
2. Graph Valid Tree (LeetCode #261)
3. Number of Connected Components (LeetCode #323)
4. Course Schedule (LeetCode #207)
5. Find Eventual Safe States (LeetCode #802)
6. Clone Graph (LeetCode #133)
7. Number of Islands (LeetCode #200)
8. Pacific Atlantic Water Flow (LeetCode #417)
9. Surrounded Regions (LeetCode #130)
10. Redundant Connection (LeetCode #684)
*/
