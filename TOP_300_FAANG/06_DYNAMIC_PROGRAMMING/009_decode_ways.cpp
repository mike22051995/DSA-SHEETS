/*
================================================================================
PROBLEM: Decode Ways (LeetCode #91)
DIFFICULTY: Medium
PATTERN: Dynamic Programming
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            // Single digit
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            
            // Two digits
            int twoDigit = stoi(s.substr(i-2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
    
    // Space Optimized
    int numDecodingsOptimized(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int prev2 = 1, prev1 = 1;
        
        for (int i = 2; i <= s.length(); i++) {
            int curr = 0;
            
            if (s[i-1] != '0') {
                curr += prev1;
            }
            
            int twoDigit = stoi(s.substr(i-2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                curr += prev2;
            }
            
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

int main() {
    Solution sol;
    cout << "Decode ways (12): " << sol.numDecodings("12") << endl;
    cout << "Decode ways (226): " << sol.numDecodings("226") << endl;
    cout << "Decode ways (06): " << sol.numDecodings("06") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Decode Ways II (LeetCode #639) - With wildcards
2. Climbing Stairs (LeetCode #70)
3. Fibonacci Number (LeetCode #509)
4. Count and Say (LeetCode #38)
5. Integer to English Words (LeetCode #273)
6. Number of Ways to Decode (Variations)
7. Knight Dialer (LeetCode #935)
8. Domino and Tromino Tiling (LeetCode #790)
9. Unique Binary Search Trees (LeetCode #96)
10. Unique Paths (LeetCode #62)
*/
