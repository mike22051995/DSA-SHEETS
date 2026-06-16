/*
================================================================================
PROBLEM: Isomorphic Strings (LeetCode #205)
DIFFICULTY: Easy
PATTERN: Hash Map / String
COMPANIES: Amazon, Microsoft, Facebook, Google, LinkedIn
================================================================================

PROBLEM DESCRIPTION:
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same
character, but a character may map to itself.

EXAMPLES:

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation: 'e' -> 'a', 'g' -> 'd'

Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation: 'o' maps to both 'a' and 'r'

Example 3:
Input: s = "paper", t = "title"
Output: true
Explanation: 'p' -> 't', 'a' -> 'i', 'e' -> 'l', 'r' -> 'e'

PATTERN RECOGNITION:
Use this pattern when:
- Need to check one-to-one character mapping between strings
- Preserve order while transforming
- Each character maps uniquely
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Two hash maps
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;
        
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            if (mapST.count(c1)) {
                if (mapST[c1] != c2) return false;
            } else {
                mapST[c1] = c2;
            }
            
            if (mapTS.count(c2)) {
                if (mapTS[c2] != c1) return false;
            } else {
                mapTS[c2] = c1;
            }
        }
        
        return true;
    }
    
    // Approach 2: Using arrays (faster)
    bool isIsomorphicArray(string s, string t) {
        int m1[256] = {0}, m2[256] = {0};
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    
    cout << "egg, add: " << (sol.isIsomorphic("egg", "add") ? "true" : "false") << endl;
    cout << "foo, bar: " << (sol.isIsomorphic("foo", "bar") ? "true" : "false") << endl;
    cout << "paper, title: " << (sol.isIsomorphic("paper", "title") ? "true" : "false") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) where n is length of string
SPACE COMPLEXITY: O(1) - fixed size for ASCII characters

SIMILAR PROBLEMS:
1. Word Pattern (LeetCode #290)
2. Word Pattern II (LeetCode #291)
3. Valid Anagram (LeetCode #242)
4. Group Anagrams (LeetCode #49)
5. Find and Replace Pattern (LeetCode #890)
6. Buddy Strings (LeetCode #859)
7. Check If Two String Arrays are Equivalent (LeetCode #1662)
8. Determine if Two Strings Are Close (LeetCode #1657)
9. Compare Strings by Frequency (LeetCode #1170)
10. Custom Sort String (LeetCode #791)
*/
