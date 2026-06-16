/*
================================================================================
PROBLEM: Critical Connections in a Network (LeetCode #1192)
DIFFICULTY: Hard
PATTERN: Graph / Tarjan's Algorithm / Bridges
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
There are n servers numbered from 0 to n - 1 connected by undirected
server-to-server connections forming a network. A critical connection is a
connection that, if removed, will make some servers unable to reach some other
server. Return all critical connections in the network in any order.

EXAMPLES:

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

PATTERN RECOGNITION:
Use this pattern when:
- Need to find bridges (critical edges) in graph
- Tarjan's algorithm for finding articulation points/bridges
- Graph connectivity problems
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int timer = 0;
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        
        // Build adjacency list
        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        vector<int> disc(n, -1);  // Discovery time
        vector<int> low(n, -1);   // Lowest reachable node
        vector<vector<int>> result;
        
        dfs(0, -1, graph, disc, low, result);
        
        return result;
    }
    
    void dfs(int node, int parent, vector<vector<int>>& graph, 
             vector<int>& disc, vector<int>& low, vector<vector<int>>& result) {
        disc[node] = low[node] = timer++;
        
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            
            if (disc[neighbor] == -1) {
                dfs(neighbor, node, graph, disc, low, result);
                low[node] = min(low[node], low[neighbor]);
                
                // Bridge found
                if (low[neighbor] > disc[node]) {
                    result.push_back({node, neighbor});
                }
            } else {
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> connections1 = {{0,1},{1,2},{2,0},{1,3}};
    auto result1 = sol.criticalConnections(4, connections1);
    
    cout << "Critical connections:" << endl;
    for (auto& conn : result1) {
        cout << "[" << conn[0] << "," << conn[1] << "]" << endl;
    }
    
    return 0;
}

/*
TIME COMPLEXITY: O(V + E) where V is vertices, E is edges
SPACE COMPLEXITY: O(V + E) for graph and recursion

SIMILAR PROBLEMS:
1. Articulation Points (LeetCode - similar concept)
2. Find Bridges in Graph (Classic problem)
3. Number of Connected Components (LeetCode #323)
4. Redundant Connection (LeetCode #684)
5. Redundant Connection II (LeetCode #685)
6. Minimize Malware Spread (LeetCode #924)
7. Minimize Malware Spread II (LeetCode #928)
8. Graph Valid Tree (LeetCode #261)
9. Number of Islands II (LeetCode #305)
10. Accounts Merge (LeetCode #721)
*/
