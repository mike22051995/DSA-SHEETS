/*
PROBLEM: Check Palindrome String
---------------------------------------------------------------------------
Given a string, check if it is a palindrome using recursion.

DIFFICULTY: Easy
PATTERN: Linear Recursion (Two Pointers)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "racecar"
Output: true
Explanation: "racecar" reads the same forward and backward

Example 2:
Input: s = "hello"
Output: false
Explanation: "hello" is not a palindrome
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        return checkPalindrome(s, 0, s.length() - 1);
    }
    
private:
    bool checkPalindrome(string& s, int left, int right) {
        // Base case: single character or empty
        if (left >= right) {
            return true;
        }
        
        // Check if characters match
        if (s[left] != s[right]) {
            return false;
        }
        
        // Recursive case
        return checkPalindrome(s, left + 1, right - 1);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "racecar";
    cout << "Test 1: Is '" << s1 << "' palindrome? " 
         << (sol.isPalindrome(s1) ? "true" : "false") << endl;
    
    // Test case 2
    string s2 = "hello";
    cout << "Test 2: Is '" << s2 << "' palindrome? " 
         << (sol.isPalindrome(s2) ? "true" : "false") << endl;
    
    return 0;
}
