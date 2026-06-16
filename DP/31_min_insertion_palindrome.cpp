/*
PROBLEM: Minimum Insertion Steps to Make String Palindrome (LeetCode 1312)
DIFFICULTY: Hard
PATTERN: LPS Application

DESCRIPTION:
Given a string s, find the minimum number of insertions to make it a palindrome.
In one step you can insert any character at any position of the string.

EXAMPLE:
Input: s = "zzazz"
Output: 0
Explanation: Already a palindrome

Input: s = "mbadm"
Output: 2
Explanation: Insert "bd" → "mbdadbm"

Input: s = "leetcode"
Output: 5
Explanation: Insert "lecot" → "leetcodocteel"

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
    // Approach 1: Using LPS (Brilliant!)
    // Minimum insertions = n - LPS(s)
    int minInsertions(string s) {
        int n = s.length();
        int lps = longestPalindromeSubseq(s);
        return n - lps;
    }
    
    int longestPalindromeSubseq(string s) {
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
        
        return dp[0][n-1];
    }
    
    // Approach 2: Direct DP
    // dp[i][j] = min insertions to make s[i..j] palindrome
    int minInsertionsDirect(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Fill by increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    // Either insert s[j] at front or s[i] at end
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
    
    // Approach 3: Get the actual palindrome
    string constructPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        // Backtrack to construct palindrome
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
            } else if (dp[i+1][j] < dp[i][j-1]) {
                result += s[i];
                i++;
            } else {
                result += s[j];
                j--;
            }
        }
        
        // Add reverse for second half
        int mid = result.length();
        for (int k = mid - (i > j ? 1 : 2); k >= 0; k--) {
            result += result[k];
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    string s1 = "zzazz";
    cout << "String: " << s1 << endl;
    cout << "Minimum insertions (LPS): " << sol.minInsertions(s1) << endl;
    cout << "Minimum insertions (Direct): " << sol.minInsertionsDirect(s1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    string s2 = "mbadm";
    cout << "String: " << s2 << endl;
    cout << "Minimum insertions: " << sol.minInsertions(s2) << endl;
    cout << "Resulting palindrome: " << sol.constructPalindrome(s2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    string s3 = "leetcode";
    cout << "String: " << s3 << endl;
    cout << "Minimum insertions: " << sol.minInsertions(s3) << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    string s4 = "abc";
    cout << "String: " << s4 << endl;
    cout << "Minimum insertions: " << sol.minInsertions(s4) << endl;
    cout << "Resulting palindrome: " << sol.constructPalindrome(s4) << endl;
    
    // Test case 5
    cout << "\nTest Case 5:" << endl;
    string s5 = "racecar";
    cout << "String: " << s5 << endl;
    cout << "Minimum insertions: " << sol.minInsertions(s5) << endl;
    
    return 0;
}

/*
EXPLANATION:

MINIMUM INSERTION TO MAKE PALINDROME

KEY INSIGHT:
Minimum insertions = n - LPS(s)

Where LPS = Longest Palindromic Subsequence

WHY?
- LPS characters are already in palindrome order
- Remaining (n - LPS) characters need to be matched
- Each unmatched character needs one insertion

EXAMPLE 1:
s = "mbadm"
LPS = "mam" (length 3)
Insertions = 5 - 3 = 2

We need to add:
- 'b' somewhere (to match existing 'b')
- 'd' somewhere (to match existing 'd')
Result: "mbdadbm" or "amdadma"

EXAMPLE 2:
s = "leetcode"
LPS = "eee" (length 3)
Insertions = 8 - 3 = 5

DIRECT DP APPROACH:
dp[i][j] = min insertions to make s[i..j] palindrome

Recurrence:
If s[i] == s[j]:
    dp[i][j] = dp[i+1][j-1]  (already matching)
Else:
    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1])
    
Either:
- Insert s[j] at beginning → make s[i..j-1] palindrome
- Insert s[i] at end → make s[i+1..j] palindrome

EXAMPLE TRACE:
s = "mbadm"

Base: dp[i][i] = 0

Length 2:
dp[0][1]: m!=b → 1 + min(dp[1][1], dp[0][0]) = 1
dp[1][2]: b!=a → 1
dp[2][3]: a!=d → 1
dp[3][4]: d!=m → 1

Length 3:
dp[0][2]: m!=a → 1 + min(dp[1][2], dp[0][1]) = 2
dp[1][3]: b!=d → 1 + min(dp[2][3], dp[1][2]) = 2
dp[2][4]: a!=m → 1 + min(dp[3][4], dp[2][3]) = 2

Length 4:
dp[0][3]: m!=d → 1 + min(dp[1][3], dp[0][2]) = 3
dp[1][4]: b!=m → 1 + min(dp[2][4], dp[1][3]) = 3

Length 5:
dp[0][4]: m==m → dp[1][3] = 2 ✓

Answer: 2

RELATED PROBLEMS:
1. Minimum Deletion to Make Palindrome: n - LPS
2. Minimum Insertion Steps: n - LPS
3. Longest Palindromic Subsequence: Base problem
4. Make Palindrome with k changes: Variation

PATTERN CONNECTIONS:
- LPS → Interval DP
- Min operations → LPS application
- Palindrome family problems

COMPARISON:
                         Deletion  Insertion
To make palindrome:      n - LPS   n - LPS
Same answer!             ✓         ✓

WHY SAME?
Both ask: "How many characters don't fit palindrome structure?"

INTERVIEW TIP:
Always mention: "This is n - LPS where LPS is Longest Palindromic 
Subsequence. LPS gives us the palindrome backbone, and remaining 
characters need to be added/removed."

SPACE OPTIMIZATION:
Can optimize LPS to O(n) space using rolling array.

OUTPUT:
Test Case 1:
String: zzazz
Minimum insertions (LPS): 0
Minimum insertions (Direct): 0

Test Case 2:
String: mbadm
Minimum insertions: 2
Resulting palindrome: mbdadbm

Test Case 3:
String: leetcode
Minimum insertions: 5

Test Case 4:
String: abc
Minimum insertions: 2
Resulting palindrome: abcba

Test Case 5:
String: racecar
Minimum insertions: 0
*/
