/*
================================================================================
PROBLEM: Longest Palindromic Subsequence (LeetCode #516)
DIFFICULTY: Medium
PATTERN: Dynamic Programming
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Every single character is a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill the table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
    
    // Space optimized - O(n) space
    int longestPalindromeSubseqOptimized(string s) {
        int n = s.length();
        vector<int> dp(n, 1);
        
        for (int i = n - 2; i >= 0; i--) {
            int prev = 0;
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = prev + 2;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        
        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    string s1 = "bbbab";
    string s2 = "cbbd";
    
    cout << "Longest palindromic subsequence in \"" << s1 << "\": " << sol.longestPalindromeSubseq(s1) << endl;
    cout << "Longest palindromic subsequence in \"" << s2 << "\": " << sol.longestPalindromeSubseq(s2) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Longest Palindromic Substring (LeetCode #5)
2. Palindromic Substrings (LeetCode #647)
3. Longest Common Subsequence (LeetCode #1143)
4. Minimum Insertion Steps (LeetCode #1312)
5. Maximum Length of Repeated Subarray (LeetCode #718)
6. Delete Operation for Two Strings (LeetCode #583)
7. Count Different Palindromic Subsequences (LeetCode #730)
8. Palindrome Partitioning II (LeetCode #132)
9. Longest Increasing Subsequence (LeetCode #300)
10. Distinct Subsequences (LeetCode #115)
*/
