/*
    String to Integer (atoi) - LeetCode #8
    
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
    
    Algorithm:
    1. Read in and ignore any leading whitespace
    2. Check if the next character is '-' or '+'. Read this character if it is either.
    3. Read in next the characters until the next non-digit character or end of the input is reached.
    4. Convert these digits into an integer. If no digits were read, then the integer is 0.
    5. If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], 
       then clamp the integer so that it remains in the range.
    6. Return the integer as the final result.
    
    Example 1:
    Input: s = "42"
    Output: 42
    
    Example 2:
    Input: s = "   -42"
    Output: -42
    
    Example 3:
    Input: s = "4193 with words"
    Output: 4193
    
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Convert digits
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Check for overflow
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return (int)(result * sign);
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << sol.myAtoi("42") << endl;                    // 42
    cout << "Test 2: " << sol.myAtoi("   -42") << endl;                // -42
    cout << "Test 3: " << sol.myAtoi("4193 with words") << endl;       // 4193
    cout << "Test 4: " << sol.myAtoi("words and 987") << endl;         // 0
    cout << "Test 5: " << sol.myAtoi("-91283472332") << endl;          // -2147483648
    
    return 0;
}
