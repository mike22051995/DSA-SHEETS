/*
PROBLEM: Minimum Window Substring
---------------------------------------------------------------------------
Given two strings s and t, return the minimum window substring of s such 
that every character in t (including duplicates) is included in the window. 
If no such substring exists, return the empty string "".

PATTERN: Sliding Window (Variable Size with HashMap)
TIME COMPLEXITY: O(m + n) where m = s.length, n = t.length
SPACE COMPLEXITY: O(n)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: Minimum window substring "BANC" includes 'A', 'B', 'C' from t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: Entire string s is the minimum window.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }
        
        int required = tCount.size();
        int formed = 0;
        unordered_map<char, int> windowCount;
        
        int left = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            windowCount[c]++;
            
            if (tCount.count(c) && windowCount[c] == tCount[c]) {
                formed++;
            }
            
            // Try to shrink window
            while (left <= right && formed == required) {
                // Update result
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                
                char leftChar = s[left];
                windowCount[leftChar]--;
                if (tCount.count(leftChar) && windowCount[leftChar] < tCount[leftChar]) {
                    formed--;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Test 1: " << sol.minWindow(s1, t1) << endl;
    
    // Test case 2
    string s2 = "a";
    string t2 = "a";
    cout << "Test 2: " << sol.minWindow(s2, t2) << endl;
    
    return 0;
}
