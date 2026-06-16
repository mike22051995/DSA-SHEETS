/*
PROBLEM: Backspace String Compare (LeetCode 844)
DIFFICULTY: Easy
PATTERN: Stack for String Processing

DESCRIPTION:
Given two strings s and t, return true if they are equal when both are typed into 
empty text editors. '#' means a backspace character.

INPUT: s = "ab#c", t = "ad#c"
OUTPUT: true
Explanation: Both s and t become "ac"

INPUT: s = "ab##", t = "c#d#"
OUTPUT: true
Explanation: Both s and t become ""

TIME COMPLEXITY: O(n + m) where n and m are lengths of strings
SPACE COMPLEXITY: O(n + m) for stacks

EXPLANATION:
Use a stack to process each string. When encountering a regular character, push it.
When encountering '#', pop from stack (if not empty). After processing both strings,
compare the final stacks.
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string processString(const string& s) {
    stack<char> st;
    
    for (char c : s) {
        if (c != '#') {
            st.push(c);
        } else if (!st.empty()) {
            st.pop();
        }
    }
    
    // Build result string from stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
}

bool backspaceCompare(string s, string t) {
    return processString(s) == processString(t);
}

// Space-optimized approach using two pointers - O(1) space
bool backspaceCompareOptimized(string s, string t) {
    int i = s.length() - 1;
    int j = t.length() - 1;
    int skipS = 0, skipT = 0;
    
    while (i >= 0 || j >= 0) {
        // Find next valid character in s
        while (i >= 0) {
            if (s[i] == '#') {
                skipS++;
                i--;
            } else if (skipS > 0) {
                skipS--;
                i--;
            } else {
                break;
            }
        }
        
        // Find next valid character in t
        while (j >= 0) {
            if (t[j] == '#') {
                skipT++;
                j--;
            } else if (skipT > 0) {
                skipT--;
                j--;
            } else {
                break;
            }
        }
        
        // Compare characters
        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false;
        }
        
        // If one string is exhausted but not the other
        if ((i >= 0) != (j >= 0)) {
            return false;
        }
        
        i--;
        j--;
    }
    
    return true;
};

int main() {
    vector<pair<string, string>> testCases = {
        {"ab#c", "ad#c"},
        {"ab##", "c#d#"},
        {"a##c", "#a#c"},
        {"a#c", "b"},
        {"bxj##tw", "bxo#j##tw"}
    };
    
    for (const auto& test : testCases) {
        string s = test.first;
        string t = test.second;
        bool result1 = backspaceCompare(s, t);
        bool result2 = backspaceCompareOptimized(s, t);
        
        cout << "s = \"" << s << "\", t = \"" << t << "\"" << endl;
        cout << "Stack approach: " << (result1 ? "true" : "false") << endl;
        cout << "Optimized approach: " << (result2 ? "true" : "false") << endl;
        cout << "Final strings: \"" << processString(s) << "\" vs \"" 
             << processString(t) << "\"" << endl << endl;
    }
    
    return 0;
}
