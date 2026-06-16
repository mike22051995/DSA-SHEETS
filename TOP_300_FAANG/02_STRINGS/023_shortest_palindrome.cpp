/*
================================================================================
PROBLEM: Shortest Palindrome (LeetCode #214)
DIFFICULTY: Hard
PATTERN: KMP / Rolling Hash / String Matching
COMPANIES: Amazon, Microsoft, Google, Facebook
================================================================================

PROBLEM DESCRIPTION:
You are given a string s. You can convert s to a palindrome by adding characters
in front of it. Return the shortest palindrome you can find by performing this
transformation.

EXAMPLES:

Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:
Input: s = "abcd"
Output: "dcbabcd"

Example 3:
Input: s = ""
Output: ""

PATTERN RECOGNITION:
Use this pattern when:
- Need to find longest palindrome prefix
- String matching with reversal
- KMP algorithm for efficient pattern matching
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: KMP algorithm
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "#" + rev;
        
        vector<int> lps = computeLPS(combined);
        int palindromeLen = lps.back();
        
        string suffix = s.substr(palindromeLen);
        reverse(suffix.begin(), suffix.end());
        
        return suffix + s;
    }
    
    vector<int> computeLPS(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        int len = 0;
        
        for (int i = 1; i < n; ) {
            if (s[i] == s[len]) {
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
    
    // Approach 2: Two pointers
    string shortestPalindromeTwoPtr(string s) {
        int n = s.length();
        int i = 0;
        
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                i++;
            }
        }
        
        if (i == n) return s;
        
        string suffix = s.substr(i);
        string prefix = suffix;
        reverse(prefix.begin(), prefix.end());
        
        return prefix + shortestPalindromeTwoPtr(s.substr(0, i)) + suffix;
    }
};

int main() {
    Solution sol;
    
    cout << "aacecaaa -> " << sol.shortestPalindrome("aacecaaa") << endl;
    cout << "abcd -> " << sol.shortestPalindrome("abcd") << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(n) using KMP
SPACE COMPLEXITY: O(n) for LPS array

SIMILAR PROBLEMS:
1. Longest Palindromic Substring (LeetCode #5)
2. Palindromic Substrings (LeetCode #647)
3. Valid Palindrome II (LeetCode #680)
4. Longest Palindrome (LeetCode #409)
5. Palindrome Partitioning (LeetCode #131)
6. Palindrome Pairs (LeetCode #336)
7. Implement strStr() (LeetCode #28)
8. Repeated Substring Pattern (LeetCode #459)
9. Minimum Insertions to Make String Palindrome (LeetCode #1312)
10. Count Different Palindromic Subsequences (LeetCode #730)
*/
