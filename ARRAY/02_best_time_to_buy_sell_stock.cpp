/*
PROBLEM: Best Time to Buy and Sell Stock
Difficulty: Easy
Pattern: Greedy, Sliding Window

DESCRIPTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any 
profit, return 0.

EXPLANATION:
We track the minimum price seen so far and calculate the profit if we sell at current price.
We update the maximum profit whenever we find a better profit opportunity.
This is a one-pass greedy algorithm.

Time Complexity: O(n)
Space Complexity: O(1)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: No profit can be made, so return 0

Example 3:
Input: prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            // Update max profit if selling at current price gives better profit
            maxProfit = max(maxProfit, prices[i] - minPrice);
            
            // Update minimum price seen so far
            minPrice = min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test 1: " << solution.maxProfit(prices1) << endl;
    
    // Test Case 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test 2: " << solution.maxProfit(prices2) << endl;
    
    // Test Case 3
    vector<int> prices3 = {2, 4, 1};
    cout << "Test 3: " << solution.maxProfit(prices3) << endl;
    
    return 0;
}
