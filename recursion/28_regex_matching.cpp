/*
PROBLEM: Regular Expression Matching
---------------------------------------------------------------------------
Given an input string s and a pattern p, implement regular expression 
matching with support for '.' and '*' where:
- '.' Matches any single character
- '*' Matches zero or more of the preceding element

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
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more 'a', so "aa" matches
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
        
        // Base case: pattern exhausted
        if (j >= p.length()) {
            result = (i >= s.length());
        } else {
            // Check if current characters match
            bool firstMatch = (i < s.length() && 
                              (p[j] == s[i] || p[j] == '.'));
            
            // Handle '*'
            if (j + 1 < p.length() && p[j + 1] == '*') {
                // Two options:
                // 1. Use * zero times (skip pattern[j] and *)
                // 2. Use * one or more times (match and stay with *)
                result = dp(s, p, i, j + 2, memo) || 
                        (firstMatch && dp(s, p, i + 1, j, memo));
            } else {
                // Normal character or '.'
                result = firstMatch && dp(s, p, i + 1, j + 1, memo);
            }
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
    string s2 = "aa", p2 = "a*";
    cout << "Test 2: Does \"" << s2 << "\" match \"" << p2 << "\"? " 
         << (sol.isMatch(s2, p2) ? "true" : "false") << endl;
    
    return 0;
}
