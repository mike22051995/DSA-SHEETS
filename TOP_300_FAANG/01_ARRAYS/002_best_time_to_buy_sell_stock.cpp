/*
================================================================================
PROBLEM: Best Time to Buy and Sell Stock (LeetCode #121)
DIFFICULTY: Easy
PATTERN: Sliding Window / Single Pass
COMPANIES: Amazon, Facebook, Microsoft, Bloomberg, Apple, Google
================================================================================

PROBLEM DESCRIPTION:
You are given an array prices where prices[i] is the price of a given stock 
on the ith day.

You want to maximize your profit by choosing a single day to buy one stock 
and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you 
cannot achieve any profit, return 0.

================================================================================
PATTERN RECOGNITION:
Use this pattern when:
1. You need to find maximum difference between two elements
2. The second element must come after the first
3. You're tracking a running minimum or maximum
4. Problem involves "best time" or "optimal point"

Key Indicators:
- Find max/min over a sequence
- Current decision depends on previous values
- Need to track "best so far"
- Single pass optimization possible

================================================================================
INPUT/OUTPUT EXAMPLES:

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), 
profit = 6-1 = 5.
Note: Buying on day 2 and selling on day 1 is not allowed because you 
must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Example 3:
Input: prices = [2,4,1,7,5,11]
Output: 10
Explanation: Buy on day 3 (price = 1) and sell on day 6 (price = 11), 
profit = 11-1 = 10.

================================================================================
EXPLANATION:

Approach 1 - Brute Force (Not Optimal):
- Check every pair (i, j) where j > i
- Calculate profit for each pair
- Time: O(n²), Space: O(1)

Approach 2 - Single Pass (Optimal):
- Keep track of minimum price seen so far
- For each price, calculate profit if we sell today
- Update maximum profit if current profit is greater

Algorithm:
1. Initialize minPrice to infinity (or first element)
2. Initialize maxProfit to 0
3. For each price:
   a. Update maxProfit = max(maxProfit, currentPrice - minPrice)
   b. Update minPrice = min(minPrice, currentPrice)
4. Return maxProfit

Why it works:
- We always buy at the lowest price seen so far
- For each day, we check if selling today gives us better profit
- Only one pass needed through the array

Time Complexity: O(n) - single pass
Space Complexity: O(1) - only two variables

================================================================================
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Optimal Solution - Single Pass
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            // Update max profit if selling today gives better result
            maxProfit = max(maxProfit, price - minPrice);
            
            // Update minimum price seen so far
            minPrice = min(minPrice, price);
        }
        
        return maxProfit;
    }
    
    // Alternative Implementation - More Explicit
    int maxProfitVerbose(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            int currentProfit = prices[i] - minPrice;
            
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
            
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
        }
        
        return maxProfit;
    }
    
    // Brute Force - For Comparison
    int maxProfitBruteForce(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        
        return maxProfit;
    }
};

// Test function
void runTest(vector<int> prices, string testName) {
    Solution sol;
    int result = sol.maxProfit(prices);
    
    cout << testName << ": ";
    cout << "prices = [";
    for (int i = 0; i < prices.size(); i++) {
        cout << prices[i];
        if (i < prices.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Maximum Profit: " << result << endl;
    cout << "-------------------" << endl;
}

int main() {
    // Test Case 1: Normal case
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    runTest(prices1, "Test 1");
    
    // Test Case 2: Decreasing prices
    vector<int> prices2 = {7, 6, 4, 3, 1};
    runTest(prices2, "Test 2");
    
    // Test Case 3: Best profit at end
    vector<int> prices3 = {2, 4, 1, 7, 5, 11};
    runTest(prices3, "Test 3");
    
    // Test Case 4: Increasing prices
    vector<int> prices4 = {1, 2, 3, 4, 5};
    runTest(prices4, "Test 4");
    
    return 0;
}

/*
================================================================================
SIMILAR LEETCODE PROBLEMS:
================================================================================
1. Best Time to Buy and Sell Stock II (LeetCode #122) - Medium
   - Multiple transactions allowed
   - Add all positive differences

2. Best Time to Buy and Sell Stock III (LeetCode #123) - Hard
   - At most two transactions
   - Use dynamic programming

3. Best Time to Buy and Sell Stock IV (LeetCode #188) - Hard
   - At most k transactions
   - DP with state machine

4. Best Time to Buy and Sell Stock with Cooldown (LeetCode #309) - Medium
   - Must wait one day after selling
   - State machine DP

5. Best Time to Buy and Sell Stock with Transaction Fee (LeetCode #714) - Medium
   - Fee charged for each transaction
   - Track buy and sell states

6. Maximum Subarray (LeetCode #53) - Medium
   - Similar single pass pattern
   - Find max sum subarray

7. Maximum Difference Between Increasing Elements (LeetCode #2016) - Easy
   - Direct variation of this problem

8. Minimum Difference Between Highest and Lowest of K Scores (LeetCode #1984)
   - Similar min/max tracking

9. Stock Price Fluctuation (LeetCode #2034) - Medium
   - Real-time stock price updates

10. Maximum Profit in Job Scheduling (LeetCode #1235) - Hard
    - Extended scheduling problem

================================================================================
FOLLOW-UP VARIATIONS:
================================================================================

1. What if you can make multiple transactions?
   - Buy and sell multiple times (no overlap)
   - Sum all profitable consecutive day differences

2. What if there's a transaction fee?
   - Subtract fee from each transaction profit
   - Use DP to track states

3. What if you can only make k transactions?
   - Use 2D DP: dp[i][j] = max profit with i transactions up to day j
   - Optimize space to O(k)

4. What if there's a cooldown period?
   - After selling, must wait before buying again
   - Use state machine: buy, sell, cooldown

5. What if you want to find actual buy/sell days?
   - Track indices when updating minPrice and maxProfit
   - Return (buyDay, sellDay) instead of profit value

================================================================================
KEY INSIGHTS:
================================================================================

1. Greedy Approach Works:
   - Always buy at minimum price seen so far
   - Check profit for selling at each day

2. No Need to Store History:
   - Only need current min price and max profit
   - O(1) space is sufficient

3. Order Matters:
   - Update maxProfit before updating minPrice
   - Prevents selling on same day as buying

4. Edge Cases:
   - Empty array or single element → return 0
   - All decreasing prices → return 0
   - All increasing prices → last - first

5. Pattern Recognition:
   - This is a special case of Maximum Subarray
   - Can be solved with Kadane's algorithm variation

================================================================================
INTERVIEW TIPS:
================================================================================

1. Start by explaining brute force O(n²) approach
2. Identify that we need to track minimum seen so far
3. Explain why single pass O(n) is sufficient
4. Mention the order of operations matters
5. Discuss edge cases (empty, single element, all decreasing)
6. Be ready to extend to multiple transactions variant
7. Can draw price graph to visualize solution

Common Mistakes to Avoid:
- Updating minPrice before checking maxProfit
- Returning negative profit (should be 0)
- Not handling empty array
- Trying to track all combinations (unnecessary)

================================================================================
*/
