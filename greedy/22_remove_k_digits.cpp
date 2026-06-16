/*
PROBLEM: Remove K Digits (LeetCode 402)
DIFFICULTY: Hard
PATTERN: Monotonic Stack Greedy

DESCRIPTION:
Given string num representing a non-negative integer num, and an integer k, return the 
smallest possible integer after removing k digits from num.

INPUT:
- num: string representing a number
- k: number of digits to remove

OUTPUT:
- Smallest possible number as string

APPROACH:
1. Use stack to build result
2. For each digit, pop larger digits from stack (while k > 0)
3. This maintains increasing order (monotonic stack)
4. Remove leading zeros
5. If all removed, return "0"

WHY GREEDY WORKS:
To minimize number, we want smaller digits at front. Removing larger digits 
from left side gives smaller result.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.length()) return "0";
        
        stack<char> st;
        
        for (char digit : num) {
            // Remove larger digits from stack while we can
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        // If k is still > 0, remove from end
        while (k > 0) {
            st.pop();
            k--;
        }
        
        // Build result string
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
};

int main() {
    Solution sol;
    
    // Test Case 1
    cout << "Test 1 - num: \"1432219\", k=3" << endl;
    cout << "Output: " << sol.removeKdigits("1432219", 3) << endl;
    cout << "Expected: 1219" << endl << endl;
    
    // Test Case 2
    cout << "Test 2 - num: \"10200\", k=1" << endl;
    cout << "Output: " << sol.removeKdigits("10200", 1) << endl;
    cout << "Expected: 200" << endl << endl;
    
    // Test Case 3
    cout << "Test 3 - num: \"10\", k=2" << endl;
    cout << "Output: " << sol.removeKdigits("10", 2) << endl;
    cout << "Expected: 0" << endl << endl;
    
    // Test Case 4
    cout << "Test 4 - num: \"112\", k=1" << endl;
    cout << "Output: " << sol.removeKdigits("112", 1) << endl;
    cout << "Expected: 11" << endl << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is length of num
SPACE COMPLEXITY: O(n) for stack

KEY LEARNING:
- Monotonic stack: maintain increasing/decreasing order
- Greedy: remove larger digits from left to minimize number
- Handle edge cases: leading zeros, all digits removed
- Pattern appears in many "remove K" problems
- Stack-based greedy is powerful for sequence problems
- Common in Amazon/Microsoft interviews
*/
