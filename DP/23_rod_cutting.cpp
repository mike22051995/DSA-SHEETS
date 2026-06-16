/*
PROBLEM: Rod Cutting Problem (LeetCode similar concepts)
DIFFICULTY: Medium
PATTERN: Unbounded Knapsack Variant

DESCRIPTION:
Given a rod of length n and an array of prices where prices[i] denotes the value of 
a piece of length i+1. Determine the maximum value obtainable by cutting up the rod 
and selling the pieces.
 
EXAMPLE:
Input:
length = 8
prices = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: Cut into pieces of length 2 and 6 (5 + 17 = 22) OR
pieces of length 2, 2, 2, 2 (5+5+5+5=20) 
Best: length 2 and length 6: prices[1] + prices[5] = 5 + 17 = 22

Input:
length = 4
prices = [2, 5, 7, 8]
Output: 10
Explanation: Cut into 2 pieces of length 2 each (5 + 5 = 10)

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Top-down with memoization
    int cutRodHelper(vector<int>& prices, int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        
        int maxVal = INT_MIN;
        
        // Try all possible first cuts
        for (int i = 1; i <= n; i++) {
            // Cut of length i costs prices[i-1]
            maxVal = max(maxVal, prices[i-1] + cutRodHelper(prices, n-i, dp));
        }
        
        return dp[n] = maxVal;
    }
    
    int cutRodMemo(vector<int>& prices, int n) {
        vector<int> dp(n+1, -1);
        return cutRodHelper(prices, n, dp);
    }
    
    // Approach 2: Bottom-up DP (BEST)
    int cutRod(vector<int>& prices, int n) {
        vector<int> dp(n+1, 0);
        
        // For each rod length
        for (int len = 1; len <= n; len++) {
            int maxVal = INT_MIN;
            
            // Try all possible first cuts
            for (int cut = 1; cut <= len; cut++) {
                // Make first cut of length 'cut'
                // Add its price + optimal solution for remaining length
                maxVal = max(maxVal, prices[cut-1] + dp[len-cut]);
            }
            
            dp[len] = maxVal;
        }
        
        return dp[n];
    }
    
    // Approach 3: Using Unbounded Knapsack concept
    int cutRodUnbounded(vector<int>& prices, int n) {
        vector<int> lengths;
        for (int i = 1; i <= n; i++) {
            lengths.push_back(i);
        }
        
        // Now it's unbounded knapsack with capacity = n
        vector<int> dp(n+1, 0);
        
        for (int i = 0; i < prices.size(); i++) {
            for (int len = lengths[i]; len <= n; len++) {
                dp[len] = max(dp[len], prices[i] + dp[len - lengths[i]]);
            }
        }
        
        return dp[n];
    }
    
    // Print the cuts
    void printCuts(vector<int>& prices, int n) {
        vector<int> dp(n+1, 0);
        vector<int> cuts(n+1, 0);  // Store the first cut
        
        for (int len = 1; len <= n; len++) {
            int maxVal = INT_MIN;
            int bestCut = 0;
            
            for (int cut = 1; cut <= len; cut++) {
                int val = prices[cut-1] + dp[len-cut];
                if (val > maxVal) {
                    maxVal = val;
                    bestCut = cut;
                }
            }
            
            dp[len] = maxVal;
            cuts[len] = bestCut;
        }
        
        cout << "Cuts: ";
        int remaining = n;
        while (remaining > 0) {
            cout << cuts[remaining] << " ";
            remaining -= cuts[remaining];
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    vector<int> prices1 = {1, 5, 8, 9, 10, 17, 17, 20};
    int length1 = 8;
    
    cout << "Rod length: " << length1 << endl;
    cout << "Prices: "; for(int p : prices1) cout << p << " "; cout << endl;
    cout << "Maximum value (Bottom-up): " << sol.cutRod(prices1, length1) << endl;
    cout << "Maximum value (Memoization): " << sol.cutRodMemo(prices1, length1) << endl;
    cout << "Maximum value (Unbounded): " << sol.cutRodUnbounded(prices1, length1) << endl;
    sol.printCuts(prices1, length1);
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    vector<int> prices2 = {2, 5, 7, 8};
    int length2 = 4;
    
    cout << "Rod length: " << length2 << endl;
    cout << "Prices: "; for(int p : prices2) cout << p << " "; cout << endl;
    cout << "Maximum value: " << sol.cutRod(prices2, length2) << endl;
    sol.printCuts(prices2, length2);
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    vector<int> prices3 = {3, 5, 8, 9, 10, 17, 17, 20};
    int length3 = 8;
    cout << "Rod length: " << length3 << endl;
    cout << "Maximum value: " << sol.cutRod(prices3, length3) << endl;
    
    return 0;
}

/*
EXPLANATION:

ROD CUTTING - Classic Unbounded Knapsack Variant

Problem: Given rod of length n, cut it to maximize profit.
Each piece of length i has price prices[i-1].

State Definition:
dp[len] = maximum value obtainable from rod of length len

Recurrence:
dp[len] = max(prices[cut-1] + dp[len-cut]) for all cut from 1 to len

Where:
- prices[cut-1] = price of piece of length 'cut'
- dp[len-cut] = optimal solution for remaining rod

WHY IT'S UNBOUNDED KNAPSACK:
- Can make multiple cuts of same length
- Similar to using same item multiple times
- Length = capacity, prices = values

EXAMPLE TRACE:
prices = [1, 5, 8, 9]  (for lengths 1, 2, 3, 4)
length = 4

dp[0] = 0
dp[1] = prices[0] + dp[0] = 1
dp[2] = max(prices[0] + dp[1], prices[1] + dp[0]) = max(1+1, 5+0) = 5
dp[3] = max(prices[0] + dp[2], prices[1] + dp[1], prices[2] + dp[0])
      = max(1+5, 5+1, 8+0) = max(6, 6, 8) = 8
dp[4] = max(prices[0] + dp[3], prices[1] + dp[2], prices[2] + dp[1], prices[3] + dp[0])
      = max(1+8, 5+5, 8+1, 9+0) = max(9, 10, 9, 9) = 10

So cut into two pieces of length 2 each!

VARIATIONS:
- Minimum cost to cut rod
- Cut with limited number of cuts
- Maximum cuts with constraint

INTERVIEW TIP:
This is a CLASSIC DP problem! Know it well.
Often appears as:
- Maximize profit by cutting
- Ribbon cutting
- Selling pieces optimally

OUTPUT:
Test Case 1:
Rod length: 8
Prices: 1 5 8 9 10 17 17 20
Maximum value (Bottom-up): 22
Maximum value (Memoization): 22
Maximum value (Unbounded): 22
Cuts: 2 6

Test Case 2:
Rod length: 4
Prices: 2 5 7 8
Maximum value: 10
Cuts: 2 2
*/
