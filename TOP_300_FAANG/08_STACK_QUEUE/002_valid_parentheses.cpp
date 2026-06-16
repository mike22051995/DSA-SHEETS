/*
================================================================================
PROBLEM: Valid Parentheses (LeetCode #20)
DIFFICULTY: Easy
PATTERN: Stack
COMPANIES: Amazon, Google, Facebook, Microsoft, Apple, Bloomberg
================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty();
    }
};

int main() {
    Solution sol;
    cout << "Is valid (()): " << (sol.isValid("()") ? "true" : "false") << endl;
    cout << "Is valid (()[]{}): " << (sol.isValid("()[]{}") ? "true" : "false") << endl;
    cout << "Is valid ((]): " << (sol.isValid("(]") ? "true" : "false") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Generate Parentheses (LeetCode #22)
2. Longest Valid Parentheses (LeetCode #32)
3. Remove Invalid Parentheses (LeetCode #301)
4. Minimum Add to Make Parentheses Valid (LeetCode #921)
5. Minimum Remove to Make Valid Parentheses (LeetCode #1249)
6. Score of Parentheses (LeetCode #856)
7. Check if Word Is Valid (LeetCode #2124)
8. Valid Parenthesis String (LeetCode #678)
9. Remove Outermost Parentheses (LeetCode #1021)
10. Maximum Nesting Depth (LeetCode #1614)
*/
