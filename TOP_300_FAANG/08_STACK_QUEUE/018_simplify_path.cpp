/*
================================================================================
PROBLEM: Simplify Path (LeetCode #71)
DIFFICULTY: Medium
PATTERN: Stack / String
COMPANIES: Amazon, Microsoft, Facebook, Google, Bloomberg
================================================================================

PROBLEM DESCRIPTION:
Given a string path representing an absolute path for a Unix-style file system,
return the simplified canonical path. In a Unix-style file system:
- A period '.' refers to the current directory
- A double period '..' refers to the directory up a level
- Multiple consecutive slashes are treated as a single slash
- The path must start with a single slash

EXAMPLES:

Example 1:
Input: path = "/home/"
Output: "/home"

Example 2:
Input: path = "/../"
Output: "/"
Explanation: Going one level up from root is not possible.

Example 3:
Input: path = "/home//foo/"
Output: "/home/foo"

Example 4:
Input: path = "/a/./b/../../c/"
Output: "/c"

PATTERN RECOGNITION:
Use this pattern when:
- Path processing with directory navigation
- Stack for handling '..' (go back)
- String splitting and filtering
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
        
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }
        
        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i < stack.size() - 1) {
                result += "/";
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << "/home/ -> " << sol.simplifyPath("/home/") << endl;
    cout << "/../ -> " << sol.simplifyPath("/../") << endl;
    cout << "/home//foo/ -> " << sol.simplifyPath("/home//foo/") << endl;
    cout << "/a/./b/../../c/ -> " << sol.simplifyPath("/a/./b/../../c/") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is path length
SPACE COMPLEXITY: O(n) for stack

SIMILAR PROBLEMS:
1. Remove K Digits (LeetCode #402)
2. Decode String (LeetCode #394)
3. Basic Calculator (LeetCode #224)
4. Valid Parentheses (LeetCode #20)
5. Min Stack (LeetCode #155)
6. Evaluate Reverse Polish Notation (LeetCode #150)
7. Longest Absolute File Path (LeetCode #388)
8. Design File System (LeetCode #1166)
9. Split a String in Balanced Strings (LeetCode #1221)
10. Minimum Remove to Make Valid Parentheses (LeetCode #1249)
*/
