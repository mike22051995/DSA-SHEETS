/*
PROBLEM: Traveling Salesman Problem (TSP) using Bitmasking DP
DIFFICULTY: Hard
PATTERN: Bitmasking DP / State Compression

DESCRIPTION:
Given a set of cities and distance between every pair of cities, find the 
shortest possible route that visits every city exactly once and returns to 
the starting city.

This is NP-hard problem. DP with bitmask gives O(n² * 2^n) solution.

EXAMPLE:
Input: 
dist[][] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
}
Output: 80
Explanation: 0 → 1 → 3 → 2 → 0 = 10+25+30+15 = 80

TIME COMPLEXITY: O(n² * 2^n)
SPACE COMPLEXITY: O(n * 2^n)
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: DP with Bitmasking
    int tsp(vector<vector<int>>& dist) {
        int n = dist.size();
        
        // dp[mask][i] = min cost to visit cities in mask, ending at city i
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        
        // Base case: start at city 0
        dp[1][0] = 0;  // mask = 0001 (only city 0 visited)
        
        // Iterate through all masks
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int u = 0; u < n; u++) {
                // If city u is in mask and state is valid
                if ((mask & (1 << u)) && dp[mask][u] != INT_MAX) {
                    // Try going to city v
                    for (int v = 0; v < n; v++) {
                        // If city v not yet visited
                        if (!(mask & (1 << v))) {
                            int newMask = mask | (1 << v);
                            dp[newMask][v] = min(dp[newMask][v], 
                                               dp[mask][u] + dist[u][v]);
                        }
                    }
                }
            }
        }
        
        // Find minimum cost to visit all cities and return to start
        int allVisited = (1 << n) - 1;
        int minCost = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (dp[allVisited][i] != INT_MAX) {
                minCost = min(minCost, dp[allVisited][i] + dist[i][0]);
            }
        }
        
        return minCost;
    }
    
    // Approach 2: Recursion with Memoization
    int tspHelper(vector<vector<int>>& dist, int mask, int pos, 
                  vector<vector<int>>& dp) {
        int n = dist.size();
        
        // All cities visited, return to start
        if (mask == (1 << n) - 1) {
            return dist[pos][0];
        }
        
        if (dp[mask][pos] != -1) {
            return dp[mask][pos];
        }
        
        int minCost = INT_MAX;
        
        // Try visiting each unvisited city
        for (int city = 0; city < n; city++) {
            if (!(mask & (1 << city))) {  // If not visited
                int newMask = mask | (1 << city);
                int cost = dist[pos][city] + tspHelper(dist, newMask, city, dp);
                minCost = min(minCost, cost);
            }
        }
        
        return dp[mask][pos] = minCost;
    }
    
    int tspMemo(vector<vector<int>>& dist) {
        int n = dist.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        
        // Start from city 0 with only city 0 visited
        return tspHelper(dist, 1, 0, dp);
    }
    
    // Get actual path
    vector<int> getTSPPath(vector<vector<int>>& dist) {
        int n = dist.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        
        dp[1][0] = 0;
        
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int u = 0; u < n; u++) {
                if ((mask & (1 << u)) && dp[mask][u] != INT_MAX) {
                    for (int v = 0; v < n; v++) {
                        if (!(mask & (1 << v))) {
                            int newMask = mask | (1 << v);
                            int newCost = dp[mask][u] + dist[u][v];
                            
                            if (newCost < dp[newMask][v]) {
                                dp[newMask][v] = newCost;
                                parent[newMask][v] = u;
                            }
                        }
                    }
                }
            }
        }
        
        // Find ending city with minimum cost
        int allVisited = (1 << n) - 1;
        int minCost = INT_MAX;
        int lastCity = -1;
        
        for (int i = 0; i < n; i++) {
            if (dp[allVisited][i] != INT_MAX) {
                int totalCost = dp[allVisited][i] + dist[i][0];
                if (totalCost < minCost) {
                    minCost = totalCost;
                    lastCity = i;
                }
            }
        }
        
        // Backtrack to get path
        vector<int> path;
        int mask = allVisited;
        int city = lastCity;
        
        while (city != -1) {
            path.push_back(city);
            int prevCity = parent[mask][city];
            if (prevCity != -1) {
                mask ^= (1 << city);  // Remove current city from mask
            }
            city = prevCity;
        }
        
        reverse(path.begin(), path.end());
        path.push_back(0);  // Return to start
        
        return path;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<vector<int>> dist1 = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    cout << "Distance matrix:" << endl;
    for (const auto& row : dist1) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    
    cout << "Minimum cost (DP): " << sol.tsp(dist1) << endl;
    cout << "Minimum cost (Memo): " << sol.tspMemo(dist1) << endl;
    
    vector<int> path1 = sol.getTSPPath(dist1);
    cout << "Optimal path: ";
    for (int i = 0; i < path1.size(); i++) {
        cout << path1[i];
        if (i < path1.size()-1) cout << " → ";
    }
    cout << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    vector<vector<int>> dist2 = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };
    
    cout << "Distance matrix:" << endl;
    for (const auto& row : dist2) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    
    cout << "Minimum cost: " << sol.tsp(dist2) << endl;
    
    vector<int> path2 = sol.getTSPPath(dist2);
    cout << "Optimal path: ";
    for (int i = 0; i < path2.size(); i++) {
        cout << path2[i];
        if (i < path2.size()-1) cout << " → ";
    }
    cout << endl;
    
    // Test case 3 - Small example
    cout << "\nTest Case 3:" << endl;
    vector<vector<int>> dist3 = {
        {0, 10, 15},
        {10, 0, 20},
        {15, 20, 0}
    };
    
    cout << "Distance matrix:" << endl;
    for (const auto& row : dist3) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    
    cout << "Minimum cost: " << sol.tsp(dist3) << endl;
    
    return 0;
}

/*
EXPLANATION:

TRAVELING SALESMAN PROBLEM - Bitmasking DP

PROBLEM:
Visit all cities exactly once, return to start, minimize distance.

WHY BITMASKING?
Need to track which cities are visited.
With n cities, there are 2^n possible subsets.
Use bitmask to represent: bit i = 1 means city i visited.

STATE DEFINITION:
dp[mask][i] = minimum cost to visit cities in mask, ending at city i

mask: bitmask representing visited cities
i: current city

EXAMPLE:
4 cities: 0, 1, 2, 3
mask = 1011 (binary) = visited {0, 1, 3}

TRANSITIONS:
From state (mask, u), we can go to city v if:
- v is not in mask
- Add edge u→v

New state: (mask | (1<<v), v)
Cost: dp[mask][u] + dist[u][v]

EXAMPLE TRACE:
Cities: 0, 1, 2, 3

Start: dp[0001][0] = 0 (at city 0)

From (0001, 0):
- Go to 1: dp[0011][1] = 0 + 10 = 10
- Go to 2: dp[0101][2] = 0 + 15 = 15
- Go to 3: dp[1001][3] = 0 + 20 = 20

From (0011, 1):
- Go to 2: dp[0111][2] = 10 + 35 = 45
- Go to 3: dp[1011][3] = 10 + 25 = 35

From (0101, 2):
- Go to 1: dp[0111][1] = 15 + 35 = 50
- Go to 3: dp[1101][3] = 15 + 30 = 45

... and so on

Final: dp[1111][i] + dist[i][0] for all i

BITMASK OPERATIONS:
- Check if city i visited: mask & (1 << i)
- Add city i to mask: mask | (1 << i)
- Remove city i: mask ^ (1 << i)
- All cities visited: (1 << n) - 1

RECURRENCE:
dp[mask][i] = min(dp[mask without i][j] + dist[j][i])
              for all j in mask, j ≠ i

BASE CASE:
dp[1<<0][0] = 0  (start at city 0)

FINAL ANSWER:
min(dp[(1<<n)-1][i] + dist[i][0]) for all i

WHY THIS WORKS:
- Avoids recomputing same subproblems
- Each state represents unique situation
- Overlapping subproblems → DP applicable

COMPLEXITY:
Time: O(n² * 2^n)
- 2^n masks
- n ending cities
- n transitions per state

Space: O(n * 2^n) for DP table

LIMITATIONS:
Only feasible for n ≤ 20
Beyond that, use approximation algorithms.

PATTERN RECOGNITION:
- Visit all exactly once → Permutation problem
- Track visited set → Bitmask
- Optimize cost → DP

SIMILAR PROBLEMS:
- Hamiltonian Path (find any path)
- Assignment Problem (bipartite matching)
- Shortest Hamiltonian Cycle

INTERVIEW TIP:
"TSP is NP-hard, but with small n, we can use bitmask DP.
State is (visited cities, current city). Try all unvisited 
next cities and take minimum. Time: O(n² * 2^n)."

PRACTICAL NOTE:
For large n, use heuristics:
- Greedy nearest neighbor
- 2-opt improvement
- Christofides algorithm (1.5 approximation)

OUTPUT:
Test Case 1:
Distance matrix:
0       10      15      20
10      0       35      25
15      35      0       30
20      25      30      0
Minimum cost (DP): 80
Minimum cost (Memo): 80
Optimal path: 0 → 1 → 3 → 2 → 0

Test Case 2:
Distance matrix:
0       20      42      25
20      0       30      34
42      30      0       10
25      34      10      0
Minimum cost: 85
Optimal path: 0 → 1 → 2 → 3 → 0

Test Case 3:
Distance matrix:
0       10      15
10      0       20
15      20      0
Minimum cost: 45
*/
