/*
PROBLEM: Coin Change II - Number of Ways (LeetCode 518)
DIFFICULTY: Medium
PATTERN: Unbounded Knapsack - Count Ways

DESCRIPTION:
You are given an integer array coins representing coins of different denominations 
and an integer amount. Return the number of combinations that make up that amount.
You may assume you have infinite number of each coin.

EXAMPLE:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: 
1+1+1+1+1
1+1+1+2
1+2+2
5

Input: amount = 3, coins = [2]
Output: 0

Input: amount = 10, coins = [10]
Output: 1

TIME COMPLEXITY: O(n * amount)
SPACE COMPLEXITY: O(n * amount), can be optimized to O(amount)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: 2D DP
    int change2D(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        // Base case: 1 way to make amount 0 (use no coins)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int amt = 1; amt <= amount; amt++) {
                // Don't use current coin
                dp[i][amt] = dp[i-1][amt];
                
                // Use current coin (if possible)
                if (coins[i-1] <= amt) {
                    // Add ways using current coin
                    // Note: dp[i][amt - coins[i-1]] not dp[i-1]
                    // Because we can use same coin multiple times
                    dp[i][amt] += dp[i][amt - coins[i-1]];
                }
            }
        }
        
        return dp[n][amount];
    }
    
    // Approach 2: 1D DP Space Optimized (MOST IMPORTANT)
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;  // Base case: 1 way to make 0
        
        // For each coin
        for (int coin : coins) {
            // Update all amounts that can use this coin
            for (int amt = coin; amt <= amount; amt++) {
                dp[amt] += dp[amt - coin];
            }
        }
        
        return dp[amount];
    }
    
    // Wrong approach: This counts permutations, not combinations!
    int changeWrong(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        // WRONG: Iterating amount first
        for (int amt = 1; amt <= amount; amt++) {
            for (int coin : coins) {
                if (coin <= amt) {
                    dp[amt] += dp[amt - coin];
                }
            }
        }
        
        return dp[amount];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    int amount1 = 5;
    vector<int> coins1 = {1, 2, 5};
    
    cout << "Amount: " << amount1 << endl;
    cout << "Coins: "; for(int c : coins1) cout << c << " "; cout << endl;
    cout << "Number of ways (2D DP): " << sol.change2D(amount1, coins1) << endl;
    cout << "Number of ways (1D DP): " << sol.change(amount1, coins1) << endl;
    cout << "Wrong approach (permutations): " << sol.changeWrong(amount1, coins1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    int amount2 = 3;
    vector<int> coins2 = {2};
    
    cout << "Amount: " << amount2 << endl;
    cout << "Coins: "; for(int c : coins2) cout << c << " "; cout << endl;
    cout << "Number of ways: " << sol.change(amount2, coins2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    int amount3 = 10;
    vector<int> coins3 = {10};
    cout << "Amount: " << amount3 << endl;
    cout << "Number of ways: " << sol.change(amount3, coins3) << endl;
    
    return 0;
}

/*
EXPLANATION:

COIN CHANGE II - Count Combinations (NOT Permutations!)

State Definition:
dp[amt] = number of ways to make amount 'amt'

Base Case:
dp[0] = 1 (one way to make 0: use no coins)

Recurrence:
dp[amt] = sum of all dp[amt - coin] for each coin

CRITICAL DIFFERENCE - Order of Loops:

COMBINATIONS (What we want):
for each coin:
    for each amount:
        update dp[amount]

This ensures [1,2] and [2,1] are counted as SAME combination.

PERMUTATIONS (Wrong!):
for each amount:
    for each coin:
        update dp[amount]

This counts [1,2] and [2,1] as DIFFERENT permutations.

EXAMPLE:
amount = 5, coins = [1, 2, 5]

After coin 1: dp = [1, 1, 1, 1, 1, 1]
               (only using 1s: 1, 1+1, 1+1+1, ...)

After coin 2: dp = [1, 1, 2, 2, 3, 3]
               (can now use 2s: 2, 2+2, 1+2+2, ...)

After coin 5: dp = [1, 1, 2, 2, 3, 4]
               (can now use 5: just 5, or 1+1+1+1+1+2, ...)

WHY THIS ORDER WORKS:
When we process coin 2, all previous amounts only used coin 1.
So we're adding NEW ways using coin 2, not duplicating.

COMPARISON WITH COIN CHANGE I:
- Coin Change I (LC 322): Minimum coins (optimization)
- Coin Change II (LC 518): Count ways (counting)

Both are unbounded knapsack variants!

INTERVIEW TIP:
Always clarify: Combinations or Permutations?
- Combinations: Iterate coins first
- Permutations: Iterate amount first

OUTPUT:
Test Case 1:
Amount: 5
Coins: 1 2 5
Number of ways (2D DP): 4
Number of ways (1D DP): 4
Wrong approach (permutations): 9

Test Case 2:
Amount: 3
Coins: 2
Number of ways: 0

Test Case 3:
Amount: 10
Number of ways: 1
*/
