/*
PROBLEM: Make The String Great (LeetCode 1544)
DIFFICULTY: Easy
PATTERN: Stack for Character Matching

DESCRIPTION:
A string is "great" if there are no two adjacent characters s[i] and s[i+1] where:
- 0 <= i <= s.length - 2
- s[i] is a lower-case letter and s[i+1] is the same letter but in upper-case or vice-versa

Given a string s, return the string after making it great by removing adjacent pairs.

INPUT: s = "leEeetcode"
OUTPUT: "leetcode"
Explanation: Remove "Ee", then "eE"

INPUT: s = "abBAcC"
OUTPUT: ""

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a stack to track characters. For each character, check if it forms a "bad pair"
with the top of stack (same letter, different case). If yes, pop. Otherwise, push.
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool isBadPair(char a, char b) {
    // Check if same letter but different cases
    return abs(a - b) == 32;  // ASCII difference between same letter in different cases
}

string makeGood(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (!st.empty() && isBadPair(st.top(), c)) {
            st.pop();  // Remove the bad pair
        } 
        else {
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

// Using string as stack (more efficient)
string makeGoodOptimized(string s) {
    string result = "";
    
    for (char c : s) {
        if (!result.empty() && abs(result.back() - c) == 32) {
            result.pop_back();
        } else {
            result.push_back(c);
        }
    }
    
    return result;
}

int main() {
    vector<string> testCases = {
        "leEeetcode",
        "abBAcC",
        "s",
        "Pp",
        "AaBbCcDdEe",
        "mC"
    };
    
    for (const string& test : testCases) {
        string result1 = makeGood(test);
        string result2 = makeGoodOptimized(test);
        
        cout << "Input: \"" << test << "\"" << endl;
        cout << "Output (stack): \"" << result1 << "\"" << endl;
        cout << "Output (optimized): \"" << result2 << "\"" << endl << endl;
    }
    
    return 0;
}
