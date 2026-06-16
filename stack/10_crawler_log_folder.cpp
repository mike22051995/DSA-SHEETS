/*
PROBLEM: Crawler Log Folder (LeetCode 1598)
DIFFICULTY: Easy
PATTERN: Stack for Navigation/Path Tracking

DESCRIPTION:
The Leetcode file system keeps a log each time some user performs a change folder operation.
Operations are described below:
- "../" : Move to the parent folder (if at main, remain)
- "./" : Remain in the same folder
- "x/" : Move to the child folder named x

Given logs of operations, return minimum number of operations needed to go back to main folder.

INPUT: logs = ["d1/","d2/","../","d21/","./"]
OUTPUT: 2
Explanation: cd d1/ -> cd d2/ -> cd ../ (back to d1/) -> cd d21/ -> ./ (stay)
Need to go back 2 levels: d1/d21/ -> d1/ -> main/

TIME COMPLEXITY: O(n) where n is number of operations
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack (or counter) to track depth. "../" pops from stack, "./" does nothing,
any other operation pushes to stack. Final stack size is the answer.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int minOperations(vector<string>& logs) {
    stack<string> st;
    
    for (const string& operation : logs) {
        if (operation == "../") {
            // Go to parent folder
            if (!st.empty()) {
                st.pop();
            }
        } else if (operation == "./") {
            // Stay in current folder
            continue;
        } else {
            // Move to child folder
            st.push(operation);
        }
    }
    
    return st.size();
}

// Optimized version using just a counter
int minOperationsOptimized(vector<string>& logs) {
    int depth = 0;
    
    for (const string& operation : logs) {
        if (operation == "../") {
            depth = max(0, depth - 1);
        } else if (operation != "./") {
            depth++;
        }
    }
    
    return depth;
}

void printVector(const vector<string>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<vector<string>> testCases = {
        {"d1/", "d2/", "../", "d21/", "./"},
        {"d1/", "d2/", "./", "d3/", "../", "../"},
        {"d1/", "../", "../", "../"},
        {"./", "../", "./"}
    };
    
    for (auto& logs : testCases) {
        cout << "Logs: ";
        printVector(logs);
        cout << endl;
        
        int result1 = minOperations(logs);
        int result2 = minOperationsOptimized(logs);
        
        cout << "Min operations (stack): " << result1 << endl;
        cout << "Min operations (optimized): " << result2 << endl << endl;
    }
    
    return 0;
}
