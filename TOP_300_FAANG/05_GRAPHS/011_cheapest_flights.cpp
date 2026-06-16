/*
================================================================================
PROBLEM: Cheapest Flights Within K Stops (LeetCode #787)
DIFFICULTY: Medium
PATTERN: Dynamic Programming / Dijkstra / BFS
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    // BFS approach
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        
        for (auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q; // {node, cost}
        q.push({src, 0});
        int stops = 0;
        
        while (!q.empty() && stops <= k) {
            int size = q.size();
            
            while (size--) {
                auto [node, cost] = q.front();
                q.pop();
                
                for (auto [neighbor, price] : graph[node]) {
                    if (cost + price < dist[neighbor]) {
                        dist[neighbor] = cost + price;
                        q.push({neighbor, cost + price});
                    }
                }
            }
            stops++;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
    
    // DP approach
    int findCheapestPriceDP(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, INT_MAX);
        dp[src] = 0;
        
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dp;
            
            for (auto& flight : flights) {
                int from = flight[0], to = flight[1], price = flight[2];
                
                if (dp[from] != INT_MAX) {
                    temp[to] = min(temp[to], dp[from] + price);
                }
            }
            
            dp = temp;
        }
        
        return dp[dst] == INT_MAX ? -1 : dp[dst];
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    
    cout << "Cheapest price: " << sol.findCheapestPrice(n, flights, 0, 3, 1) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Network Delay Time (LeetCode #743)
2. Path with Maximum Probability (LeetCode #1514)
3. Find the City (LeetCode #1334)
4. Minimum Cost to Reach Destination (LeetCode #1928)
5. Path With Minimum Effort (LeetCode #1631)
6. Shortest Path in Binary Matrix (LeetCode #1091)
7. Shortest Path with Alternating Colors (LeetCode #1129)
8. Minimum Weighted Subgraph (LeetCode #2203)
9. Number of Ways to Arrive (LeetCode #1976)
10. Second Minimum Time to Reach (LeetCode #2045)
*/
