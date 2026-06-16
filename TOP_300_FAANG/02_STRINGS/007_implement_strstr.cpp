/*
================================================================================
PROBLEM: Implement strStr() / Find Index of First Occurrence (LeetCode #28)
DIFFICULTY: Easy
PATTERN: String Matching (KMP / Sliding Window)
COMPANIES: Amazon, Microsoft, Facebook, Google
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Simple sliding window
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int m = haystack.length(), n = needle.length();
        
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == n) return i;
        }
        
        return -1;
    }
    
    // KMP Algorithm - O(m + n)
    int strStrKMP(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int m = haystack.length(), n = needle.length();
        vector<int> lps = computeLPS(needle);
        
        int i = 0, j = 0;
        while (i < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                
                if (j == n) return i - j;
            } else {
                if (j > 0) {
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
        int len = 0, i = 1;
        
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
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
    cout << "Index (sadbutsad, sad): " << sol.strStr("sadbutsad", "sad") << endl;
    cout << "Index (leetcode, leeto): " << sol.strStr("leetcode", "leeto") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Repeated Substring Pattern (LeetCode #459)
2. Shortest Palindrome (LeetCode #214)
3. Longest Happy Prefix (LeetCode #1392)
4. Find All Anagrams in String (LeetCode #438)
5. Permutation in String (LeetCode #567)
6. Minimum Window Substring (LeetCode #76)
7. Substring with Concatenation (LeetCode #30)
8. Rabin-Karp Algorithm
9. Boyer-Moore Algorithm
10. Z Algorithm
*/
