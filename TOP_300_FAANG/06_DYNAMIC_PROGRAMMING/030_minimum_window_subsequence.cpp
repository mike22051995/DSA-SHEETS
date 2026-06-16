/*
================================================================================
PROBLEM: Minimum Window Subsequence (LeetCode #727)
DIFFICULTY: Hard
PATTERN: Dynamic Programming / Two Pointers
COMPANIES: Amazon, Google, Microsoft
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Two pointers approach - O(S*T) time
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        int minLen = INT_MAX;
        string result = "";
        
        int i = 0;
        
        while (i < sLen) {
            int j = 0;
            
            // Forward pass - find subsequence
            while (i < sLen) {
                if (s[i] == t[j]) {
                    j++;
                    if (j == tLen) break;
                }
                i++;
            }
            
            if (i == sLen) break;
            
            // Backward pass - shrink window
            int end = i;
            j = tLen - 1;
            
            while (j >= 0) {
                if (s[i] == t[j]) {
                    j--;
                }
                i--;
            }
            
            i++;
            
            if (end - i + 1 < minLen) {
                minLen = end - i + 1;
                result = s.substr(i, minLen);
            }
        }
        
        return result;
    }
    
    // DP approach - O(S*T) time, O(S*T) space
    string minWindowDP(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= min(i, n); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        int start = 0;
        int minLen = INT_MAX;
        
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
};

int main() {
    Solution sol;
    string s1 = "abcdebdde";
    string t1 = "bde";
    
    cout << "Minimum window: " << sol.minWindow(s1, t1) << endl;
    
    return 0;
}

/*
SIMILAR PROBLEMS:
1. Minimum Window Substring (LeetCode #76)
2. Longest Substring Without Repeating (LeetCode #3)
3. Substring with Concatenation (LeetCode #30)
4. Is Subsequence (LeetCode #392)
5. Number of Matching Subsequences (LeetCode #792)
6. Find All Anagrams (LeetCode #438)
7. Permutation in String (LeetCode #567)
8. Longest Repeating Character Replacement (LeetCode #424)
9. Distinct Subsequences (LeetCode #115)
10. Edit Distance (LeetCode #72)
*/
