/*
================================================================================
PROBLEM: Coin Change (LeetCode #322)
DIFFICULTY: Medium
PATTERN: Dynamic Programming (Unbounded Knapsack)
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
    
    // BFS approach
    int coinChangeBFS(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        vector<bool> visited(amount + 1, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            level++;
            
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                for (int coin : coins) {
                    int next = curr + coin;
                    
                    if (next == amount) return level;
                    
                    if (next < amount && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1,2,5};
    cout << "Min coins for 11: " << sol.coinChange(coins, 11) << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Coin Change II (LeetCode #518) - Count ways
2. Perfect Squares (LeetCode #279)
3. Minimum Cost For Tickets (LeetCode #983)
4. Combination Sum IV (LeetCode #377)
5. Number of Ways to Stay in Same Place (LeetCode #1269)
6. Minimum Number of Refueling Stops (LeetCode #871)
7. Minimum Knight Moves (LeetCode #1197)
8. Reach a Number (LeetCode #754)
9. Minimum Cost to Reach Destination (LeetCode #1928)
10. Domino and Tromino Tiling (LeetCode #790)
*/
