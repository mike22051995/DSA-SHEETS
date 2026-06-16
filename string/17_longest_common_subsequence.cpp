/*
    Longest Common Subsequence - LeetCode #1143
    
    Given two strings text1 and text2, return the length of their longest common subsequence.
    If there is no common subsequence, return 0.
    
    A subsequence is a sequence that can be derived from another sequence by deleting some
    or no elements without changing the order of the remaining elements.
    
    Example 1:
    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation: The longest common subsequence is "ace" and its length is 3.
    
    Example 2:
    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.
    
    Example 3:
    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Space optimized version
    int longestCommonSubsequenceOptimized(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            swap(prev, curr);
        }
        
        return prev[n];
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << sol.longestCommonSubsequence("abcde", "ace") << endl;     // 3
    cout << "Test 2: " << sol.longestCommonSubsequence("abc", "abc") << endl;       // 3
    cout << "Test 3: " << sol.longestCommonSubsequence("abc", "def") << endl;       // 0
    
    return 0;
}
