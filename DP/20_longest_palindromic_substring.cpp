/*
PROBLEM: Longest Palindromic Substring
Difficulty: Medium
Pattern: 2D DP, String Palindrome

DESCRIPTION:
Given a string s, return the longest palindromic substring in s.

INPUT:
s = "babad"

OUTPUT:
"bab"
Note: "aba" is also a valid answer.

TIME COMPLEXITY: O(n^2) for DP and expand around center, O(n) for Manacher's algorithm
SPACE COMPLEXITY: O(n^2) for DP, O(1) for expand around center
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: Expand Around Center (Most intuitive and space efficient)
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < n; i++) {
            // Check for odd length palindromes (center is a single character)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes (center is between two characters)
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
    
    // Method 2: DP Approach
    string longestPalindromeDP(string s) {
        int n = s.length();
        if (n < 2) return s;
        
        // dp[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int start = 0, maxLen = 1;
        
        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Check for length 2
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
                
                // s[i...j] is palindrome if s[i] == s[j] AND s[i+1...j-1] is palindrome
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
    
    // Test Case 1
    string s1 = "babad";
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: \"" << sol.longestPalindrome(s1) << "\"" << endl;
    cout << "Output (DP): \"" << sol.longestPalindromeDP(s1) << "\"" << endl << endl;
    
    // Test Case 2
    string s2 = "cbbd";
    cout << "Input: s = \"" << s2 << "\"" << endl;
    cout << "Output: \"" << sol.longestPalindrome(s2) << "\"" << endl;
    cout << "Output (DP): \"" << sol.longestPalindromeDP(s2) << "\"" << endl << endl;
    
    // Test Case 3
    string s3 = "racecar";
    cout << "Input: s = \"" << s3 << "\"" << endl;
    cout << "Output: \"" << sol.longestPalindrome(s3) << "\"" << endl;
    cout << "Output (DP): \"" << sol.longestPalindromeDP(s3) << "\"" << endl;
    
    return 0;
}

/*
EXPLANATION:
Expand Around Center:
1. Palindrome mirrors around its center
2. For each position, expand outward while characters match
3. Handle both odd-length (single center) and even-length (two centers)
4. Track the longest palindrome found

DP Approach:
1. dp[i][j] = true if substring s[i...j] is a palindrome
2. Base cases:
   - Single character: dp[i][i] = true
   - Two characters: dp[i][i+1] = (s[i] == s[i+1])
3. For longer substrings:
   - dp[i][j] = (s[i] == s[j]) AND dp[i+1][j-1]
4. Build from smaller lengths to larger

KEY LEARNING:
- Multiple approaches: DP, Expand around center, Manacher's
- Expand around center is most practical (O(n^2) time, O(1) space)
- DP uses O(n^2) space but easier to extend to counting problems
- Pattern used in: Palindrome Partitioning, Palindrome Count
*/
