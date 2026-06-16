/*
================================================================================
PROBLEM: Edit Distance (LeetCode #72)
DIFFICULTY: Hard
PATTERN: 2D Dynamic Programming
COMPANIES: Amazon, Google, Microsoft, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // Base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i-1][j],     // Delete
                        dp[i][j-1],     // Insert
                        dp[i-1][j-1]    // Replace
                    });
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Space Optimized
    int minDistanceOptimized(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> prev(n + 1), curr(n + 1);
        
        for (int j = 0; j <= n; j++) prev[j] = j;
        
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                } else {
                    curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
                }
            }
            swap(prev, curr);
        }
        
        return prev[n];
    }
};

int main() {
    Solution sol;
    cout << "Edit distance (horse, ros): " << sol.minDistance("horse", "ros") << endl;
    cout << "Edit distance (intention, execution): " << sol.minDistance("intention", "execution") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. One Edit Distance (LeetCode #161)
2. Delete Operation for Two Strings (LeetCode #583)
3. Minimum ASCII Delete Sum (LeetCode #712)
4. Longest Common Subsequence (LeetCode #1143)
5. Distinct Subsequences (LeetCode #115)
6. Shortest Common Supersequence (LeetCode #1092)
7. Interleaving String (LeetCode #97)
8. Wildcard Matching (LeetCode #44)
9. Regular Expression Matching (LeetCode #10)
10. Minimum Swaps to Make Sequences Increasing (LeetCode #801)
*/
