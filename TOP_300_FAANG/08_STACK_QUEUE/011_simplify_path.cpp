/*
================================================================================
PROBLEM: Simplify Path (LeetCode #71)
DIFFICULTY: Medium
PATTERN: Stack
COMPANIES: Amazon, Facebook, Microsoft, Google
================================================================================
*/

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        stringstream ss(path);
        string token;
        
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(token);
            }
        }
        
        string result = "";
        
        while (!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }
        
        return result.empty() ? "/" : result;
    }
};

int main() {
    Solution sol;
    string path1 = "/home/";
    string path2 = "/../";
    string path3 = "/home//foo/";
    string path4 = "/a/./b/../../c/";
    
    cout << path1 << " -> " << sol.simplifyPath(path1) << endl;
    cout << path2 << " -> " << sol.simplifyPath(path2) << endl;
    cout << path3 << " -> " << sol.simplifyPath(path3) << endl;
    cout << path4 << " -> " << sol.simplifyPath(path4) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Remove All Adjacent Duplicates in String (LeetCode #1047)
2. Build Array With Stack Operations (LeetCode #1441)
3. Crawler Log Folder (LeetCode #1598)
4. Exclusive Time of Functions (LeetCode #636)
5. Basic Calculator (LeetCode #224)
6. Decode String (LeetCode #394)
7. Remove K Digits (LeetCode #402)
8. Asteroid Collision (LeetCode #735)
9. Remove Outermost Parentheses (LeetCode #1021)
10. Minimum Remove to Make Valid Parentheses (LeetCode #1249)
*/
