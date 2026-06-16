/*
PROBLEM: Best Time to Buy and Sell Stock II (LeetCode 122)
DIFFICULTY: Easy
PATTERN: Peak Valley Approach / Sum of All Positive Differences

DESCRIPTION:
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share 
of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

INPUT:
- prices: array of integers representing stock prices on each day

OUTPUT:
- Maximum profit achievable

APPROACH:
Greedy insight: Capture every upward movement!
If price increases from day i to i+1, we can capture that profit by buying at i and selling at i+1.
Simply sum all positive differences between consecutive days.

WHY GREEDY WORKS:
Any profit between two days can be decomposed into sum of daily profits.
Example: profit from day 1 to day 4 = (p[2]-p[1]) + (p[3]-p[2]) + (p[4]-p[3])
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        
        // Add all positive differences
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        
        return maxProfit;
    }
    
    // Alternative approach: Peak-Valley method (same result)
    int maxProfitPeakValley(vector<int>& prices) {
        int maxProfit = 0;
        int i = 0;
        int n = prices.size();
        
        while (i < n - 1) {
            // Find valley (local minimum)
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            int valley = prices[i];
            
            // Find peak (local maximum)
            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            int peak = prices[i];
            
            maxProfit += peak - valley;
        }
        
        return maxProfit;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test 1 - Prices: [7,1,5,3,6,4]" << endl;
    cout << "Output: " << sol.maxProfit(prices1) << endl;
    cout << "Expected: 7 (Buy at 1, sell at 5: +4, Buy at 3, sell at 6: +3)" << endl << endl;
    
    // Test Case 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Test 2 - Prices: [1,2,3,4,5]" << endl;
    cout << "Output: " << sol.maxProfit(prices2) << endl;
    cout << "Expected: 4 (Buy at 1, sell at 5)" << endl << endl;
    
    // Test Case 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Test 3 - Prices: [7,6,4,3,1]" << endl;
    cout << "Output: " << sol.maxProfit(prices3) << endl;
    cout << "Expected: 0 (No profitable transaction)" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is number of days
SPACE COMPLEXITY: O(1)

KEY LEARNING:
- Greedy works when we can decompose problem into independent subproblems
- "Capture every upward trend" is a powerful greedy insight for stock problems
- Multiple approaches can lead to same greedy solution
- This pattern appears in many optimization problems
*/
