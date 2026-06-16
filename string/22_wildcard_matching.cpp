/*
    Wildcard Matching - LeetCode #44
    
    Given an input string (s) and a pattern (p), implement wildcard pattern matching
    with support for '?' and '*' where:
    - '?' Matches any single character.
    - '*' Matches any sequence of characters (including the empty sequence).
    
    The matching should cover the entire input string (not partial).
    
    Example 1:
    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    
    Example 2:
    Input: s = "aa", p = "*"
    Output: true
    Explanation: '*' matches any sequence.
    
    Example 3:
    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'b', which does not match 'a'.
    
    Constraints:
    - 0 <= s.length, p.length <= 2000
    - s contains only lowercase English letters
    - p contains only lowercase English letters, '?' or '*'
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        // Handle patterns starting with *
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // '*' can match empty string or any sequence
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Space optimized two-pointer approach
    bool isMatchOptimized(string s, string p) {
        int i = 0, j = 0;
        int starIdx = -1, match = 0;
        
        while (i < s.length()) {
            // Current characters match or pattern has '?'
            if (j < p.length() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            // Pattern has '*'
            else if (j < p.length() && p[j] == '*') {
                starIdx = j;
                match = i;
                j++;
            }
            // No match, but there was a '*' before
            else if (starIdx != -1) {
                j = starIdx + 1;
                match++;
                i = match;
            }
            // No match and no '*' before
            else {
                return false;
            }
        }
        
        // Check remaining characters in pattern
        while (j < p.length() && p[j] == '*') {
            j++;
        }
        
        return j == p.length();
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << (sol.isMatch("aa", "a") ? "true" : "false") << endl;          // false
    cout << "Test 2: " << (sol.isMatch("aa", "*") ? "true" : "false") << endl;          // true
    cout << "Test 3: " << (sol.isMatch("cb", "?a") ? "true" : "false") << endl;         // false
    cout << "Test 4: " << (sol.isMatch("adceb", "*a*b") ? "true" : "false") << endl;    // true
    cout << "Test 5: " << (sol.isMatch("acdcb", "a*c?b") ? "true" : "false") << endl;   // false
    
    return 0;
}
