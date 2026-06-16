/*
================================================================================
PROBLEM: Wildcard Matching (LeetCode #44)
DIFFICULTY: Hard
PATTERN: Dynamic Programming
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        // Handle patterns with leading '*'
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Space optimized version
    bool isMatchOptimized(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<bool> prev(n + 1, false);
        vector<bool> curr(n + 1, false);
        
        prev[0] = true;
        
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                prev[j] = prev[j - 1];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            curr[0] = false;
            
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            
            swap(prev, curr);
        }
        
        return prev[n];
    }
};

int main() {
    Solution sol;
    
    cout << "aa vs a: " << (sol.isMatch("aa", "a") ? "true" : "false") << endl;
    cout << "aa vs *: " << (sol.isMatch("aa", "*") ? "true" : "false") << endl;
    cout << "cb vs ?a: " << (sol.isMatch("cb", "?a") ? "true" : "false") << endl;
    cout << "adceb vs *a*b: " << (sol.isMatch("adceb", "*a*b") ? "true" : "false") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Regular Expression Matching (LeetCode #10)
2. Edit Distance (LeetCode #72)
3. Minimum ASCII Delete Sum (LeetCode #712)
4. Is Subsequence (LeetCode #392)
5. Distinct Subsequences (LeetCode #115)
6. Interleaving String (LeetCode #97)
7. Longest Common Subsequence (LeetCode #1143)
8. Delete Operation for Two Strings (LeetCode #583)
9. Shortest Common Supersequence (LeetCode #1092)
10. Check if String Is Transformable (LeetCode #1585)
*/
