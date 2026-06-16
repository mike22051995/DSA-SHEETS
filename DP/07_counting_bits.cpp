/*
PROBLEM: Counting Bits
Difficulty: Easy
Pattern: 1D DP, Bit Manipulation

DESCRIPTION:
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.

INPUT:
n = 5

OUTPUT:
[0, 1, 1, 2, 1, 2]
Explanation:
0 --> 0 (0 ones)
1 --> 1 (1 one)
2 --> 10 (1 one)
3 --> 11 (2 ones)
4 --> 100 (1 one)
5 --> 101 (2 ones)

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) for result array
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: Using DP with bit manipulation
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            // If i is even: dp[i] = dp[i/2] (right shift removes a 0)
            // If i is odd: dp[i] = dp[i/2] + 1 (right shift removes a 1)
            // This can be written as: dp[i] = dp[i >> 1] + (i & 1)
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
    
    // Method 2: Using i & (i-1) pattern
    vector<int> countBitsAlternate(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            // i & (i-1) removes the rightmost set bit
            // So count for i = count for (i & (i-1)) + 1
            dp[i] = dp[i & (i - 1)] + 1;
        }
        
        return dp;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 5;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: [";
    vector<int> result1 = sol.countBits(n1);
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test Case 2
    int n2 = 8;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: [";
    vector<int> result2 = sol.countBitsAlternate(n2);
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}

/*
EXPLANATION:
Method 1 (Right Shift):
1. For any number i, i >> 1 is i divided by 2
2. If i is even, rightmost bit is 0, so dp[i] = dp[i/2]
3. If i is odd, rightmost bit is 1, so dp[i] = dp[i/2] + 1
4. Combined: dp[i] = dp[i >> 1] + (i & 1)

Method 2 (Remove Rightmost Bit):
1. i & (i-1) removes the rightmost set bit
2. dp[i] = dp[i & (i-1)] + 1

KEY LEARNING:
- DP with bit manipulation
- Reuse previously computed results
- Two different recurrence relations possible
- Understanding bit operations is crucial for optimization
*/
