/*
PROBLEM: Remove All Adjacent Duplicates In String (LeetCode 1047)
DIFFICULTY: Easy
PATTERN: Stack for Removing Consecutive Elements

DESCRIPTION:
You are given a string s. Remove all adjacent duplicate characters repeatedly 
until no adjacent duplicates remain.

INPUT: s = "abbaca"
OUTPUT: "ca"
Explanation: 
"abbaca" -> "aaca" (remove "bb")
"aaca" -> "ca" (remove "aa")

INPUT: s = "azxxzy"
OUTPUT: "ay"

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to store characters. For each character:
- If stack is empty or top is different, push the character
- If top equals current character, pop (remove the duplicate pair)
This ensures all adjacent duplicates are removed in one pass.
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            // Found adjacent duplicate, remove it
            st.pop();
        } else {
            // No duplicate, add to stack
            st.push(c);
        }
    }
    
    // Build result string
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
}

// Optimized version using string as stack (in-place)
string removeDuplicatesOptimized(string s) {
    string result = "";
    
    for (char c : s) {
        if (!result.empty() && result.back() == c) {
            result.pop_back();
        } else {
            result.push_back(c);
        }
    }
    
    return result;
}

int main() {
    vector<string> testCases = {
        "abbaca",
        "azxxzy",
        "aabbcc",
        "aaa",
        "abcd",
        "mississippi"
    };
    
    for (const string& test : testCases) {
        string result1 = removeDuplicates(test);
        string result2 = removeDuplicatesOptimized(test);
        
        cout << "Input: \"" << test << "\"" << endl;
        cout << "Output (stack): \"" << result1 << "\"" << endl;
        cout << "Output (optimized): \"" << result2 << "\"" << endl << endl;
    }
    
    return 0;
}
