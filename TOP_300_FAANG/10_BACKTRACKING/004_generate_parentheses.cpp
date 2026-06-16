/*
================================================================================
PROBLEM: Generate Parentheses (LeetCode #22)
DIFFICULTY: Medium
PATTERN: Backtracking
COMPANIES: Amazon, Facebook, Google, Microsoft, Apple, Bloomberg
================================================================================
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
    
    void backtrack(int n, int open, int close, string& current, vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            current.push_back('(');
            backtrack(n, open + 1, close, current, result);
            current.pop_back();
        }
        
        if (close < open) {
            current.push_back(')');
            backtrack(n, open, close + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    auto result = sol.generateParenthesis(3);
    
    cout << "Valid parentheses for n=3:" << endl;
    for (string& s : result) {
        cout << s << endl;
    }
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Valid Parentheses (LeetCode #20)
2. Longest Valid Parentheses (LeetCode #32)
3. Remove Invalid Parentheses (LeetCode #301)
4. Different Ways to Add Parentheses (LeetCode #241)
5. Minimum Add to Make Valid (LeetCode #921)
6. Minimum Remove to Make Valid (LeetCode #1249)
7. Check if Valid Parentheses String (LeetCode #678)
8. Score of Parentheses (LeetCode #856)
9. Maximum Nesting Depth (LeetCode #1614)
10. Balance a Binary Search Tree (LeetCode #1382)
*/
