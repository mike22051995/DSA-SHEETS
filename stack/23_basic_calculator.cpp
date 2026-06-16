/*
PROBLEM: Basic Calculator (LeetCode 224)
DIFFICULTY: Hard
PATTERN: Stack for Expression Parsing

DESCRIPTION:
Given a string s representing a valid expression, implement a basic calculator to evaluate it.
The expression may contain:
- Non-negative integers
- '+', '-' operators
- '(', ')' parentheses
- Spaces ' '

INPUT: s = "1 + 1"
OUTPUT: 2

INPUT: s = " 2-1 + 2 "
OUTPUT: 3

INPUT: s = "(1+(4+5+2)-3)+(6+8)"
OUTPUT: 23

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to handle parentheses and signs. Track current number, result, and sign.
When we see '(', push current result and sign to stack, reset for new sub-expression.
When we see ')', pop from stack and combine with current result.
This is a must-know problem for interviews!
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int result = 0;
    int number = 0;
    int sign = 1;  // 1 for positive, -1 for negative
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        } else if (c == '(') {
            // Push current result and sign to stack
            st.push(result);
            st.push(sign);
            // Reset for new sub-expression
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * number;
            number = 0;
            
            // Pop sign and previous result
            result *= st.top(); st.pop();  // sign
            result += st.top(); st.pop();  // previous result
        }
        // Skip spaces
    }
    
    // Add last number if any
    if (number != 0) {
        result += sign * number;
    }
    
    return result;
}

int main() {
    vector<string> testCases = {
        "1 + 1",
        " 2-1 + 2 ",
        "(1+(4+5+2)-3)+(6+8)",
        "1-(5)",
        "2-(5-6)",
        "(7)-(0)+(4)",
        "1-11"
    };
    
    for (const string& test : testCases) {
        int result = calculate(test);
        cout << "Expression: \"" << test << "\"" << endl;
        cout << "Result: " << result << endl << endl;
    }
    
    return 0;
}
