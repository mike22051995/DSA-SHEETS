/*
PROBLEM: Decode String (LeetCode 394)
DIFFICULTY: Medium
PATTERN: Stack for Nested Structures

DESCRIPTION:
Given an encoded string, return its decoded string.
Encoding rule: k[encoded_string], where encoded_string is repeated exactly k times.
You may assume input is always valid with properly nested brackets.

INPUT: s = "3[a]2[bc]"
OUTPUT: "aaabcbc"

INPUT: s = "3[a2[c]]"
OUTPUT: "accaccacc"

INPUT: s = "2[abc]3[cd]ef"
OUTPUT: "abcabccdcdcdef"

TIME COMPLEXITY: O(n) where n is the length of decoded string
SPACE COMPLEXITY: O(n) for the stacks

EXPLANATION:
Use two stacks - one for numbers (repeat count) and one for strings.
When we encounter '[', push current string and number to stacks.
When we encounter ']', pop from stacks and build the decoded string.
For regular characters, append to current string.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<int> numStack;
    stack<string> strStack;
    string currentStr = "";
    int currentNum = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            // Build the number (can be multi-digit)
            currentNum = currentNum * 10 + (c - '0');
        } else if (c == '[') {
            // Push current state and reset
            numStack.push(currentNum);
            strStack.push(currentStr);
            currentNum = 0;
            currentStr = "";
        } else if (c == ']') {
            // Pop and decode
            int repeatTimes = numStack.top();
            numStack.pop();
            string decodedStr = strStack.top();
            strStack.pop();
            
            // Repeat current string and append to previous
            for (int i = 0; i < repeatTimes; i++) {
                decodedStr += currentStr;
            }
            currentStr = decodedStr;
        } else {
            // Regular character
            currentStr += c;
        }
    }
    
    return currentStr;
}

int main() {
    vector<string> testCases = {
        "3[a]2[bc]",
        "3[a2[c]]",
        "2[abc]3[cd]ef",
        "abc3[cd]xyz",
        "100[leetcode]",
        "3[z]2[2[y]pq4[2[jk]e1[f]]]ef"
    };
    
    for (const string& test : testCases) {
        string result = decodeString(test);
        cout << "Encoded: \"" << test << "\"" << endl;
        cout << "Decoded: \"" << result << "\"" << endl << endl;
    }
    
    return 0;
}
