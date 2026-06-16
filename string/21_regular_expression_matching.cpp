/*
    Regular Expression Matching - LeetCode #10
    
    Given an input string s and a pattern p, implement regular expression matching with
    support for '.' and '*' where:
    - '.' Matches any single character.
    - '*' Matches zero or more of the preceding element.
    
    The matching should cover the entire input string (not partial).
    
    Example 1:
    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    
    Example 2:
    Input: s = "aa", p = "a*"
    Output: true
    Explanation: '*' means zero or more of the preceding element, 'a'.
    
    Example 3:
    Input: s = "ab", p = ".*"
    Output: true
    Explanation: ".*" means "zero or more (*) of any character (.)".
    
    Constraints:
    - 1 <= s.length <= 20
    - 1 <= p.length <= 30
    - s contains only lowercase English letters
    - p contains only lowercase English letters, '.', and '*'
    
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
        
        // Handle patterns like a*, a*b*, a*b*c*
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // Two cases:
                    // 1. Zero occurrence of character before *
                    dp[i][j] = dp[i][j - 2];
                    
                    // 2. One or more occurrence
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    // Current characters match
                    if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << (sol.isMatch("aa", "a") ? "true" : "false") << endl;        // false
    cout << "Test 2: " << (sol.isMatch("aa", "a*") ? "true" : "false") << endl;       // true
    cout << "Test 3: " << (sol.isMatch("ab", ".*") ? "true" : "false") << endl;       // true
    cout << "Test 4: " << (sol.isMatch("aab", "c*a*b") ? "true" : "false") << endl;   // true
    cout << "Test 5: " << (sol.isMatch("mississippi", "mis*is*p*.") ? "true" : "false") << endl;  // false
    
    return 0;
}
