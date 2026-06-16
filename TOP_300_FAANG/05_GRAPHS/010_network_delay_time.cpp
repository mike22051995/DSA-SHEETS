/*
================================================================================
PROBLEM: Network Delay Time (LeetCode #743)
DIFFICULTY: Medium
PATTERN: Dijkstra's Algorithm / BFS
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
    // Dijkstra's Algorithm
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        
        for (auto& time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            if (time > dist[node]) continue;
            
            for (auto [neighbor, weight] : graph[node]) {
                int newDist = time + weight;
                
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
        
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
    
    // Bellman-Ford Algorithm
    int networkDelayTimeBellmanFord(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        for (int i = 1; i < n; i++) {
            for (auto& time : times) {
                int u = time[0], v = time[1], w = time[2];
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    
    cout << "Network delay time: " << sol.networkDelayTime(times, 4, 2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Cheapest Flights Within K Stops (LeetCode #787)
2. Path with Maximum Probability (LeetCode #1514)
3. Find the City (LeetCode #1334)
4. Reachable Nodes In Subdivided Graph (LeetCode #882)
5. Minimum Cost to Reach Destination (LeetCode #1928)
6. Path With Minimum Effort (LeetCode #1631)
7. Swim in Rising Water (LeetCode #778)
8. The Maze II (LeetCode #505)
9. Shortest Path in Binary Matrix (LeetCode #1091)
10. Shortest Path with Alternating Colors (LeetCode #1129)
*/
