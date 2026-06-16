/*
================================================================================
PROBLEM: Basic Calculator II (LeetCode #227)
DIFFICULTY: Medium
PATTERN: Stack
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple
================================================================================
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char op = '+';
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            
            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (op == '+') {
                    stk.push(num);
                } else if (op == '-') {
                    stk.push(-num);
                } else if (op == '*') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * num);
                } else if (op == '/') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / num);
                }
                
                op = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string s1 = "3+2*2";
    string s2 = " 3/2 ";
    string s3 = " 3+5 / 2 ";
    
    cout << s1 << " = " << sol.calculate(s1) << endl;
    cout << s2 << " = " << sol.calculate(s2) << endl;
    cout << s3 << " = " << sol.calculate(s3) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Basic Calculator (LeetCode #224)
2. Basic Calculator III (LeetCode #772)
3. Evaluate Reverse Polish Notation (LeetCode #150)
4. Expression Add Operators (LeetCode #282)
5. Different Ways to Add Parentheses (LeetCode #241)
6. Ternary Expression Parser (LeetCode #439)
7. Parse Lisp Expression (LeetCode #736)
8. Build Binary Expression Tree (LeetCode #1597)
9. Evaluate Boolean Expression (LeetCode #1106)
10. Design Excel Sum Formula (LeetCode #631)
*/
