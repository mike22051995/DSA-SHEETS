/*
================================================================================
PROBLEM: Perfect Squares (LeetCode #279)
DIFFICULTY: Medium
PATTERN: Dynamic Programming / BFS
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    // DP approach
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        return dp[n];
    }
    
    // Mathematical approach using Lagrange's four-square theorem
    int numSquaresMath(int n) {
        // Check if n is a perfect square
        int sqrtN = sqrt(n);
        if (sqrtN * sqrtN == n) {
            return 1;
        }
        
        // Check if n can be represented as sum of 4 squares (4^a * (8b + 7))
        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }
        
        // Check if n can be represented as sum of 2 squares
        for (int i = 1; i * i <= n; i++) {
            int square = i * i;
            int remainder = n - square;
            int sqrtRem = sqrt(remainder);
            if (sqrtRem * sqrtRem == remainder) {
                return 2;
            }
        }
        
        return 3;
    }
};

int main() {
    Solution sol;
    
    cout << "12 = " << sol.numSquares(12) << " squares" << endl;
    cout << "13 = " << sol.numSquares(13) << " squares" << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Coin Change (LeetCode #322)
2. Ugly Number II (LeetCode #264)
3. Count Primes (LeetCode #204)
4. Valid Perfect Square (LeetCode #367)
5. Sum of Square Numbers (LeetCode #633)
6. Climbing Stairs (LeetCode #70)
7. Fibonacci Number (LeetCode #509)
8. Min Cost Climbing Stairs (LeetCode #746)
9. Minimum Cost For Tickets (LeetCode #983)
10. Combination Sum IV (LeetCode #377)
*/
