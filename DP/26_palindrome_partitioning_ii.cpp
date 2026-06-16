/*
PROBLEM: Palindrome Partitioning II (LeetCode 132)
DIFFICULTY: Hard
PATTERN: Partition DP + Palindrome Check

DESCRIPTION:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

EXAMPLE:
Input: s = "aab"
Output: 1
Explanation: Cut into "aa | b" (1 cut)

Input: s = "a"
Output: 0
Explanation: Already a palindrome

Input: s = "ab"
Output: 1

TIME COMPLEXITY: O(n²)
SPACE COMPLEXITY: O(n²) for palindrome table + O(n) for cuts
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    // Approach 1: DP with palindrome precomputation
    int minCut(string s) {
        int n = s.length();
        
        // Step 1: Build palindrome table
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        
        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
        }
        
        // Check for length 2
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                isPalin[i][i+1] = true;
            }
        }
        
        // Check for lengths greater than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && isPalin[i+1][j-1]) {
                    isPalin[i][j] = true;
                }
            }
        }
        
        // Step 2: Calculate minimum cuts
        vector<int> cuts(n, 0);
        
        for (int i = 0; i < n; i++) {
            // If entire substring [0...i] is palindrome, no cuts needed
            if (isPalin[0][i]) {
                cuts[i] = 0;
            } else {
                int minCuts = INT_MAX;
                
                // Try all possible cuts
                for (int j = 0; j < i; j++) {
                    // If right part [j+1...i] is palindrome
                    if (isPalin[j+1][i]) {
                        minCuts = min(minCuts, cuts[j] + 1);
                    }
                }
                
                cuts[i] = minCuts;
            }
        }
        
        return cuts[n-1];
    }
    
    // Approach 2: Optimized - build palindrome table differently
    int minCutOptimized(string s) {
        int n = s.length();
        vector<int> cuts(n);
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            cuts[i] = i;  // Max possible cuts
            
            for (int j = 0; j <= i; j++) {
                // Check if s[j...i] is palindrome
                if (s[i] == s[j] && (i - j < 2 || isPalin[j+1][i-1])) {
                    isPalin[j][i] = true;
                    
                    if (j == 0) {
                        cuts[i] = 0;  // Whole substring is palindrome
                    } else {
                        cuts[i] = min(cuts[i], cuts[j-1] + 1);
                    }
                }
            }
        }
        
        return cuts[n-1];
    }
    
    // Helper to print the partitions
    void printPartitions(string s, int minCuts) {
        cout << "Minimum cuts: " << minCuts << endl;
        // For actual partitions, need backtracking
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    cout << "Test Case 1:" << endl;
    string s1 = "aab";
    cout << "String: " << s1 << endl;
    cout << "Minimum cuts: " << sol.minCut(s1) << endl;
    cout << "Minimum cuts (Optimized): " << sol.minCutOptimized(s1) << endl;
    
    // Test case 2
    cout << "\nTest Case 2:" << endl;
    string s2 = "a";
    cout << "String: " << s2 << endl;
    cout << "Minimum cuts: " << sol.minCut(s2) << endl;
    
    // Test case 3
    cout << "\nTest Case 3:" << endl;
    string s3 = "ababbbabbababa";
    cout << "String: " << s3 << endl;
    cout << "Minimum cuts: " << sol.minCut(s3) << endl;
    
    // Test case 4
    cout << "\nTest Case 4:" << endl;
    string s4 = "racecar";
    cout << "String: " << s4 << endl;
    cout << "Minimum cuts: " << sol.minCut(s4) << endl;
    
    return 0;
}

/*
EXPLANATION:

PALINDROME PARTITIONING II - Minimum Cuts

TWO-STEP APPROACH:

Step 1: Build Palindrome Table
isPalin[i][j] = true if s[i...j] is palindrome

Recurrence:
isPalin[i][j] = (s[i] == s[j]) && isPalin[i+1][j-1]

Base cases:
- Single char: always palindrome
- Two chars: check if equal

Step 2: Calculate Minimum Cuts
cuts[i] = minimum cuts needed for s[0...i]

Recurrence:
If s[0...i] is palindrome:
    cuts[i] = 0
Else:
    cuts[i] = min(cuts[j] + 1) for all j where s[j+1...i] is palindrome

EXAMPLE:
s = "aab"

Palindrome table:
  a  a  b
a T  T  F
a    T  F
b       T

cuts[0] = 0 (a is palindrome)
cuts[1] = 0 (aa is palindrome)
cuts[2]:
  - s[0..2] = "aab" not palindrome
  - Try j=1: s[2..2]="b" is palindrome, cuts[1]+1 = 0+1 = 1 ✓
  - Try j=0: s[1..2]="ab" not palindrome
  cuts[2] = 1

KEY INSIGHTS:

1. Must check all possible partitions → DP
2. Need to know if substring is palindrome → Precompute
3. Partition DP pattern: try all split points

OPTIMIZATION:
Build palindrome table and cuts array together in single pass.

COMPARISON WITH PALINDROME PARTITIONING I:
- Part I: Find all partitions (backtracking)
- Part II: Find minimum cuts (DP)

COMMON MISTAKES:
1. Forgetting to handle single character base case
2. Not precomputing palindrome table (O(n³) without it!)
3. Wrong indices in palindrome check

INTERVIEW TIP:
Always mention: "First I'll precompute which substrings are palindromes, 
then use DP to find minimum cuts."

OUTPUT:
Test Case 1:
String: aab
Minimum cuts: 1
Minimum cuts (Optimized): 1

Test Case 2:
String: a
Minimum cuts: 0

Test Case 3:
String: ababbbabbababa
Minimum cuts: 3

Test Case 4:
String: racecar
Minimum cuts: 0
*/
