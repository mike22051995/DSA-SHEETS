/*
PROBLEM: Interleaving String (LeetCode 97)
DIFFICULTY: Medium
PATTERN: 2D String DP

DESCRIPTION:
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving 
of s1 and s2. An interleaving of two strings s and t is a configuration where 
s and t are divided into n and m non-empty substrings respectively, such that:
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
s3 = s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + ...

EXAMPLE:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: s3 can be formed by:
"aa" (from s1) + "dbbc" (from s2) + "b" (from s1) + "c" (from s2) + "ac" (from s1)

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Input: s1 = "", s2 = "b", s3 = "b"
Output: true

TIME COMPLEXITY: O(m*n) where m=len(s1), n=len(s2)
SPACE COMPLEXITY: O(m*n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Approach 1: 2D DP
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        // Quick check
        if (m + n != s3.length()) return false;
        
        // dp[i][j] = true if s3[0..i+j-1] can be formed by s1[0..i-1] and s2[0..j-1]
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        // Base case
        dp[0][0] = true;
        
        // Fill first row (only s2 used)
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }
        
        // Fill first column (only s1 used)
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        
        // Fill rest of table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int k = i + j - 1;  // Position in s3
                
                // Take from s1
                bool fromS1 = dp[i-1][j] && s1[i-1] == s3[k];
                
                // Take from s2
                bool fromS2 = dp[i][j-1] && s2[j-1] == s3[k];
                
                dp[i][j] = fromS1 || fromS2;
            }
        }
        
        return dp[m][n];
    }
    
    // Approach 2: Space Optimized (1D DP)
    bool isInterleaveOptimized(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        if (m + n != s3.length()) return false;
        
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        // Fill first row
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j-1] && s2[j-1] == s3[j-1];
        }
        
        // Process each character of s1
        for (int i = 1; i <= m; i++) {
            dp[0] = dp[0] && s1[i-1] == s3[i-1];
            
            for (int j = 1; j <= n; j++) {
                int k = i + j - 1;
                
                // From s1 (current row)
                bool fromS1 = dp[j] && s1[i-1] == s3[k];
                
                // From s2 (previous column)
                bool fromS2 = dp[j-1] && s2[j-1] == s3[k];
                
                dp[j] = fromS1 || fromS2;
            }
        }
        
        return dp[n];
    }
    
    // Approach 3: Recursion with Memoization
    bool isInterleaveHelper(string& s1, string& s2, string& s3, 
                           int i, int j, vector<vector<int>>& dp) {
        // Base case: reached end of all strings
        if (i == s1.length() && j == s2.length()) {
            return true;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        bool result = false;
        
        // Try taking from s1
        if (i < s1.length() && s1[i] == s3[i+j]) {
            result = isInterleaveHelper(s1, s2, s3, i+1, j, dp);
        }
        
        // Try taking from s2
        if (!result && j < s2.length() && s2[j] == s3[i+j]) {
            result = isInterleaveHelper(s1, s2, s3, i, j+1, dp);
        }
        
        return dp[i][j] = result;
    }
    
    bool isInterleaveMemo(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return isInterleaveHelper(s1, s2, s3, 0, 0, dp);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    string s1_1 = "aabcc", s2_1 = "dbbca", s3_1 = "aadbbcbcac";
    cout << "s1 = \"" << s1_1 << "\", s2 = \"" << s2_1 << "\", s3 = \"" << s3_1 << "\"" << endl;
    cout << "Is Interleave: " << (sol.isInterleave(s1_1, s2_1, s3_1) ? "true" : "false") << endl;
    cout << "Is Interleave (Optimized): " << (sol.isInterleaveOptimized(s1_1, s2_1, s3_1) ? "true" : "false") << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    string s1_2 = "aabcc", s2_2 = "dbbca", s3_2 = "aadbbbaccc";
    cout << "s1 = \"" << s1_2 << "\", s2 = \"" << s2_2 << "\", s3 = \"" << s3_2 << "\"" << endl;
    cout << "Is Interleave: " << (sol.isInterleave(s1_2, s2_2, s3_2) ? "true" : "false") << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    string s1_3 = "", s2_3 = "b", s3_3 = "b";
    cout << "s1 = \"" << s1_3 << "\", s2 = \"" << s2_3 << "\", s3 = \"" << s3_3 << "\"" << endl;
    cout << "Is Interleave: " << (sol.isInterleave(s1_3, s2_3, s3_3) ? "true" : "false") << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    string s1_4 = "ab", s2_4 = "bc", s3_4 = "babc";
    cout << "s1 = \"" << s1_4 << "\", s2 = \"" << s2_4 << "\", s3 = \"" << s3_4 << "\"" << endl;
    cout << "Is Interleave: " << (sol.isInterleave(s1_4, s2_4, s3_4) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:

INTERLEAVING STRING - 2D Path Finding

PROBLEM INTUITION:
Can we form s3 by taking characters from s1 and s2 in order?

KEY INSIGHT:
At each position in s3, we must take character from either s1 or s2.
This forms a 2D grid where we can move:
- Right: take from s2
- Down: take from s1

Goal: Can we reach (m, n) from (0, 0)?

RECURRENCE:
dp[i][j] = true if s3[0..i+j-1] can be formed from s1[0..i-1] and s2[0..j-1]

dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1])  // Take from s1
        || (dp[i][j-1] && s2[j-1] == s3[i+j-1])  // Take from s2

BASE CASES:
- dp[0][0] = true (empty strings)
- dp[i][0] = s1[0..i-1] == s3[0..i-1]
- dp[0][j] = s2[0..j-1] == s3[0..j-1]

EXAMPLE TRACE:
s1 = "aab", s2 = "axy", s3 = "aaxaby"

       ""  a   x   y
    "" T   F   F   F
    a  T   T   F   F
    a  T   T   T   F
    b  F   F   F   F

Wait, let's trace correctly:
s1 = "aa", s2 = "ab", s3 = "aaba"

       ""  a   b
    "" T   T   F
    a  T   T   T
    a  T   T   T

dp[0][1]: s2[0]='a' == s3[0]='a' → True
dp[1][0]: s1[0]='a' == s3[0]='a' → True
dp[1][1]: 
  From s1: dp[0][1] && s1[0]=='a' → T && T = T
  From s2: dp[1][0] && s2[0]=='a' → T && T = T
  Result: T || T = T

dp[2][1]:
  k = 2+1-1 = 2, s3[2] = 'b'
  From s1: dp[1][1] && s1[1]=='a' → T && F = F
  From s2: dp[2][0] && s2[0]=='a' → T && F = F
  Result: F || F = F... wait

Let me retrace with correct example:
s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"

       ""  d   b   b   c   a
    "" T   F   F   F   F   F
    a  T   F   F   F   F   F
    a  T   T   T   T   T   F
    b  F   T   T   F   T   F
    c  F   F   T   T   T   T
    c  F   F   F   T   F   T

VISUALIZATION:
Think of grid where:
- Horizontal move: take from s2
- Vertical move: take from s1
- Find path from top-left to bottom-right
- At each cell, check if current s3 character matches

PATTERN RECOGNITION:
- Two strings forming third → 2D DP
- Path finding in grid → Boolean DP
- OR condition → Multiple ways possible

SIMILAR PROBLEMS:
- Edit Distance (min operations)
- Distinct Subsequences (count ways)
- Longest Common Subsequence (max length)

SPACE OPTIMIZATION:
Only need previous row → O(n) space

INTERVIEW TIP:
"This is 2D DP. dp[i][j] means using first i chars of s1 and 
first j chars of s2, can we form first i+j chars of s3?
At each cell, try taking from s1 or s2."

EDGE CASES:
1. Length mismatch: immediate false
2. Empty strings: check remaining string == s3
3. Single character strings

COMPLEXITY:
Time: O(m*n) - fill m*n table
Space: O(m*n) or O(n) optimized

OUTPUT:
Test Case 1:
s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Is Interleave: true
Is Interleave (Optimized): true

Test Case 2:
s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Is Interleave: false

Test Case 3:
s1 = "", s2 = "b", s3 = "b"
Is Interleave: true

Test Case 4:
s1 = "ab", s2 = "bc", s3 = "babc"
Is Interleave: true
*/
