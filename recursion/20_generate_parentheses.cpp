/*
PROBLEM: Generate Parentheses
---------------------------------------------------------------------------
Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.

DIFFICULTY: Medium
PATTERN: Backtracking (Constraint-based)
TIME COMPLEXITY: O(4^n / sqrt(n)) - Catalan number
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(n, 0, 0, current, result);
        return result;
    }
    
private:
    void backtrack(int n, int open, int close, string& current,
                   vector<string>& result) {
        // Base case: used all parentheses
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // Add opening parenthesis if we haven't used all
        if (open < n) {
            current.push_back('(');
            backtrack(n, open + 1, close, current, result);
            current.pop_back();
        }
        
        // Add closing parenthesis if valid
        if (close < open) {
            current.push_back(')');
            backtrack(n, open, close + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int n1 = 3;
    vector<string> result1 = sol.generateParenthesis(n1);
    cout << "Test 1: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"" << (i < result1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    int n2 = 1;
    vector<string> result2 = sol.generateParenthesis(n2);
    cout << "Test 2: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"" << (i < result2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
