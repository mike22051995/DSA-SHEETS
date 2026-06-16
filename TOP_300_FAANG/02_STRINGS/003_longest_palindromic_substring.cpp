/*
================================================================================
PROBLEM: Longest Palindromic Substring (LeetCode #5)
DIFFICULTY: Medium
PATTERN: Expand Around Center / Dynamic Programming
COMPANIES: Amazon, Microsoft, Google, Facebook, Apple
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Expand Around Center - O(n^2)
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            int len1 = expandAroundCenter(s, i, i);
            // Even length palindrome
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    
    // DP Approach
    string longestPalindromeDP(string s) {
        int n = s.length();
        if (n < 2) return s;
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;
        
        // All single chars are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Check for 2-char palindromes
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        // Check for lengths >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    cout << "Longest palindrome (babad): " << sol.longestPalindrome("babad") << endl;
    cout << "Longest palindrome (cbbd): " << sol.longestPalindrome("cbbd") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Shortest Palindrome (LeetCode #214)
2. Palindrome Partitioning (LeetCode #131)
3. Palindrome Partitioning II (LeetCode #132)
4. Longest Palindromic Subsequence (LeetCode #516)
5. Palindromic Substrings (LeetCode #647)
6. Valid Palindrome II (LeetCode #680)
7. Longest Chunked Palindrome Decomposition (LeetCode #1147)
8. Count Different Palindromic Subsequences (LeetCode #730)
9. Manacher's Algorithm
10. Expand Around Center Pattern
*/
