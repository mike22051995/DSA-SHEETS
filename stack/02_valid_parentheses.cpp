/*
PROBLEM: Valid Parentheses (LeetCode 20)
DIFFICULTY: Easy
PATTERN: Stack for Matching Pairs

DESCRIPTION:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid. An input string is valid if:
1. Open brackets must be closed by the same type of brackets
2. Open brackets must be closed in the correct order

INPUT: s = "()[]{}"
OUTPUT: true

INPUT: s = "(]"
OUTPUT: false

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to keep track of opening brackets. When we encounter a closing bracket,
check if it matches the most recent opening bracket (top of stack). If all brackets
match properly, the stack will be empty at the end.
*/

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> pairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    
    for (char c : s) {
        // If it's a closing bracket
        if (pairs.count(c)) {
            // Check if stack is empty or top doesn't match
            if (st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        } else {
            // It's an opening bracket
            st.push(c);
        }
    }
    
    // Valid only if all brackets are matched (stack is empty)
    return st.empty();
}

int main() {
    // Test cases
    vector<string> testCases = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "((()))",
        "((())",
        ""
    };
    
    for (const string& test : testCases) {
        cout << "String: \"" << test << "\" -> " 
             << (isValid(test) ? "Valid" : "Invalid") << endl;
    }
    
    return 0;
}
