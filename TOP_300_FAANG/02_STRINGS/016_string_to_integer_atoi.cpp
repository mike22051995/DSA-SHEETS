/*
================================================================================
PROBLEM: String to Integer (atoi) (LeetCode #8)
DIFFICULTY: Medium
PATTERN: String Parsing
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple, Bloomberg
================================================================================
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Convert digits
        long long result = 0;
        
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Check for overflow
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return result * sign;
    }
};

int main() {
    Solution sol;
    
    cout << "\"42\" = " << sol.myAtoi("42") << endl;
    cout << "\"   -42\" = " << sol.myAtoi("   -42") << endl;
    cout << "\"4193 with words\" = " << sol.myAtoi("4193 with words") << endl;
    cout << "\"words and 987\" = " << sol.myAtoi("words and 987") << endl;
    cout << "\"-91283472332\" = " << sol.myAtoi("-91283472332") << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Reverse Integer (LeetCode #7)
2. Valid Number (LeetCode #65)
3. Roman to Integer (LeetCode #13)
4. Integer to Roman (LeetCode #12)
5. Integer to English Words (LeetCode #273)
6. Fraction to Recurring Decimal (LeetCode #166)
7. Excel Sheet Column Number (LeetCode #171)
8. Evaluate Reverse Polish Notation (LeetCode #150)
9. Basic Calculator (LeetCode #224)
10. Parse Lisp Expression (LeetCode #736)
*/
