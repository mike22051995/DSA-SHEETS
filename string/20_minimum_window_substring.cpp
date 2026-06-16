/*
    Minimum Window Substring - LeetCode #76
    
    Given two strings s and t, return the minimum window substring of s such that
    every character in t (including duplicates) is included in the window. If there
    is no such substring, return the empty string "".
    
    Example 1:
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
    
    Example 2:
    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.
    
    Example 3:
    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    
    Constraints:
    - 1 <= s.length, t.length <= 10^5
    - s and t consist of uppercase and lowercase English letters
    
    Time Complexity: O(n + m)
    Space Complexity: O(1) - fixed size of 52 or 128 for ASCII
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";
        
        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }
        
        int required = tCount.size();
        int formed = 0;
        unordered_map<char, int> windowCount;
        
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        
        while (right < s.length()) {
            // Add character from right
            char c = s[right];
            windowCount[c]++;
            
            if (tCount.count(c) && windowCount[c] == tCount[c]) {
                formed++;
            }
            
            // Try to contract window
            while (left <= right && formed == required) {
                // Update result
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                
                // Remove from left
                char leftChar = s[left];
                windowCount[leftChar]--;
                
                if (tCount.count(leftChar) && windowCount[leftChar] < tCount[leftChar]) {
                    formed--;
                }
                
                left++;
            }
            
            right++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: \"" << sol.minWindow("ADOBECODEBANC", "ABC") << "\"" << endl;  // "BANC"
    cout << "Test 2: \"" << sol.minWindow("a", "a") << "\"" << endl;                // "a"
    cout << "Test 3: \"" << sol.minWindow("a", "aa") << "\"" << endl;               // ""
    
    return 0;
}
