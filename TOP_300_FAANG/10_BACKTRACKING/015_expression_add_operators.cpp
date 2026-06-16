/*
================================================================================
PROBLEM: Expression Add Operators (LeetCode #282)
DIFFICULTY: Hard
PATTERN: Backtracking / DFS
COMPANIES: Facebook, Google, Amazon
================================================================================

PROBLEM DESCRIPTION:
Given a string num that contains only digits and an integer target, return all
possibilities to insert the binary operators '+', '-', and '*' between the
digits of num so that the resultant expression evaluates to the target value.

EXAMPLES:

Example 1:
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]

Example 2:
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]

Example 3:
Input: num = "3456237490", target = 9191
Output: []

PATTERN RECOGNITION:
Use this pattern when:
- Need to try all operator combinations
- Expression evaluation with precedence
- Backtracking to generate valid expressions
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string path;
        backtrack(num, target, 0, 0, 0, path, result);
        return result;
    }
    
    void backtrack(string& num, int target, int index, long eval, long prev, 
                   string path, vector<string>& result) {
        if (index == num.length()) {
            if (eval == target) {
                result.push_back(path);
            }
            return;
        }
        
        for (int i = index; i < num.length(); i++) {
            // Skip numbers with leading zeros
            if (i != index && num[index] == '0') break;
            
            string currStr = num.substr(index, i - index + 1);
            long curr = stol(currStr);
            
            if (index == 0) {
                backtrack(num, target, i + 1, curr, curr, currStr, result);
            } else {
                // Add +
                backtrack(num, target, i + 1, eval + curr, curr, 
                         path + "+" + currStr, result);
                
                // Add -
                backtrack(num, target, i + 1, eval - curr, -curr, 
                         path + "-" + currStr, result);
                
                // Add * (need to handle precedence)
                backtrack(num, target, i + 1, eval - prev + prev * curr, prev * curr,
                         path + "*" + currStr, result);
            }
        }
    }
};

int main() {
    Solution sol;
    
    auto result1 = sol.addOperators("123", 6);
    cout << "Expressions for '123' = 6:" << endl;
    for (const auto& expr : result1) {
        cout << expr << endl;
    }
    
    auto result2 = sol.addOperators("232", 8);
    cout << "\nExpressions for '232' = 8:" << endl;
    for (const auto& expr : result2) {
        cout << expr << endl;
    }
    
    return 0;
}

/*
TIME COMPLEXITY: O(4^n) where n is length of num
SPACE COMPLEXITY: O(n) for recursion depth

SIMILAR PROBLEMS:
1. Different Ways to Add Parentheses (LeetCode #241)
2. Evaluate Reverse Polish Notation (LeetCode #150)
3. Basic Calculator (LeetCode #224)
4. Basic Calculator II (LeetCode #227)
5. Optimal Account Balancing (LeetCode #465)
6. Target Sum (LeetCode #494)
7. Restore IP Addresses (LeetCode #93)
8. Generate Parentheses (LeetCode #22)
9. Letter Combinations (LeetCode #17)
10. Combination Sum (LeetCode #39)
*/
