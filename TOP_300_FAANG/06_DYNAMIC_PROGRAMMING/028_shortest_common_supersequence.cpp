/*
================================================================================
PROBLEM: Shortest Common Supersequence (LeetCode #1092)
DIFFICULTY: Hard
PATTERN: Dynamic Programming / LCS
COMPANIES: Amazon, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        
        // Build LCS DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Build result by tracing back
        string result = "";
        int i = m, j = n;
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }
        
        while (i > 0) {
            result += str1[i - 1];
            i--;
        }
        
        while (j > 0) {
            result += str2[j - 1];
            j--;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string str1 = "abac";
    string str2 = "cab";
    
    cout << "Shortest common supersequence: " << sol.shortestCommonSupersequence(str1, str2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Longest Common Subsequence (LeetCode #1143)
2. Edit Distance (LeetCode #72)
3. Minimum ASCII Delete Sum (LeetCode #712)
4. Delete Operation for Two Strings (LeetCode #583)
5. Distinct Subsequences (LeetCode #115)
6. Is Subsequence (LeetCode #392)
7. Longest Palindromic Subsequence (LeetCode #516)
8. Interleaving String (LeetCode #97)
9. Regular Expression Matching (LeetCode #10)
10. Wildcard Matching (LeetCode #44)
*/
