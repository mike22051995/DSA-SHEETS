/*
PROBLEM: Basic Calculator III (LeetCode 772)
DIFFICULTY: Hard
PATTERN: Stack with Recursion for Full Expression Parsing

DESCRIPTION:
Implement a basic calculator to evaluate a simple expression string.
The expression string contains:
- Non-negative integers
- '+', '-', '*', '/' operators
- '(', ')' parentheses
- Spaces ' '

INPUT: s = "2*(5+5*2)/3+(6/2+8)"
OUTPUT: 21

INPUT: s = "1 + 1"
OUTPUT: 2

INPUT: s = " 6-4 / 2 "
OUTPUT: 4

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack and recursion

EXPLANATION:
Combine Calculator I and Calculator II approaches.
Use stack for operator precedence and handling parentheses.
When encountering '(', recursively evaluate the sub-expression.
Handle *, / immediately and +, - by pushing to stack.
This is the most comprehensive calculator problem!

PATTERNS COVERED IN THIS FILE:
This is the ultimate stack problem combining multiple patterns:
1. Stack for operator precedence
2. Recursion/Stack for parentheses handling
3. Expression evaluation with multiple operators
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Calculator {
private:
    int index = 0;
    
    int calculate(string& s) {
        stack<int> st;
        int number = 0;
        char operation = '+';
        
        while (index < s.length()) {
            char c = s[index++];
            
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            }
            
            if (c == '(') {
                // Recursively evaluate sub-expression
                number = calculate(s);
            }
            
            if ((!isdigit(c) && c != ' ') || index == s.length()) {
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
                
                if (c == ')') {
                    break;  // End of sub-expression
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
    
public:
    int calculate(string s) {
        index = 0;
        return calculate(s);
    }
};

int main() {
    Calculator calc;
    
    vector<string> testCases = {
        "1 + 1",
        " 6-4 / 2 ",
        "2*(5+5*2)/3+(6/2+8)",
        "(2+6*3+5-(3*14/7+2)*5)+3",
        "0-2147483647",
        "1+2*5/3+6/4*2"
    };
    
    for (const string& test : testCases) {
        Calculator c;  // Create new instance for each test
        int result = c.calculate(test);
        cout << "Expression: \"" << test << "\"" << endl;
        cout << "Result: " << result << endl << endl;
    }
    
    return 0;
}
