/*
================================================================================
PROBLEM: Best Time to Buy and Sell Stock with Cooldown (LeetCode #309)
DIFFICULTY: Medium
PATTERN: Dynamic Programming / State Machine
COMPANIES: Amazon, Google, Facebook, Microsoft
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
        
        int sold = 0;
        int held = -prices[0];
        int reset = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            int prevSold = sold;
            
            sold = held + prices[i];
            held = max(held, reset - prices[i]);
            reset = max(reset, prevSold);
        }
        
        return max(sold, reset);
    }
    
    // DP with explicit array
    int maxProfitDP(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        vector<int> buy(n), sell(n), cooldown(n);
        
        buy[0] = -prices[0];
        sell[0] = 0;
        cooldown[0] = 0;
        
        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], cooldown[i-1] - prices[i]);
            sell[i] = buy[i-1] + prices[i];
            cooldown[i] = max(cooldown[i-1], sell[i-1]);
        }
        
        return max(sell[n-1], cooldown[n-1]);
    }
};

int main() {
    Solution sol;
    vector<int> prices1 = {1,2,3,0,2};
    vector<int> prices2 = {1};
    
    cout << "Max profit with cooldown: " << sol.maxProfit(prices1) << endl;
    cout << "Max profit with cooldown: " << sol.maxProfit(prices2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Best Time to Buy and Sell Stock (LeetCode #121)
2. Best Time to Buy and Sell Stock II (LeetCode #122)
3. Best Time to Buy and Sell Stock III (LeetCode #123)
4. Best Time to Buy and Sell Stock IV (LeetCode #188)
5. Best Time to Buy and Sell Stock with Fee (LeetCode #714)
6. House Robber II (LeetCode #213)
7. Delete and Earn (LeetCode #740)
8. Domino and Tromino Tiling (LeetCode #790)
9. Knight Dialer (LeetCode #935)
10. Maximum Alternating Subsequence Sum (LeetCode #1911)
*/
