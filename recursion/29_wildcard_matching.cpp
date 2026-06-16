/*
PROBLEM: Wildcard Matching
---------------------------------------------------------------------------
Given an input string s and a pattern p, implement wildcard pattern matching 
with support for '?' and '*' where:
- '?' Matches any single character
- '*' Matches any sequence of characters (including empty)

DIFFICULTY: Hard
PATTERN: Recursion with Memoization
TIME COMPLEXITY: O(m * n) with memoization
SPACE COMPLEXITY: O(m * n)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match entire string "aa"

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dp(s, p, 0, 0, memo);
    }
    
private:
    bool dp(string& s, string& p, int i, int j, vector<vector<int>>& memo) {
        // Check memo
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        bool result;
        
        // Base cases
        if (j >= p.length()) {
            result = (i >= s.length());
        } else if (i >= s.length()) {
            // String exhausted, check if remaining pattern is all '*'
            result = true;
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') {
                    result = false;
                    break;
                }
            }
        } else if (p[j] == '*') {
            // '*' can match:
            // 1. Empty sequence (skip *)
            // 2. One or more characters (consume char from s)
            result = dp(s, p, i, j + 1, memo) ||     // skip *
                    dp(s, p, i + 1, j, memo);        // use *
        } else if (p[j] == '?' || p[j] == s[i]) {
            // '?' or exact match
            result = dp(s, p, i + 1, j + 1, memo);
        } else {
            // No match
            result = false;
        }
        
        memo[i][j] = result;
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "aa", p1 = "a";
    cout << "Test 1: Does \"" << s1 << "\" match \"" << p1 << "\"? " 
         << (sol.isMatch(s1, p1) ? "true" : "false") << endl;
    
    // Test case 2
    string s2 = "aa", p2 = "*";
    cout << "Test 2: Does \"" << s2 << "\" match \"" << p2 << "\"? " 
         << (sol.isMatch(s2, p2) ? "true" : "false") << endl;
    
    return 0;
}
