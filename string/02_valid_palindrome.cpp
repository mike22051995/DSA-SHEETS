/*
    Valid Palindrome - LeetCode #125
    
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
    and removing all non-alphanumeric characters, it reads the same forward and backward.
    
    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
    
    Example 2:
    Input: s = "race a car"
    Output: false
    
    Constraints:
    - 1 <= s.length <= 2 * 10^5
    - s consists only of printable ASCII characters
    
    Time Complexity: O(n)
    Space Complexity: O(1)
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
    
    cout << "Test 1: " << (sol.isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << endl;
    cout << "Test 2: " << (sol.isPalindrome("race a car") ? "true" : "false") << endl;
    cout << "Test 3: " << (sol.isPalindrome(" ") ? "true" : "false") << endl;
    
    return 0;
}
