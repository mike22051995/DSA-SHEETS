/*
PROBLEM: Coin Change
Difficulty: Medium
Pattern: Unbounded Knapsack, Minimum Coins

DESCRIPTION:
You are given an integer array coins representing coins of different denominations and an integer 
amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money 
cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

INPUT:
coins = [1, 2, 5], amount = 11

OUTPUT:
3
Explanation: 11 = 5 + 5 + 1

TIME COMPLEXITY: O(amount * n) where n = number of coins
SPACE COMPLEXITY: O(amount)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum coins needed to make amount i
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // 0 coins needed for amount 0
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Input: coins = [1, 2, 5], amount = " << amount1 << endl;
    cout << "Output: " << sol.coinChange(coins1, amount1) << endl << endl;
    
    // Test Case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Input: coins = [2], amount = " << amount2 << endl;
    cout << "Output: " << sol.coinChange(coins2, amount2) << endl << endl;
    
    // Test Case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Input: coins = [1], amount = " << amount3 << endl;
    cout << "Output: " << sol.coinChange(coins3, amount3) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. dp[i] represents minimum coins needed to make amount i
2. Base case: dp[0] = 0 (0 coins for amount 0)
3. For each amount i, try using each coin
4. If coin value <= i, we can use it
5. dp[i] = min(dp[i], dp[i - coin] + 1)
6. If dp[amount] is still INT_MAX, return -1 (impossible)

Example: coins = [1,2,5], amount = 11
- dp[0] = 0
- dp[1] = 1 (use 1)
- dp[2] = 1 (use 2)
- dp[5] = 1 (use 5)
- dp[10] = 2 (5+5)
- dp[11] = 3 (5+5+1)

KEY LEARNING:
- Unbounded knapsack pattern (unlimited use of items)
- Build solution bottom-up for all amounts
- Similar to: Coin Change 2, Perfect Squares, Minimum Cost for Tickets
- Think about what subproblems you need to solve
*/
