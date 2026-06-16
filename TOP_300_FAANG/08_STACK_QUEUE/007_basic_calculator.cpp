/*
================================================================================
PROBLEM: Basic Calculator (LeetCode #224)
DIFFICULTY: Hard
PATTERN: Stack
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int number = 0;
        int sign = 1;
        
        for (char c : s) {
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
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * number;
                number = 0;
                result *= st.top(); st.pop();
                result += st.top(); st.pop();
            }
        }
        
        result += sign * number;
        return result;
    }
};

int main() {
    Solution sol;
    cout << "1 + 1 = " << sol.calculate("1 + 1") << endl;
    cout << " 2-1 + 2 = " << sol.calculate(" 2-1 + 2 ") << endl;
    cout << "(1+(4+5+2)-3)+(6+8) = " << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Basic Calculator II (LeetCode #227) - with * /
2. Basic Calculator III (LeetCode #772) - all operators
3. Evaluate Reverse Polish Notation (LeetCode #150)
4. Expression Add Operators (LeetCode #282)
5. Different Ways to Add Parentheses (LeetCode #241)
6. Parse Lisp Expression (LeetCode #736)
7. Parsing A Boolean Expression (LeetCode #1106)
8. Decode String (LeetCode #394)
9. Number of Atoms (LeetCode #726)
10. Ternary Expression Parser (LeetCode #439)
*/
