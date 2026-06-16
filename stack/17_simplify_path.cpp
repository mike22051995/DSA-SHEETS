/*
PROBLEM: Simplify Path (LeetCode 71)
DIFFICULTY: Medium
PATTERN: Stack for Path Processing

DESCRIPTION:
Given an absolute path for a Unix-style file system, simplify it.
Rules:
- "." refers to current directory
- ".." refers to parent directory
- Multiple consecutive slashes should be treated as a single slash
- The path must start with "/"
- The path must not end with "/" unless it is the root

INPUT: path = "/home/"
OUTPUT: "/home"

INPUT: path = "/../"
OUTPUT: "/"

INPUT: path = "/home//foo/"
OUTPUT: "/home/foo"

TIME COMPLEXITY: O(n) where n is the length of path
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Split the path by '/' and process each component:
- If empty or ".", skip
- If "..", pop from stack (if not empty)
- Otherwise, push to stack
Finally, join stack elements with '/' to form simplified path.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

string simplifyPath(string path) {
    stack<string> st;
    stringstream ss(path);
    string component;
    
    // Split by '/' and process each component
    while (getline(ss, component, '/')) {
        if (component == "" || component == ".") {
            // Skip empty and current directory
            continue;
        } else if (component == "..") {
            // Go to parent directory
            if (!st.empty()) {
                st.pop();
            }
        } else {
            // Valid directory name
            st.push(component);
        }
    }
    
    // Build result path
    string result = "";
    while (!st.empty()) {
        result = "/" + st.top() + result;
        st.pop();
    }
    
    return result.empty() ? "/" : result;
}

int main() {
    vector<string> testCases = {
        "/home/",
        "/../",
        "/home//foo/",
        "/a/./b/../../c/",
        "/a/../../b/../c//.//",
        "/a//b////c/d//././/..",
        "/"
    };
    
    for (const string& test : testCases) {
        string result = simplifyPath(test);
        cout << "Input:  \"" << test << "\"" << endl;
        cout << "Output: \"" << result << "\"" << endl << endl;
    }
    
    return 0;
}
