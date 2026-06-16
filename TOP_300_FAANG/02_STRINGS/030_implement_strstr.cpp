/*
================================================================================
PROBLEM: Find the Index of First Occurrence (Implement strStr) (LeetCode #28)
DIFFICULTY: Easy
PATTERN: String Matching / KMP / Two Pointers
COMPANIES: Amazon, Microsoft, Facebook, Google, Apple
================================================================================

PROBLEM DESCRIPTION:
Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.

EXAMPLES:

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6. First occurrence is at index 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

PATTERN RECOGNITION:
Use this pattern when:
- Find substring in string
- Pattern matching with KMP or simple iteration
- String search algorithms
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Simple approach
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int m = haystack.length();
        int n = needle.length();
        
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == n) return i;
        }
        
        return -1;
    }
    
    // KMP algorithm
    int strStrKMP(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int m = haystack.length();
        int n = needle.length();
        
        // Build LPS array
        vector<int> lps = computeLPS(needle);
        
        int i = 0;  // haystack index
        int j = 0;  // needle index
        
        while (i < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            
            if (j == n) {
                return i - j;
            } else if (i < m && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return -1;
    }
    
    vector<int> computeLPS(string pattern) {
        int n = pattern.length();
        vector<int> lps(n, 0);
        int len = 0;
        
        for (int i = 1; i < n; ) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
};

int main() {
    Solution sol;
    
    cout << "sadbutsad, sad: " << sol.strStr("sadbutsad", "sad") << endl;
    cout << "leetcode, leeto: " << sol.strStr("leetcode", "leeto") << endl;
    cout << "hello, ll: " << sol.strStr("hello", "ll") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(m * n) simple, O(m + n) for KMP
SPACE COMPLEXITY: O(1) simple, O(n) for KMP (LPS array)

SIMILAR PROBLEMS:
1. Repeated Substring Pattern (LeetCode #459)
2. Shortest Palindrome (LeetCode #214)
3. Longest Happy Prefix (LeetCode #1392)
4. Find All Occurrences of Pattern (Classic KMP)
5. Rotate String (LeetCode #796)
6. Longest Duplicate Substring (LeetCode #1044)
7. Longest Common Prefix (LeetCode #14)
8. Valid Anagram (LeetCode #242)
9. Find All Anagrams (LeetCode #438)
10. Isomorphic Strings (LeetCode #205)
*/
