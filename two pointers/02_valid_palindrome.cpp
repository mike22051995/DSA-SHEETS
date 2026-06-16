/*
PROBLEM: Valid Palindrome
---------------------------------------------------------------------------
A phrase is a palindrome if, after converting all uppercase letters into 
lowercase letters and removing all non-alphanumeric characters, it reads 
the same forward and backward. Return true if it is a palindrome, false otherwise.

PATTERN: Opposite Direction Two Pointers
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Skip non-alphanumeric characters from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "A man, a plan, a canal: Panama";
    cout << "Test 1: " << (sol.isPalindrome(s1) ? "true" : "false") << endl;
    
    // Test case 2
    string s2 = "race a car";
    cout << "Test 2: " << (sol.isPalindrome(s2) ? "true" : "false") << endl;
    
    return 0;
}
