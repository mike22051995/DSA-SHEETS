/*
PROBLEM: Scramble String (LeetCode 87)
DIFFICULTY: Hard
PATTERN: Interval DP / Partition with Recursion

DESCRIPTION:
We can scramble a string s to get a string t using the following algorithm:
1. If the length of the string is 1, stop.
2. If the length of the string is > 1, do the following:
   - Split the string into two non-empty substrings at a random index
   - Randomly decide to swap the two substrings or not
   - Apply step 1 recursively on each of the two substrings

Given two strings s1 and s2 of the same length, return true if s2 is a 
scrambled string of s1, otherwise, return false.

EXAMPLE:
Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: Split "great" → "gr" + "eat"
              Split "gr" → "g" + "r", swap → "rg"
              Result: "rg" + "eat" = "rgeat"

Input: s1 = "abcde", s2 = "caebd"
Output: false

Input: s1 = "a", s2 = "a"
Output: true

TIME COMPLEXITY: O(n^4) with memoization
SPACE COMPLEXITY: O(n^3) for memoization
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion with Memoization
    unordered_map<string, bool> memo;
    
    bool isScramble(string s1, string s2) {
        // Quick checks
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        // Check if same characters exist
        string sorted1 = s1, sorted2 = s2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        if (sorted1 != sorted2) return false;
        
        // Check memo
        string key = s1 + "_" + s2;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        int n = s1.length();
        
        // Try all split points
        for (int i = 1; i < n; i++) {
            // Case 1: No swap
            // s1[0..i-1] matches s2[0..i-1]
            // s1[i..n-1] matches s2[i..n-1]
            bool noSwap = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                         isScramble(s1.substr(i), s2.substr(i));
            
            if (noSwap) {
                memo[key] = true;
                return true;
            }
            
            // Case 2: Swap
            // s1[0..i-1] matches s2[n-i..n-1]
            // s1[i..n-1] matches s2[0..n-i-1]
            bool swap = isScramble(s1.substr(0, i), s2.substr(n-i)) &&
                       isScramble(s1.substr(i), s2.substr(0, n-i));
            
            if (swap) {
                memo[key] = true;
                return true;
            }
        }
        
        memo[key] = false;
        return false;
    }
    
    // Approach 2: 3D DP (More complex but educational)
    bool isScrambleDP(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        int n = s1.length();
        
        // dp[len][i][j] = true if s1[i..i+len-1] is scramble of s2[j..j+len-1]
        bool dp[n+1][n][n];
        
        // Initialize
        for (int len = 0; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[len][i][j] = false;
                }
            }
        }
        
        // Base case: length 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        // Fill for increasing lengths
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {
                    // Try all split points
                    for (int k = 1; k < len; k++) {
                        // No swap case
                        if (dp[k][i][j] && dp[len-k][i+k][j+k]) {
                            dp[len][i][j] = true;
                            break;
                        }
                        
                        // Swap case
                        if (dp[k][i][j+len-k] && dp[len-k][i+k][j]) {
                            dp[len][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return dp[n][0][0];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    string s1_1 = "great", s2_1 = "rgeat";
    cout << "s1 = \"" << s1_1 << "\", s2 = \"" << s2_1 << "\"" << endl;
    cout << "Is Scramble: " << (sol.isScramble(s1_1, s2_1) ? "true" : "false") << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    string s1_2 = "abcde", s2_2 = "caebd";
    cout << "s1 = \"" << s1_2 << "\", s2 = \"" << s2_2 << "\"" << endl;
    sol.memo.clear();
    cout << "Is Scramble: " << (sol.isScramble(s1_2, s2_2) ? "true" : "false") << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    string s1_3 = "a", s2_3 = "a";
    cout << "s1 = \"" << s1_3 << "\", s2 = \"" << s2_3 << "\"" << endl;
    sol.memo.clear();
    cout << "Is Scramble: " << (sol.isScramble(s1_3, s2_3) ? "true" : "false") << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    string s1_4 = "abcdefghijklmnopq", s2_4 = "efghijklmnopqcadb";
    cout << "s1 = \"" << s1_4 << "\", s2 = \"" << s2_4 << "\"" << endl;
    sol.memo.clear();
    cout << "Is Scramble: " << (sol.isScramble(s1_4, s2_4) ? "true" : "false") << endl;
    
    return 0;
}

/*
EXPLANATION:

SCRAMBLE STRING - Complex Partition DP

PROBLEM UNDERSTANDING:
A scramble operation:
1. Split string at any point
2. Optionally swap the two parts
3. Recursively scramble each part

Example: "great"
Split: "gr" + "eat"
Scramble "gr": swap → "rg"
Result: "rgeat"

KEY INSIGHT:
For s1 to be scramble of s2, we must find a split point where:
EITHER:
- Left of s1 matches left of s2 (no swap)
- Right of s1 matches right of s2

OR:
- Left of s1 matches right of s2 (swap)
- Right of s1 matches left of s2

RECURRENCE:
isScramble(s1, s2):
  If s1 == s2: return true
  If sorted(s1) != sorted(s2): return false
  
  For each split point i:
    If (isScramble(s1[0..i], s2[0..i]) && isScramble(s1[i..n], s2[i..n]))
       OR
       (isScramble(s1[0..i], s2[n-i..n]) && isScramble(s1[i..n], s2[0..n-i])):
      return true
  
  return false

EXAMPLE TRACE:
s1 = "great", s2 = "rgeat"

Check split at i=2:
Left: s1[0..2]="gr", Right: s1[2..5]="eat"

No swap:
  s2[0..2]="rg", s2[2..5]="eat"
  "gr" vs "rg": Not equal, check recursively
  
Swap:
  s2[3..5]="at", s2[0..3]="rge"
  "gr" vs "at": Different chars, fail
  
Check split at i=2 with swap:
  Left "gr" vs Right of s2 starting at 5-2=3: "at" - fail
  
Actually, split at i=2:
No swap: "gr"|"eat" vs "rg"|"eat"
  Need to check if "gr" scramble of "rg": YES (swap at i=1)
  And "eat" == "eat": YES
  Return TRUE!

OPTIMIZATIONS:
1. Character frequency check (sorted strings)
2. Memoization with string keys
3. Early termination

3D DP VERSION:
dp[len][i][j] = is s1[i..i+len-1] scramble of s2[j..j+len-1]

For each length, position i in s1, position j in s2:
  Try all split points k:
    No swap: dp[k][i][j] && dp[len-k][i+k][j+k]
    Swap: dp[k][i][j+len-k] && dp[len-k][i+k][j]

PATTERN RECOGNITION:
- Try all partitions → Partition DP
- Two ways at each split → OR condition
- Recursive structure → Memoization crucial

SIMILAR PROBLEMS:
- Matrix Chain Multiplication (partition)
- Burst Balloons (interval)
- Boolean Parenthesization

INTERVIEW TIP:
"For each split point, I check two cases: swap and no swap.
Must verify both left and right parts match (possibly scrambled).
Memoization is crucial to avoid recomputation."

COMPLEXITY:
Without memo: O(4^n) - exponential!
With memo: O(n^4) - n^3 states, O(n) to check each
Space: O(n^3) for memoization

EDGE CASES:
1. Single character: always true if equal
2. Different characters: immediate false
3. Anagrams but not scrambles: need full check

WHY HARD?
- Recursive structure with two cases
- Need to check all split points
- Memoization key design
- Understanding swap logic

OUTPUT:
Test Case 1:
s1 = "great", s2 = "rgeat"
Is Scramble: true

Test Case 2:
s1 = "abcde", s2 = "caebd"
Is Scramble: false

Test Case 3:
s1 = "a", s2 = "a"
Is Scramble: true

Test Case 4:
s1 = "abcdefghijklmnopq", s2 = "efghijklmnopqcadb"
Is Scramble: false
*/
