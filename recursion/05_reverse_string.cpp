 /*
PROBLEM: Reverse String
---------------------------------------------------------------------------
Write a recursive function that reverses a string.

DIFFICULTY: Easy
PATTERN: Linear Recursion
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n) - recursion stack

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "hello"
Output: "olleh"

Example 2:
Input: s = "recursion"
Output: "noisrucer"
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Method 1: Using helper with indices
    string reverseString(string s) {
        reverseHelper(s, 0, s.length() - 1);
        return s;
    }
    
    // Method 2: Building new string
    string reverseStringBuild(string s) {
        if (s.empty()) {
            return "";
        }
        return reverseStringBuild(s.substr(1)) + s[0];
    }
    
private:
    void reverseHelper(string& s, int left, int right) {
        if (left >= right) {
            return;
        }
        
        swap(s[left], s[right]);
        reverseHelper(s, left + 1, right - 1);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "hello";
    cout << "Test 1: Reverse of '" << s1 << "' = '" << sol.reverseString(s1) << "'" << endl;
    
    // Test case 2
    string s2 = "recursion";
    cout << "Test 2: Reverse of '" << s2 << "' = '" << sol.reverseStringBuild(s2) << "'" << endl;
    
    return 0;
}
