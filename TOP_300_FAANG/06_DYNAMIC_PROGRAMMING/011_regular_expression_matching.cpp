/*
================================================================================
PROBLEM: Regular Expression Matching (LeetCode #10)
DIFFICULTY: Hard
PATTERN: Dynamic Programming (String Matching)
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b*, a*b*c*
        for (int j = 2; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    // Zero occurrence of character before *
                    dp[i][j] = dp[i][j-2];
                    
                    // One or more occurrences
                    if (p[j-2] == s[i-1] || p[j-2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                } else if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    cout << "Match (aa, a): " << (sol.isMatch("aa", "a") ? "true" : "false") << endl;
    cout << "Match (aa, a*): " << (sol.isMatch("aa", "a*") ? "true" : "false") << endl;
    cout << "Match (ab, .*): " << (sol.isMatch("ab", ".*") ? "true" : "false") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Wildcard Matching (LeetCode #44)
2. Edit Distance (LeetCode #72)
3. Longest Common Subsequence (LeetCode #1143)
4. Interleaving String (LeetCode #97)
5. Distinct Subsequences (LeetCode #115)
6. String Compression II (LeetCode #1531)
7. Shortest Way to Form String (LeetCode #1055)
8. Number of Matching Subsequences (LeetCode #792)
9. Is Subsequence (LeetCode #392)
10. Minimum ASCII Delete Sum (LeetCode #712)
*/
