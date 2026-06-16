/*
PROBLEM: Longest Valid Parentheses (LeetCode 32)
DIFFICULTY: Hard
PATTERN: Stack for Parentheses Matching with Length Tracking

DESCRIPTION:
Given a string containing just the characters '(' and ')', find the length of the 
longest valid (well-formed) parentheses substring.

INPUT: s = "(()"
OUTPUT: 2
Explanation: The longest valid parentheses substring is "()".

INPUT: s = ")()())"
OUTPUT: 4
Explanation: The longest valid parentheses substring is "()()".

INPUT: s = ""
OUTPUT: 0

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Stack approach: Store indices of unmatched parentheses. Initialize with -1 as base.
For '(', push index. For ')', pop. If stack becomes empty, push current index.
Otherwise, calculate length as current index - top of stack.
This problem is frequently asked in FAANG interviews!
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);  // Base for calculating length
    int maxLen = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                // No matching '(' for this ')'
                st.push(i);
            } else {
                // Calculate length
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    
    return maxLen;
}

// Dynamic Programming approach
int longestValidParenthesesDP(string s) {
    int n = s.length();
    if (n == 0) return 0;
    
    vector<int> dp(n, 0);
    int maxLen = 0;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                // Case: ...()
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                // Case: ...))
                dp[i] = dp[i - 1] + 2 + 
                        ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0);
            }
            maxLen = max(maxLen, dp[i]);
        }
    }
    
    return maxLen;
}

int main() {
    vector<string> testCases = {
        "(()",
        ")()())",
        "",
        "()(()",
        "()(())",
        "((())))",
        "()()(()()",
        "(()())"
    };
    
    for (const string& test : testCases) {
        int result1 = longestValidParentheses(test);
        int result2 = longestValidParenthesesDP(test);
        
        cout << "String: \"" << test << "\"" << endl;
        cout << "Longest valid (stack): " << result1 << endl;
        cout << "Longest valid (DP): " << result2 << endl << endl;
    }
    
    return 0;
}
