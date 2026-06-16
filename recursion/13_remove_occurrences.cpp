/*
PROBLEM: Remove All Occurrences of a Character
---------------------------------------------------------------------------
Given a string and a character, remove all occurrences of that character 
from the string using recursion.

DIFFICULTY: Easy-Medium
PATTERN: Linear Recursion (String Building)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack + new string

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "hello", ch = 'l'
Output: "heo"
Explanation: Both 'l' characters are removed

Example 2:
Input: s = "aabbcc", ch = 'b'
Output: "aacc"
Explanation: Both 'b' characters are removed
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, char ch) {
        return removeHelper(s, ch, 0);
    }
    
    // Alternative: using substring
    string removeOccurrencesAlt(string s, char ch) {
        // Base case
        if (s.empty()) {
            return "";
        }
        
        // If first character matches, skip it
        if (s[0] == ch) {
            return removeOccurrencesAlt(s.substr(1), ch);
        }
        
        // Otherwise, keep it and process rest
        return s[0] + removeOccurrencesAlt(s.substr(1), ch);
    }
    
private:
    string removeHelper(string& s, char ch, int index) {
        // Base case
        if (index >= s.length()) {
            return "";
        }
        
        // Skip current character if it matches
        if (s[index] == ch) {
            return removeHelper(s, ch, index + 1);
        }
        
        // Keep current character
        return s[index] + removeHelper(s, ch, index + 1);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "hello";
    char ch1 = 'l';
    cout << "Test 1: Remove '" << ch1 << "' from '" << s1 << "' = '" 
         << sol.removeOccurrences(s1, ch1) << "'" << endl;
    
    // Test case 2
    string s2 = "aabbcc";
    char ch2 = 'b';
    cout << "Test 2: Remove '" << ch2 << "' from '" << s2 << "' = '" 
         << sol.removeOccurrencesAlt(s2, ch2) << "'" << endl;
    
    return 0;
}
