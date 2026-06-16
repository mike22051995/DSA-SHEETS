/*
================================================================================
PROBLEM: Valid Parenthesis String (LeetCode #678)
DIFFICULTY: Medium
PATTERN: Greedy / String
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================

PROBLEM DESCRIPTION:
Given a string s containing only three types of characters: '(', ')' and '*',
return true if s is valid. The '*' character can be treated as:
- A single right parenthesis ')'
- A single left parenthesis '('
- An empty string ""

EXAMPLES:

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

PATTERN RECOGNITION:
Use this pattern when:
- Parentheses matching with wildcards
- Greedy approach tracking min/max open count
- Need to handle multiple interpretations
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Greedy approach with two counters
    bool checkValidString(string s) {
        int minOpen = 0;  // Minimum possible open brackets
        int maxOpen = 0;  // Maximum possible open brackets
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {  // c == '*'
                minOpen--;  // Treat as ')'
                maxOpen++;  // Treat as '('
            }
            
            if (maxOpen < 0) return false;  // Too many ')'
            minOpen = max(minOpen, 0);      // Reset if negative
        }
        
        return minOpen == 0;
    }
    
    // Two-pass approach
    bool checkValidStringTwoPass(string s) {
        int open = 0;
        
        // Left to right: treat * as (
        for (char c : s) {
            if (c == '(' || c == '*') {
                open++;
            } else {
                open--;
            }
            if (open < 0) return false;
        }
        
        if (open == 0) return true;
        
        // Right to left: treat * as )
        int close = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                close++;
            } else {
                close--;
            }
            if (close < 0) return false;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    cout << "() -> " << (sol.checkValidString("()") ? "true" : "false") << endl;
    cout << "(*) -> " << (sol.checkValidString("(*)") ? "true" : "false") << endl;
    cout << "(*))" << " -> " << (sol.checkValidString("(*))") ? "true" : "false") << endl;
    cout << "(((******)) -> " << (sol.checkValidString("(((******))") ? "true" : "false") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is string length
SPACE COMPLEXITY: O(1)

SIMILAR PROBLEMS:
1. Valid Parentheses (LeetCode #20)
2. Longest Valid Parentheses (LeetCode #32)
3. Remove Invalid Parentheses (LeetCode #301)
4. Minimum Remove to Make Valid (LeetCode #1249)
5. Minimum Add to Make Valid (LeetCode #921)
6. Check if Word Is Valid (LeetCode #1003)
7. Score of Parentheses (LeetCode #856)
8. Different Ways to Add Parentheses (LeetCode #241)
9. Generate Parentheses (LeetCode #22)
10. Remove Outermost Parentheses (LeetCode #1021)
*/
