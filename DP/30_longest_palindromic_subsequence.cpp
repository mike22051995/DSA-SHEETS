/*
PROBLEM: Longest Palindromic Subsequence (LeetCode 516)
DIFFICULTY: Medium
PATTERN: Interval DP / LCS Variant

DESCRIPTION:
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting 
some or no elements without changing the order of the remaining elements.

EXAMPLE:
Input: s = "bbbab"
Output: 4
Explanation: "bbbb" is the longest palindromic subsequence.

Input: s = "cbbd"
Output: 2
Explanation: "bb" is the longest palindromic subsequence.

Input: s = "abcabcabcabc"
Output: 7
Explanation: "abcbcba" is one of the longest palindromic subsequences.

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n²)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: LCS with reverse (Smart!)
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return longestCommonSubsequence(s, rev);
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
    
    // Approach 2: Interval DP (Direct)
    int longestPalindromeSubseqDirect(string s) {
        int n = s.length();
        
        // dp[i][j] = LPS length in s[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: single character
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill by increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (i+1 <= j-1 ? dp[i+1][j-1] : 0);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
    
    // Approach 3: Memoization
    int lpsHelper(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == s[j]) {
            return dp[i][j] = 2 + lpsHelper(s, i+1, j-1, dp);
        } else {
            return dp[i][j] = max(lpsHelper(s, i+1, j, dp), 
                                   lpsHelper(s, i, j-1, dp));
        }
    }
    
    int longestPalindromeSubseqMemo(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return lpsHelper(s, 0, n-1, dp);
    }
    
    // Approach 4: Space optimized (O(n) space)
    int longestPalindromeSubseqOptimized(string s) {
        int n = s.length();
        vector<int> prev(n, 0), curr(n, 0);
        
        for (int i = n-1; i >= 0; i--) {
            curr[i] = 1;  // Single character
            
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    curr[j] = 2 + (i+1 <= j-1 ? prev[j-1] : 0);
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            
            prev = curr;
        }
        
        return prev[n-1];
    }
    
    // Bonus: Get the actual palindromic subsequence
    string getLPS(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (i+1 <= j-1 ? dp[i+1][j-1] : 0);
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        // Backtrack to find the LPS
        string result = "";
        int i = 0, j = n-1;
        
        while (i <= j) {
            if (i == j) {
                result += s[i];
                break;
            }
            
            if (s[i] == s[j]) {
                result += s[i];
                i++;
                j--;
            } else if (dp[i+1][j] > dp[i][j-1]) {
                i++;
            } else {
                j--;
            }
        }
        
        // Mirror for second half
        string secondHalf = result;
        if (result.length() % 2 == 1) {
            secondHalf.pop_back();
        }
        reverse(secondHalf.begin(), secondHalf.end());
        result += secondHalf;
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    string s1 = "bbbab";
    cout << "String: " << s1 << endl;
    cout << "LPS Length (LCS): " << sol.longestPalindromeSubseq(s1) << endl;
    cout << "LPS Length (Direct): " << sol.longestPalindromeSubseqDirect(s1) << endl;
    cout << "LPS Length (Memo): " << sol.longestPalindromeSubseqMemo(s1) << endl;
    cout << "One LPS: " << sol.getLPS(s1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    string s2 = "cbbd";
    cout << "String: " << s2 << endl;
    cout << "LPS Length: " << sol.longestPalindromeSubseq(s2) << endl;
    cout << "One LPS: " << sol.getLPS(s2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    string s3 = "abcabcabcabc";
    cout << "String: " << s3 << endl;
    cout << "LPS Length: " << sol.longestPalindromeSubseq(s3) << endl;
    cout << "One LPS: " << sol.getLPS(s3) << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    string s4 = "racecar";
    cout << "String: " << s4 << endl;
    cout << "LPS Length: " << sol.longestPalindromeSubseq(s4) << endl;
    
    return 0;
}

/*
EXPLANATION:

LONGEST PALINDROMIC SUBSEQUENCE - Two Beautiful Approaches!

APPROACH 1: LCS with Reverse (BRILLIANT!)
Key insight: LPS of string S = LCS(S, reverse(S))

Why? A palindrome reads same forwards and backwards.
So common subsequence of S and reverse(S) is palindromic!

Example:
s = "bbbab"
rev = "babbb"
LCS(s, rev) = "bbbb" or "bbb" with length 4

APPROACH 2: Interval DP (Direct)
dp[i][j] = LPS length in substring s[i...j]

Recurrence:
If s[i] == s[j]:
    dp[i][j] = 2 + dp[i+1][j-1]
Else:
    dp[i][j] = max(dp[i+1][j], dp[i][j-1])

Base case:
dp[i][i] = 1 (single character is palindrome)

EXAMPLE TRACE:
s = "bbbab"

Base: dp[i][i] = 1 for all i

Length 2:
dp[0][1]: b==b → 2 + dp[1][0] = 2
dp[1][2]: b==b → 2
dp[2][3]: b!=a → max(dp[3][3], dp[2][2]) = 1
dp[3][4]: a!=b → max(dp[4][4], dp[3][3]) = 1

Length 3:
dp[0][2]: b==b → 2 + dp[1][1] = 3
dp[1][3]: b!=a → max(dp[2][3], dp[1][2]) = 2
dp[2][4]: b==b → 2 + dp[3][3] = 3

Length 4:
dp[0][3]: b!=a → max(dp[1][3], dp[0][2]) = 3
dp[1][4]: b==b → 2 + dp[2][3] = 3

Length 5:
dp[0][4]: b==b → 2 + dp[1][3] = 4 ✓

Answer: dp[0][4] = 4

WHICH APPROACH TO USE?
- LCS method: If you already know LCS
- Direct method: More intuitive, easier to explain
- Both: O(n²) time and space

RELATED PROBLEMS:
1. Minimum Deletion to Make Palindrome:
   n - LPS(s)

2. Minimum Insertion to Make Palindrome:
   n - LPS(s)

3. Longest Palindromic Substring:
   Continuous vs subsequence

PATTERN RECOGNITION:
- Interval DP: Fill by increasing length
- Match ends: Include both, else try excluding each
- Palindrome: Think of matching from both ends

INTERVIEW TIP:
Mention both approaches:
"I can use LCS with reverse string, or direct interval DP.
Both are O(n²). The direct method is more intuitive for 
explaining the subproblem structure."

SPACE OPTIMIZATION:
Can reduce to O(n) by using only two rows (prev and curr).

OUTPUT:
Test Case 1:
String: bbbab
LPS Length (LCS): 4
LPS Length (Direct): 4
LPS Length (Memo): 4
One LPS: bbbb

Test Case 2:
String: cbbd
LPS Length: 2
One LPS: bb

Test Case 3:
String: abcabcabcabc
LPS Length: 7
One LPS: abcbcba

Test Case 4:
String: racecar
LPS Length: 7
*/
