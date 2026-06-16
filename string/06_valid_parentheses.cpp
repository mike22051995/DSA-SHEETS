/*
    Valid Parentheses - LeetCode #20
    
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
    determine if the input string is valid.
    
    An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
    3. Every close bracket has a corresponding open bracket of the same type.
    
    Example 1:
    Input: s = "()"
    Output: true
    
    Example 2:
    Input: s = "()[]{}"
    Output: true
    
    Example 3:
    Input: s = "(]"
    Output: false
    
    Constraints:
    - 1 <= s.length <= 10^4
    - s consists of parentheses only '()[]{}'
    
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <iostream>
#include <string>
#include <stack>
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
        
        return st.empty();
    }
    
    // Alternative approach without map
    bool isValidSimple(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else if (st.empty() || st.top() != c) return false;
            else st.pop();
        }
        
        return st.empty();
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << (sol.isValid("()") ? "true" : "false") << endl;           // true
    cout << "Test 2: " << (sol.isValid("()[]{}") ? "true" : "false") << endl;       // true
    cout << "Test 3: " << (sol.isValid("(]") ? "true" : "false") << endl;           // false
    cout << "Test 4: " << (sol.isValid("([)]") ? "true" : "false") << endl;         // false
    cout << "Test 5: " << (sol.isValid("{[]}") ? "true" : "false") << endl;         // true
    
    return 0;
}
