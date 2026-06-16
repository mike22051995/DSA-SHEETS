/*
PROBLEM: Strongly Connected Components - Kosaraju's Algorithm
Difficulty: Hard
Pattern: SCC using Two DFS

DESCRIPTION:
Find all Strongly Connected Components (SCCs) in a directed graph.
A strongly connected component is a maximal set of vertices where every vertex
is reachable from every other vertex in the set.

SCC DIAGRAM:
  Directed Graph:          SCCs Identified:
      0 → 1 → 2             SCC1: {0, 1, 2}
      ↑   ↓   ↓             SCC2: {3, 4}
      ←←←←   3
              ↓ ↑
              4→
  
  Within SCC1: 0→1→2→0 (all reachable from each other)
  Within SCC2: 3↔4↔3
  Between SCCs: Can go from SCC1 to SCC2, but not back
  
  Kosaraju's: DFS on original + DFS on transposed graph

APPROACH:
1. First DFS: Fill stack with vertices in finishing order
2. Transpose the graph (reverse all edges)
3. Second DFS: Process vertices from stack, each DFS gives one SCC

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // First DFS to fill stack
    void dfs1(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs1(neighbor, adj, visited, st);
            }
        }
        
        st.push(node);
    }
    
    // Second DFS to find SCC
    void dfs2(int node, vector<int> transpose[], vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        
        for (int neighbor : transpose[node]) {
            if (!visited[neighbor]) {
                dfs2(neighbor, transpose, visited, component);
            }
        }
    }
    
    vector<vector<int>> findSCCs(int V, vector<int> adj[]) {
        stack<int> st;
        vector<bool> visited(V, false);
        
        // Step 1: Fill stack with finishing order
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }
        
        // Step 2: Create transpose graph
        vector<int> transpose[V];
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                transpose[v].push_back(u);
            }
        }
        
        // Step 3: Find SCCs using second DFS
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (!visited[node]) {
                vector<int> component;
                dfs2(node, transpose, visited, component);
                sccs.push_back(component);
            }
        }
        
        return sccs;
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];
    
    // Creating a directed graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);
    
    Solution sol;
    vector<vector<int>> sccs = sol.findSCCs(V, adj);
    
    cout << "Strongly Connected Components:" << endl;
    for (int i = 0; i < sccs.size(); i++) {
        cout << "SCC " << i + 1 << ": ";
        for (int node : sccs[i]) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
INPUT:
Vertices: 5
Directed Edges: 0->1, 1->2, 2->0, 1->3, 3->4

OUTPUT:
Strongly Connected Components:
SCC 1: 0 2 1
SCC 2: 3
SCC 3: 4

EXPLANATION:
SCC 1: {0, 1, 2} - these vertices form a cycle
SCC 2: {3} - single vertex
SCC 3: {4} - single vertex
*/
