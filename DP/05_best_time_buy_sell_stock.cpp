/*
PROBLEM: Best Time to Buy and Sell Stock
Difficulty: Easy
Pattern: 1D DP, Max Profit with Single Transaction

DESCRIPTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any 
profit, return 0.

INPUT:
prices = [7, 1, 5, 3, 6, 4]

OUTPUT:
5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Method 1: Track minimum price and maximum profit
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            // Update minimum price seen so far
            minPrice = min(minPrice, prices[i]);
            
            // Calculate profit if we sell at current price
            int profit = prices[i] - minPrice;
            
            // Update maximum profit
            maxProfit = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
    
    // Method 2: DP approach
    int maxProfitDP(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int minPriceSoFar = prices[0];
        int maxProfitSoFar = 0;
        
        for (int i = 1; i < n; i++) {
            maxProfitSoFar = max(maxProfitSoFar, prices[i] - minPriceSoFar);
            minPriceSoFar = min(minPriceSoFar, prices[i]);
        }
        
        return maxProfitSoFar;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Input: prices = [7, 1, 5, 3, 6, 4]" << endl;
    cout << "Output: " << sol.maxProfit(prices1) << endl;
    cout << "Output (DP): " << sol.maxProfitDP(prices1) << endl << endl;
    
    // Test Case 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Input: prices = [7, 6, 4, 3, 1]" << endl;
    cout << "Output: " << sol.maxProfit(prices2) << endl;
    cout << "Output (DP): " << sol.maxProfitDP(prices2) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. Keep track of minimum price seen so far
2. For each day, calculate profit if we sell today
3. Profit = current price - minimum price so far
4. Update maximum profit as we iterate
5. Only one pass needed through the array

KEY LEARNING:
- Single transaction stock problem
- Track minimum buy price and maximum profit simultaneously
- Greedy approach works here (buy at lowest, sell at highest after)
- Foundation for multi-transaction stock problems
*/
