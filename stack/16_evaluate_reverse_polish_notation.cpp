/*
PROBLEM: Evaluate Reverse Polish Notation (LeetCode 150)
DIFFICULTY: Medium
PATTERN: Stack for Expression Evaluation

DESCRIPTION:
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Division between two integers should truncate toward zero.

INPUT: tokens = ["2","1","+","3","*"]
OUTPUT: 9
Explanation: ((2 + 1) * 3) = 9

INPUT: tokens = ["4","13","5","/","+"]
OUTPUT: 6
Explanation: (4 + (13 / 5)) = 6

TIME COMPLEXITY: O(n) where n is the number of tokens
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
In RPN, operators come after operands. Use a stack to store numbers.
When we encounter a number, push it. When we encounter an operator,
pop two operands, apply the operation, and push the result back.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Pop two operands
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            // Perform operation
            int result;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else result = a / b;  // Integer division
            
            st.push(result);
        } else {
            // It's a number
            st.push(stoi(token));
        }
    }
    
    return st.top();
}

void printVector(const vector<string>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<vector<string>> testCases = {
        {"2", "1", "+", "3", "*"},
        {"4", "13", "5", "/", "+"},
        {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"},
        {"3", "4", "+", "2", "*", "7", "/"},
        {"18"}
    };
    
    for (auto& tokens : testCases) {
        cout << "Tokens: ";
        printVector(tokens);
        cout << endl;
        
        int result = evalRPN(tokens);
        cout << "Result: " << result << endl << endl;
    }
    
    return 0;
}
