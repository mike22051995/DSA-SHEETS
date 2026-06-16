/*
PROBLEM: Articulation Points (Cut Vertices)
Difficulty: Hard
Pattern: DFS with Discovery and Low Time

DESCRIPTION:
Find all articulation points in an undirected graph.
An articulation point is a vertex whose removal increases the number of connected components.

ARTICULATION POINTS DIAGRAM:
  Original Graph:          Remove vertex 1:
      0---1---2                0       2
          |   |                        |
          3---4                    3---4
  
  Articulation Point: 1
  (Removing 1 disconnects 0 from rest of graph)
  
  Non-Articulation: 3 or 4
  (Removing them keeps graph connected)
  
  Detection: low[child] >= disc[node]
  (Child cannot reach ancestor without going through node)

APPROACH:
1. Use DFS to assign discovery time and low time to each vertex
2. Low time = minimum discovery time reachable from subtree
3. For root: articulation point if it has more than 1 child
4. For non-root: articulation point if low[child] >= disc[node]

TIME COMPLEXITY: O(V + E)
SPACE COMPLEXITY: O(V)
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    int timer = 0;
    
public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, 
             vector<int>& low, vector<bool>& visited, set<int>& articulationPoints) {
        
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;
        
        for (int v : adj[u]) {
            if (v == parent) continue;
            
            if (visited[v]) {
                // Back edge
                low[u] = min(low[u], disc[v]);
            } else {
                // Tree edge
                children++;
                dfs(v, u, adj, disc, low, visited, articulationPoints);
                
                low[u] = min(low[u], low[v]);
                
                // Check articulation point conditions
                if (parent == -1 && children > 1) {
                    // Root with multiple children
                    articulationPoints.insert(u);
                }
                
                if (parent != -1 && low[v] >= disc[u]) {
                    // Non-root: child cannot reach ancestor
                    articulationPoints.insert(u);
                }
            }
        }
    }
    
    vector<int> findArticulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> visited(V, false);
        set<int> articulationPoints;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, articulationPoints);
            }
        }
        
        return vector<int>(articulationPoints.begin(), articulationPoints.end());
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];
    
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
    vector<int> artPoints = sol.findArticulationPoints(V, adj);
    
    cout << "Articulation Points: ";
    if (artPoints.empty()) {
        cout << "None" << endl;
    } else {
        for (int point : artPoints) {
            cout << point << " ";
        }
        cout << endl;
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
Articulation Points: 1 3

EXPLANATION:
- Removing vertex 1 disconnects 0 from rest of graph
- Removing vertex 3 disconnects 4 from rest of graph
- These are critical vertices for connectivity
*/
