/*
PROBLEM: Minimum Window Substring
Difficulty: Hard
Pattern: Sliding Window, Hash Map

DESCRIPTION:
Given two strings s and t of lengths m and n respectively, return the minimum window substring 
of s such that every character in t (including duplicates) is included in the window. If there 
is no such substring, return the empty string "".

EXPLANATION:
Sliding Window with two pointers:
1. Expand window by moving right pointer until all characters of t are included
2. Contract window by moving left pointer while maintaining all characters
3. Track minimum window that contains all characters
4. Use hash map to track character frequencies

Time Complexity: O(m + n)
Space Complexity: O(n)

INPUT-OUTPUT EXAMPLES:

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: Minimum window containing A, B, and C

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: Entire string is the minimum window

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Not enough 'a's in s
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
        
        unordered_map<char, int> need, window;
        
        // Count characters in t
        for (char c : t) {
            need[c]++;
        }
        
        int left = 0, right = 0;
        int valid = 0; // Count of characters matched
        int start = 0, minLen = INT_MAX;
        
        while (right < s.length()) {
            char c = s[right];
            right++;
            
            // Update window
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            
            // Contract window
            while (valid == need.size()) {
                // Update minimum window
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                
                char d = s[left];
                left++;
                
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Test 1: " << solution.minWindow(s1, t1) << endl;
    
    // Test Case 2
    string s2 = "a", t2 = "a";
    cout << "Test 2: " << solution.minWindow(s2, t2) << endl;
    
    // Test Case 3
    string s3 = "a", t3 = "aa";
    cout << "Test 3: " << solution.minWindow(s3, t3) << endl;
    
    return 0;
}
