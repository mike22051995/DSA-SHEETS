/*
PROBLEM: Score of Parentheses (LeetCode 856)
DIFFICULTY: Medium
PATTERN: Stack for Nested Scoring

DESCRIPTION:
Given a balanced parentheses string s, return the score of the string.
Rules:
- "()" has score 1
- "AB" has score A + B, where A and B are balanced parentheses strings
- "(A)" has score 2 * A, where A is a balanced parentheses string

INPUT: s = "()"
OUTPUT: 1

INPUT: s = "(())"
OUTPUT: 2

INPUT: s = "()()"
OUTPUT: 2

INPUT: s = "(()(()))"
OUTPUT: 6

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to track scores at each depth level.
When we see '(', push current score and reset to 0.
When we see ')', the current level is complete - calculate score and add to parent level.
Score is max(2 * current, 1) added to the popped parent score.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0);  // Initialize with base score
    
    for (char c : s) {
        if (c == '(') {
            // Start new level
            st.push(0);
        } else {
            // Complete current level
            int top = st.top();
            st.pop();
            int score = st.top() + max(2 * top, 1);
            st.pop();
            st.push(score);
        }
    }
    
    return st.top();
}

// Alternative approach without stack
int scoreOfParenthesesOptimized(string s) {
    int score = 0;
    int depth = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            depth++;
        } else {
            depth--;
            // If previous char is '(', it's a primitive pair "()"
            if (s[i - 1] == '(') {
                score += 1 << depth;  // 2^depth
            }
        }
    }
    
    return score;
}

int main() {
    vector<string> testCases = {
        "()",
        "(())",
        "()()",
        "(()(()))",
        "(((())))",
        "()((()))"
    };
    
    for (const string& test : testCases) {
        int result1 = scoreOfParentheses(test);
        int result2 = scoreOfParenthesesOptimized(test);
        
        cout << "String: \"" << test << "\"" << endl;
        cout << "Score (stack): " << result1 << endl;
        cout << "Score (optimized): " << result2 << endl << endl;
    }
    
    return 0;
}
