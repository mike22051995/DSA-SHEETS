/*
PROBLEM: Distinct Subsequences (LeetCode 115)
DIFFICULTY: Hard
PATTERN: String DP / Counting Paths

DESCRIPTION:
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

EXAMPLE:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
rabbb̲it (remove 1st b)
rabb̲bit (remove 2nd b)  
rabbi̲t (remove 3rd b)

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
b̲abgbag̲
b̲abgb̲ag
b̲a̲bgba̲g̲
ba̲bgb̲ag̲
babgbag̲

TIME COMPLEXITY: O(m*n) where m = len(s), n = len(t)
SPACE COMPLEXITY: O(m*n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Approach 1: 2D DP
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // dp[i][j] = number of distinct subsequences of s[0..i-1] that equal t[0..j-1]
        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1, 0));
        
        // Base case: empty t can be formed by any prefix of s (empty subsequence)
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Don't use s[i-1]
                dp[i][j] = dp[i-1][j];
                
                // Use s[i-1] if it matches t[j-1]
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
    
    // Approach 2: Space Optimized (1D DP)
    int numDistinctOptimized(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<unsigned long long> dp(n+1, 0);
        dp[0] = 1;  // Empty string
        
        for (int i = 1; i <= m; i++) {
            // Traverse right to left to avoid overwriting
            for (int j = n; j >= 1; j--) {
                if (s[i-1] == t[j-1]) {
                    dp[j] += dp[j-1];
                }
            }
        }
        
        return dp[n];
    }
    
    // Approach 3: Memoization
    int numDistinctHelper(string& s, string& t, int i, int j, 
                          vector<vector<int>>& dp) {
        // If t is exhausted, found one subsequence
        if (j == 0) return 1;
        
        // If s is exhausted but t is not
        if (i == 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        // Don't use s[i-1]
        int count = numDistinctHelper(s, t, i-1, j, dp);
        
        // Use s[i-1] if matches
        if (s[i-1] == t[j-1]) {
            count += numDistinctHelper(s, t, i-1, j-1, dp);
        }
        
        return dp[i][j] = count;
    }
    
    int numDistinctMemo(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return numDistinctHelper(s, t, m, n, dp);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    string s1 = "rabbbit", t1 = "rabbit";
    cout << "s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Distinct subsequences: " << sol.numDistinct(s1, t1) << endl;
    cout << "Distinct subsequences (Optimized): " << sol.numDistinctOptimized(s1, t1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    string s2 = "babgbag", t2 = "bag";
    cout << "s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Distinct subsequences: " << sol.numDistinct(s2, t2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    string s3 = "abc", t3 = "abc";
    cout << "s = \"" << s3 << "\", t = \"" << t3 << "\"" << endl;
    cout << "Distinct subsequences: " << sol.numDistinct(s3, t3) << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    string s4 = "aaaa", t4 = "aa";
    cout << "s = \"" << s4 << "\", t = \"" << t4 << "\"" << endl;
    cout << "Distinct subsequences: " << sol.numDistinct(s4, t4) << endl;
    
    return 0;
}

/*
EXPLANATION:

DISTINCT SUBSEQUENCES - Counting Paths in DP Grid

PROBLEM INTUITION:
Count how many ways we can form string t as subsequence of s.

KEY INSIGHT:
At each position, we have TWO choices:
1. Don't use current character of s
2. Use current character (if it matches)

Both choices are INDEPENDENT → Add them!

RECURRENCE:
dp[i][j] = number of ways to form t[0..j-1] from s[0..i-1]

If s[i-1] == t[j-1]:
    dp[i][j] = dp[i-1][j]         (don't use s[i-1])
             + dp[i-1][j-1]       (use s[i-1])
Else:
    dp[i][j] = dp[i-1][j]         (can't use s[i-1])

BASE CASES:
- dp[i][0] = 1 for all i (empty string always matchable)
- dp[0][j] = 0 for j > 0 (can't form non-empty from empty)

EXAMPLE TRACE:
s = "rabbbit", t = "rabbit"

     ""  r  a  b  b  i  t
""   1   0  0  0  0  0  0
r    1   1  0  0  0  0  0
a    1   1  1  0  0  0  0
b    1   1  1  1  0  0  0
b    1   1  1  2  1  0  0
b    1   1  1  3  3  0  0
i    1   1  1  3  3  3  0
t    1   1  1  3  3  3  3

Let's trace key cells:

dp[4][3] (s="rabb", t="rab"):
s[3]='b' == t[2]='b'
dp[4][3] = dp[3][3] + dp[3][2] = 1 + 1 = 2
(Two ways: use 1st b or 2nd b)

dp[5][3] (s="rabbb", t="rab"):
s[4]='b' == t[2]='b'
dp[5][3] = dp[4][3] + dp[4][2] = 2 + 1 = 3
(Three ways: use any of 3 b's)

Final: dp[7][6] = 3

VISUALIZATION:
Think of it as paths in a grid!
- Each match gives us 2 paths: use it or skip it
- Count all paths from (0,0) to (m,n)

PATTERN RECOGNITION:
- Counting problems → DP
- Subsequence → Two pointers with choices
- Two choices at each step → Add both

SIMILAR PROBLEMS:
- Edit Distance (minimum operations)
- Longest Common Subsequence (maximum length)
- Interleaving String (possible/not)

SPACE OPTIMIZATION:
Can reduce to O(n) by using 1D array.
Important: Traverse right to left for inner loop!

WHY RIGHT TO LEFT?
dp[j] needs old dp[j-1], not updated one.

INTERVIEW TIP:
"For each character in s, I have two choices: use it or skip it.
If I use it (and it matches), I add the ways from previous state.
This is counting paths in DP grid."

EDGE CASES:
1. t longer than s: return 0
2. t empty: return 1
3. Multiple same characters: Count all combinations

COMPLEXITY ANALYSIS:
Time: O(m*n) - fill m*n table
Space: O(m*n) or O(n) with optimization

OUTPUT:
Test Case 1:
s = "rabbbit", t = "rabbit"
Distinct subsequences: 3
Distinct subsequences (Optimized): 3

Test Case 2:
s = "babgbag", t = "bag"
Distinct subsequences: 5

Test Case 3:
s = "abc", t = "abc"
Distinct subsequences: 1

Test Case 4:
s = "aaaa", t = "aa"
Distinct subsequences: 6
*/
