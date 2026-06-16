/*
================================================================================
PROBLEM: Interleaving String (LeetCode #97)
DIFFICULTY: Medium
PATTERN: 2D Dynamic Programming
COMPANIES: Amazon, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        
        if (m + n != s3.length()) return false;
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        // Initialize first column
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        
        // Initialize first row
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }
        
        // Fill the rest
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                           (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        
        return dp[m][n];
    }
    
    // Space optimized
    bool isInterleaveOptimized(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        
        if (m + n != s3.length()) return false;
        
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j-1] && s2[j-1] == s3[j-1];
        }
        
        for (int i = 1; i <= m; i++) {
            dp[0] = dp[0] && s1[i-1] == s3[i-1];
            
            for (int j = 1; j <= n; j++) {
                dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) ||
                        (dp[j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    
    cout << "Is interleave: " << (sol.isInterleave(s1, s2, s3) ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Edit Distance (LeetCode #72)
2. Scramble String (LeetCode #87)
3. Longest Common Subsequence (LeetCode #1143)
4. Distinct Subsequences (LeetCode #115)
5. Wildcard Matching (LeetCode #44)
6. Regular Expression Matching (LeetCode #10)
7. Minimum ASCII Delete Sum (LeetCode #712)
8. Delete Operation for Two Strings (LeetCode #583)
9. Longest Palindromic Subsequence (LeetCode #516)
10. Shortest Common Supersequence (LeetCode #1092)
*/
