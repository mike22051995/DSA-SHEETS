/*
PROBLEM: Cheapest Flights Within K Stops (LeetCode 787)
Difficulty: Hard
Pattern: Modified Dijkstra / Bellman-Ford

DESCRIPTION:
Find the cheapest price from src to dst with at most k stops.
If no such route exists, return -1.

FLIGHT NETWORK DIAGRAM:
  Example: n=4, src=0, dst=3, k=1
  flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
  
       100      600
    0 → 1 →→→→→→ 3
    ↑   ↓         ↑
   100  100      200
    |     ↓         ↑
    ←←← 2 →→→→→→

  Path 0→1→3: cost=700 (1 stop) ✓
  Path 0→1→2→3: cost=400 (2 stops, exceeds k=1) ✗
  Answer: 700 (cheapest within k stops)

APPROACH:
1. Use modified Dijkstra with state (cost, node, stops)
2. Track minimum cost to reach each node with given stops
3. Only explore paths with stops <= k
4. Use priority queue ordered by cost

TIME COMPLEXITY: O(E * K * log(E * K))
SPACE COMPLEXITY: O(V * K)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]}); // {destination, price}
        }
        
        // Priority queue: {cost, {node, stops}}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0}); // {cost, node, stops}
        
        // Track minimum cost to reach each node with specific stops
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int cost = curr[0];
            int node = curr[1];
            int stops = curr[2];
            
            // If we reached destination
            if (node == dst) {
                return cost;
            }
            
            // If we've used all stops
            if (stops > k) {
                continue;
            }
            
            // Explore neighbors
            for (auto& [nextNode, price] : adj[node]) {
                int newCost = cost + price;
                if (newCost < dist[nextNode][stops + 1]) {
                    dist[nextNode][stops + 1] = newCost;
                    pq.push({newCost, nextNode, stops + 1});
                }
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 4;
    vector<vector<int>> flights1 = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src1 = 0, dst1 = 3, k1 = 1;
    cout << "Cheapest price: " << sol.findCheapestPrice(n1, flights1, src1, dst1, k1) << endl;
    
    // Example 2
    int n2 = 3;
    vector<vector<int>> flights2 = {{0,1,100},{1,2,100},{0,2,500}};
    int src2 = 0, dst2 = 2, k2 = 1;
    cout << "Cheapest price: " << sol.findCheapestPrice(n2, flights2, src2, dst2, k2) << endl;
    
    return 0;
}

/*
INPUT 1:
n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0, dst = 3, k = 1

OUTPUT:
Cheapest price: 700

EXPLANATION:
Path: 0 -> 1 -> 3 (1 stop, cost 700)
Alternative: 0 -> 1 -> 2 -> 3 (2 stops, exceeds k=1)

INPUT 2:
n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1

OUTPUT:
Cheapest price: 200

EXPLANATION:
Path: 0 -> 1 -> 2 (cost 200) is cheaper than direct 0 -> 2 (cost 500)
*/
