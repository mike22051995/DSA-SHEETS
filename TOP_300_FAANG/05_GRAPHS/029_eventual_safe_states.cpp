/*
================================================================================
PROBLEM: Find Eventual Safe States (LeetCode #802)
DIFFICULTY: Medium
PATTERN: Graph / DFS / Topological Sort
COMPANIES: Amazon, Microsoft, Google
================================================================================

PROBLEM DESCRIPTION:
There is a directed graph of n nodes with each node labeled from 0 to n - 1.
The graph is represented by a 0-indexed 2D integer array graph where graph[i]
is an integer array of nodes adjacent to node i. A node is a terminal node if
there are no outgoing edges. A node is a safe node if every possible path
starting from that node leads to a terminal node. Return an array containing
all the safe nodes of the graph, in ascending order.

EXAMPLES:

Example 1:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]

Example 2:
Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]

PATTERN RECOGNITION:
Use this pattern when:
- Detect cycles in directed graph
- Nodes safe if no cycle reachable from them
- DFS with three states: unvisited, visiting, visited
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);  // 0: unvisited, 1: visiting, 2: safe
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (isSafe(graph, i, state)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
    
    bool isSafe(vector<vector<int>>& graph, int node, vector<int>& state) {
        if (state[node] != 0) {
            return state[node] == 2;
        }
        
        state[node] = 1;  // Mark as visiting
        
        for (int neighbor : graph[node]) {
            if (!isSafe(graph, neighbor, state)) {
                return false;  // Cycle detected
            }
        }
        
        state[node] = 2;  // Mark as safe
        return true;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> graph1 = {{1,2},{2,3},{5},{0},{5},{},{}};
    auto result1 = sol.eventualSafeNodes(graph1);
    
    cout << "Safe nodes: ";
    for (int node : result1) {
        cout << node << " ";
    }
    cout << endl;
    
    vector<vector<int>> graph2 = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    auto result2 = sol.eventualSafeNodes(graph2);
    
    cout << "Safe nodes: ";
    for (int node : result2) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(V + E) where V is vertices, E is edges
SPACE COMPLEXITY: O(V) for state array and recursion

SIMILAR PROBLEMS:
1. Course Schedule (LeetCode #207)
2. Course Schedule II (LeetCode #210)
3. Detect Cycle in Directed Graph (Classic)
4. All Paths From Source to Target (LeetCode #797)
5. Minimum Height Trees (LeetCode #310)
6. Parallel Courses (LeetCode #1136)
7. Alien Dictionary (LeetCode #269)
8. Sequence Reconstruction (LeetCode #444)
9. Sort Items by Groups (LeetCode #1203)
10. Find All Possible Recipes (LeetCode #2115)
*/
