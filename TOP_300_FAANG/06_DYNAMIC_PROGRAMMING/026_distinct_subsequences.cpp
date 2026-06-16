/*
================================================================================
PROBLEM: Distinct Subsequences (LeetCode #115)
DIFFICULTY: Hard
PATTERN: Dynamic Programming
COMPANIES: Amazon, Google, Facebook
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Empty string t can be found in any string s
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j];
                
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Space optimized version
    int numDistinctOptimized(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i-1] == t[j-1]) {
                    dp[j] += dp[j-1];
                }
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    string s1 = "rabbbit", t1 = "rabbit";
    string s2 = "babgbag", t2 = "bag";
    
    cout << "Distinct subsequences: " << sol.numDistinct(s1, t1) << endl;
    cout << "Distinct subsequences: " << sol.numDistinct(s2, t2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Edit Distance (LeetCode #72)
2. Longest Common Subsequence (LeetCode #1143)
3. Delete Operation for Two Strings (LeetCode #583)
4. Minimum ASCII Delete Sum (LeetCode #712)
5. Number of Matching Subsequences (LeetCode #792)
6. Is Subsequence (LeetCode #392)
7. Shortest Common Supersequence (LeetCode #1092)
8. Count Different Palindromic Subsequences (LeetCode #730)
9. Longest Palindromic Subsequence (LeetCode #516)
10. Subsequence of Size K With Largest Even Sum (LeetCode #2098)
*/
