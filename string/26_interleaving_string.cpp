/*
    Interleaving String - LeetCode #97
    
    Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
    An interleaving of two strings s and t is a configuration where s and t are divided into
    n and m substrings respectively, such that: s = s1 + s2 + ... + sn, t = t1 + t2 + ... + tm,
    and s3 = s1 + t1 + s2 + t2 + ... or t1 + s1 + t2 + s2 + ...
    
    Example 1:
    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    Output: true
    Explanation: One way to obtain s3 is:
    Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
    Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
    
    Example 2:
    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
    Output: false
    
    Example 3:
    Input: s1 = "", s2 = "", s3 = ""
    Output: true
    
    Constraints:
    - 0 <= s1.length, s2.length <= 100
    - 0 <= s3.length <= 200
    - s1, s2, and s3 consist of lowercase English letters
    
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        if (m + n != s3.length()) return false;
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        // Fill first column (only using s1)
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        
        // Fill first row (only using s2)
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        
        // Fill rest of the table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int k = i + j - 1;
                
                // Try taking from s1
                if (s1[i - 1] == s3[k]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                
                // Try taking from s2
                if (s2[j - 1] == s3[k]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Space optimized version
    bool isInterleaveOptimized(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        if (m + n != s3.length()) return false;
        
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }
        
        for (int i = 1; i <= m; i++) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            
            for (int j = 1; j <= n; j++) {
                int k = i + j - 1;
                bool takeS1 = dp[j] && s1[i - 1] == s3[k];
                bool takeS2 = dp[j - 1] && s2[j - 1] == s3[k];
                dp[j] = takeS1 || takeS2;
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1: " << (sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") ? "true" : "false") << endl;   // true
    cout << "Test 2: " << (sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") ? "true" : "false") << endl;   // false
    cout << "Test 3: " << (sol.isInterleave("", "", "") ? "true" : "false") << endl;                       // true
    
    return 0;
}
