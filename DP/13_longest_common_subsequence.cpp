/*
PROBLEM: Longest Common Subsequence (LCS)
Difficulty: Medium
Pattern: 2D DP, String Matching

DESCRIPTION:
Given two strings text1 and text2, return the length of their longest common subsequence.
A subsequence is a sequence that can be derived from another sequence by deleting some or no 
elements without changing the order of the remaining elements.

INPUT:
text1 = "abcde", text2 = "ace"

OUTPUT:
3
Explanation: The longest common subsequence is "ace" and its length is 3.

TIME COMPLEXITY: O(m * n) where m, n are lengths of strings
SPACE COMPLEXITY: O(m * n), can be optimized to O(min(m, n))
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Method 1: 2D DP
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // dp[i][j] = LCS length of text1[0...i-1] and text2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    // Characters match, add 1 to LCS without these characters
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    // Characters don't match, take max of excluding one character
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Method 2: Space Optimized (using 1D array)
    int longestCommonSubsequenceOptimized(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    curr[j] = prev[j-1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        
        return curr[n];
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string text1_1 = "abcde", text2_1 = "ace";
    cout << "Input: text1 = \"" << text1_1 << "\", text2 = \"" << text2_1 << "\"" << endl;
    cout << "Output: " << sol.longestCommonSubsequence(text1_1, text2_1) << endl;
    cout << "Output (Optimized): " << sol.longestCommonSubsequenceOptimized(text1_1, text2_1) << endl << endl;
    
    // Test Case 2
    string text1_2 = "abc", text2_2 = "abc";
    cout << "Input: text1 = \"" << text1_2 << "\", text2 = \"" << text2_2 << "\"" << endl;
    cout << "Output: " << sol.longestCommonSubsequence(text1_2, text2_2) << endl;
    cout << "Output (Optimized): " << sol.longestCommonSubsequenceOptimized(text1_2, text2_2) << endl << endl;
    
    // Test Case 3
    string text1_3 = "abc", text2_3 = "def";
    cout << "Input: text1 = \"" << text1_3 << "\", text2 = \"" << text2_3 << "\"" << endl;
    cout << "Output: " << sol.longestCommonSubsequence(text1_3, text2_3) << endl;
    cout << "Output (Optimized): " << sol.longestCommonSubsequenceOptimized(text1_3, text2_3) << endl;
    
    return 0;
}

/*
EXPLANATION:
1. dp[i][j] = LCS length of first i characters of text1 and first j characters of text2
2. If characters match: dp[i][j] = dp[i-1][j-1] + 1
3. If don't match: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
4. Base case: dp[0][j] = dp[i][0] = 0 (empty string has LCS 0)

Example: text1 = "abcde", text2 = "ace"
    ""  a  c  e
""   0  0  0  0
a    0  1  1  1
b    0  1  1  1
c    0  1  2  2
d    0  1  2  2
e    0  1  2  3

KEY LEARNING:
- Foundation for many string DP problems
- 2D DP table comparing two sequences
- Can reconstruct actual LCS by backtracking through dp table
- Used in: diff tools, DNA sequence alignment, plagiarism detection
- Variants: Edit Distance, Shortest Common Supersequence
*/
