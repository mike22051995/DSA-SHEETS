/*
    Minimum Window Subsequence - LeetCode #727 (Premium)
    
    Given strings s and t, find the minimum (contiguous) substring of s, such that t is a
    subsequence of this substring. If there is no such substring, return the empty string "".
    
    Example 1:
    Input: s = "abcdebdde", t = "bde"
    Output: "bcde"
    Explanation: "bcde" is the shortest substring that contains the subsequence "bde".
    "deb" is also a valid answer, but we choose "bcde" since it comes first.
    
    Example 2:
    Input: s = "jmeqksfrsdcmsiwvaovztaqenprpvnbstl", t = "u"
    Output: ""
    
    Constraints:
    - 1 <= s.length <= 2 * 10^4
    - 1 <= t.length <= 100
    - s and t consist of lowercase English letters
    
    Note: A subsequence of a string is a new string that is formed from the original string
    by deleting some (can be none) of the characters without disturbing the relative positions
    of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
    
    Time Complexity: O(m*n) where m = len(s), n = len(t)
    Space Complexity: O(m*n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Approach 1: Dynamic Programming
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        
        // dp[i][j] = start index of minimum window ending at s[i] that contains t[0...j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        // Empty t is valid for all positions
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        int minLen = INT_MAX;
        int start = 0;
        
        // Find minimum window
        for (int i = 1; i <= m; i++) {
            if (dp[i][n] != -1) {
                int len = i - dp[i][n];
                if (len < minLen) {
                    minLen = len;
                    start = dp[i][n];
                }
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
    
    // Approach 2: Two Pointers (Optimized)
    string minWindowTwoPointers(string s, string t) {
        int m = s.length(), n = t.length();
        int minLen = INT_MAX;
        string result = "";
        
        int i = 0;
        while (i < m) {
            int j = 0;
            
            // Find the first occurrence of t[0] in s starting from i
            while (i < m && s[i] != t[j]) {
                i++;
            }
            
            if (i == m) break;
            
            int start = i;
            
            // Try to match all characters of t
            while (i < m && j < n) {
                if (s[i] == t[j]) {
                    j++;
                }
                i++;
            }
            
            // If we matched all characters of t
            if (j == n) {
                // Move back to minimize window
                i--;
                j--;
                
                while (j >= 0) {
                    if (s[i] == t[j]) {
                        j--;
                    }
                    i--;
                }
                
                i++;
                
                // Update result if this window is smaller
                if (start - i + 1 < minLen) {
                    minLen = start - i + 1;
                    result = s.substr(i, start - i + 1);
                }
                
                i++;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: \"" << sol.minWindow("abcdebdde", "bde") << "\"" << endl;                        // "bcde"
    cout << "Test 2: \"" << sol.minWindow("jmeqksfrsdcmsiwvaovztaqenprpvnbstl", "u") << "\"" << endl; // ""
    cout << "Test 3: \"" << sol.minWindow("cnhczmccqouqauvlmgkztudygjkz", "mm") << "\"" << endl;      // "mccqouqauvlm"
    
    return 0;
}
