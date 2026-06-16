/*
PROBLEM: Find All Anagrams in a String
---------------------------------------------------------------------------
Given two strings s and p, return an array of all the start indices of p's 
anagrams in s. An Anagram is a word formed by rearranging the letters of 
a different word.

PATTERN: Sliding Window (Fixed Size)
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(26) = O(1)

INPUT/OUTPUT EXAMPLES:
---------------------------------------------------------------------------
Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation: The anagrams "cba" at index 0 and "bac" at index 6.

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation: Anagrams "ab" at 0, "ba" at 1, "ab" at 2.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;
        
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        
        // Count characters in p
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        // Sliding window
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            
            // Remove leftmost character if window exceeds p size
            if (i >= p.length()) {
                sCount[s[i - p.length()] - 'a']--;
            }
            
            // Check if current window is an anagram
            if (pCount == sCount) {
                result.push_back(i - p.length() + 1);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "cbaebabacd";
    string p1 = "abc";
    vector<int> result1 = sol.findAnagrams(s1, p1);
    cout << "Test 1: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i] << (i < result1.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    // Test case 2
    string s2 = "abab";
    string p2 = "ab";
    vector<int> result2 = sol.findAnagrams(s2, p2);
    cout << "Test 2: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i < result2.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
    
    return 0;
}
