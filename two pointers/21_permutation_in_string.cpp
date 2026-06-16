/*
PROBLEM: Permutation in String
---------------------------------------------------------------------------
Given two strings s1 and s2, return true if s2 contains a permutation of s1, 
or false otherwise. In other words, return true if one of s1's permutations 
is a substring of s2.

PATTERN: Sliding Window (Fixed Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(26) = O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
Explanation: s2 does not contain any permutation of s1.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        
        // Count characters in s1
        for (char c : s1) {
            s1Count[c - 'a']++;
        }
        
        // Sliding window
        for (int i = 0; i < s2.length(); i++) {
            s2Count[s2[i] - 'a']++;
            
            // Remove leftmost character if window exceeds s1 size
            if (i >= s1.length()) {
                s2Count[s2[i - s1.length()] - 'a']--;
            }
            
            // Check if current window matches
            if (s1Count == s2Count) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1_1 = "ab";
    string s2_1 = "eidbaooo";
    cout << "Test 1: " << (sol.checkInclusion(s1_1, s2_1) ? "true" : "false") << endl;
    
    // Test case 2
    string s1_2 = "ab";
    string s2_2 = "eidboaoo";
    cout << "Test 2: " << (sol.checkInclusion(s1_2, s2_2) ? "true" : "false") << endl;
    
    return 0;
}
