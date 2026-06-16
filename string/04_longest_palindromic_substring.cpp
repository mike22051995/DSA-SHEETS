/*
    Longest Palindromic Substring - LeetCode #5
    
    Given a string s, return the longest palindromic substring in s.
    
    Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
    
    Example 2:
    Input: s = "cbbd"
    Output: "bb"
    
    Constraints:
    - 1 <= s.length <= 1000
    - s consist of only digits and English letters
    
    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Expand Around Center
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindromes
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    
public:
    // Approach 2: Dynamic Programming
    string longestPalindromeDP(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;
        
        // All single characters are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Check for two character palindromes
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        // Check for lengths greater than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
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
    
    cout << "Test 1: " << sol.longestPalindrome("babad") << endl;      // "bab" or "aba"
    cout << "Test 2: " << sol.longestPalindrome("cbbd") << endl;       // "bb"
    cout << "Test 3: " << sol.longestPalindrome("racecar") << endl;    // "racecar"
    cout << "Test 4: " << sol.longestPalindrome("a") << endl;          // "a"
    cout << "Test 5: " << sol.longestPalindrome("ac") << endl;         // "a" or "c"
    
    return 0;
}
