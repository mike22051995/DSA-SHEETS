/*
================================================================================
PROBLEM: Longest Valid Parentheses (LeetCode #32)
DIFFICULTY: Hard
PATTERN: Stack / Dynamic Programming
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Stack approach
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }
        
        return maxLen;
    }
    
    // DP approach
    int longestValidParenthesesDP(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        int maxLen = 0;
        
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                    dp[i] = dp[i-1] + 2 + (i - dp[i-1] >= 2 ? dp[i - dp[i-1] - 2] : 0);
                }
                
                maxLen = max(maxLen, dp[i]);
            }
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    cout << "(()" << " -> " << sol.longestValidParentheses("(()") << endl;
    cout << ")()())" << " -> " << sol.longestValidParentheses(")()())") << endl;
    cout << "" << " -> " << sol.longestValidParentheses("") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Parentheses (LeetCode #20)
2. Generate Parentheses (LeetCode #22)
3. Remove Invalid Parentheses (LeetCode #301)
4. Different Ways to Add Parentheses (LeetCode #241)
5. Minimum Remove to Make Valid Parentheses (LeetCode #1249)
6. Minimum Add to Make Parentheses Valid (LeetCode #921)
7. Check if Word Is Valid After Substitutions (LeetCode #1003)
8. Score of Parentheses (LeetCode #856)
9. Valid Parenthesis String (LeetCode #678)
10. Longest Absolute File Path (LeetCode #388)
*/
