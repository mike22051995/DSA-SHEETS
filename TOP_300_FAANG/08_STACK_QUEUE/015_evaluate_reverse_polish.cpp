/*
================================================================================
PROBLEM: Evaluate Reverse Polish Notation (LeetCode #150)
DIFFICULTY: Medium
PATTERN: Stack
COMPANIES: Amazon, Microsoft, Facebook, Google, LinkedIn, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another
expression. Division between two integers should truncate toward zero.

EXAMPLES:

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22

PATTERN RECOGNITION:
Use this pattern when:
- Postfix/RPN expression evaluation
- Stack-based calculation
- Operators appear after operands
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                
                int result = 0;
                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else if (token == "/") result = a / b;
                
                stk.push(result);
            } else {
                stk.push(stoi(token));
            }
        }
        
        return stk.top();
    }
};

int main() {
    Solution sol;
    
    vector<string> tokens1 = {"2","1","+","3","*"};
    cout << "Result: " << sol.evalRPN(tokens1) << endl;
    
    vector<string> tokens2 = {"4","13","5","/","+"};
    cout << "Result: " << sol.evalRPN(tokens2) << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is number of tokens
SPACE COMPLEXITY: O(n) for stack

SIMILAR PROBLEMS:
1. Basic Calculator (LeetCode #224)
2. Basic Calculator II (LeetCode #227)
3. Basic Calculator III (LeetCode #772)
4. Expression Add Operators (LeetCode #282)
5. Different Ways to Add Parentheses (LeetCode #241)
6. Build Binary Expression Tree (LeetCode #1597)
7. Parsing A Boolean Expression (LeetCode #1106)
8. Ternary Expression Parser (LeetCode #439)
9. Convert to Base -2 (LeetCode #1017)
10. Score of Parentheses (LeetCode #856)
*/
