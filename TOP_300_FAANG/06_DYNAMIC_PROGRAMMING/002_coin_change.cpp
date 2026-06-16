/*
================================================================================
PROBLEM: Coin Change (LeetCode #322)
DIFFICULTY: Medium
PATTERN: Dynamic Programming (Unbounded Knapsack)
COMPANIES: Amazon, Google, Microsoft, Facebook, Apple
================================================================================

PROBLEM DESCRIPTION:
You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, 
return -1.

You may assume that you have an infinite number of each kind of coin.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. Finding minimum/maximum ways to reach target
2. Unlimited use of elements (unbounded knapsack)
3. Need to minimize/maximize count or sum
4. Target can be achieved in multiple ways

Key Indicators:
- "Minimum number of" or "maximum value"
- Can use each element multiple times
- Need to reach exact target amount
- Optimization problem (min/max)

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1 (3 coins)

Example 2:
Input: coins = [2], amount = 3
Output: -1
Explanation: Cannot make 3 with only coin of value 2

Example 3:
Input: coins = [1], amount = 0
Output: 0
Explanation: 0 coins needed for amount 0

Example 4:
Input: coins = [1,2,5], amount = 100
Output: 20
Explanation: 100 = 5*20 (20 coins of value 5)

================================================================================
EXPLANATION:

DP Approach (Bottom-up):
dp[i] = minimum coins needed to make amount i

For each amount from 1 to target:
  For each coin:
    If coin <= amount:
      dp[amount] = min(dp[amount], dp[amount - coin] + 1)

Base Case:
- dp[0] = 0 (need 0 coins for amount 0)
- dp[i] = infinity for i > 0 (initially impossible)

Recurrence:
dp[amount] = min(dp[amount - coin] + 1) for all coins

Time Complexity: O(amount * n) where n is number of coins
Space Complexity: O(amount)

================================================================================
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Bottom-up DP (Most efficient)
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);  // Initialize with impossible value
        dp[0] = 0;  // Base case
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
    // Top-down DP with Memoization
    int coinChangeMemo(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2);  // -2 means not computed
        return helper(coins, amount, memo);
    }
    
    int helper(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != -2) return memo[amount];
        
        int minCoins = INT_MAX;
        
        for (int coin : coins) {
            int result = helper(coins, amount - coin, memo);
            if (result >= 0) {
                minCoins = min(minCoins, result + 1);
            }
        }
        
        memo[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
        return memo[amount];
    }
    
    // BFS Approach (Level by level)
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
                    
                    if (next == amount) {
                        return level;
                    }
                    
                    if (next < amount && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        
        return -1;
    }
    
    // With coin combination tracking
    vector<int> coinChangeWithPath(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        vector<int> parent(amount + 1, -1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    parent[i] = coin;
                }
            }
        }
        
        if (dp[amount] > amount) return {};
        
        // Reconstruct path
        vector<int> result;
        int curr = amount;
        while (curr > 0) {
            result.push_back(parent[curr]);
            curr -= parent[curr];
        }
        
        return result;
    }
};

void runTest(vector<int> coins, int amount, string testName) {
    Solution sol;
    int result = sol.coinChange(coins, amount);
    
    cout << testName << ": " << endl;
    cout << "Coins: [";
    for (int i = 0; i < coins.size(); i++) {
        cout << coins[i];
        if (i < coins.size() - 1) cout << ",";
    }
    cout << "], Amount: " << amount << endl;
    cout << "Minimum coins: " << result << endl;
    
    if (result != -1) {
        vector<int> path = sol.coinChangeWithPath(coins, amount);
        cout << "Coin combination: [";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    cout << "-------------------" << endl;
}

int main() {
    vector<int> coins1 = {1, 2, 5};
    runTest(coins1, 11, "Test 1");
    
    vector<int> coins2 = {2};
    runTest(coins2, 3, "Test 2");
    
    vector<int> coins3 = {1};
    runTest(coins3, 0, "Test 3");
    
    vector<int> coins4 = {1, 2, 5};
    runTest(coins4, 100, "Test 4");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Coin Change II (LeetCode #518) - Medium
   - Count number of combinations (not minimum)
   - Similar DP approach

2. Perfect Squares (LeetCode #279) - Medium
   - Minimum perfect squares that sum to n
   - Same pattern as coin change

3. Minimum Cost For Tickets (LeetCode #983) - Medium
   - DP with multiple choices

4. Last Stone Weight II (LeetCode #1049) - Medium
   - Partition problem variant

5. Target Sum (LeetCode #494) - Medium
   - Count ways using +/- operators

6. Partition Equal Subset Sum (LeetCode #416) - Medium
   - 0/1 knapsack variant

7. Ones and Zeroes (LeetCode #474) - Medium
   - 2D knapsack problem

8. Combination Sum IV (LeetCode #377) - Medium
   - Count combinations (order matters)

9. Integer Break (LeetCode #343) - Medium
   - Maximize product DP

10. Decode Ways (LeetCode #91) - Medium
    - Count decoding possibilities

================================================================================
DP PATTERNS - KNAPSACK FAMILY:
================================================================================

1. **0/1 Knapsack**:
   - Each item used at most once
   - Example: Partition Equal Subset Sum

2. **Unbounded Knapsack** (This Problem):
   - Items can be used unlimited times
   - Example: Coin Change, Perfect Squares

3. **Bounded Knapsack**:
   - Each item has limited quantity
   - Extend unbounded with counts

4. **Multiple Knapsacks**:
   - Multiple containers/targets
   - 2D/3D DP

================================================================================
KEY INSIGHTS:
================================================================================

1. Why DP Works:
   - Optimal substructure: min(amount) uses min(amount - coin)
   - Overlapping subproblems: same amounts calculated repeatedly
   - Bottom-up builds solution incrementally

2. Initialization:
   - dp[0] = 0 (base case)
   - Others = infinity or amount + 1
   - Final check if dp[amount] was updated

3. Common Mistakes:
   - Forgetting to handle impossible case
   - Wrong initialization value
   - Not checking coin <= amount
   - Integer overflow with INT_MAX

4. Optimization Tips:
   - Sort coins (helps with early termination)
   - Can exit early if dp[i] == infinity
   - BFS can be faster for small amounts

5. Follow-up Variations:
   - Count all combinations? (Coin Change II)
   - Minimize value instead of count?
   - With constraints on coin usage?
   - Multiple currencies?

================================================================================
INTERVIEW APPROACH:
================================================================================

1. **Clarify** (2 min):
   - Can coins be used multiple times? Yes
   - Always positive integers? Yes
   - What if impossible? Return -1

2. **Examples** (3 min):
   - Walk through example
   - Identify subproblems

3. **Brute Force** (5 min):
   - Recursion: try all coins at each step
   - Complexity: O(amount^n) - too slow

4. **Optimize** (10 min):
   - Add memoization → O(amount * n)
   - Or bottom-up DP

5. **Code** (15 min):
   - Implement bottom-up (cleaner)
   - Test with examples

6. **Test & Discuss** (5 min):
   - Edge cases: amount=0, impossible case
   - Complexity analysis
   - Possible optimizations

================================================================================
*/
