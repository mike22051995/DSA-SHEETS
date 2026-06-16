/*
PROBLEM: Expression Add Operators
---------------------------------------------------------------------------
Given a string num that contains only digits and an integer target, return 
all possibilities to insert the binary operators '+', '-', and '*' between 
the digits of num so that the resultant expression evaluates to target.

DIFFICULTY: Hard
PATTERN: Backtracking (Expression Building)
TIME COMPLEXITY: O(4^n) - 4 choices per position
SPACE COMPLEXITY: O(n) - recursion depth

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: num = "123", target = 6
Output: ["1+2+3","1*2*3"]
Explanation: Both expressions evaluate to 6

Example 2:
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both expressions evaluate to 8
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string expr;
        backtrack(num, target, 0, 0, 0, expr, result);
        return result;
    }
    
private:
    void backtrack(string& num, int target, int pos, long long eval,
                   long long multed, string expr, vector<string>& result) {
        // Base case: processed all digits
        if (pos >= num.length()) {
            if (eval == target) {
                result.push_back(expr);
            }
            return;
        }
        
        // Try different number lengths starting from pos
        for (int i = pos; i < num.length(); i++) {
            // Skip numbers with leading zeros
            if (i > pos && num[pos] == '0') break;
            
            string currStr = num.substr(pos, i - pos + 1);
            long long currNum = stoll(currStr);
            
            if (pos == 0) {
                // First number, no operator
                backtrack(num, target, i + 1, currNum, currNum, 
                         currStr, result);
            } else {
                // Try '+'
                backtrack(num, target, i + 1, eval + currNum, currNum,
                         expr + "+" + currStr, result);
                
                // Try '-'
                backtrack(num, target, i + 1, eval - currNum, -currNum,
                         expr + "-" + currStr, result);
                
                // Try '*'
                // Need to undo last addition/subtraction and multiply
                backtrack(num, target, i + 1, 
                         eval - multed + multed * currNum,
                         multed * currNum,
                         expr + "*" + currStr, result);
            }
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string num1 = "123";
    int target1 = 6;
    vector<string> result1 = sol.addOperators(num1, target1);
    cout << "Test 1: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"" << (i < result1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    string num2 = "232";
    int target2 = 8;
    vector<string> result2 = sol.addOperators(num2, target2);
    cout << "Test 2: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"" << (i < result2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
