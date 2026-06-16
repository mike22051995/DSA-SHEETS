/*
    Generate Parentheses - LeetCode #22
    
    Given n pairs of parentheses, write a function to generate all combinations
    of well-formed parentheses.
    
    Example 1:
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
    
    Example 2:
    Input: n = 1
    Output: ["()"]
    
    Constraints:
    - 1 <= n <= 8
    
    Time Complexity: O(4^n / sqrt(n)) - Catalan number
    Space Complexity: O(n) for recursion stack
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string current, 
                   int open, int close, int max) {
        // Base case: if current string is complete
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }
        
        // Add opening bracket if we haven't used all
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        
        // Add closing bracket if it doesn't exceed opening
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};

int main() {
    Solution sol;
    
    // Test 1
    vector<string> result1 = sol.generateParenthesis(3);
    cout << "Test 1 (n=3): ";
    for (const string& s : result1) {
        cout << s << " ";
    }
    cout << endl;
    
    // Test 2
    vector<string> result2 = sol.generateParenthesis(1);
    cout << "Test 2 (n=1): ";
    for (const string& s : result2) {
        cout << s << " ";
    }
    cout << endl;
    
    // Test 3
    vector<string> result3 = sol.generateParenthesis(2);
    cout << "Test 3 (n=2): ";
    for (const string& s : result3) {
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}
