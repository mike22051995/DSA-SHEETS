/*
================================================================================
PROBLEM: Best Time to Buy and Sell Stock II (LeetCode #122)
DIFFICULTY: Medium
PATTERN: Greedy / Dynamic Programming
COMPANIES: Amazon, Microsoft, Google, Facebook, Bloomberg
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Greedy approach - O(n) time, O(1) space
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        
        return profit;
    }
    
    // DP approach
    int maxProfitDP(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // dp[i][0] = max profit on day i with no stock
        // dp[i][1] = max profit on day i with stock
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        
        return dp[n-1][0];
    }
};

int main() {
    Solution sol;
    vector<int> prices1 = {7,1,5,3,6,4};
    vector<int> prices2 = {1,2,3,4,5};
    
    cout << "Max profit (multiple transactions): " << sol.maxProfit(prices1) << endl;
    cout << "Max profit (multiple transactions): " << sol.maxProfit(prices2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Best Time to Buy and Sell Stock (LeetCode #121)
2. Best Time to Buy and Sell Stock III (LeetCode #123)
3. Best Time to Buy and Sell Stock IV (LeetCode #188)
4. Best Time to Buy and Sell Stock with Cooldown (LeetCode #309)
5. Best Time to Buy and Sell Stock with Fee (LeetCode #714)
6. Maximum Subarray (LeetCode #53)
7. Jump Game (LeetCode #55)
8. Jump Game II (LeetCode #45)
9. Gas Station (LeetCode #134)
10. Wiggle Subsequence (LeetCode #376)
*/
