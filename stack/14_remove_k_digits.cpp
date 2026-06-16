/*
PROBLEM: Remove K Digits (LeetCode 402)
DIFFICULTY: Medium
PATTERN: Monotonic Stack for Optimization

DESCRIPTION:
Given string num representing a non-negative integer, and an integer k, 
return the smallest possible integer after removing k digits from the number.

INPUT: num = "1432219", k = 3
OUTPUT: "1219"
Explanation: Remove digits 4, 3, and 2 to form 1219 which is the smallest.

INPUT: num = "10200", k = 1
OUTPUT: "200"
Explanation: Remove leading 1, result is 200 (remove leading zeros).

TIME COMPLEXITY: O(n) where n is the length of num
SPACE COMPLEXITY: O(n) for the stack

EXPLANATION:
Use a monotonic increasing stack. For each digit, remove larger digits from stack
if we have remaining removals. This ensures the smallest number is formed.
After processing, remove any remaining digits from end and handle leading zeros.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    if (k >= num.length()) return "0";
    
    stack<char> st;
    
    for (char digit : num) {
        // Remove larger digits while we can
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    
    // Remove remaining k digits from end
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }
    
    // Build result from stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    // Remove leading zeros
    int i = 0;
    while (i < result.length() && result[i] == '0') {
        i++;
    }
    result = result.substr(i);
    
    return result.empty() ? "0" : result;
}

int main() {
    vector<pair<string, int>> testCases = {
        {"1432219", 3},
        {"10200", 1},
        {"10", 2},
        {"112", 1},
        {"9", 1},
        {"1234567890", 9},
        {"10001", 4}
    };
    
    for (const auto& test : testCases) {
        string num = test.first;
        int k = test.second;
        string result = removeKdigits(num, k);
        
        cout << "num = \"" << num << "\", k = " << k << endl;
        cout << "Result: \"" << result << "\"" << endl << endl;
    }
    
    return 0;
}
