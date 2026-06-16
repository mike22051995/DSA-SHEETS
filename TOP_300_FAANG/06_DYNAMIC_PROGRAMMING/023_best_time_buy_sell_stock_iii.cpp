/*
================================================================================
PROBLEM: Best Time to Buy and Sell Stock III (LeetCode #123)
DIFFICULTY: Hard
PATTERN: Dynamic Programming
COMPANIES: Amazon, Facebook, Google, Microsoft, Bloomberg
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        
        for (int price : prices) {
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }
        
        return sell2;
    }
    
    // DP approach with explicit states
    int maxProfitDP(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(5, 0));
        // States: 0 = no transaction, 1 = first buy, 2 = first sell, 3 = second buy, 4 = second sell
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = INT_MIN;
        dp[0][3] = INT_MIN;
        dp[0][4] = INT_MIN;
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }
        
        return max({dp[n-1][0], dp[n-1][2], dp[n-1][4]});
    }
};

int main() {
    Solution sol;
    vector<int> prices1 = {3,3,5,0,0,3,1,4};
    vector<int> prices2 = {1,2,3,4,5};
    
    cout << "Max profit (at most 2 transactions): " << sol.maxProfit(prices1) << endl;
    cout << "Max profit (at most 2 transactions): " << sol.maxProfit(prices2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Best Time to Buy and Sell Stock (LeetCode #121)
2. Best Time to Buy and Sell Stock II (LeetCode #122)
3. Best Time to Buy and Sell Stock IV (LeetCode #188)
4. Best Time to Buy and Sell Stock with Cooldown (LeetCode #309)
5. Best Time to Buy and Sell Stock with Fee (LeetCode #714)
6. Maximum Alternating Subsequence Sum (LeetCode #1911)
7. Maximum Profit in Job Scheduling (LeetCode #1235)
8. Paint House II (LeetCode #265)
9. Maximum Earnings From Taxi (LeetCode #2008)
10. Number of Ways to Earn Points (LeetCode #2585)
*/
