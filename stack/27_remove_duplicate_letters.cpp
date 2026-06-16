/*
PROBLEM: Remove Duplicate Letters (LeetCode 316) / Smallest Subsequence (LeetCode 1081)
DIFFICULTY: Hard
PATTERN: Greedy + Monotonic Stack

DESCRIPTION:
Given a string s, remove duplicate letters so that every letter appears once and only once.
You must make sure your result is the smallest in lexicographical order among all possible results.

INPUT: s = "bcabc"
OUTPUT: "abc"

INPUT: s = "cbacdcbc"
OUTPUT: "acdb"

TIME COMPLEXITY: O(n) where n is the length of string
SPACE COMPLEXITY: O(1) - using constant space (26 letters)

EXPLANATION:
Use a greedy approach with monotonic stack. Track:
1. Count of remaining characters
2. Whether character is already in result
For each character, decide whether to remove previous characters to get smaller result.
Remove previous character if: it's larger, appears later, and not already used.
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> count(26, 0);  // Count of each character
    vector<bool> inStack(26, false);  // Whether character is in result
    stack<char> st;
    
    // Count frequency of each character
    for (char c : s) {
        count[c - 'a']++;
    }
    
    for (char c : s) {
        count[c - 'a']--;  // Decrease count as we process
        
        if (inStack[c - 'a']) {
            continue;  // Already in result
        }
        
        // Remove larger characters that appear later
        while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
            inStack[st.top() - 'a'] = false;
            st.pop();
        }
        
        st.push(c);
        inStack[c - 'a'] = true;
    }
    
    // Build result from stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
}

int main() {
    vector<string> testCases = {
        "bcabc",
        "cbacdcbc",
        "abacb",
        "ecbacba",
        "bbcaac",
        "rusrbofeggbbkyuyjsrzornpdguwzizqszpbicdquakqws"
    };
    
    for (const string& test : testCases) {
        string result = removeDuplicateLetters(test);
        cout << "Input:  \"" << test << "\"" << endl;
        cout << "Output: \"" << result << "\"" << endl << endl;
    }
    
    return 0;
}
