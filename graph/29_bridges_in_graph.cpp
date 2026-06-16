/*
PROBLEM: Bridges in a Graph (Critical Connections)
Difficulty: Hard
Pattern: DFS with Discovery and Low Time

DESCRIPTION:
Find all bridges in an undirected graph.
A bridge is an edge whose removal increases the number of connected components.

BRIDGES DIAGRAM:
  Original Graph:          Remove edge (1,3):
      0---1---2                0---1---2       3---4
          |   |                    |   |           |
          3---4                    │   4           |
              |                    └───┘           |
              5                                5
  
  Bridge: (1,3)
  (Removing it disconnects {0,1,2,4,5} from {3})
  
  Non-Bridge: (1,2) or (2,4)
  (Removing them keeps graph connected via alternate path)
  
  Detection: low[v] > disc[u] for edge (u,v)

APPROACH:
1. Use DFS to assign discovery time and low time to each vertex
2. An edge (u,v) is a bridge if low[v] > disc[u]
3. This means v cannot reach u or any ancestor of u without using edge (u,v)

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int timer = 0;
    
public:
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& disc,
             vector<int>& low, vector<bool>& visited, vector<vector<int>>& bridges) {
        
        visited[u] = true;
        disc[u] = low[u] = timer++;
        
        for (int v : adj[u]) {
            if (v == parent) continue;
            
            if (visited[v]) {
                // Back edge
                low[u] = min(low[u], disc[v]);
            } else {
                // Tree edge
                dfs(v, u, adj, disc, low, visited, bridges);
                
                low[u] = min(low[u], low[v]);
                
                // Check bridge condition
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }
    
    vector<vector<int>> findBridges(int V, vector<vector<int>>& adj) {
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> visited(V, false);
        vector<vector<int>> bridges;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, bridges);
            }
        }
        
        return bridges;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    
    // Creating an undirected graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    
    adj[2].push_back(3);
    adj[3].push_back(2);
    
    adj[1].push_back(3);
    adj[3].push_back(1);
    
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    Solution sol;
    vector<vector<int>> bridges = sol.findBridges(V, adj);
    
    cout << "Bridges (Critical Connections):" << endl;
    if (bridges.empty()) {
        cout << "None" << endl;
    } else {
        for (auto& bridge : bridges) {
            cout << bridge[0] << " -- " << bridge[1] << endl;
        }
    }
    
    return 0;
}

/*
INPUT:
Vertices: 5
Undirected Edges: (0,1), (1,2), (2,3), (1,3), (3,4)

Graph structure:
    0---1
        |\
        | 2
        |/
        3---4

OUTPUT:
Bridges (Critical Connections):
0 -- 1
3 -- 4

EXPLANATION:
- Edge (0,1): Removing it disconnects vertex 0
- Edge (3,4): Removing it disconnects vertex 4
- Edges (1,2), (2,3), (1,3) form a cycle, so none are bridges
*/
