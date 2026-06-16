/*
================================================================================
PROBLEM: Palindromic Substrings (LeetCode #647)
DIFFICULTY: Medium
PATTERN: Expand Around Center / Dynamic Programming
COMPANIES: Amazon, Facebook, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Expand Around Center - O(n^2)
    int countSubstrings(string s) {
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindromes
            count += expandAroundCenter(s, i, i);
            // Even length palindromes
            count += expandAroundCenter(s, i, i + 1);
        }
        
        return count;
    }
    
    int expandAroundCenter(string& s, int left, int right) {
        int count = 0;
        
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        
        return count;
    }
    
    // DP Approach
    int countSubstringsDP(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        
        // All single characters are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            count++;
        }
        
        // Check for 2-character palindromes
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                count++;
            }
        }
        
        // Check for lengths >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    cout << "Count (abc): " << sol.countSubstrings("abc") << endl;
    cout << "Count (aaa): " << sol.countSubstrings("aaa") << endl;
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Longest Palindromic Substring (LeetCode #5)
2. Longest Palindromic Subsequence (LeetCode #516)
3. Palindrome Partitioning (LeetCode #131)
4. Palindrome Partitioning II (LeetCode #132)
5. Valid Palindrome (LeetCode #125)
6. Valid Palindrome II (LeetCode #680)
7. Shortest Palindrome (LeetCode #214)
8. Count Different Palindromic Subsequences (LeetCode #730)
9. Palindrome Removal (LeetCode #1246)
10. Maximum Product of Splitted Binary Tree (LeetCode #1339)
*/
