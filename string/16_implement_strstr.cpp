/*
    Implement strStr() / Find the Index of the First Occurrence - LeetCode #28
    
    Given two strings needle and haystack, return the index of the first occurrence
    of needle in haystack, or -1 if needle is not part of haystack.
    
    Example 1:
    Input: haystack = "sadbutsad", needle = "sad"
    Output: 0
    Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0.
    
    Example 2:
    Input: haystack = "leetcode", needle = "leeto"
    Output: -1
    Explanation: "leeto" did not occur in "leetcode".
    
    Constraints:
    - 1 <= haystack.length, needle.length <= 10^4
    - haystack and needle consist of only lowercase English characters
    
    Time Complexity: O(n*m) naive, O(n+m) with KMP
    Space Complexity: O(1) naive, O(m) with KMP
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Naive / Built-in
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int n = haystack.length();
        int m = needle.length();
        
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;
        }
        
        return -1;
    }
    
    // Approach 2: KMP Algorithm
    int strStrKMP(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int n = haystack.length();
        int m = needle.length();
        
        // Build LPS array
        vector<int> lps = buildLPS(needle);
        
        int i = 0;  // index for haystack
        int j = 0;  // index for needle
        
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            
            if (j == m) {
                return i - j;
            } else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return -1;
    }
    
private:
    vector<int> buildLPS(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        
        while (i < m) {
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
    
    cout << "Test 1: " << sol.strStr("sadbutsad", "sad") << endl;      // 0
    cout << "Test 2: " << sol.strStr("leetcode", "leeto") << endl;     // -1
    cout << "Test 3: " << sol.strStr("hello", "ll") << endl;           // 2
    cout << "Test 4: " << sol.strStr("aaaaa", "bba") << endl;          // -1
    
    return 0;
}
