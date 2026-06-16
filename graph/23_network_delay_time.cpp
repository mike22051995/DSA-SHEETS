/*
PROBLEM: Network Delay Time (LeetCode 743)
Difficulty: Medium-Hard
Pattern: Dijkstra's Algorithm Application

DESCRIPTION:
Given a network of n nodes labeled 1 to n, and a list of travel times as directed edges
times[i] = (ui, vi, wi), where ui is source, vi is target, and wi is the time for a
signal to travel. Send a signal from node k. Return the minimum time for all nodes to
receive the signal. If impossible, return -1.

NETWORK DIAGRAM:
  Example: n=4, k=2, times=[[2,1,1],[2,3,1],[3,4,1]]
  
       1 ← 2 (start)
            ↓ 1
            3
            ↓ 1
            4

  Signal travels: 2→1(1), 2→3(1), 3→4(1)
  Time to reach all: max(1,1,2) = 2 minutes
  (All nodes receive signal in 2 time units)

APPROACH:
1. Build adjacency list from edges
2. Use Dijkstra's algorithm from source k
3. Find maximum distance among all nodes
4. If any node is unreachable, return -1

TIME COMPLEXITY: O((V + E) * log V)
SPACE COMPLEXITY: O(V + E)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }
        
        // Dijkstra's algorithm
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[k] = 0;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Find maximum distance
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1; // Node unreachable
            }
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> times1 = {{2,1,1},{2,3,1},{3,4,1}};
    int n1 = 4, k1 = 2;
    cout << "Network delay time: " << sol.networkDelayTime(times1, n1, k1) << endl;
    
    // Example 2
    vector<vector<int>> times2 = {{1,2,1}};
    int n2 = 2, k2 = 1;
    cout << "Network delay time: " << sol.networkDelayTime(times2, n2, k2) << endl;
    
    // Example 3: Unreachable
    vector<vector<int>> times3 = {{1,2,1}};
    int n3 = 2, k3 = 2;
    cout << "Network delay time: " << sol.networkDelayTime(times3, n3, k3) << endl;
    
    return 0;
}

/*
INPUT 1:
times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2

OUTPUT:
Network delay time: 2

EXPLANATION:
From node 2:
- Node 1 receives signal at time 1
- Node 3 receives signal at time 1
- Node 4 receives signal at time 2
Maximum time is 2.

INPUT 2:
times = [[1,2,1]], n = 2, k = 1

OUTPUT:
Network delay time: 1

INPUT 3:
times = [[1,2,1]], n = 2, k = 2

OUTPUT:
Network delay time: -1

EXPLANATION:
Node 1 is unreachable from node 2.
*/
