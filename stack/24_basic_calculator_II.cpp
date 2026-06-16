/*
PROBLEM: Basic Calculator II (LeetCode 227)
DIFFICULTY: Hard/Medium
PATTERN: Stack for Operator Precedence

DESCRIPTION:
Given a string s which represents an expression, evaluate this expression and return its value.
The expression contains:
- Non-negative integers
- '+', '-', '*', '/' operators
- Spaces ' '

INPUT: s = "3+2*2"
OUTPUT: 7

INPUT: s = " 3/2 "
OUTPUT: 1

INPUT: s = " 3+5 / 2 "
OUTPUT: 5

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Process operators based on precedence. Use a stack to store intermediate results.
For '+' and '-', push to stack with appropriate sign.
For '*' and '/', immediately pop and compute, then push result.
Finally, sum all elements in stack.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int number = 0;
    char operation = '+';  // Previous operation
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        }
        
        // Process when we hit an operator or end of string (and not a space)
        if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
            if (operation == '+') {
                st.push(number);
            } else if (operation == '-') {
                st.push(-number);
            } else if (operation == '*') {
                int top = st.top();
                st.pop();
                st.push(top * number);
            } else if (operation == '/') {
                int top = st.top();
                st.pop();
                st.push(top / number);
            }
            
            operation = c;
            number = 0;
        }
    }
    
    // Sum all numbers in stack
    int result = 0;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
}

int main() {
    vector<string> testCases = {
        "3+2*2",
        " 3/2 ",
        " 3+5 / 2 ",
        "42",
        "1-1+1",
        "14-3/2",
        "100000000/1/2/3/4/5/6/7/8/9/10"
    };
    
    for (const string& test : testCases) {
        int result = calculate(test);
        cout << "Expression: \"" << test << "\"" << endl;
        cout << "Result: " << result << endl << endl;
    }
    
    return 0;
}
