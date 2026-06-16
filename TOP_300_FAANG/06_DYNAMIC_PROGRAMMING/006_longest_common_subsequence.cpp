/*
================================================================================
PROBLEM: Longest Common Subsequence (LeetCode #1143)
DIFFICULTY: Medium
PATTERN: 2D Dynamic Programming
COMPANIES: Amazon, Google, Facebook, Microsoft
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Space Optimized
    int longestCommonSubsequenceOptimized(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    curr[j] = prev[j-1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            swap(prev, curr);
        }
        
        return prev[n];
    }
};

int main() {
    Solution sol;
    cout << "LCS: " << sol.longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Edit Distance (LeetCode #72)
2. Uncrossed Lines (LeetCode #1035)
3. Shortest Common Supersequence (LeetCode #1092)
4. Delete Operation for Two Strings (LeetCode #583)
5. Minimum ASCII Delete Sum (LeetCode #712)
6. Longest Palindromic Subsequence (LeetCode #516)
7. Distinct Subsequences (LeetCode #115)
8. Interleaving String (LeetCode #97)
9. Regular Expression Matching (LeetCode #10)
10. Wildcard Matching (LeetCode #44)
*/
